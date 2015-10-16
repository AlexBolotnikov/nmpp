//------------------------------------------------------------------------
//
//  $Workfile:: Cnv16to32.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:08 $
//
//! \if file_doc
//!
//! \file   Cnv16to32.asm 
//! \author ������ �������
//! \brief  ������� �������������� ��������� �������.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vConvert.h"

import from macros.mlb;
extern vec_vsum_data_0:label;
data ".data"
    WConvert16to32: long[8] =   ( 1l, 100000000hl, 0l dup 4, 1l, 100000000hl);
end ".data";
begin ".text_nmplv"
/////////////////////////////////////////////////////////////////////////////////////////


//! \fn void VEC_Cnv( nm16s* pSrcVec, nm32s* pDstVec, int nSize)
//!
//! \perfinclude _VEC_Cnv__FPSsPii.html

global _void._.8.8VEC_Cnv.1short._.0.9._int._.0.9._int.2 :label;
<_void._.8.8VEC_Cnv.1short._.0.9._int._.0.9._int.2>
.branch;
	delayed goto JumpFromSigned;
		nb1 = 80000000h;

/////////////////////////////////////////////////////////////////////////////////////////

//! \fn void VEC_Cnv( nm16u* pSrcVec, nm32u* pDstVec, int nSize)
//!
//! \perfinclude _VEC_Cnv__FPUsPUii.html

global _void._.8.8VEC_Cnv.1unsigned._short._.0.9._unsigned._int._.0.9._int.2 :label;
<_void._.8.8VEC_Cnv.1unsigned._short._.0.9._unsigned._int._.0.9._int.2>
.branch;
	nb1 = 80008000h;
	<JumpFromSigned>
	ar5 = WConvert16to32 set;
	sb  = 00020002h;
	rep 8 wfifo =[ar5++],ftw;

	ar5 = sp - 2;
	push ar0,gr0	with gr0=false;
	push ar5,gr5	with gr0++;
	push ar6,gr6	with gr0++;		//gr0=2

	ar0 = [--ar5]	with gr6=gr0;	// pSrcVec , gr6=2
	ar6 = [--ar5] ;					// pDstVec
	gr5 = [--ar5] ;					// nSize in 8-bit elements 
	gr7 = ar0		with gr5>>=2;
	ar5 = ar6+gr6	with gr6<<=1;	// gr6=4
		
	delayed call vec_vsum_data_0;
		wtw;
		ftw;		
		
	ar0 = gr7;
	ar6 = ar5;
	delayed call vec_vsum_data_0;
		wtw;
		nul;

	pop ar6,gr6;
	pop ar5,gr5;
	pop ar0,gr0;
	return;
.wait;
end ".text_nmplv";
