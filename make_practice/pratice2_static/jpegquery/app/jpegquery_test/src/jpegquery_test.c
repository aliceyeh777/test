/*
   *******************************************************************************
   *
   *  Copyright (c) 2000-2021 Vivotek Inc. All rights reserved.
   *
   *  +-----------------------------------------------------------------+
   *  | THIS SOFTWARE IS FURNISHED UNDER A LICENSE AND MAY ONLY BE USED |
   *  | AND COPIED IN ACCORDANCE WITH THE TERMS AND CONDITIONS OF SUCH  |
   *  | A LICENSE AND WITH THE INCLUSION OF THE THIS COPY RIGHT NOTICE. |
   *  | THIS SOFTWARE OR ANY OTHER COPIES OF THIS SOFTWARE MAY NOT BE   |
   *  | PROVIDED OR OTHERWISE MADE AVAILABLE TO ANY OTHER PERSON. THE   |
   *  | OWNERSHIP AND TITLE OF THIS SOFTWARE IS NOT TRANSFERRED.        |
   *  |                                                                 |
   *  | THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE WITHOUT   |
   *  | ANY PRIOR NOTICE AND SHOULD NOT BE CONSTRUED AS A COMMITMENT BY |
   *  | VIVOTEK INC.                                                    |
   *  +-----------------------------------------------------------------+
   *
   * $History$
   *
   *
   *******************************************************************************
   */


/*!
  *******************************************************************************
  * Copyright 2000-2021 Vivotek, Inc. All rights reserved.
  *
  * \file
  * jpegquery_test.c
  *
  * \brief
  * Sample Code of Jpeg query information library 
  *
  * \date
  * 2021/03/28
  *
  * \author
  * Alice Yeh
  *
  *******************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <jpegquery.h>
//-------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    FILE *pfRead;
    unsigned int uiImageWidth = 0, uiImageHeight = 0, uiColorComponents = 0;

    if (argc < 2)
    {
        printf("Please enter the path of the Jpeg file\n");
        return -1;
    }

    if ((pfRead = fopen(argv[1], "rb")) == NULL)
    {
        printf("Can't open file:%s\n", argv[1]);
        return -1;
    }
    
     if (JpegQuery_Info(pfRead, &uiImageWidth, &uiImageHeight, &uiColorComponents) != 0)
    {
        printf("Not a Jpeg file\n");    
    }
    else
    {
        printf("imageHeight:%d\n", uiImageHeight);
        printf("imageWidth: %d\n", uiImageWidth);
        printf("number of color components: %d\n", uiColorComponents);
    }

    fclose(pfRead);
    return 0;
}
