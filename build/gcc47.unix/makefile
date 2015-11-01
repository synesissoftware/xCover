############################################################################
# File:     makefile
#
# Purpose:  Makefile for the xCover:C project, for the GCC 4.7 (UNIX)
#           compiler, on UNIX
#
# Created:  28th December 2008
# Updated:  1st November 2015
#
############################################################################


############################################################################
# Environment check
#

ifndef STLSOFT
$(error STLSOFT must be defined)
endif # !STLSOFT

############################################################################
# Symbols

########################################
# Project & compiler version

COMP_TAG			=	gcc47
ARCH_TAG            =   
OS_TAG				=   
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

PROJ_BASE_DIR				=   ../..
PROJ_BIN_DIR				=   $(PROJ_BASE_DIR)/bin
PROJ_INCLUDE_DIR			=   $(PROJ_BASE_DIR)/include
PROJ_LIB_DIR				=   $(PROJ_BASE_DIR)/lib
PROJ_OBJ_DIR				=   .
PROJ_SRC_DIR				=   $(PROJ_BASE_DIR)/src
PROJ_EXAMPLES_DIR			=   $(PROJ_BASE_DIR)/examples
PROJ_TEST_ROOT_DIR			=   $(PROJ_BASE_DIR)/test
PROJ_TEST_COMPONENT_DIR		=   $(PROJ_TEST_ROOT_DIR)/component
PROJ_TEST_PERFORMANCE_DIR	=	$(PROJ_TEST_ROOT_DIR)/performance
PROJ_TEST_SCRATCH_DIR		=   $(PROJ_TEST_ROOT_DIR)/scratch
PROJ_TEST_UNIT_DIR			=   $(PROJ_TEST_ROOT_DIR)/unit

SHWILD_INCLUDE_DIR			=	$(PROJ_BASE_DIR)/include
SHWILD_SRC_DIR				=   $(PROJ_SRC_DIR)/shwild

XTESTS_INCLUDE_DIR			=	$(PROJ_BASE_DIR)/include
XTESTS_SRC_DIR				=	$(PROJ_SRC_DIR)/xtests

########################################
# tools

CC						=   gcc
CPPC					=   g++
AR						=   ar
LD						=   g++
RM						=   rm -f
CP						=   cp
RC						=   


########################################
# variables

# Lib

LIBS_LEADER             =   

# lib paths

ENV_LIBPATHS        =
COMMON_LIBPATHS         =


LIBPATHS=\
$(LIBS_LEADER)\
$(COMMON_LIBPATHS)\
$(ENV_LIBPATHS)\
\


# lib names

TARGET_LIB_MT_D = \
 -lpthread \
 \

TARGET_LIB_MT_R = \
 -lpthread \
 \

TARGET_LIB_ST_D = \
  \
 \

TARGET_LIB_ST_R = \
  \
 \


# #defines

COMMON_DEFS 		=	-Dunix

CUSTOM_DEFS			=

# includes

COMMON_INCLUDES		=	



# CC flags

CC_F_NOLOGO           =   
CC_F_COMPILE_ONLY     =   -c
CC_F_WARNING_MAX      =   -Wall -pedantic -Wno-long-long -Wno-unused-value -Wundef -Wshadow
CC_F_WARNING_ERR      =   -Werror
CC_F_MINIMUM_SIZE     =   -O1
CC_F_MAXIMUM_SPEED	=	-O3

CC_FLAGS_BASE =\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

CC_FLAGS_MT_D =\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_MT_R =\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_ST_D =\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_ST_R =\
 $(CC_FLAGS_BASE)\
 \


# CPPC flags

CPPC_F_NOLOGO           =   
CPPC_F_COMPILE_ONLY     =   -c
CPPC_F_WARNING_MAX      =   -Wall -pedantic -Wno-long-long -Wno-unused-value -Wno-non-virtual-dtor
CPPC_F_WARNING_ERR      =   -Werror
CPPC_F_EXCEPTIONS_ON    =   
CPPC_F_EXCEPTIONS_OFF   =   
CPPC_F_RTTI             =   $(CPPC_F_RTTI_ON)
CPPC_F_MINIMUM_SIZE     =   -O1
CPPC_F_MAXIMUM_SPEED	=	-O3

CPPC_FLAGS_BASE =\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_F_WARNING_MAX)\
 $(CPPC_F_WARNING_ERR)\
 $(CPPC_F_EXCEPTIONS_ON)\
 $(CPPC_F_RTTI)\
 \

CPPC_FLAGS_MT_D =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_MT_R =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_ST_D =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_ST_R =\
 $(CPPC_FLAGS_BASE)\
 \



# defines

!ifdef BOOST
DEFINE_BOOST_FOR_PERFTEST	=	-DFASTFORMAT_PERFTEST_USE_BOOST
!else # BOOST
DEFINE_BOOST_FOR_PERFTEST	=	
!endif # BOOST

!ifdef LOKI
DEFINE_LOKI_FOR_PERFTEST	=	-DFASTFORMAT_PERFTEST_USE_LOKI
!else # LOKI
DEFINE_LOKI_FOR_PERFTEST	=	
!endif # LOKI

# CC defines

CC_DEFS_BASE =\
 $(COMMON_DEFS)\
 $(CUSTOM_DEFS)\
 \

CC_DEFS_MT_D =\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_MT_R =\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_ST_D =\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_ST_R =\
 $(CC_DEFS_BASE)\
 \


# CPPC defines

CPPC_DEFS_BASE =\
 $(COMMON_DEFS)\
 $(CUSTOM_DEFS)\
 \

CPPC_DEFS_MT_D =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \

CPPC_DEFS_MT_R =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \

CPPC_DEFS_ST_D =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \

CPPC_DEFS_ST_R =\
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

!ifdef LOKI
INCLUDE_LOKI_FOR_PERFTEST	=	-I"$(LOKI)/include"
!else # LOKI
INCLUDE_LOKI_FOR_PERFTEST	=	
!endif # LOKI

# CC includes

CC_INCLUDES_BASE =\
 \
 -I$(PROJ_INCLUDE_DIR)\
 -I$(STLSOFT)/include\
 $(COMMON_INCLUDES)\
 \

CC_INCLUDES_MT_D =\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_MT_R =\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_ST_D =\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_ST_R =\
 $(CC_INCLUDES_BASE)\
 \



# CPPC includes

CPPC_INCLUDES_BASE =\
 \
 -I$(PROJ_INCLUDE_DIR)\
 -I$(STLSOFT)/include\
 $(COMMON_INCLUDES)\
 \

CPPC_INCLUDES_MT_D =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \

CPPC_INCLUDES_MT_R =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \

CPPC_INCLUDES_ST_D =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \

CPPC_INCLUDES_ST_R =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \



CPPC_SHWILD_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_D =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_R =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_ST_D =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_ST_R =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \


CPPC_XTESTS_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_D =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_R =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_ST_D =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_ST_R =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \



# CC args (= flags + defines + includes)

CC_ARGS_MT_D=\
 $(CC_FLAGS_MT_D)\
 -D_REENTRANT -D_DEBUG -UNDEBUG\
 $(CC_DEFS_MT_D)\
 -DXCOVER_NO_IMPLICIT_LINK\
 $(CC_INCLUDES_MT_D)
CC_ARGS_MT_R=\
 $(CC_FLAGS_MT_R)\
 -D_REENTRANT -DNDEBUG -U_DEBUG $(CC_F_MAXIMUM_SPEED)\
 $(CC_DEFS_MT_R)\
 -DXCOVER_NO_IMPLICIT_LINK\
 $(CC_INCLUDES_MT_R)
CC_ARGS_ST_D=\
 $(CC_FLAGS_ST_D)\
 -D_DEBUG -UNDEBUG\
 $(CC_DEFS_ST_D)\
 -DXCOVER_NO_IMPLICIT_LINK\
 $(CC_INCLUDES_ST_D)
CC_ARGS_ST_R=\
 $(CC_FLAGS_ST_R)\
 -DNDEBUG -U_DEBUG $(CC_F_MAXIMUM_SPEED)\
 $(CC_DEFS_ST_R)\
 -DXCOVER_NO_IMPLICIT_LINK\
 $(CC_INCLUDES_ST_R)

# CPPC args (= flags + defines + includes)

CPPC_ARGS_MT_D=\
 $(CPPC_FLAGS_MT_D)\
 -D_REENTRANT -D_DEBUG -UNDEBUG\
 $(CPPC_DEFS_MT_D)\
 -DXCOVER_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_MT_D)
CPPC_ARGS_MT_R=\
 $(CPPC_FLAGS_MT_R)\
 -D_REENTRANT -DNDEBUG -U_DEBUG $(CPPC_F_MAXIMUM_SPEED)\
 $(CPPC_DEFS_MT_R)\
 -DXCOVER_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_MT_R)
CPPC_ARGS_ST_D=\
 $(CPPC_FLAGS_ST_D)\
 -D_DEBUG -UNDEBUG\
 $(CPPC_DEFS_ST_D)\
 -DXCOVER_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_ST_D)
CPPC_ARGS_ST_R=\
 $(CPPC_FLAGS_ST_R)\
 -DNDEBUG -U_DEBUG $(CPPC_F_MAXIMUM_SPEED)\
 $(CPPC_DEFS_ST_R)\
 -DXCOVER_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_ST_R)



# AR Args

AR_ARGS             =   


# LD flags

LD_F_NOLOGO				=   

LD_FLAGS_BASE =\
 $(LD_F_NOLOGO)\
 \

LD_FLAGS_MT_D =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_MT_R =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_ST_D =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_ST_R =\
 $(LD_FLAGS_BASE)\
 \


# LD includes

LD_INCLUDES_BASE =\
 $(LIBPATHS)\
 \

LD_INCLUDES_MT_D =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_MT_R =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_ST_D =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_ST_R =\
 $(LD_INCLUDES_BASE)\
 \


# LD args

LD_ARGS_MT_D= $(LD_FLAGS_MT_D)  $(LD_INCLUDES_MT_D)
LD_ARGS_MT_R= $(LD_FLAGS_MT_R)  $(LD_INCLUDES_MT_R)
LD_ARGS_ST_D= $(LD_FLAGS_ST_D)  $(LD_INCLUDES_ST_D)
LD_ARGS_ST_R= $(LD_FLAGS_ST_R)  $(LD_INCLUDES_ST_R)

############################################################################
# Headers

CORE_HEADERS=\
 $(PROJ_INCLUDE_DIR)/xcover/xcover.h\
 $(PROJ_INCLUDE_DIR)/xcover/implicit_link.h\
 $(PROJ_INCLUDE_DIR)/xcover/internal/reporter.h\
 \

SHWILD_HEADERS=\
 $(PROJ_INCLUDE_DIR)/shwild/shwild.h\
 $(PROJ_INCLUDE_DIR)/shwild/shwild.hpp\
 \

XTESTS_HEADERS=\
 $(PROJ_INCLUDE_DIR)/xtests/xtests.h\
 \

############################################################################
# Names

############################################################
# Targets

########################################
# Libraries

# xCover
LIB_CORE_MT_D				=	$(PROJ_LIB_DIR)/lib$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).mt.debug.a
LIB_CORE_MT_R				=	$(PROJ_LIB_DIR)/lib$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).mt.a
LIB_CORE_ST_D				=	$(PROJ_LIB_DIR)/lib$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).debug.a
LIB_CORE_ST_R				=	$(PROJ_LIB_DIR)/lib$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).a

# shwild - testing only
LIB_SHWILD_MT_D			=	$(PROJ_LIB_DIR)/lib$(SHWILD_TAG_VER).xcvr.$(COMP_ARCH_OS_TAG).mt.debug.a
LIB_SHWILD_MT_R			=	$(PROJ_LIB_DIR)/lib$(SHWILD_TAG_VER).xcvr.$(COMP_ARCH_OS_TAG).mt.a
LIB_SHWILD_ST_D			=	$(PROJ_LIB_DIR)/lib$(SHWILD_TAG_VER).xcvr.$(COMP_ARCH_OS_TAG).debug.a
LIB_SHWILD_ST_R			=	$(PROJ_LIB_DIR)/lib$(SHWILD_TAG_VER).xcvr.$(COMP_ARCH_OS_TAG).a

# xtests - unit/component testing only
LIB_XTESTS_MT_D			=	$(PROJ_LIB_DIR)/lib$(XTESTS_TAG_VER).xcvr.$(COMP_ARCH_OS_TAG).mt.debug.a
LIB_XTESTS_MT_R			=	$(PROJ_LIB_DIR)/lib$(XTESTS_TAG_VER).xcvr.$(COMP_ARCH_OS_TAG).mt.a
LIB_XTESTS_ST_D			=	$(PROJ_LIB_DIR)/lib$(XTESTS_TAG_VER).xcvr.$(COMP_ARCH_OS_TAG).debug.a
LIB_XTESTS_ST_R			=	$(PROJ_LIB_DIR)/lib$(XTESTS_TAG_VER).xcvr.$(COMP_ARCH_OS_TAG).a

########################################
# Examples



########################################
# Tests


##############################
# Component Tests

OBJ_TEST_COMP_c_1_MT_D	=   $(PROJ_OBJ_DIR)/test.component.c.1.mt.debug.o
OBJ_TEST_COMP_c_1_MT_R	=   $(PROJ_OBJ_DIR)/test.component.c.1.mt.o
OBJ_TEST_COMP_c_1_ST_D	=   $(PROJ_OBJ_DIR)/test.component.c.1.debug.o
OBJ_TEST_COMP_c_1_ST_R	=   $(PROJ_OBJ_DIR)/test.component.c.1.o

##############################
# Scratch Tests

OBJ_TEST_SCRT_c_1_MT_D = $(PROJ_OBJ_DIR)/test.scratch.c.1.mt.debug.o
OBJ_TEST_SCRT_c_1_a_MT_D = $(PROJ_OBJ_DIR)/test.scratch.c.1.api.1.a.mt.debug.o
OBJ_TEST_SCRT_c_1_b_MT_D = $(PROJ_OBJ_DIR)/test.scratch.c.1.api.1.b.mt.debug.o
OBJ_TEST_SCRT_c_1_MT_R = $(PROJ_OBJ_DIR)/test.scratch.c.1.mt.o
OBJ_TEST_SCRT_c_1_a_MT_R = $(PROJ_OBJ_DIR)/test.scratch.c.1.api.1.a.mt.o
OBJ_TEST_SCRT_c_1_b_MT_R = $(PROJ_OBJ_DIR)/test.scratch.c.1.api.1.b.mt.o
OBJ_TEST_SCRT_c_1_ST_D = $(PROJ_OBJ_DIR)/test.scratch.c.1.debug.o
OBJ_TEST_SCRT_c_1_a_ST_D = $(PROJ_OBJ_DIR)/test.scratch.c.1.api.1.a.debug.o
OBJ_TEST_SCRT_c_1_b_ST_D = $(PROJ_OBJ_DIR)/test.scratch.c.1.api.1.b.debug.o
OBJ_TEST_SCRT_c_1_ST_R = $(PROJ_OBJ_DIR)/test.scratch.c.1.o
OBJ_TEST_SCRT_c_1_a_ST_R = $(PROJ_OBJ_DIR)/test.scratch.c.1.api.1.a.o
OBJ_TEST_SCRT_c_1_b_ST_R = $(PROJ_OBJ_DIR)/test.scratch.c.1.api.1.b.o

OBJ_TEST_SCRT_mfe_MT_D =   $(PROJ_OBJ_DIR)/test.scratch.mark_file_end.mt.debug.o
OBJ_TEST_SCRT_mfe_cex1_MT_D =   $(PROJ_OBJ_DIR)/test.scratch.mark_file_end.cex1.mt.debug.o
OBJ_TEST_SCRT_mfe_MT_R =   $(PROJ_OBJ_DIR)/test.scratch.mark_file_end.mt.o
OBJ_TEST_SCRT_mfe_cex1_MT_R =   $(PROJ_OBJ_DIR)/test.scratch.mark_file_end.cex1.mt.o
OBJ_TEST_SCRT_mfe_ST_D =   $(PROJ_OBJ_DIR)/test.scratch.mark_file_end.debug.o
OBJ_TEST_SCRT_mfe_cex1_ST_D =   $(PROJ_OBJ_DIR)/test.scratch.mark_file_end.cex1.debug.o
OBJ_TEST_SCRT_mfe_ST_R =   $(PROJ_OBJ_DIR)/test.scratch.mark_file_end.o
OBJ_TEST_SCRT_mfe_cex1_ST_R =   $(PROJ_OBJ_DIR)/test.scratch.mark_file_end.cex1.o

############################################################
# Objects

########################################
# Libraries

# core

OBJ_lib_core_MT_D =	$(PROJ_OBJ_DIR)/core.mt.debug.o

OBJ_LIB_CORE_MT_D=\
 $(OBJ_lib_core_MT_D)\
 \

OBJ_lib_core_MT_R =	$(PROJ_OBJ_DIR)/core.mt.o

OBJ_LIB_CORE_MT_R=\
 $(OBJ_lib_core_MT_R)\
 \

OBJ_lib_core_ST_D =	$(PROJ_OBJ_DIR)/core.debug.o

OBJ_LIB_CORE_ST_D=\
 $(OBJ_lib_core_ST_D)\
 \

OBJ_lib_core_ST_R =	$(PROJ_OBJ_DIR)/core.o

OBJ_LIB_CORE_ST_R=\
 $(OBJ_lib_core_ST_R)\
 \


# shwild

OBJ_shw_api_MT_D            = $(PROJ_OBJ_DIR)/shwild.pan.api.mt.debug.o
OBJ_shw_matches_MT_D        = $(PROJ_OBJ_DIR)/shwild.pan.matches.mt.debug.o
OBJ_shw_pattern_MT_D        = $(PROJ_OBJ_DIR)/shwild.pan.pattern.mt.debug.o

OBJ_SHWILD_MT_D=\
 $(OBJ_shw_api_MT_D)\
 $(OBJ_shw_matches_MT_D)\
 $(OBJ_shw_pattern_MT_D)\
 \

OBJ_shw_api_MT_R            = $(PROJ_OBJ_DIR)/shwild.pan.api.mt.o
OBJ_shw_matches_MT_R        = $(PROJ_OBJ_DIR)/shwild.pan.matches.mt.o
OBJ_shw_pattern_MT_R        = $(PROJ_OBJ_DIR)/shwild.pan.pattern.mt.o

OBJ_SHWILD_MT_R=\
 $(OBJ_shw_api_MT_R)\
 $(OBJ_shw_matches_MT_R)\
 $(OBJ_shw_pattern_MT_R)\
 \

OBJ_shw_api_ST_D            = $(PROJ_OBJ_DIR)/shwild.pan.api.debug.o
OBJ_shw_matches_ST_D        = $(PROJ_OBJ_DIR)/shwild.pan.matches.debug.o
OBJ_shw_pattern_ST_D        = $(PROJ_OBJ_DIR)/shwild.pan.pattern.debug.o

OBJ_SHWILD_ST_D=\
 $(OBJ_shw_api_ST_D)\
 $(OBJ_shw_matches_ST_D)\
 $(OBJ_shw_pattern_ST_D)\
 \

OBJ_shw_api_ST_R            = $(PROJ_OBJ_DIR)/shwild.pan.api.o
OBJ_shw_matches_ST_R        = $(PROJ_OBJ_DIR)/shwild.pan.matches.o
OBJ_shw_pattern_ST_R        = $(PROJ_OBJ_DIR)/shwild.pan.pattern.o

OBJ_SHWILD_ST_R=\
 $(OBJ_shw_api_ST_R)\
 $(OBJ_shw_matches_ST_R)\
 $(OBJ_shw_pattern_ST_R)\
 \


# xtests

OBJ_xts_core_MT_D           = $(PROJ_OBJ_DIR)/xtests.ff.core.api.mt.debug.o

OBJ_XTESTS_MT_D = \
 $(OBJ_xts_core_MT_D)\
 \

OBJ_xts_core_MT_R           = $(PROJ_OBJ_DIR)/xtests.ff.core.api.mt.o

OBJ_XTESTS_MT_R = \
 $(OBJ_xts_core_MT_R)\
 \

OBJ_xts_core_ST_D           = $(PROJ_OBJ_DIR)/xtests.ff.core.api.debug.o

OBJ_XTESTS_ST_D = \
 $(OBJ_xts_core_ST_D)\
 \

OBJ_xts_core_ST_R           = $(PROJ_OBJ_DIR)/xtests.ff.core.api.o

OBJ_XTESTS_ST_R = \
 $(OBJ_xts_core_ST_R)\
 \


########################################
# Examples



########################################
# Tests

##############################
# Component Tests

TARG_TEST_COMP_c_1_MT_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.component.c.1.$(COMP_TAG).mt.debug
TARG_TEST_COMP_c_1_MT_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.component.c.1.$(COMP_TAG).mt
TARG_TEST_COMP_c_1_ST_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.component.c.1.$(COMP_TAG).debug
TARG_TEST_COMP_c_1_ST_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.component.c.1.$(COMP_TAG)

##############################
# Scratch Tests

TARG_TEST_SCRT_c_1_MT_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.c.1.$(COMP_TAG).mt.debug
TARG_TEST_SCRT_c_1_MT_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.c.1.$(COMP_TAG).mt
TARG_TEST_SCRT_c_1_ST_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.c.1.$(COMP_TAG).debug
TARG_TEST_SCRT_c_1_ST_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.c.1.$(COMP_TAG)

TARG_TEST_SCRT_mfe_MT_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.mark_file_end.$(COMP_TAG).mt.debug
TARG_TEST_SCRT_mfe_MT_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.mark_file_end.$(COMP_TAG).mt
TARG_TEST_SCRT_mfe_ST_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.mark_file_end.$(COMP_TAG).debug
TARG_TEST_SCRT_mfe_ST_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.mark_file_end.$(COMP_TAG)

##############################
# Unit Tests


# Target groups

########################################
# Objects

# core
OBJS_CORE=\
# $(OBJ_UTIL_MT_D)\
 $(OBJ_CORE_MT_D)\
# $(OBJ_UTIL_MT_R)\
 $(OBJ_CORE_MT_R)\
# $(OBJ_UTIL_ST_D)\
 $(OBJ_CORE_ST_D)\
# $(OBJ_UTIL_ST_R)\
 $(OBJ_CORE_ST_R)\
 \

# shwild
OBJS_SHWILD=\
 $(OBJ_SHWILD_MT_D)\
 $(OBJ_SHWILD_MT_R)\
 $(OBJ_SHWILD_ST_D)\
 $(OBJ_SHWILD_ST_R)\
 \

# examples
OBJS_EXAMPLE=\
 \

# Component Tests
OBJS_TEST_COMPONENT=\
 $(OBJ_TEST_COMP_c_1_MT_D)\
 $(OBJ_TEST_COMP_c_1_MT_R)\
 $(OBJ_TEST_COMP_c_1_ST_D)\
 $(OBJ_TEST_COMP_c_1_ST_R)\
 \

# Scratch Tests
OBJS_TEST_SCRATCH=\
 $(OBJ_TEST_SCRT_c_1_MT_D)\
 $(OBJ_TEST_SCRT_c_1_a_MT_D)\
 $(OBJ_TEST_SCRT_c_1_b_MT_D)\
 $(OBJ_TEST_SCRT_mfe_MT_D)\
 $(OBJ_TEST_SCRT_mfe_cex1_MT_D)\
 $(OBJ_TEST_SCRT_c_1_MT_R)\
 $(OBJ_TEST_SCRT_c_1_a_MT_R)\
 $(OBJ_TEST_SCRT_c_1_b_MT_R)\
 $(OBJ_TEST_SCRT_mfe_MT_R)\
 $(OBJ_TEST_SCRT_mfe_cex1_MT_R)\
 $(OBJ_TEST_SCRT_c_1_ST_D)\
 $(OBJ_TEST_SCRT_c_1_a_ST_D)\
 $(OBJ_TEST_SCRT_c_1_b_ST_D)\
 $(OBJ_TEST_SCRT_mfe_ST_D)\
 $(OBJ_TEST_SCRT_mfe_cex1_ST_D)\
 $(OBJ_TEST_SCRT_c_1_ST_R)\
 $(OBJ_TEST_SCRT_c_1_a_ST_R)\
 $(OBJ_TEST_SCRT_c_1_b_ST_R)\
 $(OBJ_TEST_SCRT_mfe_ST_R)\
 $(OBJ_TEST_SCRT_mfe_cex1_ST_R)\
 \

# Unit Tests
OBJS_TEST_UNIT=\
 \

########################################
# Libraries

TARGETS_LIB_CORE=\
 $(LIB_CORE_MT_D)\
 $(LIB_CORE_MT_R)\
 $(LIB_CORE_ST_D)\
 $(LIB_CORE_ST_R)\
 \

TARGETS_LIB_ALL=\
 $(TARGETS_LIB_CORE)\
 \

TARGETS_LIB_SHWILD=\
 $(LIB_SHWILD_MT_D)\
 $(LIB_SHWILD_MT_R)\
 $(LIB_SHWILD_ST_D)\
 $(LIB_SHWILD_ST_R)\
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
 $(TARG_TEST_COMP_c_1_MT_D)\
 $(TARG_TEST_COMP_c_1_MT_R)\
 $(TARG_TEST_COMP_c_1_ST_D)\
 $(TARG_TEST_COMP_c_1_ST_R)\
 \

TARGETS_TEST_SCRATCH=\
 $(TARG_TEST_SCRT_c_1_MT_D)\
 $(TARG_TEST_SCRT_mfe_MT_D)\
 $(TARG_TEST_SCRT_c_1_MT_R)\
 $(TARG_TEST_SCRT_mfe_MT_R)\
 $(TARG_TEST_SCRT_c_1_ST_D)\
 $(TARG_TEST_SCRT_mfe_ST_D)\
 $(TARG_TEST_SCRT_c_1_ST_R)\
 $(TARG_TEST_SCRT_mfe_ST_R)\
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
	@-mkdir -p $(PROJ_LIB_DIR)

check.bin.dir:				$(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_BIN_DIR)


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
	$(TARG_TEST_SCRT_c_1_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_c_1_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_c_1_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_c_1_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_mfe_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_mfe_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_mfe_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_mfe_ST_R) --verbosity=$(TEST_VERBOSITY)

test.unit_:
	@echo Running Test:Unit programs ...

test.component:			$(PROJ_MAKEFILE_NAME)	build.test.component test.component_
	$(TARG_TEST_COMP_c_1_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_c_1_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_c_1_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_c_1_ST_R) --verbosity=$(TEST_VERBOSITY)

test.scratch:			$(PROJ_MAKEFILE_NAME)	build.test.scratch test.scratch_

test.unit:				$(PROJ_MAKEFILE_NAME)	build.test.unit test.unit_

test:											test.unit test.component

test.all:										test test.scratch
test-all:				test.all


# clean targets

clean.libs.core:
	@echo Cleaning Core libraries ...
	@-$(RM) $(LIB_CORE_MT_D)
	@-$(RM) $(LIB_UTIL_MT_D)
	@-$(RM) $(LIB_CORE_MT_R)
	@-$(RM) $(LIB_UTIL_MT_R)
	@-$(RM) $(LIB_CORE_ST_D)
	@-$(RM) $(LIB_UTIL_ST_D)
	@-$(RM) $(LIB_CORE_ST_R)
	@-$(RM) $(LIB_UTIL_ST_R)
	@-$(RM) $(OBJ_CORE_MT_D)
	@-$(RM) $(OBJ_UTIL_MT_D)
	@-$(RM) $(OBJ_CORE_MT_R)
	@-$(RM) $(OBJ_UTIL_MT_R)
	@-$(RM) $(OBJ_CORE_ST_D)
	@-$(RM) $(OBJ_UTIL_ST_D)
	@-$(RM) $(OBJ_CORE_ST_R)
	@-$(RM) $(OBJ_UTIL_ST_R)

clean.libs.shwild:
	@echo Cleaning shwild libraries ...
	@-$(RM) $(LIB_SHWILD_MT_D)
	@-$(RM) $(LIB_SHWILD_MT_R)
	@-$(RM) $(LIB_SHWILD_ST_D)
	@-$(RM) $(LIB_SHWILD_ST_R)
	@-$(RM) $(OBJ_SHWILD_MT_D)
	@-$(RM) $(OBJ_SHWILD_MT_R)
	@-$(RM) $(OBJ_SHWILD_ST_D)
	@-$(RM) $(OBJ_SHWILD_ST_R)

clean.test.component:
	@echo cleaning Test:Component libraries ...

clean.test.scratch:
	@echo cleaning Test:Scratch libraries ...
	@-$(RM) $(TARG_TEST_SCRT_c_1_MT_D)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_MT_D)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_a_MT_D)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_b_MT_D)
	@-$(RM) $(TARG_TEST_SCRT_mfe_MT_D)
	@-$(RM) $(OBJ_TEST_SCRT_mfe_MT_D)
	@-$(RM) $(OBJ_TEST_SCRT_mfe_cex1_MT_D)
	@-$(RM) $(TARG_TEST_SCRT_c_1_MT_R)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_MT_R)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_a_MT_R)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_b_MT_R)
	@-$(RM) $(TARG_TEST_SCRT_mfe_MT_R)
	@-$(RM) $(OBJ_TEST_SCRT_mfe_MT_R)
	@-$(RM) $(OBJ_TEST_SCRT_mfe_cex1_MT_R)
	@-$(RM) $(TARG_TEST_SCRT_c_1_ST_D)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_ST_D)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_a_ST_D)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_b_ST_D)
	@-$(RM) $(TARG_TEST_SCRT_mfe_ST_D)
	@-$(RM) $(OBJ_TEST_SCRT_mfe_ST_D)
	@-$(RM) $(OBJ_TEST_SCRT_mfe_cex1_ST_D)
	@-$(RM) $(TARG_TEST_SCRT_c_1_ST_R)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_ST_R)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_a_ST_R)
	@-$(RM) $(OBJ_TEST_SCRT_c_1_b_ST_R)
	@-$(RM) $(TARG_TEST_SCRT_mfe_ST_R)
	@-$(RM) $(OBJ_TEST_SCRT_mfe_ST_R)
	@-$(RM) $(OBJ_TEST_SCRT_mfe_cex1_ST_R)

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

$(LIB_SHWILD_MT_D): $(OBJ_SHWILD_MT_D) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) rcs $@ $(OBJ_SHWILD_MT_D)

$(OBJ_shw_api_MT_D): $(SHWILD_SRC_DIR)/api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -o $@ $(SHWILD_SRC_DIR)/api.cpp
$(OBJ_shw_matches_MT_D): $(SHWILD_SRC_DIR)/matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -o $@ $(SHWILD_SRC_DIR)/matches.cpp
$(OBJ_shw_pattern_MT_D): $(SHWILD_SRC_DIR)/pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -o $@ $(SHWILD_SRC_DIR)/pattern.cpp

$(LIB_SHWILD_MT_R): $(OBJ_SHWILD_MT_R) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) rcs $@ $(OBJ_SHWILD_MT_R)

$(OBJ_shw_api_MT_R): $(SHWILD_SRC_DIR)/api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -o $@ $(SHWILD_SRC_DIR)/api.cpp
$(OBJ_shw_matches_MT_R): $(SHWILD_SRC_DIR)/matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -o $@ $(SHWILD_SRC_DIR)/matches.cpp
$(OBJ_shw_pattern_MT_R): $(SHWILD_SRC_DIR)/pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -o $@ $(SHWILD_SRC_DIR)/pattern.cpp

$(LIB_SHWILD_ST_D): $(OBJ_SHWILD_ST_D) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) rcs $@ $(OBJ_SHWILD_ST_D)

$(OBJ_shw_api_ST_D): $(SHWILD_SRC_DIR)/api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) $(CPPC_SHWILD_INCLUDES_ST_D) -o $@ $(SHWILD_SRC_DIR)/api.cpp
$(OBJ_shw_matches_ST_D): $(SHWILD_SRC_DIR)/matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) $(CPPC_SHWILD_INCLUDES_ST_D) -o $@ $(SHWILD_SRC_DIR)/matches.cpp
$(OBJ_shw_pattern_ST_D): $(SHWILD_SRC_DIR)/pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) $(CPPC_SHWILD_INCLUDES_ST_D) -o $@ $(SHWILD_SRC_DIR)/pattern.cpp

$(LIB_SHWILD_ST_R): $(OBJ_SHWILD_ST_R) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) rcs $@ $(OBJ_SHWILD_ST_R)

$(OBJ_shw_api_ST_R): $(SHWILD_SRC_DIR)/api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) $(CPPC_SHWILD_INCLUDES_ST_R) -o $@ $(SHWILD_SRC_DIR)/api.cpp
$(OBJ_shw_matches_ST_R): $(SHWILD_SRC_DIR)/matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) $(CPPC_SHWILD_INCLUDES_ST_R) -o $@ $(SHWILD_SRC_DIR)/matches.cpp
$(OBJ_shw_pattern_ST_R): $(SHWILD_SRC_DIR)/pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) $(CPPC_SHWILD_INCLUDES_ST_R) -o $@ $(SHWILD_SRC_DIR)/pattern.cpp

########################################
# xTests library - 'xtests.X.xcvr.core.a'

$(LIB_XTESTS_MT_D): $(OBJ_XTESTS_MT_D) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) rcs $@ $(OBJ_XTESTS_MT_D)

$(OBJ_xts_core_MT_D): $(XTESTS_SRC_DIR)/xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_XTESTS_INCLUDES_MT_D) -o $@ $(XTESTS_SRC_DIR)/xtests.core.cpp

$(LIB_XTESTS_MT_R): $(OBJ_XTESTS_MT_R) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) rcs $@ $(OBJ_XTESTS_MT_R)

$(OBJ_xts_core_MT_R): $(XTESTS_SRC_DIR)/xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_XTESTS_INCLUDES_MT_R) -o $@ $(XTESTS_SRC_DIR)/xtests.core.cpp

$(LIB_XTESTS_ST_D): $(OBJ_XTESTS_ST_D) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) rcs $@ $(OBJ_XTESTS_ST_D)

$(OBJ_xts_core_ST_D): $(XTESTS_SRC_DIR)/xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) $(CPPC_XTESTS_INCLUDES_ST_D) -o $@ $(XTESTS_SRC_DIR)/xtests.core.cpp

$(LIB_XTESTS_ST_R): $(OBJ_XTESTS_ST_R) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) rcs $@ $(OBJ_XTESTS_ST_R)

$(OBJ_xts_core_ST_R): $(XTESTS_SRC_DIR)/xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) $(CPPC_XTESTS_INCLUDES_ST_R) -o $@ $(XTESTS_SRC_DIR)/xtests.core.cpp

########################################
# Main library - 'xcover.X.core.a'

$(LIB_CORE_MT_D): $(OBJ_LIB_CORE_MT_D) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) rcs $@ $(OBJ_LIB_CORE_MT_D)

$(OBJ_lib_core_MT_D):	$(PROJ_MAKEFILE_NAME) $(PROJ_SRC_DIR)/xcover.core.cpp
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_SRC_DIR)/xcover.core.cpp

$(LIB_CORE_MT_R): $(OBJ_LIB_CORE_MT_R) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) rcs $@ $(OBJ_LIB_CORE_MT_R)

$(OBJ_lib_core_MT_R):	$(PROJ_MAKEFILE_NAME) $(PROJ_SRC_DIR)/xcover.core.cpp
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_SRC_DIR)/xcover.core.cpp

$(LIB_CORE_ST_D): $(OBJ_LIB_CORE_ST_D) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) rcs $@ $(OBJ_LIB_CORE_ST_D)

$(OBJ_lib_core_ST_D):	$(PROJ_MAKEFILE_NAME) $(PROJ_SRC_DIR)/xcover.core.cpp
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_SRC_DIR)/xcover.core.cpp

$(LIB_CORE_ST_R): $(OBJ_LIB_CORE_ST_R) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) rcs $@ $(OBJ_LIB_CORE_ST_R)

$(OBJ_lib_core_ST_R):	$(PROJ_MAKEFILE_NAME) $(PROJ_SRC_DIR)/xcover.core.cpp
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_SRC_DIR)/xcover.core.cpp

##################################################
# Examples

##################################################
# Tests

##############################
# Component Tests

$(TARG_TEST_COMP_c_1_MT_D):	\
			$(OBJ_TEST_COMP_c_1_MT_D)\
			$(LIB_CORE_MT_D)\
			$(LIB_SHWILD_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_COMP_c_1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIBS_3PTY_TEST_COMPONENT)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_c_1_MT_D):	$(PROJ_TEST_COMPONENT_DIR)/test.component.c.1/test.component.c.1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)/test.component.c.1/test.component.c.1.c

$(TARG_TEST_COMP_c_1_MT_R):	\
			$(OBJ_TEST_COMP_c_1_MT_R)\
			$(LIB_CORE_MT_R)\
			$(LIB_SHWILD_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_COMP_c_1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIBS_3PTY_TEST_COMPONENT)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_c_1_MT_R):	$(PROJ_TEST_COMPONENT_DIR)/test.component.c.1/test.component.c.1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)/test.component.c.1/test.component.c.1.c

$(TARG_TEST_COMP_c_1_ST_D):	\
			$(OBJ_TEST_COMP_c_1_ST_D)\
			$(LIB_CORE_ST_D)\
			$(LIB_SHWILD_ST_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_COMP_c_1_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIBS_3PTY_TEST_COMPONENT)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_COMP_c_1_ST_D):	$(PROJ_TEST_COMPONENT_DIR)/test.component.c.1/test.component.c.1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)/test.component.c.1/test.component.c.1.c

$(TARG_TEST_COMP_c_1_ST_R):	\
			$(OBJ_TEST_COMP_c_1_ST_R)\
			$(LIB_CORE_ST_R)\
			$(LIB_SHWILD_ST_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_COMP_c_1_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIBS_3PTY_TEST_COMPONENT)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_COMP_c_1_ST_R):	$(PROJ_TEST_COMPONENT_DIR)/test.component.c.1/test.component.c.1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)/test.component.c.1/test.component.c.1.c

##############################
# Scratch Tests

$(TARG_TEST_SCRT_c_1_MT_D):	\
			$(OBJ_TEST_SCRT_c_1_MT_D)\
			$(OBJ_TEST_SCRT_c_1_a_MT_D)\
			$(OBJ_TEST_SCRT_c_1_b_MT_D)\
			$(LIB_CORE_MT_D)\
			$(LIB_SHWILD_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_SCRT_c_1_MT_D)\
		$(OBJ_TEST_SCRT_c_1_a_MT_D)\
		$(OBJ_TEST_SCRT_c_1_b_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_SCRT_c_1_MT_D):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/test.scratch.c.1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/test.scratch.c.1.c
$(OBJ_TEST_SCRT_c_1_a_MT_D):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.a.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.a.c
$(OBJ_TEST_SCRT_c_1_b_MT_D):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.b.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.b.c

$(TARG_TEST_SCRT_c_1_MT_R):	\
			$(OBJ_TEST_SCRT_c_1_MT_R)\
			$(OBJ_TEST_SCRT_c_1_a_MT_R)\
			$(OBJ_TEST_SCRT_c_1_b_MT_R)\
			$(LIB_CORE_MT_R)\
			$(LIB_SHWILD_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_SCRT_c_1_MT_R)\
		$(OBJ_TEST_SCRT_c_1_a_MT_R)\
		$(OBJ_TEST_SCRT_c_1_b_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_SCRT_c_1_MT_R):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/test.scratch.c.1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/test.scratch.c.1.c
$(OBJ_TEST_SCRT_c_1_a_MT_R):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.a.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.a.c
$(OBJ_TEST_SCRT_c_1_b_MT_R):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.b.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.b.c

$(TARG_TEST_SCRT_c_1_ST_D):	\
			$(OBJ_TEST_SCRT_c_1_ST_D)\
			$(OBJ_TEST_SCRT_c_1_a_ST_D)\
			$(OBJ_TEST_SCRT_c_1_b_ST_D)\
			$(LIB_CORE_ST_D)\
			$(LIB_SHWILD_ST_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_SCRT_c_1_ST_D)\
		$(OBJ_TEST_SCRT_c_1_a_ST_D)\
		$(OBJ_TEST_SCRT_c_1_b_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_SCRT_c_1_ST_D):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/test.scratch.c.1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/test.scratch.c.1.c
$(OBJ_TEST_SCRT_c_1_a_ST_D):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.a.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.a.c
$(OBJ_TEST_SCRT_c_1_b_ST_D):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.b.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.b.c

$(TARG_TEST_SCRT_c_1_ST_R):	\
			$(OBJ_TEST_SCRT_c_1_ST_R)\
			$(OBJ_TEST_SCRT_c_1_a_ST_R)\
			$(OBJ_TEST_SCRT_c_1_b_ST_R)\
			$(LIB_CORE_ST_R)\
			$(LIB_SHWILD_ST_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_SCRT_c_1_ST_R)\
		$(OBJ_TEST_SCRT_c_1_a_ST_R)\
		$(OBJ_TEST_SCRT_c_1_b_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_SCRT_c_1_ST_R):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/test.scratch.c.1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/test.scratch.c.1.c
$(OBJ_TEST_SCRT_c_1_a_ST_R):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.a.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.a.c
$(OBJ_TEST_SCRT_c_1_b_ST_R):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.b.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.c.1/api.1.b.c

$(TARG_TEST_SCRT_mfe_MT_D):	\
			$(OBJ_TEST_SCRT_mfe_MT_D)\
			$(OBJ_TEST_SCRT_mfe_cex1_MT_D)\
			$(LIB_CORE_MT_D)\
			$(LIB_SHWILD_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_SCRT_mfe_MT_D)\
		$(OBJ_TEST_SCRT_mfe_cex1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_SCRT_mfe_MT_D):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/test.scratch.mark_file_end.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/test.scratch.mark_file_end.cpp
$(OBJ_TEST_SCRT_mfe_cex1_MT_D):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/cex1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/cex1.c

$(TARG_TEST_SCRT_mfe_MT_R):	\
			$(OBJ_TEST_SCRT_mfe_MT_R)\
			$(OBJ_TEST_SCRT_mfe_cex1_MT_R)\
			$(LIB_CORE_MT_R)\
			$(LIB_SHWILD_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_SCRT_mfe_MT_R)\
		$(OBJ_TEST_SCRT_mfe_cex1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_SCRT_mfe_MT_R):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/test.scratch.mark_file_end.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/test.scratch.mark_file_end.cpp
$(OBJ_TEST_SCRT_mfe_cex1_MT_R):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/cex1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/cex1.c

$(TARG_TEST_SCRT_mfe_ST_D):	\
			$(OBJ_TEST_SCRT_mfe_ST_D)\
			$(OBJ_TEST_SCRT_mfe_cex1_ST_D)\
			$(LIB_CORE_ST_D)\
			$(LIB_SHWILD_ST_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_SCRT_mfe_ST_D)\
		$(OBJ_TEST_SCRT_mfe_cex1_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_SCRT_mfe_ST_D):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/test.scratch.mark_file_end.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/test.scratch.mark_file_end.cpp
$(OBJ_TEST_SCRT_mfe_cex1_ST_D):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/cex1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/cex1.c

$(TARG_TEST_SCRT_mfe_ST_R):	\
			$(OBJ_TEST_SCRT_mfe_ST_R)\
			$(OBJ_TEST_SCRT_mfe_cex1_ST_R)\
			$(LIB_CORE_ST_R)\
			$(LIB_SHWILD_ST_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_SCRT_mfe_ST_R)\
		$(OBJ_TEST_SCRT_mfe_cex1_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_SCRT_mfe_ST_R):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/test.scratch.mark_file_end.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/test.scratch.mark_file_end.cpp
$(OBJ_TEST_SCRT_mfe_cex1_ST_R):	$(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/cex1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.mark_file_end/cex1.c

##############################
# Unit Tests

############################### end of file ################################
