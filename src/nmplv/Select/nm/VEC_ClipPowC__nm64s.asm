//------------------------------------------------------------------------
//
//  $Workfile:: Clip.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2011/11/22 13:50:09 $
//
//! \if file_doc
//!
//! \file   Clip.asm
//! \author ������ �������
//! \brief  ������� ��������� � ������������ ���������� ��������� �������
//!         ��� ��������� �����.
//!
//! \endif
//!
//------------------------------------------------------------------------
//#include "vClip.h"

extern vec_activate_data_add_0:label;
extern tbl_f1cr_nm64:long[64];

begin ".text_nmplv"


/////////////////////////////////////////////////////////////////////////////////


//! \fn void VEC_ClipPowC (nm64s *pSrcVec, int nClipFactor, nm64s *pDstVec, int nSize) 
//!
//! \perfinclude _VEC_ClipPowC__FPiiPii.html

global _void._.8.8VEC_ClipPowC.1long._.0.9._int.9._long._.0.9._int.2 :label;
<_void._.8.8VEC_ClipPowC.1long._.0.9._int.9._long._.0.9._int.2>
.branch;

	ar5=ar7-2;
	push ar0,gr0	with gr7=false;
	push ar5,gr5	with gr7++;
	push ar6,gr6	with gr7++;
	
	ar0 = [--ar5] with gr0=gr7;				//Src	
	gr6 = [--ar5];							//ClipIndex
	ar6 = tbl_f1cr_nm64	with gr6<<=1;		
	f1cr= [ar6+=gr6];
	delayed call vec_activate_data_add_0;
		ar6 = [--ar5] with gr6=gr7;			//Dst
		gr5 = [--ar5];						//Size
		

	pop ar6,gr6;
	pop ar5,gr5;
	pop ar0,gr0;

	return;
.wait;



end ".text_nmplv";

