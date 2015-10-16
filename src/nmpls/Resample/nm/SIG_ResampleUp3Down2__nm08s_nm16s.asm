//------------------------------------------------------------------------
//
//  $Workfile:: ResampleUp3Down2_8s1 $
//
//  ���������� ��������� ��������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/01/12 14:09:08 $
//
//! \if file_doc
//!
//! \file   Add.Asm
//! \author ������ �������
//! \brief  ������� ����������������� ������� � 3/2 ����
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vArithm.h"

extern vec_Mul2D2W8_AddVr:label;
begin ".text_nmpls"

//! \fn void SIG_ResampleUp3Down2(nm8s* pSrcVec, nm16s* pDstVec, int nSrcVecSize, nm64s* pKernel);
//!
// \perfinclude _SIG_ResampleUp3Down2__FPcPSsiPl.html

//
global _SIG_ResampleUp3Down2__FPcPSsiPl:label;
global _void._.8.8SIG_ResampleUp3Down2.1char._.0.9._short._.0.9._int.9._long._.0.2:label;
<_SIG_ResampleUp3Down2__FPcPSsiPl>
<_void._.8.8SIG_ResampleUp3Down2.1char._.0.9._short._.0.9._int.9._long._.0.2>
.branch;
	ar5 = sp - 2;
	
	push ar0,gr0 with gr0 = false;
	push ar1,gr1 with gr0++;
	push ar4,gr4 with gr0++;
	push ar5,gr5 with gr1 = gr0;
	push ar6,gr6 with gr6 = gr0<<1;
				 with gr6+= gr0;
	ar0 = [--ar5];	// pSrcVec
	ar6 = [--ar5];	// pDstVec
	gr5 = [--ar5];	// nSrcVecSize
	ar4 = [--ar5];	// pKernel
		
	gr4 = 80008000h;
	sb  = 02020202h;
	nb1 = gr4;
	vr  = 0;
	wtw;

	gr5>>=3;

	ar1 = ar0;
	ar0-= 2;
	//-----------------------------------------------
//	ar4 = _PolyphaseFilter;
	push ar0,gr0;
	push ar1,gr1;
	push ar6,gr6;

	delayed call vec_Mul2D2W8_AddVr;
		nul;
		nul;

	pop ar6,gr6;
	pop ar1,gr1;
	pop ar0,gr0;
	//-----------------------------------------------
	ar0+= 2;
	ar1+= 2;
	ar4+= 32;
	ar6+= 2;
	push ar0,gr0;
	push ar1,gr1;
	push ar6,gr6;

	delayed call vec_Mul2D2W8_AddVr;
		nul;
		nul;

	pop ar6,gr6;
	pop ar1,gr1;
	pop ar0,gr0;
	//-----------------------------------------------
	ar4+= 32;
	ar6+= 2;
	
	push ar0,gr0;
	push ar1,gr1;
	push ar6,gr6;

	delayed call vec_Mul2D2W8_AddVr;
		nul;
		nul;

	pop ar6,gr6;
	pop ar1,gr1;
	pop ar0,gr0;
	//-----------------------------------------------
	
	pop ar6,gr6;
	pop ar5,gr5;
	pop ar4,gr4;
	pop ar1,gr1;
	pop ar0,gr0;
return with gr7=false;
.wait;




end ".text_nmpls";
