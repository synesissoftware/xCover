############################################################################
# File:     makefile
#
# Purpose:  Makefile for the xCover:C project, for the Visual C++ 14.0 (x86 UNIXem)
#           compiler, on UNIX
#
# Created:  28th December 2008
# Updated:  1st November 2015
#
############################################################################


############################################################################
# Environment check
#

!ifndef STLSOFT
!error STLSOFT must be defined
!endif # !STLSOFT
!ifndef PTHREADS_WIN32
!error PTHREADS_WIN32 must be defined
!endif # !PTHREADS_WIN32
!ifndef UNIXEM
!error UNIXEM must be defined
!endif # !UNIXEM

############################################################################
# Symbols

########################################
# Project & compiler version

COMP_TAG			=	vc14
ARCH_TAG            =   
OS_TAG				=   .unix
PROJ_TAG			=	xcover
PROJ_VER_MAJOR		=   0
PROJ_TAG_VER		=   $(PROJ_TAG).$(PROJ_VER_MAJOR)
COMP_ARCH_OS_TAG	=	$(COMP_TAG)$(OS_TAG)$(ARCH_TAG)

SHWILD_VER_MAJOR	=	0
SHWILD_TAG_VER		=	shwild.$(SHWILD_VER_MAJOR)

XTESTS_VER_MAJOR    =   0
XTESTS_TAG_VER      =   xtests.$(XTESTS_VER_MAJOR)

UNIXEM_VER_MAJOR	=	1
UNIXEM_TAG_VER      =   unixem.$(XTESTS_VER_MAJOR)

PROJ_MAKEFILE_NAME	=	makefile

########################################
# Testing verbosity

TEST_VERBOSITY		=	2

########################################
# Directories

PROJ_BASE_DIR				=   ..\..
PROJ_BIN_DIR				=   $(PROJ_BASE_DIR)\bin
PROJ_INCLUDE_DIR			=   $(PROJ_BASE_DIR)\include
PROJ_LIB_DIR				=   $(PROJ_BASE_DIR)\lib
PROJ_OBJ_DIR				=   .
PROJ_SRC_DIR				=   $(PROJ_BASE_DIR)\src
PROJ_EXAMPLES_DIR			=   $(PROJ_BASE_DIR)\examples
PROJ_TEST_ROOT_DIR			=   $(PROJ_BASE_DIR)\test
PROJ_TEST_COMPONENT_DIR		=   $(PROJ_TEST_ROOT_DIR)\component
PROJ_TEST_PERFORMANCE_DIR	=	$(PROJ_TEST_ROOT_DIR)\performance
PROJ_TEST_SCRATCH_DIR		=   $(PROJ_TEST_ROOT_DIR)\scratch
PROJ_TEST_UNIT_DIR			=   $(PROJ_TEST_ROOT_DIR)\unit

SHWILD_INCLUDE_DIR			=	$(PROJ_BASE_DIR)\include
SHWILD_SRC_DIR				=   $(PROJ_SRC_DIR)\shwild

XTESTS_INCLUDE_DIR			=	$(PROJ_BASE_DIR)\include
XTESTS_SRC_DIR				=	$(PROJ_SRC_DIR)\xtests

########################################
# tools

CC						=   cl
CPPC					=   cl
AR						=   lib
LD						=   link
RM						=   del /f
CP						=   copy
RC						=   rc


########################################
# variables

# Lib

LIBS_LEADER             =   

# lib paths

ENV_LIBPATHS        =
COMMON_LIBPATHS         =   -libpath:$(SYNESIS_DEV)/lib 


LIBPATHS=\
$(LIBS_LEADER)\
-libpath:"$(PTHREADS_WIN32)\lib"\
-libpath:"$(UNIXEM)\lib"\
$(COMMON_LIBPATHS)\
$(ENV_LIBPATHS)\
\


# lib names

TARGET_LIB_MT_UX = \
 kernel32.lib user32.lib advapi32.lib uuid.lib wininet.lib ole32.lib oleaut32.lib ws2_32.lib pthreadVC.lib \
 \

TARGET_LIB_MT_UX_DEBUG = \
 kernel32.lib user32.lib advapi32.lib uuid.lib wininet.lib ole32.lib oleaut32.lib ws2_32.lib pthreadVC.lib \
 \


# #defines

COMMON_DEFS 		=	-DUNIX

CUSTOM_DEFS			=

# includes

COMMON_INCLUDES 	=	-I$(SYNESIS_DEV)/include -I$(SYNESIS_DEV)/libraries/include



# CC flags

CC_F_NOLOGO           =   -nologo
CC_F_COMPILE_ONLY     =   -c
CC_F_WARNING_MAX      =   -W4
CC_F_WARNING_ERR      =   -WX
CC_F_MINIMUM_SIZE     =   -O1
CC_F_MAXIMUM_SPEED	=	-O2

CC_FLAGS_BASE =\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

CC_FLAGS_MT_UX =\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_MT_UX_DEBUG =\
 $(CC_FLAGS_BASE)\
 \


# CPPC flags

CPPC_F_NOLOGO           =   -nologo
CPPC_F_COMPILE_ONLY     =   -c
CPPC_F_WARNING_MAX      =   -W4
CPPC_F_WARNING_ERR      =   -WX
CPPC_F_EXCEPTIONS_ON    =   -EHsc
CPPC_F_EXCEPTIONS_OFF   =   -wd4530
CPPC_F_RTTI             =   -GR
CPPC_F_MINIMUM_SIZE     =   -O1
CPPC_F_MAXIMUM_SPEED	=	-O2

CPPC_FLAGS_BASE =\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_F_WARNING_MAX)\
 $(CPPC_F_WARNING_ERR)\
 $(CPPC_F_EXCEPTIONS_ON)\
 $(CPPC_F_RTTI)\
 \

CPPC_FLAGS_MT_UX =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_MT_UX_DEBUG =\
 $(CPPC_FLAGS_BASE)\
 \



# defines

!ifdef BOOST
DEFINE_BOOST_FOR_PERFTEST	=	-DFASTFORMAT_PERFTEST_USE_BOOST
!else # BOOST
DEFINE_BOOST_FOR_PERFTEST	=	
!endif # BOOST

DEFINE_LOKI_FOR_PERFTEST	=	

# CC defines

CC_DEFS_BASE =\
 $(COMMON_DEFS)\
 $(CUSTOM_DEFS)\
 \

CC_DEFS_MT_UX =\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_MT_UX_DEBUG =\
 $(CC_DEFS_BASE)\
 \


# CPPC defines

CPPC_DEFS_BASE =\
 $(COMMON_DEFS)\
 $(CUSTOM_DEFS)\
 \

CPPC_DEFS_MT_UX =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \

CPPC_DEFS_MT_UX_DEBUG =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \



# includes

!ifdef BOOST
INCLUDE_BOOST_FOR_PERFTEST	=	-I"$(BOOST)"
!else # BOOST
INCLUDE_BOOST_FOR_PERFTEST	=	
!endif # BOOST

INCLUDE_LOKI_FOR_PERFTEST	=	

# CC includes

CC_INCLUDES_BASE =\
 \
 -I$(PROJ_INCLUDE_DIR)\
 -I$(STLSOFT)\include\
 $(COMMON_INCLUDES)\
 -I"$(PTHREADS_WIN32)\include"\
 -I"$(UNIXEM)\include"\
 \

CC_INCLUDES_MT_UX =\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_MT_UX_DEBUG =\
 $(CC_INCLUDES_BASE)\
 \



# CPPC includes

CPPC_INCLUDES_BASE =\
 \
 -I$(PROJ_INCLUDE_DIR)\
 -I$(STLSOFT)\include\
 $(COMMON_INCLUDES)\
 -I"$(PTHREADS_WIN32)\include"\
 -I"$(UNIXEM)\include"\
 \

CPPC_INCLUDES_MT_UX =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \

CPPC_INCLUDES_MT_UX_DEBUG =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \



CPPC_SHWILD_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_UX =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_UX_DEBUG =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \


CPPC_XTESTS_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_UX =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_UX_DEBUG =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \



# CC args (= flags + defines + includes)

CC_ARGS_MT_UX=\
 $(CC_FLAGS_MT_UX)\
 $(CPPC_F_WITH_EXCEPTIONS) -MT -D_REENTRANT -DNDEBUG $(CC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER\
 $(CC_DEFS_MT_UX)\
 -DXCOVER_NO_IMPLICIT_LINK\
 $(CC_INCLUDES_MT_UX)
CC_ARGS_MT_UX_DEBUG=\
 $(CC_FLAGS_MT_UX_DEBUG)\
 $(CPPC_F_WITH_EXCEPTIONS) -MTd -D_REENTRANT -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.pdb\
 $(CC_DEFS_MT_UX_DEBUG)\
 -DXCOVER_NO_IMPLICIT_LINK\
 $(CC_INCLUDES_MT_UX_DEBUG)

# CPPC args (= flags + defines + includes)

CPPC_ARGS_MT_UX=\
 $(CPPC_FLAGS_MT_UX)\
 $(CPPC_F_WITH_EXCEPTIONS) -MT -D_REENTRANT -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER\
 $(CPPC_DEFS_MT_UX)\
 -DXCOVER_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_MT_UX)
CPPC_ARGS_MT_UX_DEBUG=\
 $(CPPC_FLAGS_MT_UX_DEBUG)\
 $(CPPC_F_WITH_EXCEPTIONS) -MTd -D_REENTRANT -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.pdb\
 $(CPPC_DEFS_MT_UX_DEBUG)\
 -DXCOVER_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_MT_UX_DEBUG)



# AR Args

AR_ARGS             =   -nologo


# LD flags

LD_F_NOLOGO				=   -nologo

LD_FLAGS_BASE =\
 $(LD_F_NOLOGO)\
 \

LD_FLAGS_MT_UX =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_MT_UX_DEBUG =\
 $(LD_FLAGS_BASE)\
 \


# LD includes

LD_INCLUDES_BASE =\
 $(LIBPATHS)\
 \

LD_INCLUDES_MT_UX =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_MT_UX_DEBUG =\
 $(LD_INCLUDES_BASE)\
 \


# LD args

LD_ARGS_MT_UX= $(LD_FLAGS_MT_UX) libWinSysLog.$(COMP_TAG).mt.lib unixem.1.$(COMP_TAG).mt.lib -release $(LD_INCLUDES_MT_UX)
LD_ARGS_MT_UX_DEBUG= $(LD_FLAGS_MT_UX_DEBUG) libWinSysLog.$(COMP_TAG).mt.debug.lib unixem.1.$(COMP_TAG).mt.debug.lib -debug $(LD_INCLUDES_MT_UX_DEBUG)

############################################################################
# Headers

CORE_HEADERS=\
 $(PROJ_INCLUDE_DIR)\xcover\xcover.h\
 $(PROJ_INCLUDE_DIR)\xcover\implicit_link.h\
 $(PROJ_INCLUDE_DIR)\xcover\internal\reporter.h\
 \

SHWILD_HEADERS=\
 $(PROJ_INCLUDE_DIR)\shwild\shwild.h\
 $(PROJ_INCLUDE_DIR)\shwild\shwild.hpp\
 \

XTESTS_HEADERS=\
 $(PROJ_INCLUDE_DIR)\xtests\xtests.h\
 \

############################################################################
# Names

############################################################
# Targets

########################################
# Libraries

# xCover
LIB_CORE_MT_UX				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).mt.lib
LIB_CORE_MT_UX_DEBUG				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).mt.debug.lib

# shwild - testing only
LIB_SHWILD_MT_UX			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).xcvr.$(COMP_ARCH_OS_TAG).mt.lib
LIB_SHWILD_MT_UX_DEBUG			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).xcvr.$(COMP_ARCH_OS_TAG).mt.debug.lib

# xtests - unit/component testing only
LIB_XTESTS_MT_UX			=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).xcvr.$(COMP_ARCH_OS_TAG).mt.lib
LIB_XTESTS_MT_UX_DEBUG			=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).xcvr.$(COMP_ARCH_OS_TAG).mt.debug.lib

########################################
# Examples



########################################
# Tests


##############################
# Component Tests

OBJ_TEST_COMP_c_1_MT_UX	=   $(PROJ_OBJ_DIR)\test.component.c.1.mt.obj
OBJ_TEST_COMP_c_1_MT_UX_DEBUG	=   $(PROJ_OBJ_DIR)\test.component.c.1.mt.debug.obj

##############################
# Scratch Tests

OBJ_TEST_SCRT_c_1_MT_UX = $(PROJ_OBJ_DIR)\test.scratch.c.1.mt.obj
OBJ_TEST_SCRT_c_1_a_MT_UX = $(PROJ_OBJ_DIR)\test.scratch.c.1.api.1.a.mt.obj
OBJ_TEST_SCRT_c_1_b_MT_UX = $(PROJ_OBJ_DIR)\test.scratch.c.1.api.1.b.mt.obj
OBJ_TEST_SCRT_c_1_MT_UX_DEBUG = $(PROJ_OBJ_DIR)\test.scratch.c.1.mt.debug.obj
OBJ_TEST_SCRT_c_1_a_MT_UX_DEBUG = $(PROJ_OBJ_DIR)\test.scratch.c.1.api.1.a.mt.debug.obj
OBJ_TEST_SCRT_c_1_b_MT_UX_DEBUG = $(PROJ_OBJ_DIR)\test.scratch.c.1.api.1.b.mt.debug.obj

OBJ_TEST_SCRT_mfe_MT_UX =   $(PROJ_OBJ_DIR)\test.scratch.mark_file_end.mt.obj
OBJ_TEST_SCRT_mfe_cex1_MT_UX =   $(PROJ_OBJ_DIR)\test.scratch.mark_file_end.cex1.mt.obj
OBJ_TEST_SCRT_mfe_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\test.scratch.mark_file_end.mt.debug.obj
OBJ_TEST_SCRT_mfe_cex1_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\test.scratch.mark_file_end.cex1.mt.debug.obj

############################################################
# Objects

########################################
# Libraries

# core

OBJ_lib_core_MT_UX =	$(PROJ_OBJ_DIR)\core.mt.obj

OBJ_LIB_CORE_MT_UX=\
 $(OBJ_lib_core_MT_UX)\
 \

OBJ_lib_core_MT_UX_DEBUG =	$(PROJ_OBJ_DIR)\core.mt.debug.obj

OBJ_LIB_CORE_MT_UX_DEBUG=\
 $(OBJ_lib_core_MT_UX_DEBUG)\
 \


# shwild

OBJ_shw_api_MT_UX            = $(PROJ_OBJ_DIR)\shwild.pan.api.mt.obj
OBJ_shw_matches_MT_UX        = $(PROJ_OBJ_DIR)\shwild.pan.matches.mt.obj
OBJ_shw_pattern_MT_UX        = $(PROJ_OBJ_DIR)\shwild.pan.pattern.mt.obj

OBJ_SHWILD_MT_UX=\
 $(OBJ_shw_api_MT_UX)\
 $(OBJ_shw_matches_MT_UX)\
 $(OBJ_shw_pattern_MT_UX)\
 \

OBJ_shw_api_MT_UX_DEBUG            = $(PROJ_OBJ_DIR)\shwild.pan.api.mt.debug.obj
OBJ_shw_matches_MT_UX_DEBUG        = $(PROJ_OBJ_DIR)\shwild.pan.matches.mt.debug.obj
OBJ_shw_pattern_MT_UX_DEBUG        = $(PROJ_OBJ_DIR)\shwild.pan.pattern.mt.debug.obj
PDB_shw_api_MT_UX_DEBUG            = $(PROJ_OBJ_DIR)\shwild.pan.api.mt.debug.pdb
PDB_shw_matches_MT_UX_DEBUG        = $(PROJ_OBJ_DIR)\shwild.pan.matches.mt.debug.pdb
PDB_shw_pattern_MT_UX_DEBUG        = $(PROJ_OBJ_DIR)\shwild.pan.pattern.mt.debug.pdb

OBJ_SHWILD_MT_UX_DEBUG=\
 $(OBJ_shw_api_MT_UX_DEBUG)\
 $(OBJ_shw_matches_MT_UX_DEBUG)\
 $(OBJ_shw_pattern_MT_UX_DEBUG)\
 \

PDB_SHWILD_MT_UX_DEBUG=\
 $(PDB_shw_api_MT_UX_DEBUG)\
 $(PDB_shw_matches_MT_UX_DEBUG)\
 $(PDB_shw_pattern_MT_UX_DEBUG)\
 \


# xtests

OBJ_xts_core_MT_UX           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.mt.obj

OBJ_XTESTS_MT_UX = \
 $(OBJ_xts_core_MT_UX)\
 \

OBJ_xts_core_MT_UX_DEBUG           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.mt.debug.obj
PDB_xts_core_MT_UX_DEBUG           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.mt.debug.pdb

OBJ_XTESTS_MT_UX_DEBUG = \
 $(OBJ_xts_core_MT_UX_DEBUG)\
 \

PDB_CORE_MT_UX_DEBUG = \
 $(PDB_xts_core_MT_UX_DEBUG)\
 \


########################################
# Examples



########################################
# Tests

##############################
# Component Tests

TARG_TEST_COMP_c_1_MT_UX    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.c.1.$(COMP_TAG).mt.exe
TARG_TEST_COMP_c_1_MT_UX_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.c.1.$(COMP_TAG).mt.debug.exe

##############################
# Scratch Tests

TARG_TEST_SCRT_c_1_MT_UX    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.c.1.$(COMP_TAG).mt.exe
TARG_TEST_SCRT_c_1_MT_UX_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.c.1.$(COMP_TAG).mt.debug.exe

TARG_TEST_SCRT_mfe_MT_UX    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.mark_file_end.$(COMP_TAG).mt.exe
TARG_TEST_SCRT_mfe_MT_UX_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.mark_file_end.$(COMP_TAG).mt.debug.exe

##############################
# Unit Tests


# Target groups

########################################
# Objects

# core
OBJS_CORE=\
# $(OBJ_UTIL_MT_UX)\
 $(OBJ_CORE_MT_UX)\
# $(OBJ_UTIL_MT_UX_DEBUG)\
 $(OBJ_CORE_MT_UX_DEBUG)\
 \

# shwild
OBJS_SHWILD=\
 $(OBJ_SHWILD_MT_UX)\
 $(OBJ_SHWILD_MT_UX_DEBUG)\
 \

# examples
OBJS_EXAMPLE=\
 \

# Component Tests
OBJS_TEST_COMPONENT=\
 $(OBJ_TEST_COMP_c_1_MT_UX)\
 $(OBJ_TEST_COMP_c_1_MT_UX_DEBUG)\
 \

# Scratch Tests
OBJS_TEST_SCRATCH=\
 $(OBJ_TEST_SCRT_c_1_MT_UX)\
 $(OBJ_TEST_SCRT_c_1_a_MT_UX)\
 $(OBJ_TEST_SCRT_c_1_b_MT_UX)\
 $(OBJ_TEST_SCRT_mfe_MT_UX)\
 $(OBJ_TEST_SCRT_mfe_cex1_MT_UX)\
 $(OBJ_TEST_SCRT_c_1_MT_UX_DEBUG)\
 $(OBJ_TEST_SCRT_c_1_a_MT_UX_DEBUG)\
 $(OBJ_TEST_SCRT_c_1_b_MT_UX_DEBUG)\
 $(OBJ_TEST_SCRT_mfe_MT_UX_DEBUG)\
 $(OBJ_TEST_SCRT_mfe_cex1_MT_UX_DEBUG)\
 \

# Unit Tests
OBJS_TEST_UNIT=\
 \

########################################
# Libraries

TARGETS_LIB_CORE=\
 $(LIB_CORE_MT_UX)\
 $(LIB_CORE_MT_UX_DEBUG)\
 \

TARGETS_LIB_ALL=\
 $(TARGETS_LIB_CORE)\
 \

TARGETS_LIB_SHWILD=\
 $(LIB_SHWILD_MT_UX)\
 $(LIB_SHWILD_MT_UX_DEBUG)\
 \

########################################
# Programs

TARGETS_EXAMPLE_C=\
 \

TARGETS_EXAMPLE_CPP=\
 \

TARGETS_EXAMPLE=\
 $(TARGETS_EXAMPLE_C)\
 $(TARGETS_EXAMPLE_CPP)\
 \


TARGETS_TEST_COMPONENT=\
 $(TARG_TEST_COMP_c_1_MT_UX)\
 $(TARG_TEST_COMP_c_1_MT_UX_DEBUG)\
 \

TARGETS_TEST_SCRATCH=\
 $(TARG_TEST_SCRT_c_1_MT_UX)\
 $(TARG_TEST_SCRT_mfe_MT_UX)\
 $(TARG_TEST_SCRT_c_1_MT_UX_DEBUG)\
 $(TARG_TEST_SCRT_mfe_MT_UX_DEBUG)\
 \

TARGETS_TEST_UNIT=\
 \


############################################################
# Third-party libraries

############################################################################
# External Targets (invokable by make)

# primary

_default:					build

usage:
	@echo "make [usage | compile | build | test | clean] - default is 'build'"

# infrastructure

check.lib.dir:				$(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)

check.bin.dir:				$(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)


# compile targets

compile.libs.core:			$(PROJ_MAKEFILE_NAME)	$(OBJS_CORE)

compile.libs.shwild:		$(PROJ_MAKEFILE_NAME)	$(OBJS_SHWILD)

compile.libs.xtests:		$(PROJ_MAKEFILE_NAME)	$(OBJS_XTESTS)

compile.libs.3pty:									compile.libs.shwild compile.libs.xtests

compile.libs:										compile.libs.core

compile.libs.all:                                   compile.libs compile.libs.3pty

compile.examples:			$(PROJ_MAKEFILE_NAME)	$(OBJS_EXAMPLE)

compile.test.component:		$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_COMPONENT)

compile.test.performance:	$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_PERFORMANCE)

compile.test.scratch:		$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_SCRATCH)

compile.test.unit:			$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_UNIT)

compile.test:										compile.test.unit compile.test.component

compile.test.all:									compile.test compile.test.scratch compile.test.performance

compile:                                            compile.libs compile.test compile.examples

compile.all:                                        compile compile.test.all



# build targets

build.libs.core:			check.lib.dir			$(TARGETS_LIB_CORE)

build.libs:											build.libs.core

build.libs.shwild:			check.lib.dir			$(TARGETS_LIB_SHWILD)

build.libs.xtests:          check.lib.dir           $(TARGETS_LIB_XTESTS)

build.libs.3pty:									build.libs.shwild build.libs.xtests

build.libs.all:										build.libs build.libs.3pty

build.examples:				check.bin.dir			$(TARGETS_EXAMPLE)

build.test.component:		check.bin.dir			$(TARGETS_TEST_COMPONENT)

build.test.performance:		check.bin.dir			$(TARGETS_TEST_PERFORMANCE)

build.test.scratch:			check.bin.dir			$(TARGETS_TEST_SCRATCH)

build.test.unit:			check.bin.dir			$(TARGETS_TEST_UNIT)

build.test:                                         build.test.unit build.test.component build.test.performance

build.test.all:                                     build.test build.test.scratch

build:                                              build.libs build.examples build.test

build.all:											build.libs.all build.examples build.test.all



# test targets

test.component_:
	@echo Running Test:Component programs ...

test.scratch_:
	@echo Running Test:Scratch programs ...
	$(TARG_TEST_SCRT_c_1_MT_UX) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_c_1_MT_UX_DEBUG) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_mfe_MT_UX) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_mfe_MT_UX_DEBUG) --verbosity=$(TEST_VERBOSITY)

test.unit_:
	@echo Running Test:Unit programs ...

test.component:			$(PROJ_MAKEFILE_NAME)	build.test.component test.component_
	$(TARG_TEST_COMP_c_1_MT_UX) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_c_1_MT_UX_DEBUG) --verbosity=$(TEST_VERBOSITY)

test.scratch:			$(PROJ_MAKEFILE_NAME)	build.test.scratch test.scratch_

test.unit:				$(PROJ_MAKEFILE_NAME)	build.test.unit test.unit_

test:											test.unit test.component

test.all:										test test.scratch
test-all:				test.all


# clean targets

clean.libs.core:
	@echo Cleaning Core libraries ...
	@-$(RM) $(LIB_CORE_MT_UX)
	@-$(RM) $(LIB_UTIL_MT_UX)
	@-$(RM) $(LIB_CORE_MT_UX_DEBUG)
	@-$(RM) $(LIB_UTIL_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CORE_MT_UX)
	@-$(RM) $(OBJ_UTIL_MT_UX)
	@-$(RM) $(OBJ_CORE_MT_UX_DEBUG)
	@-$(RM) $(OBJ_UTIL_MT_UX_DEBUG)
	@-$(RM) $(PDB_CORE_MT_UX_DEBUG)

clean.libs.shwild:
	@echo Cleaning shwild libraries ...
	@-$(RM) $(LIB_SHWILD_MT_UX)
	@-$(RM) $(LIB_SHWILD_MT_UX_DEBUG)
	@-$(RM) $(OBJ_SHWILD_MT_UX)
	@-$(RM) $(OBJ_SHWILD_MT_UX_DEBUG)
	@-$(RM) $(PDB_SHWILD_MT_UX_DEBUG)

clean.test.component:
	@echo cleaning Test:Component libraries ...

clean.test.scratch:
	@echo cleaning Test:Scratch libraries ...
	@-$(RM) $(TARG_TEST_SCRT_c_1_MT_UX)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_MT_UX)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_a_MT_UX)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_b_MT_UX)
	@-$(RM) $(TARG_TEST_SCRT_mfe_MT_UX)
	@-$(RM) $(OBJ_TEST_SCRT_mfe_MT_UX)
	@-$(RM) $(OBJ_TEST_SCRT_mfe_cex1_MT_UX)
	@-$(RM) $(TARG_TEST_SCRT_c_1_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_a_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_b_MT_UX_DEBUG)
	@-$(RM) $(TARG_TEST_SCRT_mfe_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_SCRT_mfe_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_SCRT_mfe_cex1_MT_UX_DEBUG)

clean.test.unit:
	@echo cleaning Test:Unit libraries ...

clean.libs: 									clean.libs.core

clean.libs.3pty:								clean.libs.shwild

clean.libs.all: 								clean.libs clean.libs.3pty

clean.examples:			$(PROJ_MAKEFILE_NAME)

clean.test:										clean.test.component clean.test.scratch clean.test.unit

clean:					$(PROJ_MAKEFILE_NAME)	clean.libs.all clean.test clean.examples



############################################################################
# build targets

##################################################
# Libraries

########################################
# shwild library - 'shwild.X.xcvr.core.a'

$(LIB_SHWILD_MT_UX): $(OBJ_SHWILD_MT_UX) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_MT_UX)

$(OBJ_shw_api_MT_UX): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) $(CPPC_SHWILD_INCLUDES_MT_UX) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_MT_UX): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) $(CPPC_SHWILD_INCLUDES_MT_UX) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_MT_UX): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) $(CPPC_SHWILD_INCLUDES_MT_UX) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_MT_UX_DEBUG): $(OBJ_SHWILD_MT_UX_DEBUG) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_MT_UX_DEBUG)

$(OBJ_shw_api_MT_UX_DEBUG): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) $(CPPC_SHWILD_INCLUDES_MT_UX_DEBUG) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_MT_UX_DEBUG): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) $(CPPC_SHWILD_INCLUDES_MT_UX_DEBUG) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_MT_UX_DEBUG): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) $(CPPC_SHWILD_INCLUDES_MT_UX_DEBUG) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

########################################
# xTests library - 'xtests.X.xcvr.core.a'

$(LIB_XTESTS_MT_UX): $(OBJ_XTESTS_MT_UX) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_MT_UX)

$(OBJ_xts_core_MT_UX): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) $(CPPC_XTESTS_INCLUDES_MT_UX) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_MT_UX_DEBUG): $(OBJ_XTESTS_MT_UX_DEBUG) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_MT_UX_DEBUG)

$(OBJ_xts_core_MT_UX_DEBUG): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) $(CPPC_XTESTS_INCLUDES_MT_UX_DEBUG) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

########################################
# Main library - 'xcover.X.core.a'

$(LIB_CORE_MT_UX): $(OBJ_LIB_CORE_MT_UX) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_LIB_CORE_MT_UX)

$(OBJ_lib_core_MT_UX):	$(PROJ_MAKEFILE_NAME) $(PROJ_SRC_DIR)\xcover.core.cpp
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\xcover.core.cpp

$(LIB_CORE_MT_UX_DEBUG): $(OBJ_LIB_CORE_MT_UX_DEBUG) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_LIB_CORE_MT_UX_DEBUG)

$(OBJ_lib_core_MT_UX_DEBUG):	$(PROJ_MAKEFILE_NAME) $(PROJ_SRC_DIR)\xcover.core.cpp
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\xcover.core.cpp

##################################################
# Examples

##################################################
# Tests

##############################
# Component Tests

$(TARG_TEST_COMP_c_1_MT_UX):	\
			$(OBJ_TEST_COMP_c_1_MT_UX)\
			$(LIB_CORE_MT_UX)\
			$(LIB_SHWILD_MT_UX)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_COMP_c_1_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIBS_3PTY_TEST_COMPONENT)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_COMP_c_1_MT_UX):	$(PROJ_TEST_COMPONENT_DIR)\test.component.c.1\test.component.c.1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.c.1\test.component.c.1.c

$(TARG_TEST_COMP_c_1_MT_UX_DEBUG):	\
			$(OBJ_TEST_COMP_c_1_MT_UX_DEBUG)\
			$(LIB_CORE_MT_UX_DEBUG)\
			$(LIB_SHWILD_MT_UX_DEBUG)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_COMP_c_1_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIBS_3PTY_TEST_COMPONENT)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_COMP_c_1_MT_UX_DEBUG):	$(PROJ_TEST_COMPONENT_DIR)\test.component.c.1\test.component.c.1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.c.1\test.component.c.1.c

##############################
# Scratch Tests

$(TARG_TEST_SCRT_c_1_MT_UX):	\
			$(OBJ_TEST_SCRT_c_1_MT_UX)\
			$(OBJ_TEST_SCRT_c_1_a_MT_UX)\
			$(OBJ_TEST_SCRT_c_1_b_MT_UX)\
			$(LIB_CORE_MT_UX)\
			$(LIB_SHWILD_MT_UX)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_SCRT_c_1_MT_UX)\
		$(OBJ_TEST_SCRT_c_1_a_MT_UX)\
		$(OBJ_TEST_SCRT_c_1_b_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_SCRT_c_1_MT_UX):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.c.1\test.scratch.c.1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.c.1\test.scratch.c.1.c
$(OBJ_TEST_SCRT_c_1_a_MT_UX):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.c.1\api.1.a.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.c.1\api.1.a.c
$(OBJ_TEST_SCRT_c_1_b_MT_UX):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.c.1\api.1.b.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.c.1\api.1.b.c

$(TARG_TEST_SCRT_c_1_MT_UX_DEBUG):	\
			$(OBJ_TEST_SCRT_c_1_MT_UX_DEBUG)\
			$(OBJ_TEST_SCRT_c_1_a_MT_UX_DEBUG)\
			$(OBJ_TEST_SCRT_c_1_b_MT_UX_DEBUG)\
			$(LIB_CORE_MT_UX_DEBUG)\
			$(LIB_SHWILD_MT_UX_DEBUG)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_SCRT_c_1_MT_UX_DEBUG)\
		$(OBJ_TEST_SCRT_c_1_a_MT_UX_DEBUG)\
		$(OBJ_TEST_SCRT_c_1_b_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_SCRT_c_1_MT_UX_DEBUG):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.c.1\test.scratch.c.1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.c.1\test.scratch.c.1.c
$(OBJ_TEST_SCRT_c_1_a_MT_UX_DEBUG):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.c.1\api.1.a.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.c.1\api.1.a.c
$(OBJ_TEST_SCRT_c_1_b_MT_UX_DEBUG):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.c.1\api.1.b.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.c.1\api.1.b.c

$(TARG_TEST_SCRT_mfe_MT_UX):	\
			$(OBJ_TEST_SCRT_mfe_MT_UX)\
			$(OBJ_TEST_SCRT_mfe_cex1_MT_UX)\
			$(LIB_CORE_MT_UX)\
			$(LIB_SHWILD_MT_UX)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_SCRT_mfe_MT_UX)\
		$(OBJ_TEST_SCRT_mfe_cex1_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_SCRT_mfe_MT_UX):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.mark_file_end\test.scratch.mark_file_end.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.mark_file_end\test.scratch.mark_file_end.cpp
$(OBJ_TEST_SCRT_mfe_cex1_MT_UX):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.mark_file_end\cex1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.mark_file_end\cex1.c

$(TARG_TEST_SCRT_mfe_MT_UX_DEBUG):	\
			$(OBJ_TEST_SCRT_mfe_MT_UX_DEBUG)\
			$(OBJ_TEST_SCRT_mfe_cex1_MT_UX_DEBUG)\
			$(LIB_CORE_MT_UX_DEBUG)\
			$(LIB_SHWILD_MT_UX_DEBUG)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_SCRT_mfe_MT_UX_DEBUG)\
		$(OBJ_TEST_SCRT_mfe_cex1_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_SCRT_mfe_MT_UX_DEBUG):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.mark_file_end\test.scratch.mark_file_end.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.mark_file_end\test.scratch.mark_file_end.cpp
$(OBJ_TEST_SCRT_mfe_cex1_MT_UX_DEBUG):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.mark_file_end\cex1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.mark_file_end\cex1.c

##############################
# Unit Tests

############################### end of file ################################
