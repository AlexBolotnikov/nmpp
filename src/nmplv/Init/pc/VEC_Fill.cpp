//------------------------------------------------------------------------
//
//  $Workfile:: Init.cp $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:15 $
//
//! \if file_doc
//!
//! \file   Init.cpp
//! \author ������ �������
//! \brief  ������� ������������� � ����������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmplv.h"
////////////////////////////////////////////////////////////////////////////
//  Setting all 64-bit elements of Buffer to const value given by InitValue
void VEC_Fill(
		nm64s*	Buffer,		// Destination array					:long Global [SizeInt64]
		nm64s*		InitValue,	// Init value
		int			SizeInt64	// nSize of Source array in 64-bit ints; :SizeInt32= [0,1,2,...]
		)
{
	for(int i=0;i<SizeInt64;i++)
		Buffer[i]=(*InitValue);
}

//void VEC_Fill(
//		nm64s*		Buffer,		// Destination array					:long Global [SizeInt64]
//		nm64s		InitValue,	// Init value
//		int			SizeInt64	// nSize of Source array in 64-bit ints; :SizeInt32= [0,1,2,...]
//		)
//{
//	for(int i=0;i<SizeInt64;i++)
//		Buffer[i]=InitValue;
//}


////////////////////////////////////////////////////////////////////////////
//  Setting all 32-bit elements of Buffer to const value given by InitValue
void VEC_Fill(
		nm32s*	Buffer,		// Destination array					:long Global [SizeInt32/2]
		int		InitValue,	// Init value 
		int		SizeInt32	// nSize of Source array in 32-bit ints; :SizeInt32= [0,2,4...]
		)
{
	for(int i=0;i<SizeInt32;i++)
		Buffer[i]=InitValue;
}

////////////////////////////////////////////////////////////////////////////
//  Setting all 16-bit elements of Buffer to const value given by InitValue
void VEC_Fill(
		nm16s*	Buffer,		// Destination array					:long Global [SizeInt16/4]
		int		InitValue,	// Init value 
		int		SizeInt16	// nSize of Source array in 16-bit shorts:SizeInt16= [0,4,8,...]
		)
{
	for(int i=0;i<SizeInt16;i++)
		Buffer[i]=InitValue;
}


////////////////////////////////////////////////////////////////////////////
//  Setting all 8-bit elements of Buffer to const number given by InitValue
void VEC_Fill(					
		nm8s*	Buffer,		// Destination array					:long Global [SizeInt8/8]
		int		InitValue,	// Init value
		int		SizeInt8	// nSize of Source array in 8-bit chars; :SizeInt8=  [0,8,16....]
		)
{
	for(int i=0;i<SizeInt8;i++)
		Buffer[i]=InitValue;
}


