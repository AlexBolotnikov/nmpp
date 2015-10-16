//------------------------------------------------------------------------
//
//  $Workfile:: Abs.cpp    $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:15 $
//
//! \if file_doc
//!
//! \file   Abs.cpp
//! \author ������ �������
//! \brief  �������������� ������� 
//!
//! \endif
//!
//------------------------------------------------------------------------
//#include "vec.h"
#include "nmplv.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Absolute value calculation
void VEC_Abs1(
		nm4s*			pSrcVec,		// input buffer		:long Local [VecSize/8]
		nm4s*			pDstVec,		// output buffer	:long Global[VecSize/8]
		int				nSize		// size of input buffer in 8 bit elements. nSize=[8,16,32...]
		)
{
	nm8s v,m;
	for(int i=0; i<nSize/2; i++)
	{
		v=((nm8s*)pSrcVec)[i];
		m=((v>>3)&0xF0)|(((char(v<<4))>>7)&0xF);
		v^=m;
		((nm8s*)pDstVec)[i]=v;
	}
}

void VEC_Abs1(
		nm8s*			pSrcVec,		// input buffer		:long Local [VecSize/8]
		nm8s*			pDstVec,		// output buffer	:long Global[VecSize/8]
		int				nSize		// size of input buffer in 8 bit elements. nSize=[8,16,32...]
		)
{
	nm8s v;
	for(int i=0; i<nSize; i++)
	{
		v=pSrcVec[i];
		pDstVec[i] = (v>>7)^v;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
// Absolute value calculation
void VEC_Abs1(
		nm16s*			pSrcVec,		// input buffer		:long Local [VecSize/4]
		nm16s*			pDstVec,		// output buffer	:long Global[VecSize/4]
		int				nSize		// size of input buffer in 8 bit elements. nSize=[0,4,8,..]
		)
{
	nm16s v;
	for(int i=0; i<nSize; i++)
	{
		v=pSrcVec[i];
		pDstVec[i] = (v>>15)^v;
	}
}


/////////////////////////////////////////////////////////////////////////////////////////
// Absolute value calculation
void VEC_Abs1(
		nm32s*			pSrcVec,		// input buffer		:long Local [VecSize/2]
		nm32s*			pDstVec,		// output buffer	:long Global[VecSize/2]
		int				nSize		// size of input buffer in 32 bit elements. nSize=[2,4,6...]
		)
{
	nm32s v;
	for(int i=0; i<nSize; i++)
	{
		v=pSrcVec[i];
		pDstVec[i] = (v>>31)^v;
	}
}


/////////////////////////////////////////////////////////////////////////////////////////
// Absolute value calculation
void VEC_Abs1(
		nm64s*			pSrcVec,		// input buffer		:long Local [VecSize/2]
		nm64s*			pDstVec,		// output buffer	:long Global[VecSize/2]
		int				nSize		// size of input buffer in 32 bit elements. nSize=[2,4,6...]
		)
{
	nm64s v;
	for(int i=0; i<nSize; i++)
	{
		v=pSrcVec[i];
		pDstVec[i] = (v>>63)^v;
	}
}
