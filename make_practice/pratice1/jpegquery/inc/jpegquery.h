/*
 *******************************************************************************
 * $Header: $
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
 * $History: $
 *
 */

/*!
 *******************************************************************************
 * Copyright 2000-2021 Vivotek, Inc. All rights reserved.
 *
 * \file
 * jpegquery.h
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
 *
 *******************************************************************************
*/
#ifndef __JPEGQUERY_H__
#define __JPEGQUERY_H__

#if 0
// --------------------- function brief ----------------------------------------
int JpegQuery_Info(FILE *pfRead, unsigned int *puiImageWidth, unsigned int *puiImageHeight, unsigned int *puiColorComponents)
#endif

/*!
 ******************************************************************************
 * \brief
 * Query Wdith and Height and number of color components from Jpeg file  
 *
 * \param pfRead
 * \a (i) a FILE pointer.
 *
 * \param puiImageWidth
 * \a (o) a pointer to receive the Image Width.
 *
 * \param *puiImageHeight
 * \a (o) a pointer to receive the Image Height.
 *
 * \param *puiColorComponents
 * \a (o) a pointer to receive the number of color components.
 *
 * \retval 0
 * Get Jpeg information success
 *
 * \retval non-zero
 * Get Jpeg information fail
 *
 * \remark
 * NONE
 *
 ******************************************************************************
 */
int JpegQuery_Info(FILE *pfRead, unsigned int *puiImageWidth, unsigned int *puiImageHeight, unsigned int *puiColorComponents);
#endif //__JPEGQUERY_H__
