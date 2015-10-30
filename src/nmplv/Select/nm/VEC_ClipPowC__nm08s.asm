//------------------------------------------------------------------------
//
//  $Workfile:: Clip.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:09 $
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
import from macros.mlb;

extern vec_activate_data_add_0:label;
extern tbl_f1cr_nm8:long[8];

begin ".text_nmplv"

///////////////////////////////////////////////////////////////////////////////////////////

//! \fn void nmppsClipPowC_8s(nm8s *pSrcVec, int nClipFactor, nm8s *pDstVec, int nSize) 
//!
//! \perfinclude _nmppsClipPowC__FPciPci_.html

global _nmppsClipPowC__FPciPci_:label;
global _void._.8.8nmppsClipPowC_.1char._.0.9._int.9._char._.0.9._int.2 :label;
<_nmppsClipPowC__FPciPci_>
<_void._.8.8nmppsClipPowC_.1char._.0.9._int.9._char._.0.9._int.2>
.branch;
	ar5=ar7-2;
	push ar0,gr0	with gr7=false;
	push ar5,gr5	with gr7++;
	push ar6,gr6	with gr7++;
	
	ar0 = [--ar5] with gr0=gr7;	//Src	
	gr6 = [--ar5];							//ClipIndex
	ar6 = tbl_f1cr_nm8	with gr6<<=1;		
	f1cr= [ar6+=gr6];
	ar6 = [--ar5] with gr6=gr7;	//Dst
	delayed call vec_activate_data_add_0;
		gr5 = [--ar5];							//Size
		with gr5>>=3;

	pop ar6,gr6;
	pop ar5,gr5;
	pop ar0,gr0;

	return;
.wait;



end ".text_nmplv";

