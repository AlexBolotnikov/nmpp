//------------------------------------------------------------------------
//
//  $Workfile:: iFiltration.h                $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/02/10 12:36:38 $
//
//! \if file_doc
//!
//! \file   vFilter.h
//! \author ������ �������
//! \brief  ����������� ������� ���������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------

#ifndef _IFILTRATION_H_INCLUDED_
#define _IFILTRATION_H_INCLUDED_

#include "iFilter.h"
//*****************************************************************************

    /**
	\internal
    \defgroup IMG_Median3x3 IMG_Median3x3
    \ingroup iFiltration
 	\brief
		\ru ��������� ���������� ����� 3�3
		\en Median filtration by 3x3 window

		\~
	\~
	\param pSrc
        \ru �������� �����������. 
        \en Input image. 
		\~
	\param *pDst
        \ru �������������� �����������; 
        \en Output image. 
		\~
	\param nWidth
        \ru ������ �����������; ��������� �������� �������� ����.
        \en Image width; 
		\~
	\param nHeight
        \ru ������ ����������� [32,64,96....]. 
        \en Image height [32,64,96....]. 
		\~
	\param pLTmp
        \ru ��������� �����  �������  nm64s[3*nHeight] �� ��������� ����. 
        \en Temporary buffer with size of nm64s[3*nHeight] on local bus. 
		\~
	\param pGTmp
        \ru ��������� �����  �������  nm64s[3*nHeight] �� ���������� ����. 
        \en Temporary buffer with size of nm64s[3*nHeight] on global bus. 
		
		\~
	\par
    \xmlonly
			<testperf> 
					 <param> pSrc </param> <values> L G </values>
					 <param> pDst </param> <values> L G </values>
					 <param> pLTmp </param> <values> L G </values>
					 <param> pGTmp </param> <values> L G </values>
					 <param> nWidth </param> <values>  128 512 </values>
					 <param> nHeight </param> <values> 128 512 </values>
					 <size> nWidth*nHeight </size>
			</testperf>
	\endxmlonly
	*/
    //! \{
void IMG_Median3x3(  nm8s7b * pSrc, nm8s7b *pDst, int nWidth, int nHeight, void* pLTmp , void* pGTmp );
    //! \}





#endif // _IFILTER_H_INCLUDED_


