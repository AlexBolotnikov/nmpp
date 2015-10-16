//------------------------------------------------------------------------
//
//  $Workfile:: CharShortAccess.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:11 $
//
//! \if file_doc
//!
//! \file   CharShortAccess.asm
//! \author ������ �������
//! \brief  ������� ������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vConvert.h"

begin ".text_nmplv"

//! \fn void VEC_GetVal (nm4u *pVec, int nIndex, uint4b& nVal) 
//!
//! \perfinclude _VEC_GetVal__F4nm4uPiRUi.html

macro EXTRACT(n)
	delayed return with	gr7<<=n;
		gr7 >>=28;
		[ar5]=gr7;
		nul;
end EXTRACT;

global _VEC_GetVal__F4nm4uPiRUi:	label;
global _void._.8.8VEC_GetVal.1class._nm4u._.0.9._int.9._unsigned._int._.6.2 :label;
<_VEC_GetVal__F4nm4uPiRUi>
<_void._.8.8VEC_GetVal.1class._nm4u._.0.9._int.9._unsigned._int._.6.2>




.branch;
	ar5 = ar7 - 2;
	push ar0, gr0;
	ar0 = [--ar5];	// pVec				
	gr7 = [--ar5];	// nIndex				
	ar5 = [--ar5] with gr0 = gr7>>3;
	gr7 = [ar0+=gr0] with gr0=gr7<<29;
	with gr0>>=27;
	gr0++;
	gr0++;
	delayed skip gr0;
		pop ar0, gr0;
		nul;
		nul;
	EXTRACT(28);
	EXTRACT(24);
	EXTRACT(20);
	EXTRACT(16);
	EXTRACT(12);	
	EXTRACT(8);	
	EXTRACT(4);
	delayed return with	gr7;
		gr7 >>=28;
		[ar5]=gr7;
		nul;	
	
.wait;




end ".text_nmplv";
