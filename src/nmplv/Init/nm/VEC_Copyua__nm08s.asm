//------------------------------------------------------------------------
//
//  $Workfile:: vCopyUtoA08. $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:08 $
//
//! \if file_doc
//!
//! \file   GetVector.asm
//! \author ������ �������
//! \brief  ������� ������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vClip.h"

extern vec_data:label;
extern vec_Mul2D2W8_AddVr:label;

import from macros.mlb;
data ".data_nmplv_L"
	global LWSum2CharBuffers: long[8*16] = (
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl);
end ".data_nmplv_L";

data ".data_nmplv_G"
	global GWSum2CharBuffers: long[8*16] = (
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl);

end ".data_nmplv_G";

begin ".text_nmplv"

    //! \fn void nmppsCopyua_8s(nm8s *pSrcVec, int nOffset, nm8s *pDstVec, int nSize) 
    //!
    //! \perfinclude _nmppsCopyua_8s.html

global _nmppsCopyua_8s:label;
global _void._.8.8nmppsCopyua_.1char._.0.9._int.9._char._.0.9._int.2 :label;
<_nmppsCopyua_8s>
<_void._.8.8nmppsCopyua_.1char._.0.9._int.9._char._.0.9._int.2>
.branch;
	ar5 = sp-2		with gr7=false;	
	push ar0,gr0;
	push ar1,gr1;
	push ar4,gr4;
	push ar5,gr5;
	push ar6,gr6 with gr7++;

	ar0 = [--ar5]	with gr7++;			// input buffer		:long Long[...]
	gr1 = [--ar5]	with gr6 = gr7;		// start copy from index SrcVecIndx	:[0,1,2,3,4...]
	ar6 = [--ar5]	with gr0 = gr1>>3;	// output buffer	:long Long[nDstVecSize>>3]	
	gr7 = ar0		with gr7;
	gr5 = [--ar5]	with gr0 <<=1;		// buffer size in 8-bit elemetns	:[0,8,16,24...]
		
	ar0+= gr0		with gr7=gr1<<29;

	if =0 delayed goto CopyVector	with gr0  = gr6;
		sb  = 02020202h				with gr5>>=3; 

	if >= delayed goto UseGlobalWeightData;
		ar4 = GWSum2CharBuffers;
	ar4=LWSum2CharBuffers;
	<UseGlobalWeightData>
		
	ar1 = ar0		with gr4 = gr7>>24;
	ar4+= gr4		with gr1 = gr6;
	gr4 = 80808080h;
	nb1 = gr4		with gr7 = false;
	vr  = gr7;
	delayed call vec_Mul2D2W8_AddVr;
		ar1+= 2;
	
	delayed goto Finish;
		pop ar6,gr6;
		pop ar5,gr5;
	
	<CopyVector>
	call vec_data;
	
	pop ar6,gr6;
	pop ar5,gr5;
	<Finish>
	pop ar4,gr4;
	pop ar1,gr1;
	pop ar0,gr0;
return;
.wait;




end ".text_nmplv";

