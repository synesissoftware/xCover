/* /////////////////////////////////////////////////////////////////////////
 * File:        xcover/internal/reporter.h
 *
 * Purpose:     Definition of the xcover_reporter_t interface.
 *
 * Created:     23rd September 2008
 * Updated:     12th August 2009
 *
 * Home:        http://xcover.org/
 *
 * Copyright (c) 2008-2009, Matthew Wilson and Synesis Software
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


/** \file xcover/internal/reporter.h
 *
 * [C, C++] Definition of the xcover_reporter_t interface.
 */

#ifndef XCOVER_INCL_XCOVER_INTERNAL_H_REPORTER
#define XCOVER_INCL_XCOVER_INTERNAL_H_REPORTER

#ifndef XCOVER_DOCUMENTATION_SKIP_SECTION
# define XCOVER_VER_XCOVER_INTERNAL_H_REPORTER_MAJOR    1
# define XCOVER_VER_XCOVER_INTERNAL_H_REPORTER_MINOR    0
# define XCOVER_VER_XCOVER_INTERNAL_H_REPORTER_REVISION 2
# define XCOVER_VER_XCOVER_INTERNAL_H_REPORTER_EDIT     3
#endif /* !XCOVER_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

struct xcover_reporter_tVTable
{
    void (XCOVER_CALLCONV* xcover_reporter_onBeginGroupReport)(xcover_reporter_t* instance, char const* groupName);
    void (XCOVER_CALLCONV* xcover_reporter_onEndGroupReport)(xcover_reporter_t* instance, char const* groupName);

    void (XCOVER_CALLCONV* xcover_reporter_onBeginFileReport)(xcover_reporter_t* instance, char const* fileName, char const* aliasName);
    void (XCOVER_CALLCONV* xcover_reporter_onEndFileReport)(xcover_reporter_t* instance, char const* fileName, char const* aliasName, unsigned n);

    void (XCOVER_CALLCONV* xcover_reporter_onReportItem)(xcover_reporter_t* reporter, xcover_coverItem_t const* item);
};

struct xcover_reporter_t
{
#ifdef __cplusplus
private:
#endif /* __cplusplus */
    struct xcover_reporter_tVTable *const   vtable;
#ifdef __cplusplus
public:
    typedef xcover_reporter_t               interface_type;
protected:
    typedef struct xcover_reporter_tVTable  vtable_t;

    vtable_t *get_vtable_()
    {
        return vtable;
    }
    vtable_t const *get_vtable_() const
    {
        return vtable;
    }

protected:
    xcover_reporter_t(struct xcover_reporter_tVTable *vt)
        : vtable(vt)
    {}
    ~xcover_reporter_t()
    {}
public:
    inline void onBeginGroupReport(char const* groupName)
    {
        STLSOFT_ASSERT(NULL != get_vtable_());
        get_vtable_()->xcover_reporter_onBeginGroupReport(this, groupName);
    }
    inline void onEndGroupReport(char const* groupName)
    {
        STLSOFT_ASSERT(NULL != get_vtable_());
        get_vtable_()->xcover_reporter_onEndGroupReport(this, groupName);
    }
    inline void onBeginFileReport(char const* fileName, char const* aliasName)
    {
        STLSOFT_ASSERT(NULL != get_vtable_());
        get_vtable_()->xcover_reporter_onBeginFileReport(this, fileName, aliasName);
    }
    inline void onEndFileReport(char const* fileName, char const* aliasName, unsigned n)
    {
        STLSOFT_ASSERT(NULL != get_vtable_());
        get_vtable_()->xcover_reporter_onEndFileReport(this, fileName, aliasName, n);
    }
    inline void onReportItem(xcover_coverItem_t const* item)
    {
        STLSOFT_ASSERT(NULL != get_vtable_());
        get_vtable_()->xcover_reporter_onReportItem(this, item);
    }
private:
    xcover_reporter_t(xcover_reporter_t const &rhs);
    xcover_reporter_t &operator =(xcover_reporter_t const &rhs);
#endif /* __cplusplus */
};

#ifdef __cplusplus
# ifdef XCOVER_INTRINSIC_VTABLES_ARE_PORTABLE
typedef xcover_reporter_t  xcover_reporter_concrete_t;
# else /* ? XCOVER_INTRINSIC_VTABLES_ARE_PORTABLE */
struct xcover_reporter_concrete_t
    : public xcover_reporter_t
{
public:
    typedef xcover_reporter_concrete_t             class_type;
private:
    typedef xcover_reporter_t::vtable_t    vtable_t;

public:
    xcover_reporter_concrete_t()
        : xcover_reporter_t(get_VTable())
    {}
    xcover_reporter_concrete_t(class_type const &/* rhs */)
        : xcover_reporter_t(get_VTable())
    {}
    xcover_reporter_concrete_t &operator =(class_type const &/* rhs */)
    {
        return *this;
    }

/* xcover_reporter_t */
public:
    virtual void    XCOVER_CALLCONV onBeginGroupReport(char const* groupName) = 0;
    virtual void    XCOVER_CALLCONV onEndGroupReport(char const* groupName) = 0;
    virtual void    XCOVER_CALLCONV onBeginFileReport(char const* fileName, char const* aliasName) = 0;
    virtual void    XCOVER_CALLCONV onEndFileReport(char const* fileName, char const* aliasName, unsigned n) = 0;
    virtual void    XCOVER_CALLCONV onReportItem(xcover_coverItem_t const* item) = 0;

private:
    static void XCOVER_CALLCONV onBeginGroupReport_(xcover_reporter_t *this_, char const* groupName)
    {
        static_cast<class_type*>(this_)->onBeginGroupReport(groupName);
    }
    static void XCOVER_CALLCONV onEndGroupReport_(xcover_reporter_t *this_, char const* groupName)
    {
        static_cast<class_type*>(this_)->onEndGroupReport(groupName);
    }
    static void XCOVER_CALLCONV onBeginFileReport_(xcover_reporter_t *this_, char const* fileName, char const* aliasName)
    {
        static_cast<class_type*>(this_)->onBeginFileReport(fileName, aliasName);
    }
    static void XCOVER_CALLCONV onEndFileReport_(xcover_reporter_t *this_, char const* fileName, char const* aliasName, unsigned n)
    {
        static_cast<class_type*>(this_)->onEndFileReport(fileName, aliasName, n);
    }
    static void XCOVER_CALLCONV onReportItem_(xcover_reporter_t *this_, xcover_coverItem_t const* item)
    {
        static_cast<class_type*>(this_)->onReportItem(item);
    }

    static vtable_t make_VTable()
    {
        vtable_t vt = { onBeginGroupReport_, onEndGroupReport_, onBeginFileReport_, onEndFileReport_, onReportItem_ };

        return vt;
    }
    static vtable_t *const get_VTable()
    {
        static vtable_t s_vt = make_VTable();

        return &s_vt;
    }
};
# endif /* !XCOVER_INTRINSIC_VTABLES_ARE_PORTABLE */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !XCOVER_INCL_XCOVER_INTERNAL_H_REPORTER */

/* ///////////////////////////// end of file //////////////////////////// */
