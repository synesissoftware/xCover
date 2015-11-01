/* /////////////////////////////////////////////////////////////////////////
 * File:        src/xcover.core.cpp
 *
 * Purpose:     Main implementation file for xCover, a C/C++ code coverage
 *              library.
 *
 * Created:     1st March 2008
 * Updated:     19th January 2010
 *
 * Home:        http://xcover.org/
 *
 * Copyright (c) 2008-2010, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */



/* /////////////////////////////////////////////////////////////////////////
 * Feature control
 */

#define XCOVER_NO_AUTO_INIT
#ifdef _DEBUG
//# define XCOVER_USE_SHWILD
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <xcover/xcover.h>

#include <stlsoft/stlsoft.h>
#if defined(STLSOFT_COMPILER_IS_MSVC)
# if _MSC_VER >= 1400
/* #  define STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_MALLOC_ALLOCATOR */
/* #  define STLSOFT_ALLOCATOR_SELECTOR_NO_USE_STD_ALLOCATOR */
/* #  define XCOVER_USE_SIMPLE_STRING_ */
# else
#  pragma warning(disable: 4702)
# endif
#endif /* compiler */


#ifdef XCOVER_USE_SHWILD
# include <shwild/shwild.hpp>
#else /* ? XCOVER_USE_SHWILD */
# include <platformstl/platformstl.h>
# if defined(PLATFORMSTL_OS_IS_UNIX) && \
		 !defined(_WIN32)
# define XCOVER_USE_FNMATCH_
# elif defined(PLATFORMSTL_OS_IS_WINDOWS) || \
       (   defined(PLATFORMSTL_OS_IS_UNIX) && \
           defined(_WIN32))
#  include <shlwapi.h>
#  define XCOVER_USE_PATHMATCH_
# else /* ? OS */
#  error Platform not discriminated
# endif /* OS */
#endif /* XCOVER_USE_SHWILD */

#include <stlsoft/smartptr/shared_ptr.hpp>
#ifdef XCOVER_USE_SIMPLE_STRING_
# include <stlsoft/string/simple_string.hpp>
#endif /* XCOVER_USE_SIMPLE_STRING_ */
#include <stlsoft/synch/lock_scope.hpp>
#include <platformstl/platformstl.h>
#include <platformstl/filesystem/filesystem_traits.hpp>
#include <platformstl/synch/spin_mutex.hpp>
#include <platformstl/synch/thread_mutex.hpp>

#include <map>
#include <string>
#include <vector>

#include <limits.h>
#include <stdio.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if defined(_STLSOFT_NO_NAMESPACE)
# define XCOVER_NO_NAMESPACE
#endif /* _STLSOFT_NO_NAMESPACE */

#ifndef XCOVER_NO_NAMESPACE
namespace xcover
{
#endif /* !XCOVER_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

namespace
{
    // String type used by the implementation
    typedef char                                    char_t;
#ifdef XCOVER_USE_SIMPLE_STRING_
    typedef stlsoft::basic_simple_string<char_t>    string_t;
#else /* ? XCOVER_USE_SIMPLE_STRING_ */
    typedef std::basic_string<char_t>               string_t;
#endif /* XCOVER_USE_SIMPLE_STRING_ */
    typedef platformstl::filesystem_traits<char_t>  filesystem_traits_t;

#if defined(PLATFORMSTL_OS_IS_WINDOWS) || \
    defined(_WIN32)
    inline string_t normalise_fileName(string_t const& fileName)
    {
        string_t newFileName(fileName);

        std::replace(newFileName.begin(), newFileName.end(), '\\', '/');

        return newFileName;
    }
#else /* ? OS */
    inline string_t const& normalise_fileName(string_t const& fileName)
    {
        return fileName;
    }
#endif /* OS */

    struct xCover_LineAndCounter_t
    {
    public: /// Member Variables
        int     line;
        int     counter;

    public: /// Construction
        xCover_LineAndCounter_t(int line, int counter)
            : line(line)
            , counter(counter)
        {}
    };

    // A line is represented by line number and count
    struct xCover_Mark_t
    {
    public: /// Member Variables
        int     line;
        long    count;

    public: /// Construction
        xCover_Mark_t(int line, unsigned long count = 0)
            : line(line)
            , count(count)
        {}
    };

    // A file is represented by a name and a container of lines
    struct xCover_File_t
    {
    public: /// Member Types
        typedef std::vector<xCover_Mark_t>  marks_type;

    public: /// Member Variables
        string_t                name;   // Original name of file (not \ => / normalised
        marks_type              marks;  // Stored contiguously by counter, not by line!
        xCover_LineAndCounter_t start;
        xCover_LineAndCounter_t end;

    public: /// Construction
        explicit xCover_File_t(string_t const& name)
            : name(name)
            , marks()
            , start(-1, INT_MIN)
            , end(-1, INT_MAX)
        {}

    public: /// Operations
        void markStart(int line, int counter)
        {
            start.line      =   line;
            start.counter   =   counter;
        }

        void markEnd(int line, int counter)
        {
            end.line    =   line;
            end.counter =   counter;

            if(int(marks.size()) <= counter)
            {
                xCover_Mark_t exemplar(-1, 0);

                marks.resize(1 + counter, exemplar);
            }
        }

        void markLine(int line, int counter_)
        {
            STLSOFT_ASSERT(counter_ >= 0);

            size_t counter = static_cast<size_t>(counter_);

            if(int(marks.size()) <= counter)
            {
                xCover_Mark_t exemplar(-1, 0);

                marks.resize(counter, exemplar);
                marks.push_back(xCover_Mark_t(line, 1));
            }
            else
            {
                STLSOFT_ASSERT(-1 == marks[counter].line || line == marks[counter].line);

                marks[counter].line = line;
                ++marks[counter].count;
            }
        }

        void reset()
        {
            marks.clear();
            start   =   xCover_LineAndCounter_t(-1, -1);
            end     =   xCover_LineAndCounter_t(-1, -1);
        }

        unsigned report(char const* groupName, xcover_reporter_t* reporter) const
        {
            unsigned n = 0;

            { for(size_t i = 0; i != marks.size(); ++i)
            {
                if(int(i) <= start.counter)
                {
                    continue;
                }
                if(int(i) >= end.counter)
                {
                    continue;
                }

                // For each record with 0 coverage
                if(0 == marks[i].count)
                {
                    // Find prior file location
                    int priorLine = start.line;

                    { for(size_t j = 0; j != i; ++j)
                    {
                        if(marks[j].line > priorLine)
                        {
                            priorLine = marks[j].line;
                        }
                    }}

                    // Find posterior file location
                    int posteriorLine = end.line;

                    { for(size_t j = i + 1; j < marks.size(); ++j)
                    {
                        if( marks[j].line >= 0 &&
                            (   posteriorLine < 0 ||
                                marks[j].line < posteriorLine))
                        {
                            posteriorLine = marks[j].line;
                        }
                    }}

                    xcover_coverItem_t  item;

                    item.groupName          =   groupName;
                    item.fileName           =   name.c_str();
                    item.markIndex          =   int(i);
                    item.priorMarkLine      =   priorLine;
                    item.posteriorMarkLine  =   posteriorLine;

                    reporter->onReportItem(&item);

                    ++n;
                }
            }}

            return n;
        }
    };

    // shared file pointer
    typedef stlsoft::shared_ptr<xCover_File_t>  File_ptr_t;

    // A group is a named collection of files
    struct xCover_Group_t
    {
    public: /// Member Types
        typedef std::map<string_t, File_ptr_t>  files_type;

    public: /// Member Variables
        string_t        name;
        files_type      files;

    public: /// Construction
        explicit xCover_Group_t(string_t const& name)
            : name(name)
        {}

    public: /// Operations
        void start()
        {
            { for(files_type::iterator it = files.begin(); it != files.end(); ++it)
            {
                (*it).second->reset();
            }}
        }
        void end()
        {
        }
    };

    class file_compare_t
        : public std::binary_function<string_t, string_t, bool>
    {
    public:
        bool operator()(string_t const& lhs, string_t const& rhs) const
        {
            return lhs < rhs;
        }
    };


    // Context class
    class xCover_Context_t
    {
    public:
        xCover_Context_t();
        ~xCover_Context_t() stlsoft_throw_0();

        void* operator new(size_t cb, void* );
        void operator delete(void*, void* );

    public:
        xcover_rc_t associateFileWithGroup(string_t const& fileName, int line, string_t const& groupName);

        xcover_rc_t createFileAlias(string_t const& fileName, int line, string_t const& aliasName);

        xcover_rc_t markFileStart(string_t const& fileName, int line, char const* function, int counter);
        xcover_rc_t markFileEnd(string_t const& fileName, int line, char const* function, int counter);
        xcover_rc_t markLine(string_t const& fileName, char const* function, int counter, int line);

        xcover_rc_t startGroupCoverage(string_t const& fileName, int line, string_t const& groupName);
        xcover_rc_t endGroupCoverage(string_t const& fileName, int line, string_t const& groupName);

        xcover_rc_t reportGroupCoverage(string_t const& fileName, int line, string_t const& groupName, xcover_reporter_t* reporter) const;

        xcover_rc_t reportFileCoverage(string_t const& fileName, xcover_reporter_t* reporter) const;

        xcover_rc_t reportAliasCoverage(string_t const& aliasName, xcover_reporter_t* reporter) const;

    private:
        typedef std::map<string_t, File_ptr_t, file_compare_t>  files_type_;
        typedef std::map<string_t, string_t>                    aliases_type_;
        typedef std::map<string_t, xCover_Group_t>              groups_type_;
        typedef platformstl::thread_mutex                       mutex_type_;

        mutex_type_     m_mutex;
        files_type_     m_files;
        aliases_type_   m_aliases;
        groups_type_    m_groups;
    };

    // default reporter that writes to stdout
    class xCover_FILE_reporter_t
        : public xcover_reporter_concrete_t
    {
    public: /// Construction
        void* operator new(size_t cb, void* );
        void operator delete(void*, void* );

    public: /// Overrides
        void XCOVER_CALLCONV onBeginGroupReport(char const* groupName);
        void XCOVER_CALLCONV onEndGroupReport(char const* groupName);
        void XCOVER_CALLCONV onBeginFileReport(char const* fileName, char const* aliasName);
        void XCOVER_CALLCONV onEndFileReport(char const* fileName, char const* aliasName, unsigned n);
        void XCOVER_CALLCONV onReportItem(xcover_coverItem_t const* item);
    };

    union u1_t_
    {
    private:
        long double     ld;
        stlsoft::byte_t ctxtBytes[sizeof(xCover_Context_t)];

    public:
        stlsoft::byte_t& operator [](size_t index)
        {
            STLSOFT_ASSERT(index < STLSOFT_NUM_ELEMENTS(ctxtBytes));

            return ctxtBytes[index];
        }
    }                       s_ctxtBytes;
    union u2_t_
    {
    private:
        long double     ld;
        stlsoft::byte_t fileReporterBytes[sizeof(xCover_FILE_reporter_t)];

    public:
        stlsoft::byte_t& operator [](size_t index)
        {
            STLSOFT_ASSERT(index < STLSOFT_NUM_ELEMENTS(fileReporterBytes));

            return fileReporterBytes[index];
        }
    }                       s_fileReporterBytes;

    xCover_Context_t*       s_ctxt;
    xCover_FILE_reporter_t* s_defaultReporter;
    stlsoft::ss_sint_t      s_mx;
    int                     s_apiInit;

    xcover_rc_t xcover_init_onetime()
    {
        STLSOFT_ASSERT(NULL == s_ctxt);

        try
        {
            s_ctxt              =   new(&s_ctxtBytes[0]) xCover_Context_t();
            s_defaultReporter   =   new(&s_fileReporterBytes[0]) xCover_FILE_reporter_t();

            return XCOVER_RC_SUCCESS;
        }
        catch(std::bad_alloc&)
        {
            return XCOVER_RC_OUT_OF_MEMORY;
        }
        catch(std::exception&)
        {
            return XCOVER_RC_EXCEPTION;
        }
        catch(...)
        {
            return XCOVER_RC_UNEXPECTED;
        }
    }

    void xcover_uninit_onetime()
    {
        STLSOFT_ASSERT(NULL != s_ctxt);
        STLSOFT_ASSERT(NULL != s_defaultReporter);

        s_defaultReporter->~xCover_FILE_reporter_t();
        s_defaultReporter = NULL;

        s_ctxt->~xCover_Context_t();
        s_ctxt = NULL;
    }

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * API
 */

XCOVER_CALL(xcover_rc_t) xcover_init(void)
{
    platformstl::spin_mutex                         mx(&s_mx);
    stlsoft::lock_scope<platformstl::spin_mutex>    lock(mx);

    if(1 == ++s_apiInit)
    {
        return xcover_init_onetime();
    }

    return XCOVER_RC_SUCCESS;
}

XCOVER_CALL(void) xcover_uninit(void)
{
    STLSOFT_ASSERT(NULL != s_ctxt);

    platformstl::spin_mutex                         mx(&s_mx);
    stlsoft::lock_scope<platformstl::spin_mutex>    lock(mx);

    if(0 == --s_apiInit)
    {
        xcover_uninit_onetime();
    }
}

XCOVER_CALL(char const*) xcover_getApiCodeString(xcover_rc_t code)
{
    switch(code)
    {
        case    XCOVER_RC_SUCCESS:              return "the operation completed successfully";
        case    XCOVER_RC_EXCEPTION:            return "an exception occurred";
        case    XCOVER_RC_OUT_OF_MEMORY:        return "out of memory";
        case    XCOVER_RC_UNEXPECTED:           return "an unexpected error occurred";
        case    XCOVER_RC_GROUP_NOT_FOUND:      return "the specified group does not exist";
        case    XCOVER_RC_FILE_NOT_FOUND:       return "the specified file does not exist";
        case    XCOVER_RC_ALIAS_NOT_FOUND:      return "the specified alias does not exist";
        case    XCOVER_RC_ALIAS_ALREADY_USED:   return "the specified alias is already used";
    }

    return "<<unknown init code>>";
}

XCOVER_CALL(size_t) xcover_getApiCodeStringLength(xcover_rc_t code)
{
    return ::strlen(xcover_getApiCodeString(code));
}

XCOVER_CALL(xcover_rc_t) xcover_associateFileWithGroup(char const* fileName, int line, char const* groupName)
{
    STLSOFT_ASSERT(NULL != s_ctxt);

    try
    {
        return s_ctxt->associateFileWithGroup(fileName, line, groupName);
    }
    catch(std::bad_alloc&)
    {
        return XCOVER_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        return XCOVER_RC_EXCEPTION;
    }
    catch(...)
    {
        return XCOVER_RC_UNEXPECTED;
    }
}

XCOVER_CALL(xcover_rc_t) xcover_createFileAlias(char const* fileName, int line, char const* aliasName)
{
    STLSOFT_ASSERT(NULL != s_ctxt);

    try
    {
        return s_ctxt->createFileAlias(fileName, line, aliasName);
    }
    catch(std::bad_alloc&)
    {
        return XCOVER_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        return XCOVER_RC_EXCEPTION;
    }
    catch(...)
    {
        return XCOVER_RC_UNEXPECTED;
    }
}

XCOVER_CALL(xcover_rc_t) xcover_markFileStart(char const* fileName, int line, char const* function, int counter)
{
    STLSOFT_ASSERT(NULL != s_ctxt);

    try
    {
        return s_ctxt->markFileStart(fileName, line, function, counter);
    }
    catch(std::bad_alloc&)
    {
        return XCOVER_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        return XCOVER_RC_EXCEPTION;
    }
    catch(...)
    {
        return XCOVER_RC_UNEXPECTED;
    }
}

XCOVER_CALL(xcover_rc_t) xcover_markFileEnd(char const* fileName, int line, char const* function, int counter)
{
    STLSOFT_ASSERT(NULL != s_ctxt);

    try
    {
        return s_ctxt->markFileEnd(fileName, line, function, counter);
    }
    catch(std::bad_alloc&)
    {
        return XCOVER_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        return XCOVER_RC_EXCEPTION;
    }
    catch(...)
    {
        return XCOVER_RC_UNEXPECTED;
    }
}

XCOVER_CALL(xcover_rc_t) xcover_markLine(char const* fileName, int line, char const* function, int counter)
{
    STLSOFT_ASSERT(NULL != s_ctxt);

    try
    {
        return s_ctxt->markLine(fileName, function, counter, line);
    }
    catch(std::bad_alloc&)
    {
        return XCOVER_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        return XCOVER_RC_EXCEPTION;
    }
    catch(...)
    {
        return XCOVER_RC_UNEXPECTED;
    }
}

XCOVER_CALL(xcover_rc_t) xcover_startGroupCoverage(char const* fileName, int line, char const* groupName)
{
    STLSOFT_ASSERT(NULL != s_ctxt);

    try
    {
        return s_ctxt->startGroupCoverage(fileName, line, groupName);
    }
    catch(std::bad_alloc&)
    {
        return XCOVER_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        return XCOVER_RC_EXCEPTION;
    }
    catch(...)
    {
        return XCOVER_RC_UNEXPECTED;
    }
}

XCOVER_CALL(xcover_rc_t) xcover_endGroupCoverage(char const* fileName, int line, char const* groupName)
{
    STLSOFT_ASSERT(NULL != s_ctxt);

    try
    {
        return s_ctxt->endGroupCoverage(fileName, line, groupName);
    }
    catch(std::bad_alloc&)
    {
        return XCOVER_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        return XCOVER_RC_EXCEPTION;
    }
    catch(...)
    {
        return XCOVER_RC_UNEXPECTED;
    }
}

XCOVER_CALL(xcover_rc_t) xcover_reportGroupCoverage(char const* fileName, int line, char const* groupName, xcover_reporter_t* reporter)
{
    STLSOFT_ASSERT(NULL != s_ctxt);

    try
    {
        return s_ctxt->reportGroupCoverage(fileName, line, groupName, reporter);
    }
    catch(std::bad_alloc&)
    {
        return XCOVER_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        return XCOVER_RC_EXCEPTION;
    }
    catch(...)
    {
        return XCOVER_RC_UNEXPECTED;
    }
}

XCOVER_CALL(xcover_rc_t) xcover_reportFileCoverage(char const* fileName, xcover_reporter_t* reporter)
{
    STLSOFT_ASSERT(NULL != s_ctxt);

    try
    {
        return s_ctxt->reportFileCoverage(fileName, reporter);
    }
    catch(std::bad_alloc&)
    {
        return XCOVER_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        return XCOVER_RC_EXCEPTION;
    }
    catch(...)
    {
        return XCOVER_RC_UNEXPECTED;
    }
}

XCOVER_CALL(xcover_rc_t) xcover_reportAliasCoverage(char const* aliasName, xcover_reporter_t* reporter)
{
    STLSOFT_ASSERT(NULL != s_ctxt);

    try
    {
        return s_ctxt->reportAliasCoverage(aliasName, reporter);
    }
    catch(std::bad_alloc&)
    {
        return XCOVER_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        return XCOVER_RC_EXCEPTION;
    }
    catch(...)
    {
        return XCOVER_RC_UNEXPECTED;
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * xCover_Context_t
 */

namespace
{
    xCover_Context_t::xCover_Context_t()
        : m_mutex()
        , m_files()
        , m_aliases()
        , m_groups()
    {}

    xCover_Context_t::~xCover_Context_t() stlsoft_throw_0()
    {}

    void* xCover_Context_t::operator new(size_t /* cb */, void* pv)
    {
        return pv;
    }
    void xCover_Context_t::operator delete(void*, void* )
    {}

    xcover_rc_t xCover_Context_t::associateFileWithGroup(string_t const& fileName, int line, string_t const& groupName)
    {
        // Normalise file name
        if(~0 != fileName.find('\\'))
        {
            return associateFileWithGroup(normalise_fileName(fileName), line, groupName);
        }

        stlsoft::lock_scope<mutex_type_>    lock(m_mutex);

        // If no such file exists, then we add it in

        files_type_::iterator it_File = m_files.find(fileName);

        if(it_File == m_files.end())
        {
            it_File = m_files.insert(std::make_pair(normalise_fileName(fileName), File_ptr_t(new xCover_File_t(fileName)))).first;
        }

        // If no such group exists, then we add it in

        groups_type_::iterator it_Group = m_groups.find(groupName);

        if(it_Group == m_groups.end())
        {
            it_Group = m_groups.insert(std::make_pair(groupName, xCover_Group_t(groupName))).first;
        }

        // Now we have a file and a group, so we simply associate them (and ignore any
        // previous association
        (*it_Group).second.files.insert(std::make_pair(fileName, (*it_File).second));

        return XCOVER_RC_SUCCESS;
    }

    xcover_rc_t xCover_Context_t::createFileAlias(string_t const& fileName, int line, string_t const& aliasName)
    {
        // Normalise file name
        if(~0 != fileName.find('\\'))
        {
            return createFileAlias(normalise_fileName(fileName), line, aliasName);
        }

        stlsoft::lock_scope<mutex_type_>    lock(m_mutex);

        // If no such file exists, then we add it in

        files_type_::iterator it_File = m_files.find(fileName);

        if(it_File == m_files.end())
        {
            it_File = m_files.insert(std::make_pair(normalise_fileName(fileName), File_ptr_t(new xCover_File_t(fileName)))).first;
        }

        // If the alias exists, then we fail

        aliases_type_::iterator it_Alias = m_aliases.find(aliasName);

        if(it_Alias != m_aliases.end())
        {
            return XCOVER_RC_ALIAS_ALREADY_USED;
        }
        else
        {
            m_aliases.insert(std::make_pair(aliasName, fileName));

            return XCOVER_RC_SUCCESS;
        }
    }

    xcover_rc_t xCover_Context_t::markFileStart(string_t const& fileName, int line, char const* function, int counter)
    {
        // Normalise file name
        if(~0 != fileName.find('\\'))
        {
            return markFileStart(normalise_fileName(fileName), line, function, counter);
        }

        stlsoft::lock_scope<mutex_type_>    lock(m_mutex);

        // If no such file exists, then we add it in

        files_type_::iterator it_File = m_files.find(fileName);

        if(it_File == m_files.end())
        {
            it_File = m_files.insert(std::make_pair(normalise_fileName(fileName), File_ptr_t(new xCover_File_t(fileName)))).first;
        }

        // Now we mark the file's start
        xCover_File_t& file = *(*it_File).second;

        file.markStart(line, counter);

        return XCOVER_RC_SUCCESS;
    }

    xcover_rc_t xCover_Context_t::markFileEnd(string_t const& fileName, int line, char const* function, int counter)
    {
        // Normalise file name
        if(~0 != fileName.find('\\'))
        {
            return markFileEnd(normalise_fileName(fileName), line, function, counter);
        }

        stlsoft::lock_scope<mutex_type_>    lock(m_mutex);

        // If no such file exists, then we add it in

        files_type_::iterator it_File = m_files.find(fileName);

        if(it_File == m_files.end())
        {
            it_File = m_files.insert(std::make_pair(normalise_fileName(fileName), File_ptr_t(new xCover_File_t(fileName)))).first;
        }

        // Now we mark the file's end
        xCover_File_t& file = *(*it_File).second;

        file.markEnd(line, counter);

        return XCOVER_RC_SUCCESS;
    }

    xcover_rc_t xCover_Context_t::markLine(string_t const& fileName, char const* function, int counter, int line)
    {
        // Normalise file name
        if(~0 != fileName.find('\\'))
        {
            return markLine(normalise_fileName(fileName), function, counter, line);
        }

        stlsoft::lock_scope<mutex_type_>    lock(m_mutex);

        // If no such file exists, then we add it in

        files_type_::iterator it_File = m_files.find(fileName);

        if(it_File == m_files.end())
        {
            it_File = m_files.insert(std::make_pair(normalise_fileName(fileName), File_ptr_t(new xCover_File_t(fileName)))).first;

            /// ... and mark this as the start
            (*it_File).second->markStart(line, counter);
        }

        (*it_File).second->markLine(line, counter);

        return XCOVER_RC_SUCCESS;
    }

    xcover_rc_t xCover_Context_t::startGroupCoverage(string_t const& /* fileName */, int /* line */, string_t const& groupName)
    {
        stlsoft::lock_scope<mutex_type_>    lock(m_mutex);

        // If no such group exists, then we add it in

        groups_type_::iterator it_Group = m_groups.find(groupName);

        if(it_Group == m_groups.end())
        {
            it_Group = m_groups.insert(std::make_pair(groupName, xCover_Group_t(groupName))).first;
        }

        // Now we enumerate all files within the group, and reset all their counts
        (*it_Group).second.start();

        return XCOVER_RC_SUCCESS;
    }

    xcover_rc_t xCover_Context_t::endGroupCoverage(string_t const& /* fileName */, int /* line */, string_t const& groupName)
    {
        stlsoft::lock_scope<mutex_type_>    lock(m_mutex);

        // If no such group exists, then we add it in

        groups_type_::iterator it_Group = m_groups.find(groupName);

        if(it_Group == m_groups.end())
        {
            it_Group = m_groups.insert(std::make_pair(groupName, xCover_Group_t(groupName))).first;
        }

        // Now we enumerate all files within the group, and reset all their counts
        (*it_Group).second.end();

        return XCOVER_RC_SUCCESS;
    }

    xcover_rc_t xCover_Context_t::reportGroupCoverage(string_t const& /* fileName */, int /* line */, string_t const& groupName, xcover_reporter_t* reporter) const
    {
        stlsoft::lock_scope<mutex_type_>    lock(const_cast<mutex_type_&>(m_mutex));

        // Check the reporter
        if(NULL == reporter)
        {
            reporter = s_defaultReporter;
        }

        groups_type_::const_iterator it_Group = m_groups.find(groupName);

        if(it_Group == m_groups.end())
        {
            return XCOVER_RC_GROUP_NOT_FOUND;
        }
        else
        {
            reporter->onBeginGroupReport(groupName.c_str());

            xCover_Group_t const& group = (*it_Group).second;

            { for(xCover_Group_t::files_type::const_iterator it_File = group.files.begin(); it_File != group.files.end(); ++it_File)
            {
                (*it_File).second->report(groupName.c_str(), reporter);
            }}

            reporter->onEndGroupReport(groupName.c_str());

            return XCOVER_RC_SUCCESS;
        }
    }

    xcover_rc_t xCover_Context_t::reportFileCoverage(string_t const& fileName, xcover_reporter_t* reporter) const
    {
        // Normalise file name
        if(~0 != fileName.find('\\'))
        {
            return reportFileCoverage(normalise_fileName(fileName), reporter);
        }

        stlsoft::lock_scope<mutex_type_>    lock(const_cast<mutex_type_&>(m_mutex));

        // Check the reporter
        if(NULL == reporter)
        {
            reporter = s_defaultReporter;
        }

        // Search order:
        //
        // 1. Exact: search for exact match
        // 2. Name+Ext: if fileName has no path separators but has an extension, match on file name/ext
        // 3. Name Only: if fileName has no path separators or extension, match on file name
        // 4. shwild: if fileName has any wildcards / ranges, use shwild to match

        std::vector<files_type_::const_iterator>  iterators;

        files_type_::const_iterator it_File = m_files.end();

        if(m_files.end() == it_File)
        {
            // 1. Exact
            it_File = m_files.find(fileName);
        }

        if(m_files.end() == it_File)
        {
            // 2. Name+Ext:
            // 3. Name Only:
            if(~0u == fileName.find('/'))
            {
                const bool hasExtension = (~0u != fileName.find('.'));

                { for(files_type_::const_iterator it = m_files.begin(); it != m_files.end(); ++it)
                {
                    string_t    item    =   (*it).first;
                    size_t      pos;

                    // Trim off any dir info
                    pos = item.find_last_of('/');
                    if(pos < item.size())
                    {
                        item.erase(0u, pos + 1);
                    }

                    // Trim off extension, if required
                    if(!hasExtension)
                    {
                        pos = item.find_last_of('.');
                        if(pos < item.size())
                        {
                            item.erase(pos);
                        }
                    }

# if defined(PLATFORMSTL_OS_IS_UNIX)
                    if(0 == filesystem_traits_t::str_compare(fileName.c_str(), item.c_str()))
# elif defined(PLATFORMSTL_OS_IS_WINDOWS)
                    if(0 == filesystem_traits_t::str_compare_no_case(fileName.c_str(), item.c_str()))
# else /* ? OS */
# endif /* OS */
                    {
                        it_File = it;
                        break;
                    }
                }}
            }
        }

        if(it_File == m_files.end())
        {
#ifdef XCOVER_USE_SHWILD
            // 4. shwild: if fileName has any wildcards / ranges, use shwild to match

            shwild::Pattern pattern(fileName.c_str());

            { for(files_type_::const_iterator it = m_files.begin(); it != m_files.end(); ++it)
            {
                if(pattern.match((*it).first.c_str()))
                {
                    iterators.push_back(it);
                }
            }}

#else /* ? XCOVER_USE_SHWILD */
            { for(files_type_::const_iterator it = m_files.begin(); it != m_files.end(); ++it)
            {
# if defined(XCOVER_USE_FNMATCH_)
                if(0 == ::fnmatch(fileName.c_str(), (*it).first.c_str(), FNM_PATHNAME))
# elif defined(XCOVER_USE_PATHMATCH_)
                if(::PathMatchSpec((*it).first.c_str(), fileName.c_str()))
# else /* ? OS */
#  error Platform not discriminated
# endif /* OS */
                {
                    iterators.push_back(it);
                }
            }}
#endif /* XCOVER_USE_SHWILD */
        }
        else
        {
            iterators.push_back(it_File);
        }

        if(iterators.empty())
        {
            return XCOVER_RC_FILE_NOT_FOUND;
        }
        else
        {
            { for(size_t i = 0; i != iterators.size(); ++i)
            {
                string_t const& filePath = (*iterators[i]).second->name;

                reporter->onBeginFileReport(filePath.c_str(), NULL);

                unsigned n = (*iterators[i]).second->report(filePath.c_str(), reporter);

                reporter->onEndFileReport(filePath.c_str(), NULL, n);
            }}

            return XCOVER_RC_SUCCESS;
        }
    }

    xcover_rc_t xCover_Context_t::reportAliasCoverage(string_t const& aliasName, xcover_reporter_t* reporter) const
    {
        stlsoft::lock_scope<mutex_type_>    lock(const_cast<mutex_type_&>(m_mutex));

        // Check the reporter
        if(NULL == reporter)
        {
            reporter = s_defaultReporter;
        }

        aliases_type_::const_iterator it_Alias = m_aliases.find(aliasName);

        if(it_Alias == m_aliases.end())
        {
            return XCOVER_RC_ALIAS_NOT_FOUND;
        }
        else
        {
            string_t const& fileName = (*it_Alias).second;

            files_type_::const_iterator it_File = m_files.find(fileName);

            if(it_File == m_files.end())
            {
                return XCOVER_RC_FILE_NOT_FOUND;
            }
            else
            {
                string_t const& filePath = (*it_File).second->name;

                reporter->onBeginFileReport(filePath.c_str(), aliasName.c_str());

                unsigned n = (*it_File).second->report(filePath.c_str(), reporter);

                reporter->onEndFileReport(filePath.c_str(), aliasName.c_str(), n);

                return XCOVER_RC_SUCCESS;
            }
        }
    }


    void* xCover_FILE_reporter_t::operator new(size_t /* cb */, void* pv)
    {
        return pv;
    }
    void xCover_FILE_reporter_t::operator delete(void*, void* )
    {}

    void XCOVER_CALLCONV xCover_FILE_reporter_t::onBeginGroupReport(char const* groupName)
    {
        fprintf(stdout, "[Start of group %s]:\n", groupName);
    }

    void XCOVER_CALLCONV xCover_FILE_reporter_t::onEndGroupReport(char const* groupName)
    {
        fprintf(stdout, "[End of group %s]:\n", groupName);
    }

    void XCOVER_CALLCONV xCover_FILE_reporter_t::onBeginFileReport(char const* fileName, char const* aliasName)
    {
        fprintf(stdout, (NULL == aliasName) ? "[Start of file %s]:\n" : "[Start of file %s; alias %s]:\n", fileName, aliasName);
    }

    void XCOVER_CALLCONV xCover_FILE_reporter_t::onEndFileReport(char const* fileName, char const* aliasName, unsigned n)
    {
        if(NULL == aliasName)
        {
            fprintf(stdout, "[End of file %s]: %u uncovered block(s)\n", fileName, n);
        }
        else
        {
            fprintf(stdout, "[End of file %s; alias %s]: %u uncovered block(s)\n", fileName, aliasName, n);
        }
    }

    void XCOVER_CALLCONV xCover_FILE_reporter_t::onReportItem(xcover_coverItem_t const* item)
    {
        if(-1 == item->priorMarkLine)
        {
            if(-1 == item->posteriorMarkLine)
            {
                fprintf(stderr, "Uncovered code at index %d in file %s\n", item->markIndex, item->fileName);
            }
            else
            {
                fprintf(stderr, "Uncovered code at index %d in file %s, between the start of the file and line %d\n", item->markIndex, item->fileName, item->posteriorMarkLine);
            }
        }
        else
        {
            if(-1 == item->posteriorMarkLine)
            {
                fprintf(stderr, "Uncovered code at index %d in file %s, between line %d and the end of file\n", item->markIndex, item->fileName, item->priorMarkLine);
            }
            else
            {
                fprintf(stderr, "Uncovered code at index %d in file %s, between lines %d and %d\n", item->markIndex, item->fileName, item->priorMarkLine, item->posteriorMarkLine);
            }
        }
    }

} // anonymous namespace

/* ////////////////////////////////////////////////////////////////////// */

#ifndef XCOVER_NO_NAMESPACE
} /* namespace xcover */
#endif /* !XCOVER_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
