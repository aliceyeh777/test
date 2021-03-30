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
#* makefile
#*
#* \brief
#* biuild dynamic library
#*
#* \date
#* 2021/03/26
#*
#* \author
#* Alice Yeh
#*
#**********************************************************************
include compile.mk
TARGET  = libjpegquery

$(TARGET) : $(OBJ)
	$(AR) rcs $@.a $^ 
	mv $@.a $(BIN_DIR)

%.o : %.c
	$(CC) $(CFLAGS) $(CINCS) -c $< -o $@

all:
	make clean
	make
	make install
		
install:
	$(STRIP) $(BIN_DIR)/*.a

clean:
	rm -f $(BIN_DIR)/*.a $(SRC_DIR)/*.o
