//------------------------------------------------------------------------
//
//  $Workfile:: Copy.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:08 $
//
//! \if file_doc
//!
//! \file   Copy.asm
//! \author ������ �������
//! \brief  ������� ������������� � �����������.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vCopy.h"

extern vec_data:label;


begin ".text_nmplv"
    
//! \fn void VEC_Copy( nm64s* pSrcVec, nm64s* pDstVec, int nSize);
//!
//! \perfinclude _VEC_Copy__FPlPli.html


global _void._.8.8VEC_Copy.1long._.0.9._long._.0.9._int.2 :label;
<_void._.8.8VEC_Copy.1long._.0.9._long._.0.9._int.2>
.branch;
    ar5 = sp - 2	with gr7=gr5;
    push ar0,gr0	with gr0=false;
	push ar6,gr6	with gr0++;
    ar0 = [--ar5]	with gr0++;		// pSrcVec
	ar6 = [--ar5];					// pDstVec
	delayed call vec_data with gr6=gr0;
		gr5 = [--ar5];				// nSize
		nul;
	pop ar6,gr6;
	pop ar0,gr0		with gr5=gr7;
	return;
.wait;


end ".text_nmplv";