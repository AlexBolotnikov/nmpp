//------------------------------------------------------------------------
//
//  $Workfile:: Abs.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   Abs.Asm
//! \author ������ �������
//! \brief  ���������� �������� ��������� �������.
//!
//! \endif
//!
//------------------------------------------------------------------------
//#include "vArithm.h"

extern vec_activate_data_xor_data:label;

begin ".text_nmplv"


/////////////////////////////////////////////////////////////////////////////////////////
//! \fn void VEC_Abs1 (nm64s *pSrcVec, nm64s *pDstVec, int nSize) 
//!
//! \perfinclude _VEC_Abs1__FPlPli.html

global _VEC_Abs1__FPlPli:label;
global _void._.8.8VEC_Abs1.1long._.0.9._long._.0.9._int.2 :label;

<_VEC_Abs1__FPlPli>
<_void._.8.8VEC_Abs1.1long._.0.9._long._.0.9._int.2>
.branch;
	ar5 = sp - 2	with gr7=gr5;
	push ar0,gr0	with gr0=false;
	push ar6,gr6	with gr0++;
	
	ar0 = [--ar5]	with gr0++;		// pSrcVec
	ar6 = [--ar5]	with gr6=gr0;	// pDstVec
	gr5 = [--ar5];	// nSize
						
	f1crl= 00000000h;   
	delayed call  vec_activate_data_xor_data with gr5;	// nSize in 64-bit longs
		f1crh= 80000000h;   

	pop ar6,gr6;
	pop ar0,gr0		with gr5=gr7;
	return;
.wait;

end ".text_nmplv";
