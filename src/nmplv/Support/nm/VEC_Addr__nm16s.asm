//------------------------------------------------------------------------
//
//  $Workfile:: Access.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:11 $
//
//! \if file_doc
//!
//! \file   Access.asm
//! \author ������ �������
//! \brief  ������� ������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vClip.h"



begin ".text_nmplv"

  

    //--------------------------------------------------------------------
    //! \fn nm16s * VEC_Addr (nm16s *pVec, int nIndex) 
	//!
	//! \perfinclude _VEC_Addr__FPSsi.html
    //--------------------------------------------------------------------
    

global _VEC_Addr__FPSsi:label;
global _short._.0.8.8VEC_Addr.1short._.0.9._int.2 :label;
<_VEC_Addr__FPSsi>
<_short._.0.8.8VEC_Addr.1short._.0.9._int.2>
.branch;
	ar5 = sp-4 with gr7=gr5;	
	gr5 = [ar5++];
	ar5 = [ar5++] with gr5 A>>=1;
delayed return;
	nul;
	ar5+=gr5   with gr5 = gr7;
	nul;
return;
.wait;

 


end ".text_nmplv";

