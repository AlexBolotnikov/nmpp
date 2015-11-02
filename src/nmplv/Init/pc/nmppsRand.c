//------------------------------------------------------------------------
//
//  $Workfile:: InitRand.cp $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:02 $
//
//! \if file_doc
//!
//! \file   InitRand.cpp
//! \author ������ �������
//! \brief  ������� ������������� � ����������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmtype.h"
////////////////////////////////////////////////////////////////////////////
//  Random initalization of 32-bit buffer

 
//! 
//! \perfinclude _nmppsRand__FPUiiUi_.html
//! 



////////////////////////////////////////////////////////////////////////////
//  Random initialization of 64-bit Buffer
void nmppsRand_64s(nm64s*			pDstVec,		// array									:int Global [SizeInt]
		int				nSize,		// nSize of Source array in 64-bit elements	:nSize=    [0,1,2,3,4...]
		int				Randomize
		)
{
	__int64 Rand=Randomize&0xFFFFFFFFL;
	int i;
	for(i=0;i<nSize;i++)
	{
		Rand=1664525L*Rand+1013904223L;
		pDstVec[i]=Rand;
	}
}


