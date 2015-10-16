//------------------------------------------------------------------------
//
//  $Workfile:: mtrMulMN.cp $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/01/12 14:05:15 $
//
//! \if file_doc
//!
//! \file   mtrMulMN.cpp
//! \author ������ �������
//! \brief  ������� ��������� ������� �� �������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmplv.h"


void MTR_MulC_AddVsVc(
			int			MulN,
			nm32s*		SrcMtr,
			nm32s*		SrcVecStr,
			nm32s*		SrcVecCol,
			nm32s*		DstMtr,
			int			nHeight,
			int			nWidth)

{
	for(int row=0;row<nHeight;row++)
		VEC_MulC_AddV_AddC(SrcMtr+row*nWidth,MulN,SrcVecStr,SrcVecCol[row],DstMtr+row*nWidth,nWidth);
}
