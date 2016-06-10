//------------------------------------------------------------------------
//
//  $Workfile:: GetMin.cp $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:16 $
//
//! \if file_doc
//!
//! \file   GetMin.cpp
//! \author ������ �������
//! \brief  �������������� ������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "rpc/rpc-host.h"
#include "nmplv.h"
/////////////////////////////////////////////////////////////////////////////////////////
// Search of minimum value in 8-bit buffer
void nmppsMin_8s7b(
		const	nm8s7b*		pSrcVec,	// input buffer					:long Global [Size/8]
				int			nSize,		// buffer size in 8-bit words	:nSize=[8,16,24.....]
				int8b*		pMinValue)	// Minimum
{
	RPC_HOST_PIR("nmppsMin_8s",pSrcVec,nSize,pMinValue,1);
}
/////////////////////////////////////////////////////////////////////////////////////////
// Search of minimum value in 16-bit buffer
void nmppsMin_16s15b(
		const	nm16s15b*	pSrcVec,	// input buffer					:long Global [Size/4]
				int			nSize,		// buffer size in 16-bit words	:nSize=[4,8,12....]
				int16b*		pMinValue)	// Minimum
{
	RPC_HOST_PIR("nmppsMin_16s",pSrcVec,nSize,pMinValue,2);
}
/////////////////////////////////////////////////////////////////////////////////////////
// Search of minimum value in 32-bit buffer
void nmppsMin_32s31b(
		const	nm32s31b*		pSrcVec,	// input buffer					:long Global [Size/2]
				int			nSize,		// buffer size in 32-bit words	:nSize=[2,4,6....]
				int*		pMinValue)	// Minimum
{
	RPC_HOST_PIR("nmppsMin_32s",pSrcVec,nSize,pMinValue,4);
}




