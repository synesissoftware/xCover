/* /////////////////////////////////////////////////////////////////////////
 * File:        xcover/implicit_link.h
 *
 * Purpose:     Implicit linking for the FastFormat API
 *
 * Created:     3rd January 2009
 * Updated:     12th August 2009
 *
 * Home:        http://xcover.org/
 *
 * Copyright (c) 2007-2009, Matthew Wilson and Synesis Software
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
 * - Neither the names of Matthew Wilson and Synesis Software nor the names
 *   of any contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
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


/** \file xcover/implicit_link.h Implicit linking for the FastFormat API
 */

#ifndef XCOVER_INCL_XCOVER_H_IMPLICIT_LINK
#define XCOVER_INCL_XCOVER_H_IMPLICIT_LINK

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef XCOVER_DOCUMENTATION_SKIP_SECTION
# define XCOVER_VER_XCOVER_H_IMPLICIT_LINK_MAJOR    1
# define XCOVER_VER_XCOVER_H_IMPLICIT_LINK_MINOR    1
# define XCOVER_VER_XCOVER_H_IMPLICIT_LINK_REVISION 1
# define XCOVER_VER_XCOVER_H_IMPLICIT_LINK_EDIT     3
#endif /* !XCOVER_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef XCOVER_INCL_XCOVER_H_FASTFORMAT
# include <xcover/xcover.h>
#endif /* !XCOVER_INCL_XCOVER_H_FASTFORMAT */

#include <platformstl/platformstl.h>

/* /////////////////////////////////////////////////////////////////////////
 * Implicit linking
 */

#if defined(_WIN32) || \
    defined(_WIN64)

# if defined(__BORLANDC__) || \
     /* defined(__DMC__) || */ \
     defined(__INTEL_COMPILER) || \
     defined(__MWERKS__) || \
     defined(_MSC_VER)
#  if !defined(__COMO__)
#   define XCOVER_IMPLICIT_LINK_SUPPORT
#  endif /* compiler */
# endif /* compiler */

# if defined(XCOVER_IMPLICIT_LINK_SUPPORT) && \
     defined(XCOVER_NO_IMPLICIT_LINK)
#  undef XCOVER_IMPLICIT_LINK_SUPPORT
# endif /* XCOVER_IMPLICIT_LINK_SUPPORT && XCOVER_NO_IMPLICIT_LINK */

# if defined(XCOVER_IMPLICIT_LINK_SUPPORT)

  /* prefix */

#  define XCOVER_IMPL_LINK_PREFIX

  /* library basename */

#  define XCOVER_IMPL_LINK_LIBRARY_BASENAME         "xcover"

  /* major version */

#  define XCOVER_IMPL_LINK_MAJOR_VERSION            "." STLSOFT_STRINGIZE(XCOVER_VER_MAJOR) 

  /* module name */

#  define XCOVER_IMPL_LINK_MODULE_NAME              ".core"

  /* compiler tag */

#  if defined(__BORLANDC__)
#   if __BORLANDC__ == 0x0550
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "bc55"
#   elif (__BORLANDC__ == 0x0551)
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "bc551"
#   elif (__BORLANDC__ == 0x0560)
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "bc56"
#   elif (__BORLANDC__ == 0x0564)
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "bc564"
#   elif (__BORLANDC__ == 0x0582)
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "bc582"
#   elif (0x0590 == (__BORLANDC__ & 0xfff0))
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "bc59x"
#   elif (0x0610 == (__BORLANDC__ & 0xfff0))
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "bc61x"
#   else /* ? __BORLANDC__ */
#    error Unrecognised value of __BORLANDC__
#   endif /* __BORLANDC__ */

/*
#  elif defined(__DMC__)
#   define XCOVER_IMPL_LINK_COMPILER_NAME           "dm"
 */

#  elif defined(__INTEL_COMPILER)
#   if __INTEL_COMPILER == 600
#    define   XCOVER_IMPL_LINK_COMPILER_NAME        "icl6"
#   elif __INTEL_COMPILER == 700
#    define   XCOVER_IMPL_LINK_COMPILER_NAME        "icl7"
#   elif __INTEL_COMPILER == 800
#    define   XCOVER_IMPL_LINK_COMPILER_NAME        "icl8"
#   elif __INTEL_COMPILER == 900
#    define   XCOVER_IMPL_LINK_COMPILER_NAME        "icl9"
#   elif __INTEL_COMPILER == 1000
#    define   XCOVER_IMPL_LINK_COMPILER_NAME        "icl10"
#   elif __INTEL_COMPILER == 1100
#    define   XCOVER_IMPL_LINK_COMPILER_NAME        "icl11"
#   else /* ? __INTEL_COMPILER */
#    error Intel C/C++ version not supported
#   endif /* __INTEL_COMPILER */

#  elif defined(__MWERKS__)
#   if ((__MWERKS__ & 0xFF00) == 0x2400)
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "cw7"
#   elif ((__MWERKS__ & 0xFF00) == 0x3000)
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "cw8"
#   elif ((__MWERKS__ & 0xFF00) == 0x3200)
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "cw9"
#   else /* ? __MWERKS__ */
#    error CodeWarrior version not supported
#   endif /* __MWERKS__ */

#  elif defined(_MSC_VER)
#   if _MSC_VER == 1000
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "vc4"
#   elif _MSC_VER == 1020
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "vc42"
#   elif _MSC_VER == 1100
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "vc5"
#   elif _MSC_VER == 1200
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "vc6"
#   elif _MSC_VER == 1300
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "vc7"
#   elif _MSC_VER == 1310
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "vc71"
#   elif _MSC_VER == 1400
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "vc8"
#   elif _MSC_VER == 1500
#    define XCOVER_IMPL_LINK_COMPILER_NAME          "vc9"
#   else /* ? _MSC_VER */
#    error Visual C++ version not supported
#   endif /* _MSC_VER */

#  else /* ? compiler */
#   error Unrecognised compiler
#  endif /* compiler */


  /* operating system tag */

#  if defined(_STLSOFT_FORCE_ANY_COMPILER) && \
      defined(PLATFORMSTL_OS_IS_UNIX) && \
      defined(_WIN32)
#   define XCOVER_IMPL_LINK_OS_TAG                  ".unix"
#  endif /* pseudo UNIX */

#  if !defined(XCOVER_IMPL_LINK_OS_TAG)
#   define XCOVER_IMPL_LINK_OS_TAG                  ""
#  endif /* !XCOVER_IMPL_LINK_OS_TAG */


  /* architecture tag */

#  if defined(PLATFORMSTL_ARCH_IS_X86)
#   define XCOVER_IMPL_LINK_ARCH_TAG                ""
#  elif defined(PLATFORMSTL_ARCH_IS_X64)
#   define XCOVER_IMPL_LINK_ARCH_TAG                ".x64"
#  elif defined(PLATFORMSTL_ARCH_IS_IA64)
#   define XCOVER_IMPL_LINK_ARCH_TAG                ".ia64"
#  endif /* arch */

#  if !defined(XCOVER_IMPL_LINK_ARCH_TAG)
#   define XCOVER_IMPL_LINK_ARCH_TAG                ""
#  endif /* !XCOVER_IMPL_LINK_ARCH_TAG */


  /* encoding tag */

#  if defined(XCOVER_USE_WIDE_STRINGS)
#   define XCOVER_IMPL_LINK_ENCODING_TAG            ".widestring"
#  else /* ? XCOVER_USE_WIDE_STRINGS */
#   define XCOVER_IMPL_LINK_ENCODING_TAG            ""
#  endif /* XCOVER_USE_WIDE_STRINGS */


  /* threading tag */

#  if defined(__MT__) || \
      defined(_REENTRANT) || \
      defined(_MT)
#   if defined(_DLL) || \
       defined(__DLL)
#    define XCOVER_IMPL_LINK_THREADING_TAG          ".dll"
#   else /* ? dll */
#    define XCOVER_IMPL_LINK_THREADING_TAG          ".mt"
#   endif /* dll */
#  else /* ? mt */
#    define XCOVER_IMPL_LINK_THREADING_TAG          ""
#  endif /* mt */


  /* debug tag */

#  if !defined(NDEBUG) && \
      defined(_DEBUG)
#   define XCOVER_IMPL_LINK_DEBUG_TAG               ".debug"
#  else /* ? debug */
#   define XCOVER_IMPL_LINK_DEBUG_TAG               ""
#  endif /* debug */


  /* suffix */

#  define XCOVER_IMPL_LINK_SUFFIX                   ".lib"


   /* Library name is:
    *
    * [lib]<library-basename>.<major-version>.<module-name>.<compiler-name>[.<os-arch-tag>][.<char-encoding-tag>][.<threading-tag>][.<nox-tag>][.<debug-tag>].{a|lib}
    */

#  define XCOVER_IMPL_LINK_LIBRARY_NAME             XCOVER_IMPL_LINK_PREFIX \
                                                    XCOVER_IMPL_LINK_LIBRARY_BASENAME \
                                                    XCOVER_IMPL_LINK_MAJOR_VERSION \
                                                    XCOVER_IMPL_LINK_MODULE_NAME \
                                                    "." XCOVER_IMPL_LINK_COMPILER_NAME \
                                                    XCOVER_IMPL_LINK_OS_TAG \
                                                    XCOVER_IMPL_LINK_ARCH_TAG \
                                                    XCOVER_IMPL_LINK_ENCODING_TAG \
                                                    XCOVER_IMPL_LINK_THREADING_TAG \
                                                    XCOVER_IMPL_LINK_DEBUG_TAG \
                                                    XCOVER_IMPL_LINK_SUFFIX
                                                        

#  pragma message("lib: " XCOVER_IMPL_LINK_LIBRARY_NAME)

#  pragma comment(lib, XCOVER_IMPL_LINK_LIBRARY_NAME)

# endif /* XCOVER_IMPLICIT_LINK_SUPPORT */

#endif /* Win-32 || Win-64 */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !XCOVER_INCL_XCOVER_H_IMPLICIT_LINK */

/* ///////////////////////////// end of file //////////////////////////// */
