//------------------------------------------------------------------------
//
//  $Workfile:: sConvolution. $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/01/12 14:09:07 $
//
//! \if file_doc
//!
//! \file   vConvolution.h
//! \author ������ �������
//! \brief  ����������� ������� ���������� �������.
//!
//! \endif
//!
//------------------------------------------------------------------------

#ifndef _SCONVOLUTION_H_INCLUDED_
#define _SCONVOLUTION_H_INCLUDED_
#include "nmtype.h"

//*****************************************************************************

    /**
    \defgroup SIG_XCorr SIG_XCorr
    \ingroup sConvolution
    \brief
        \ru ������� ���� ��������. 
        \en Two vectors convolution. 
    
		\~
    
	\f[
        DstVec_i  = \sum \limits_{j = 0}^{nKernelSize - 1} pSrcVec[i + j]  \cdot pKernel[j] 
    \f]
    
	\f[
        i = \overline{0 \ldots nSrcVecSize-nKernelSize+1}
    \f]
    
    \param	pSrcVec		
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param	pKernel		
        \ru ������ ������������� ���� �������. 
        \en Vector of convolution window coefficients. 
		\~
    \param	pTmpBuf		\ru ��������� �� ��������� ������ ������� 
                            2*nKernelSize + 32 32-������ ����;\n 
                        \en Pointer to a temporary buffer sized
		\~
                            2*nKernelSize + 32 32-bit words;\n 
    \param	nKernelSize	
        \ru ������ ���� �������  [1,2,3,4...nSrcVecSize-1]. 
        \en Convolution window size.  [1,2,3,4...nSrcVecSize-1]. 
		\~
    \param	nSrcVecSize	
        \ru ������ �������� ������� � ��������� .������ ������ 8,4 ��� 2 �������� ���� ������. 
        \en Input vec size in elements. 
		\~
    \retval	pDstVec		
        \ru �������������� ������, �������� nSrcVecSize-nKernelSize+1. ����� �������� ����� ������������  ��� �� 7 ���������� 32� �����.
        \en The result vec. 
		\~
    \note
        \ru �� ���� ������� ������������ ���������� ������ ����� �������.
        \en As a matter of fact the functions filter data by means of convolution window.
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pTmpBuf </param> <values> L G </values>
             <param> pKernel </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nKernelSize </param> <values> 1 2 3 </values>
             <param> nSrcVecSize </param> <values> 4 8 16 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void SIG_XCorr(nm32s* pSrcVec, int nSrcVecSize,nm32s* pKernel, int nKernelSize, nm32s* pDstVec, void* pTmpBuf);
void SIG_XCorr(nm16s* pSrcVec, int nSrcVecSize,nm32s* pKernel, int nKernelSize, nm32s* pDstVec, void* pTmpBuf);
void SIG_XCorr(nm8s* pSrcVec,  int nSrcVecSize,nm32s* pKernel, int nKernelSize, nm32s* pDstVec, void* pTmpBuf);
    //! \}



#endif
