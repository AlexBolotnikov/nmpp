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
#include "nmtype.h"
#include "nmpp.h"


////////////////////////////////////////////////////////////////////////////
//  Random initalization of 32-bit buffer
unsigned nmppsRandUniformomize_=1;

//! 
//! \perfinclude _nmppsRandUniform__Fiii_.html
//! 

int nmppsRandUniform_(
		int Min,
		int Max)
{
	unsigned int R=nmppsRandUniform();
	R%=unsigned(Max-Min+1);
	int X=int(R)+Min;
	return X;
}

int nmppsRandUniform_(
		int Min,
		int Max,
		int	Divisible)
{
	unsigned int R=nmppsRandUniform();
	R%=unsigned(Max-Min+1);
	int X=int(R)+Min;
	X/=Divisible;
	X*=Divisible;
	return X;
}

////////////////////////////////////////////////////////////////////////////
//  Random initalization of 32-bit buffer

//! 
//! \perfinclude _nmppsRandUniform__Fv_.html
//! 

int nmppsRandUniform_()
{

	nmppsRandUniformomize_=1664525L*nmppsRandUniformomize_+1013904223L;
	unsigned int R=nmppsRandUniformomize_>>16;
	nmppsRandUniformomize_=1664525L*nmppsRandUniformomize_+1013904223L;
	R|=(nmppsRandUniformomize_&0xFFFF0000);
	return R;
}
