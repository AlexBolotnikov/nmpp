//------------------------------------------------------------------------
//
//  $Workfile:: InitRand.cp $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/01/12 13:30:01 $
//
//! \if file_doc
//!
//! \file   InitRand.cpp
//! \author ������ �������
//! \brief  ������� ������������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmplc.h"
////////////////////////////////////////////////////////////////////////////
//  Random initalization of 32-bit buffer
unsigned nmppcRandomize=1;

//! 
//! \perfinclude _SCL_Rand__Fiii.html
//! 

int nmppcRand(
		int Min,
		int Max)
{

	unsigned int R=nmppcRand();
	R%=unsigned(Max-Min+1);
	int X=int(R)+Min;
	return X;
}

int nmppcRand(
		int Min,
		int Max,
		int	Divisible)
{
	unsigned int R=nmppcRand();
	R%=unsigned(Max-Min+1);
	int X=int(R)+Min;
	X/=Divisible;
	X*=Divisible;
	return X;
}

////////////////////////////////////////////////////////////////////////////
//  Random initalization of 32-bit buffer

//! 
//! \perfinclude _nmppcRand__Fv.html
//! 

int nmppcRand()
{

	nmppcRandomize=1664525L*nmppcRandomize+1013904223L;
	unsigned int R=nmppcRandomize>>16;
	nmppcRandomize=1664525L*nmppcRandomize+1013904223L;
	R|=(nmppcRandomize&0xFFFF0000);
	return R;
}
