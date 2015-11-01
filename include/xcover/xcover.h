/* /////////////////////////////////////////////////////////////////////////
 * File:        xcover/xcover.h
 *
 * Purpose:     Main header file for xCover, a C/C++ code coverage library.
 *
 * Created:     1st March 2008
 * Updated:     1st November 2015
 *
 * Home:        http://xcover.org/
 *
 * Copyright (c) 2008-2015, Matthew Wilson and Synesis Software
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


/** \file xcover/xcover.h
 *
 * [C, C++] A C/C++ code coverage library.
 */

#ifndef XCOVER_INCL_XCOVER_H_XCOVER
#define XCOVER_INCL_XCOVER_H_XCOVER

#ifndef XCOVER_DOCUMENTATION_SKIP_SECTION
# define XCOVER_VER_XCOVER_H_XCOVER_MAJOR       1
# define XCOVER_VER_XCOVER_H_XCOVER_MINOR       6
# define XCOVER_VER_XCOVER_H_XCOVER_REVISION    1
# define XCOVER_VER_XCOVER_H_XCOVER_EDIT        24
#endif /* !XCOVER_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

/**
 * \def XCOVER_VER_MAJOR
 * The Major version number of the xCover library
 *
 * \def XCOVER_VER_MINOR
 * Minor version number of the xCover library
 *
 * \def XCOVER_VER_REVISION
 * The revision number of the xCover library
 *
 * \def XCOVER_VER
 * The composite version of the xCover library
 */

#define XCOVER_VER_MAJOR        0
#define XCOVER_VER_MINOR        3
#define XCOVER_VER_REVISION     4

#define XCOVER_VER              0x000304ff

/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if defined(STLSOFT_VER) && \
    STLSOFT_VER >= 0x010c0000
# define XTESTS_STLSOFT_1_12_OR_LATER
#elif _STLSOFT_VER < 0x01097aff
# error xCover requires version 1.9.122 (or later) of STLSoft; download from www.stlsoft.org
#endif /* _STLSOFT_VER */

#if defined(STLSOFT_CF_FUNCTION_SYMBOL_SUPPORT)
#elif \
    defined(STLSOFT_COMPILER_IS_CLANG)
 /* Clang supports __COUNTER__ */
#elif \
    defined(STLSOFT_COMPILER_IS_GCC) && \
    (   __GNUC__ > 4 || \
        (   __GNUC__ == 4 && \
            __GNUC_MINOR__ >= 3))
 /* GCC Supports __COUNTER__ from 4.3 onwards */
#elif \
    defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
 /* VC++ supports __COUNTER__ from 7.1 onwards */
#elif \
    defined(__COUNTER__) && \
    defined(STLSOFT_FUNCTION_SYMBOL)
 /* Arbitrary compiler that defines the symbols. Note: some do not define __func__ / __FUNCTION__ unless inside a function, hence the explicit tests above */
#else
# error xCover can only be used with compilers that support the (non-standard) predefined preprocessor symbol __COUNTER__ and either the (standard) predefined preprocessor symbol __func__ or the (non-standard) preprocessor symbol __FUNCTION__
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * includes - 2
 */

#ifdef __cplusplus
# include <stdexcept>
#endif /* __cplusplus */

#include <stdio.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if defined(_STLSOFT_NO_NAMESPACE)
# define XCOVER_NO_NAMESPACE
#endif /* _STLSOFT_NO_NAMESPACE */

#ifndef XCOVER_NO_NAMESPACE
namespace xcover
{
#endif /* !XCOVER_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * features
 */

#ifndef XCOVER_DOCUMENTATION_SKIP_SECTION

# ifndef XCOVER_NO_NAMESPACE
#  define XCOVER_NS_QUAL(ns, sym)           ns::sym
# else /* ? XCOVER_NO_NAMESPACE */
#  define XCOVER_NS_QUAL(ns, sym)           sym
# endif /* XCOVER_NO_NAMESPACE */

# if !defined(XCOVER_CALLCONV)
#  define XCOVER_CALLCONV
# endif /* !XCOVER_CALLCONV */

# ifndef XCOVER_CALL
#  ifdef __cplusplus
#   define XCOVER_CALL(x)                   extern "C" x
#  else /* ? __cplusplus */
#   define XCOVER_CALL(x)                   extern x
#  endif /* __cplusplus */
# endif /* !XCOVER_CALL */

#endif /* !XCOVER_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * constants & definitions
 */

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

/** \def XCOVER_MARK_FILE_START()
 *
 * Used to define the start of a file.
 *
 * Any line marks before this point will not be reported
 *
 * \note This line must be executed at least once for the start of the file
 *   to be marked
 */
#define XCOVER_MARK_FILE_START()                            XCOVER_NS_QUAL(::xcover, xcover_markFileStart)(__FILE__, __LINE__, __FUNCTION__, __COUNTER__, 0)

/** \def XCOVER_MARK_FILE_END()
 *
 * Used to define the end of a file.
 *
 * Any line marks after this point will not be reported
 *
 * \note This line must be executed at least once for the end of the file
 *   to be marked
 */
#define XCOVER_MARK_FILE_END()                              XCOVER_NS_QUAL(::xcover, xcover_markFileEnd)(__FILE__, __LINE__, __FUNCTION__, __COUNTER__, 0)

/** \def XCOVER_MARK_LINE()
 *
 * Used to mark a line.
 */
#define XCOVER_MARK_LINE()                                  XCOVER_NS_QUAL(::xcover, xcover_markLine)(__FILE__, __LINE__, __FUNCTION__, __COUNTER__)

/** \def XCOVER_CREATE_FILE_ALIAS(aliasName)
 *
 * Creates a well-known alias for the file
 *
 * \param aliasName The name for the alias
 *
 * \note This line must be executed at least once for alias to be created
 */
#define XCOVER_CREATE_FILE_ALIAS(aliasName)                 XCOVER_NS_QUAL(::xcover, xcover_createFileAlias)(__FILE__, __LINE__, aliasName)

/** \def XCOVER_ASSOCIATE_FILE_WITH_GROUP(groupName)
 *
 * Associates a file with a group
 *
 * \param groupName The name of the group to which the file will be associated
 *
 * \note This line must be executed at least once for file to be associated
 *   with the given group
 */
#define XCOVER_ASSOCIATE_FILE_WITH_GROUP(groupName)         XCOVER_NS_QUAL(::xcover, xcover_associateFileWithGroup)(__FILE__, __LINE__, groupName)

/** \def XCOVER_START_GROUP_COVERAGE(groupName)
 *
 * Used to define the start of a group.
 *
 * Any line marks before this point will not be reported
 *
 * \note This line must be executed at least once for the start of the group
 *   to be marked
 */
#define XCOVER_START_GROUP_COVERAGE(groupName)              XCOVER_NS_QUAL(::xcover, xcover_startGroupCoverage)(__FILE__, __LINE__, groupName)

/** \def XCOVER_END_GROUP_COVERAGE(groupName)
 *
 * Used to define the end of a group.
 *
 * Any line marks after this point will not be reported
 *
 * \note This line must be executed at least once for the end of the group
 *   to be marked
 */
#define XCOVER_END_GROUP_COVERAGE(groupName)                XCOVER_NS_QUAL(::xcover, xcover_endGroupCoverage)(__FILE__, __LINE__, groupName)

/** \def XCOVER_REPORT_GROUP_COVERAGE(aliasName, reporter)
 *
 * Reports coverage for a group
 *
 * \param groupName The name of the group
 * \param reporter A pointer to a \link xcover_reporter_t reporter\endlink instance. May be NULL
 */
#define XCOVER_REPORT_GROUP_COVERAGE(groupName, reporter)   XCOVER_NS_QUAL(::xcover, xcover_reportGroupCoverage)(__FILE__, __LINE__, groupName, reporter)

/** \def XCOVER_REPORT_FILE_COVERAGE(fileName, reporter)
 *
 * Reports coverage of a file
 *
 * \param fileName The name of the file, or a name that can match the file
 * \param reporter A pointer to a \link xcover_reporter_t reporter\endlink instance. May be NULL
 */
#define XCOVER_REPORT_FILE_COVERAGE(fileName, reporter)     XCOVER_NS_QUAL(::xcover, xcover_reportFileCoverage)(fileName, reporter)

/** \def XCOVER_REPORT_THIS_FILE_COVERAGE(reporter)
 *
 * Reports coverage of the current file
 *
 * \param reporter A pointer to a \link xcover_reporter_t reporter\endlink instance. May be NULL
 */
#define XCOVER_REPORT_THIS_FILE_COVERAGE(reporter)          XCOVER_NS_QUAL(::xcover, xcover_reportFileCoverage)(__FILE__, reporter)

/** \def XCOVER_REPORT_ALIAS_COVERAGE(aliasName, reporter)
 *
 * Reports coverage for an alias
 *
 * \param aliasName The name of the alias
 * \param reporter A pointer to a \link xcover_reporter_t reporter\endlink instance. May be NULL
 */
#define XCOVER_REPORT_ALIAS_COVERAGE(aliasName, reporter)   XCOVER_NS_QUAL(::xcover, xcover_reportAliasCoverage)(aliasName, reporter)

/* /////////////////////////////////////////////////////////////////////////
 * status codes
 */

/** API function status code */
enum xcover_rc_t
{
    /*!< The operation completed successfully */
    XCOVER_RC_SUCCESS                   =   0,

    /*!< An exception occurred */
    XCOVER_RC_EXCEPTION                 =   -1001,

    /*!< Out of memory */
    XCOVER_RC_OUT_OF_MEMORY,

    /*!< An unexpected error occurred */
    XCOVER_RC_UNEXPECTED,

    /*!< The specified group does not exist */
    XCOVER_RC_GROUP_NOT_FOUND,

    /*!< The specified file does not exist */
    XCOVER_RC_FILE_NOT_FOUND,

    /*!< The specified alias does not exist */
    XCOVER_RC_ALIAS_NOT_FOUND,

    /*!< The specified alias is already used */
    XCOVER_RC_ALIAS_ALREADY_USED,

#ifndef XCOVER_DOCUMENTATION_SKIP_SECTION
    XCOVER_RC_last_
#endif /* !XCOVER_DOCUMENTATION_SKIP_SECTION */
};

#ifndef XCOVER_NO_NAMESPACE
typedef xcover_rc_t             rc_t;
#endif /* !XCOVER_NO_NAMESPACE */
#ifndef __cplusplus
typedef enum xcover_rc_t        xcover_rc_t;
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

/** Structure used by reporters to indicate an uncovered mark
 */
struct xcover_coverItem_t
{
    char const* groupName;          /*!< The name of the group. */
    char const* fileName;           /*!< The name of the file. */
    int         markIndex;          /*!< The index of the mark. */
    int         priorMarkLine;      /*!< The previous marked line. */
    int         posteriorMarkLine;  /*!< The next marked line. */
};
#ifndef XCOVER_NO_NAMESPACE
typedef xcover_coverItem_t          coverItem_t;
#endif /* !XCOVER_NO_NAMESPACE */
#ifndef __cplusplus
typedef struct xcover_coverItem_t   xcover_coverItem_t;
#endif /* !__cplusplus */

struct xcover_reporter_t;
#ifndef XCOVER_NO_NAMESPACE
typedef xcover_reporter_t           reporter_t;
#endif /* !XCOVER_NO_NAMESPACE */
#ifndef __cplusplus
typedef struct xcover_reporter_t    xcover_reporter_t;
#endif /* __cplusplus */

#include <xcover/internal/reporter.h>

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Initialises the xCover API
 */
XCOVER_CALL(xcover_rc_t)
xcover_init(void);

/** Uninitialises the xCover API
 */
XCOVER_CALL(void)
xcover_uninit(void);

#ifndef XCOVER_DOCUMENTATION_SKIP_SECTION
XCOVER_CALL(char const*)
xcover_getApiCodeString(
    xcover_rc_t code
);
XCOVER_CALL(size_t)
xcover_getApiCodeStringLength(
    xcover_rc_t code
);
#endif /* !XCOVER_DOCUMENTATION_SKIP_SECTION */

/** Create file alias
 *
 * \param fileName The file name
 * \param line The line number
 * \param aliasName The alias name
 */
XCOVER_CALL(xcover_rc_t)
xcover_createFileAlias(
    char const* fileName
,   int         line
,   char const* aliasName
);

/** Associates the file with a group
 *
 * \param fileName The file name
 * \param line The line number
 * \param groupName The group name
 */
XCOVER_CALL(xcover_rc_t)
xcover_associateFileWithGroup(
    char const* fileName
,   int         line
,   char const* groupName
);

/** Marks the start of a file
 *
 * \param fileName The file name
 * \param line The line number
 * \param function The function name
 * \param counter The counter
 * \param countForward The number of marks to count forward. (Used in macros that themselves use <code>__COUNTER__</code>)
 *
 * \note any prior markings, via xcover_markLine() (XCOVER_MARK_LINE()) will be discarded
 */
XCOVER_CALL(xcover_rc_t)
xcover_markFileStart(
    char const* fileName
,   int         line
,   char const* function
,   int         counter
,   int         countForward
);

/** Marks the end of a file
 *
 * \param fileName The file name
 * \param line The line number
 * \param function The function name
 * \param counter The counter
 * \param countBackward The number of marks to count forward. (Used in macros that themselves use <code>__COUNTER__</code>)
 *
 * \note any posterior markings, via xcover_markLine() (XCOVER_MARK_LINE()) will be discarded
 */
XCOVER_CALL(xcover_rc_t)
xcover_markFileEnd(
    char const* fileName
,   int         line
,   char const* function
,   int         counter
,   int         countBackward
);

/** Marks a line for coverage
 *
 * \param fileName The file name
 * \param line The line number
 * \param function The function name
 * \param counter The counter
 */
XCOVER_CALL(xcover_rc_t)
xcover_markLine(
    char const* fileName
,   int         line
,   char const* function
,   int         counter
);

/** 
 *
 * \param fileName The file name
 * \param line The line number
 * \param groupName The group name
 */
XCOVER_CALL(xcover_rc_t)
xcover_startGroupCoverage(
    char const* fileName
,   int         line
,   char const* groupName
);

/** 
 *
 * \param fileName The file name
 * \param line The line number
 * \param groupName The group name
 */
XCOVER_CALL(xcover_rc_t)
xcover_endGroupCoverage(
    char const* fileName
,   int         line
,   char const* groupName
);

/** Reports coverage for all files in the group
 *
 * \param fileName The file name
 * \param line The line number
 *
 * \param groupName The name of the group. May not be NULL
 * \param reporter A pointer to a \link xcover_reporter_t reporter\endlink instance. May be NULL
 *
 * \return An error code from the \link xcover::xcover_rc_t xcover_rc_t\endlink enumeration
 */
XCOVER_CALL(xcover_rc_t)
xcover_reportGroupCoverage(
    char const*         fileName
,   int                 line
,   char const*         groupName
,   xcover_reporter_t*  reporter
);

/** Reports coverage for a files
 *
 * \param fileName The file name. May be a file name only, a file name + extension, a full path name, or a shell wild-card path
 * \param reporter A pointer to a \link xcover_reporter_t reporter\endlink instance. May be NULL
 *
 * \return An error code from the \link xcover::xcover_rc_t xcover_rc_t\endlink enumeration
 */
XCOVER_CALL(xcover_rc_t)
xcover_reportFileCoverage(
    char const*         fileName
,   xcover_reporter_t*  reporter
);

/** Reports coverage for all files matching the alias
 *
 * \param aliasName The name of the alias. May not be NULL
 * \param reporter A pointer to a \link xcover_reporter_t reporter\endlink instance. May be NULL
 *
 * \return An error code from the \link xcover::xcover_rc_t xcover_rc_t\endlink enumeration
 */
XCOVER_CALL(xcover_rc_t)
xcover_reportAliasCoverage(
    char const*         fileName
,   xcover_reporter_t*  reporter
);

/* /////////////////////////////////////////////////////////////////////////
 * C++-only functionality
 */

#if defined(__cplusplus)

# ifndef XCOVER_DOCUMENTATION_SKIP_SECTION
#  define XCOVER_YIELD_SYMBOL_(x)       x 
#  define XCOVER_PASTE__(x, y)          x ## y
#  define XCOVER_PASTE_(x, y)           XCOVER_PASTE__(x, y)
#  define XCOVER_DEFINE_FILE_STARTER()              namespace { static XCOVER_NS_QUAL(::xcover, xcover_SchwarzMarker) XCOVER_PASTE_(xcover_file_starter_, __COUNTER__)(XCOVER_NS_QUAL(::xcover, xcover_markFileStart), __FILE__, __LINE__, __COUNTER__, +1); } 
#  define XCOVER_DEFINE_FILE_ENDER()                namespace { static XCOVER_NS_QUAL(::xcover, xcover_SchwarzMarker) XCOVER_PASTE_(xcover_file_ender_, XCOVER_YIELD_SYMBOL_(__COUNTER__))(XCOVER_NS_QUAL(::xcover, xcover_markFileEnd), __FILE__, __LINE__, __COUNTER__, +1); }
#  define XCOVER_FILE_GROUP_ASSOCIATOR(groupName)   namespace { static XCOVER_NS_QUAL(::xcover, xcover_SchwarzFileGroupAssociator) XCOVER_PASTE_(xcover_file_group_associator_, XCOVER_YIELD_SYMBOL_(__COUNTER__))(__FILE__, __LINE__, groupName); }

class xcover_SchwarzFileGroupAssociator
{
public:
    xcover_SchwarzFileGroupAssociator(
        char const* fileName
    ,   int         line
    ,   char const* groupName
    )
    {
        XCOVER_NS_QUAL(::xcover, xcover_associateFileWithGroup)(fileName, line, groupName);
    }
};

class xcover_SchwarzMarker
{
public:
    xcover_SchwarzMarker(xcover_rc_t (XCOVER_CALLCONV* pfn)(char const*, int, char const*, int, int), char const* fileName, int line, int counter, int countExtra)
    {
        (*pfn)(fileName, line, __FUNCTION__, counter, countExtra);
    }
};

# endif /* !XCOVER_DOCUMENTATION_SKIP_SECTION */


# if !defined(XCOVER_NO_AUTO_INIT) || \
     defined(XCOVER_FORCE_AUTO_INIT)

/** Schwarz Counter class used to automatically initialise the library
 */
class xcover_initialiser
{
public: /* Member Types */
    typedef xcover_initialiser  class_type;

public: /* Construction */
    xcover_initialiser()
    {
        if(xcover_init() < 0)
        {
            throw std::runtime_error("could not initialise the xCover library");
        }
    }
    ~xcover_initialiser()
    {
        xcover_uninit();
    }
private:
    xcover_initialiser(class_type const&);      // proscribed
    class_type& operator =(class_type const&);  // proscribed
};

namespace
{
    static xcover_initialiser   xc_init;

} /* anonymous namespace */

#endif /* !XCOVER_NO_AUTO_INIT || XCOVER_FORCE_AUTO_INIT */
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

/* /////////////////////////////////////////////////////////////////////////
 * API functions for C++
 */

/* /////////////////////////////////////////////////////////////////////////
 * string access shims
 */

#ifndef XCOVER_DOCUMENTATION_SKIP_SECTION
STLSOFT_INLINE
char const*
c_str_data_a(
    xcover_rc_t code
)
{
    return xcover_getApiCodeString(code);
}

STLSOFT_INLINE
char const*
c_str_data(
    xcover_rc_t code
)
{
    return xcover_getApiCodeString(code);
}


STLSOFT_INLINE
size_t
c_str_len_a(
    xcover_rc_t code
)
{
    return xcover_getApiCodeStringLength(code);
}

STLSOFT_INLINE
size_t
c_str_len(
    xcover_rc_t code
)
{
    return xcover_getApiCodeStringLength(code);
}


STLSOFT_INLINE
char const*
c_str_ptr_a(
    xcover_rc_t code
)
{
    return xcover_getApiCodeString(code);
}

STLSOFT_INLINE
char const*
c_str_ptr(
    xcover_rc_t code
)
{
    return xcover_getApiCodeString(code);
}
#endif /* !XCOVER_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Core Functions
 */

#ifndef XCOVER_NO_NAMESPACE

inline
xcover_rc_t
init()
{
    return xcover_init();
}

inline
xcover_rc_t
uninit()
{
    xcover_uninit();
}

#endif /* !XCOVER_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef XCOVER_NO_NAMESPACE
} /* namespace xcover */

# ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
# endif /* !_STLSOFT_NO_NAMESPACE */

# ifndef XCOVER_DOCUMENTATION_SKIP_SECTION
    using ::xcover::c_str_data_a;
    using ::xcover::c_str_len_a;
    using ::xcover::c_str_ptr_a;

    using ::xcover::c_str_data;
    using ::xcover::c_str_len;
    using ::xcover::c_str_ptr;
# endif /* !XCOVER_DOCUMENTATION_SKIP_SECTION */

# ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
# endif /* !_STLSOFT_NO_NAMESPACE */

#else /* ? !XCOVER_NO_NAMESPACE */

# ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
# endif /* !_STLSOFT_NO_NAMESPACE */

# ifdef __cplusplus
#  ifndef XCOVER_DOCUMENTATION_SKIP_SECTION
    using ::c_str_data_a;
    using ::c_str_len_a;
    using ::c_str_ptr_a;

    using ::c_str_data;
    using ::c_str_len;
    using ::c_str_ptr;
#  endif /* !XCOVER_DOCUMENTATION_SKIP_SECTION */
# endif /* __cplusplus */

# ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
# endif /* !_STLSOFT_NO_NAMESPACE */

#endif /* !XCOVER_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !XCOVER_INCL_XCOVER_H_XCOVER */

/* ///////////////////////////// end of file //////////////////////////// */
