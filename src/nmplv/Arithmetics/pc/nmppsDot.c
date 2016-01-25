//------------------------------------------------------------------------
//
//  $Workfile:: Mul_VxxVxx.cp $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:15 $
//
//! \if file_doc
//!
//! \file   Mul_VxxVxx.cpp
//! \author ������ �������
//! \brief  ������� ��������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------

#include "rpc-host.h"
#include "nmpp.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Scalar multiplication of two vectors
/*
int	nmppsDotProd_32s(
			nm32s*		pSrcVec1,		// input  32-bit vec		:long -----[Size/2]
			nm32s*		pSrcVec2,		// input  32-bit vec		:long -----[Size/2]
			int			nSize			// size of input buffers	:nSize=[0,2,4...]
		)
{
	#ifdef RPC
	RPC_PPI(pSrcVec,pDstVec,nSize);
	#else

	int Res=0;
	int i;
	for (i=0;i<nSize;i++)
		Res+=pSrcVec1[i]*pSrcVec2[i];
	return Res;

	//ippsDotProd_32s_Sfs(const Ipp32s* pSrc1, const Ipp32s*pSrc2, int len, Ipp32s* pDp, int scaleFactor);

	#endif
}
*/


//////////////////////////////////////////////////////////////////////////////////////
// Vector multiplication
//////////////////////////////////////////////////////////////////////////////////////
void nmppsDotProd_64s64s(
	nm64s*	srcVec0,	//Input0 buffer		:long Local [Size].
	nm64s*	srcVec1,	//Input1 buffer		:long Global[Size].
	int		size,		//Size of input vec
	int64b*	dst			//Output buffer		:long Any
	)
{
	#ifdef RPC
	RPC_HOST_PPIP("nmppsDotProd_64s64s",srcVec0,srcVec1,size,dst,8,8);
	#else

	int i;
	*dst=0;
	for (i=0; i<size; i++)
		*dst += ((nm64s)srcVec0[i])*((nm64s)srcVec1[i]);

	#endif
}

//////////////////////////////////////////////////////////////////////////////////////
void nmppsDotProd_32s64s(
	nm32s*	srcVec0,	//Input0 buffer		:long Local [Size].
	nm64s*	srcVec1,	//Input1 buffer		:long Global[Size].
	int		size,		//Size of input vec
	int64b*	dst			//Output buffer		:long Any
	)
{
	#ifdef RPC
	RPC_HOST_PPIP("nmppsDotProd_32s64s",srcVec0,srcVec1,size,dst,4,8);
	#else

	int i;
	*dst = 0;
	for (i=0; i<size; i++)
		*dst += ((nm64s)srcVec0[i])*((nm64s)srcVec1[i]);

	#endif
}

//////////////////////////////////////////////////////////////////////////////////////
void nmppsDotProd_16s64s(
	nm16s*	srcVec0,	//Input0 buffer		:long Local [Size].
	nm64s*	srcVec1,	//Input1 buffer		:long Global[Size].
	int		size,		//Size of input vec
	int64b*	dst			//Output buffer		:long Any
	)
{
	#ifdef RPC
	RPC_HOST_PPIP("nmppsDotProd_16s64s",srcVec0,srcVec1,size,dst,2,8);
	#else
	int i;
	*dst = 0;
	for (i=0; i<size; i++)
		*dst += ((nm64s)srcVec0[i])*((nm64s)srcVec1[i]);

	#endif
}

//////////////////////////////////////////////////////////////////////////////////////
void nmppsDotProd_8s64s(
	nm8s*	srcVec0,	//Input0 buffer		:long Local [Size].
	nm64s*	srcVec1,	//Input1 buffer		:long Global[Size].
	int		size,		//Size of input vec
	int64b*	dst			//Output buffer		:long Any
	)
{
	#ifdef RPC
	RPC_HOST_PPIP("nmppsDotProd_8s64s",srcVec0,srcVec1,size,dst,1,8);
	#else
	int i;
	*dst = 0;
	for (i=0; i<size; i++)
		*dst += ((nm64s)srcVec0[i])*((nm64s)srcVec1[i]);

	#endif
}

