#/*
#**********************************************************************
#* $Header$
#*
#*  Copyright (c) 2000-2021 Vivotek Inc. All rights reserved.
#*
#*  +-----------------------------------------------------------------+
#*  | THIS SOFTWARE IS FURNISHED UNDER A LICENSE AND MAY ONLY BE USED |
#*  | AND COPIED IN ACCORDANCE WITH THE TERMS AND CONDITIONS OF SUCH  |
#*  | A LICENSE AND WITH THE INCLUSION OF THE THIS COPY RIGHT NOTICE. |
#*  | THIS SOFTWARE OR ANY OTHER COPIES OF THIS SOFTWARE MAY NOT BE   |
#*  | PROVIDED OR OTHERWISE MADE AVAILABLE TO ANY OTHER PERSON. THE   |
#*  | OWNERSHIP AND TITLE OF THIS SOFTWARE IS NOT TRANSFERRED.        |
#*  |                                                                 |
#*  | THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE WITHOUT   |
#*  | ANY PRIOR NOTICE AND SHOULD NOT BE CONSTRUED AS A COMMITMENT BY |
#*  | VIVOTEK INC.                                                    |
#*  +-----------------------------------------------------------------+
#*
#* $History$
#***********************************************************************
#* Copyright 2000-2003 Vivotek, Inc. All rights reserved.
#*
#* \file
#* complie.mk
#*
#* \brief
#* application for makefile inclusion
#*
#* \date
#* 2021/03/26
#*
#* \author
#* Alice Yeh
#*
#**********************************************************************

ifeq "$(PLATFORM)" "AMBA"
    CROSS_COMPILE=aarch64-linux-
	TOOLCHAIN=/opt/Vivotek/lsp/amcv2x/linaro-aarch64-2018.08-gcc8.2
	PATH:= $(PATH):$(TOOLCHAIN)/bin
endif

SRC_DIR        := ./src
INC_DIR        := ./inc
BIN_DIR        := ./bin
LIB_INC_DIR    := ../../jpegquery_info/inc
LIBS_DIR       := ../../jpegquery_info/bin
CINCS          := -I$(INC_DIR) -I$(LIB_INC_DIR)
SRC            := $(wildcard $(SRC_DIR)/*.c)
OBJ            := $(SRC:%.c=%.o)
LIBS           := $(wildcard $(LIBS_DIR)/*.a)

AS             := $(CROSS_COMPILE)as
AR             := $(CROSS_COMPILE)ar
CC             := $(CROSS_COMPILE)gcc
STRIP          := $(CROSS_COMPILE)strip
CFLAGS         := -Wall -O3
