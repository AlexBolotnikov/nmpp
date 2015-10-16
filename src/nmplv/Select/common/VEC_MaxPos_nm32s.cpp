//------------------------------------------------------------------------
//
//  $Workfile:: GetMax.cp $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   GetMax.cpp
//! \author ������ �������
//! \brief  �������������� ������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmplv.h"
//!
//! \perfinclude _VEC_MaxPos__FPiiRiRiPvPvi.html
//! 
void VEC_MaxPos (nm32s31b *pSrcVec, int nSize, int& nIndex, int32b &nMaxValue, void *pLTmpBuff,void *pGTmpBuff, int nSearchDir)
{
	int nPos;
	void* pTmp1;
	void* pTmp2;
	
	//if ((int)pSrcVec>0){
		pTmp1=pGTmpBuff;
		pTmp2=pLTmpBuff;
	//}
	//else	{
	//	pTmp1=pLTmpBuff;
	//	pTmp2=pGTmpBuff;
	//}

	VEC_MaxVal(pSrcVec, nSize, nMaxValue);
	VEC_SubC_Neg(pSrcVec,nMaxValue,(nm32s*)pTmp1,nSize);
	VEC_CmpEq0((nm32u31b*)pTmp1,(nm1*)pTmp2,nSize,0); //Create Max bitmap

	if(nSearchDir > 0){
		nPos  =VEC_FirstNonZeroPos((int*)pTmp2,nSize>>5);
		nIndex=VEC_FirstZeroPos((int*)pTmp1+nPos*32,32);
		nIndex+=nPos*32;
	} else {
		nPos  =VEC_LastNonZeroPos((int*)pTmp2,nSize>>5); 
		nIndex=VEC_LastZeroPos((int*)pTmp1+nPos*32,32);
		nIndex+=nPos*32;
	}
}

