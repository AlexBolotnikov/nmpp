//------------------------------------------------------------------------
//
//  $Workfile:: 32Clc.cp $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:16 $
//
//! \if file_doc
//!
//! \file   32Clc.cpp
//! \author ������ �������
//! \brief  ������� �������� ������������ ���� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------
extern unsigned int CRC32_Table[];
//#include "vcrc.h"
#include "nmplv.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void nmppsCrc_32s(
    unsigned int* pSrcVec, // Input Vector			:long Any[Size/2]
    int nSize,             // Vector size        	:[0,1,2...]
    unsigned int& nCrc     // Init/Output crc
    )
       
{
	nm32u* pTable=CRC32_Table; 
    unsigned a,b;
	int i;

    

    for( i = 0; i < nSize; i++ )
    {
		a = pSrcVec[i];
        b = a & 0x000000FF;
        nCrc = ( nCrc >> 8 ) ^ pTable[( b ^ ( nCrc & 0x000000FF ) )];
        b = ( a >> 8 ) & 0x000000FF;
        nCrc = ( nCrc >> 8 ) ^ pTable[( b ^ ( nCrc & 0x000000FF ) )];
        b = ( a >> 16 ) & 0x000000FF;
        nCrc = ( nCrc >> 8 ) ^ pTable[( b ^ ( nCrc & 0x000000FF ) )];
        b = ( a >> 24 ) & 0x000000FF;
        nCrc = ( nCrc >> 8 ) ^ pTable[( b ^ ( nCrc & 0x000000FF ) )];
    }
    nCrc = ~ nCrc;

}
