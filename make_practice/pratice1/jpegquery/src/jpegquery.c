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
  * jpegquery.c
  *
  * \brief
  * Query Wdith and Height and number of color components from Jpeg file 
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
//-------------------------------------------------------------------------------
#define READ_BYTE(a,b)\
    do\
    {\
        if(((a)=getc((b))) == EOF)\
        {\
            return -1;\
        }\
    }\
    while (0)

#define READ_WORD(a,b)\
    do\
    {\
        int cc_=0,dd_=0; \
        if((cc_=getc((b))) == EOF || (dd_=getc((b))) == EOF)\
        {\
            return -1; \
        }\
        (a) = (cc_<<8) + (dd_); \
    }\
    while(0) 

#define MARKER_SOI      0xFFD8
#define MARKER_EOI        0xFFD9
#define MARKER_SOF0        0xFFC0
#define MARKER_SOF0_L    0xC0
//-------------------------------------------------------------------------------
int JpegQuery_Info(FILE *pfRead, unsigned int *puiImageWidth, unsigned int *puiImageHeight, unsigned int *puiColorComponents)
{
    unsigned int uiMarker=0;
    unsigned int uiDummy=0;
    unsigned int uiLen = 0;
    int uiFindMarker = 0;

    if (pfRead == NULL || puiImageWidth == NULL || puiImageHeight == NULL || puiColorComponents == NULL)
    {
        return -1;
    }
    
    if (fseek(pfRead, 0, SEEK_SET) != 0)
    {
        return -1;
    }

    READ_WORD(uiDummy, pfRead);
    //SOI
    if (uiDummy != MARKER_SOI)
    {
        return -1;
    }

    if (fseek(pfRead, -2, SEEK_END) != 0)
    {
        return -1;
    }

    READ_WORD(uiDummy, pfRead);
    //EOI
    if (uiDummy != MARKER_EOI)
    {
        return -1;
    }

    if (fseek(pfRead, 2, SEEK_SET) != 0)
    {
        return -1;
    }

    while(uiFindMarker == 0)
    {
        READ_BYTE(uiMarker, pfRead);
        if (uiMarker != 0xFF)
        {
            continue;
        }

        READ_BYTE(uiMarker, pfRead);
        if (uiMarker == 0x00 || uiMarker == 0xFF)
        {
            continue;
        }
        
        switch (uiMarker)
        {
            case MARKER_SOF0_L:
                 READ_WORD(uiLen,pfRead);    /* usual parameter uiLen count */
                READ_BYTE(uiDummy,pfRead); /* per pixel */
                READ_WORD((*puiImageHeight), pfRead); /* image height */
                READ_WORD((*puiImageWidth), pfRead); /* image width */
                READ_BYTE((*puiColorComponents), pfRead); /* number of components*/
                uiFindMarker = 1; 
            break;

            default:
                 READ_WORD(uiLen,pfRead);
                if (uiLen < 2)
                {
                    uiFindMarker = -1;
                }
                else
                {
                    uiLen -= 2;
                    while (uiLen > 0)
                    {
                        READ_BYTE(uiDummy, pfRead);
                        uiLen--;
                    }    
                }
            break;
        }
    }

    if (uiFindMarker == 1)
    {
        return 0;
    }

    return -1;
}
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

