//------------------------------------------------------------------------
//
//  $Workfile:: ARSH16.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:04 $
//
//! \if file_doc
//!
//! \file   ARSH16.asm
//! \author ����� ���������
//! \brief  ������� ������ ��� ��������.
//! 
//! \endif
//!
//------------------------------------------------------------------------
//#include "vShift.h"

	extern vec_vsum_shift_data_0:label;
	extern vec_vsum_data_0:label;

data ".data_nmplv_G"
		vec_tbl_w_char_ARSH:long[12*16]=(

				//ArShr 0
				0000000000000001hl,
				0000000000000004hl,
				0000000000004000hl,
				0000000000010000hl,
				0000000000040000hl,
				0000000040000000hl,
				0000000100000000hl,
				0000000400000000hl,
				0000400000000000hl,
				0001000000000000hl,
				0004000000000000hl,
				4000000000000000hl,

				//ArShr 1
				0000000000000001hl,
				0000000000000004hl,
				000000000000c000hl,
				0000000000010000hl,
				0000000000040000hl,
				00000000c0000000hl,
				0000000100000000hl,
				0000000400000000hl,
				0000c00000000000hl,
				0001000000000000hl,
				0004000000000000hl,
			   0c000000000000000hl,

				//ArShr 2
				0000000000000000hl,
				0000000000000001hl,
				0000000000001000hl,
				0000000000000000hl,
				0000000000010000hl,
				0000000010000000hl,
				0000000000000000hl,
				0000000100000000hl,
				0000100000000000hl,
				0000000000000000hl,
				0001000000000000hl,
				1000000000000000hl,

				//ArShr 3
				0000000000000000hl,
				0000000000000001hl,
				000000000000f000hl,
				0000000000000000hl,
				0000000000010000hl,
				00000000f0000000hl,
				0000000000000000hl,
				0000000100000000hl,
				0000f00000000000hl,
				0000000000000000hl,
				0001000000000000hl,
			   0f000000000000000hl,

				//ArShr 4
				0000000000000000hl,
				0000000000000001hl,
				0000000000000400hl,
				0000000000000000hl,
				0000000000010000hl,
				0000000004000000hl,
				0000000000000000hl,
				0000000100000000hl,
				0000040000000000hl,
				0000000000000000hl,
				0001000000000000hl,
				0400000000000000hl,

				//ArShr 5
				0000000000000000hl,
				0000000000000001hl,
				000000000000fc00hl,
				0000000000000000hl,
				0000000000010000hl,
				00000000fc000000hl,
				0000000000000000hl,
				0000000100000000hl,
				0000fc0000000000hl,
				0000000000000000hl,
				0001000000000000hl,
			   0fc00000000000000hl,

				//ArShr 6
				0000000000000000hl,
				0000000000000001hl,
				0000000000000100hl,
				0000000000000000hl,
				0000000000010000hl,
				0000000001000000hl,
				0000000000000000hl,
				0000000100000000hl,
				0000010000000000hl,
				0000000000000000hl,
				0001000000000000hl,
				0100000000000000hl,

				//ArShr 7
				0000000000000000hl,
				0000000000000001hl,
				000000000000ff00hl,
				0000000000000000hl,
				0000000000010000hl,
				00000000ff000000hl,
				0000000000000000hl,
				0000000100000000hl,
				0000ff0000000000hl,
				0000000000000000hl,
				0001000000000000hl,
			   0ff00000000000000hl,

				//ArShr 8
				0000000000000000hl,
				0000000000000001hl,
				0000000000000040hl,
				0000000000000000hl,
				0000000000010000hl,
				0000000000400000hl,
				0000000000000000hl,
				0000000100000000hl,
				0000004000000000hl,
				0000000000000000hl,
				0001000000000000hl,
				0040000000000000hl,

				//ArShr 9
				0000000000000000hl,
				0000000000000001hl,
				000000000000ffc0hl,
				0000000000000000hl,
				0000000000010000hl,
				00000000ffc00000hl,
				0000000000000000hl,
				0000000100000000hl,
				0000ffc000000000hl,
				0000000000000000hl,
				0001000000000000hl,
			   0ffc0000000000000hl,

				//ArShr 10
				0000000000000000hl,
				0000000000000001hl,
				0000000000000010hl,
				0000000000000000hl,
				0000000000010000hl,
				0000000000100000hl,
				0000000000000000hl,
				0000000100000000hl,
				0000001000000000hl,
				0000000000000000hl,
				0001000000000000hl,
				0010000000000000hl,

				//ArShr 11
				0000000000000000hl,
				0000000000000001hl,
				000000000000fff0hl,
				0000000000000000hl,
				0000000000010000hl,
				00000000fff00000hl,
				0000000000000000hl,
				0000000100000000hl,
				0000fff000000000hl,
				0000000000000000hl,
				0001000000000000hl,
			   0fff0000000000000hl,

				//ArShr 12
				0000000000000000hl,
				0000000000000001hl,
				0000000000000004hl,
				0000000000000000hl,
				0000000000010000hl,
				0000000000040000hl,
				0000000000000000hl,
				0000000100000000hl,
				0000000400000000hl,
				0000000000000000hl,
				0001000000000000hl,
				0004000000000000hl,

				//ArShr 13
				0000000000000000hl,
				0000000000000001hl,
				000000000000fffchl,
				0000000000000000hl,
				0000000000010000hl,
				00000000fffc0000hl,
				0000000000000000hl,
				0000000100000000hl,
				0000fffc00000000hl,
				0000000000000000hl,
				0001000000000000hl,
			   0fffc000000000000hl,

				//ArShr 14
				0000000000000000hl,
				0000000000000000hl,
				0000000000000001hl,
				0000000000000000hl,
				0000000000000000hl,
				0000000000010000hl,
				0000000000000000hl,
				0000000000000000hl,
				0000000100000000hl,
				0000000000000000hl,
				0000000000000000hl,
				0001000000000000hl,

				//ArShr 15
				0000000000000000hl,
				0000000000000000hl,
				000000000000ffffhl,
				0000000000000000hl,
				0000000000000000hl,
				00000000ffff0000hl,
				0000000000000000hl,
				0000000000000000hl,
				0000ffff00000000hl,
				0000000000000000hl,
				0000000000000000hl,
			   0ffff000000000000hl
				);


		vec_tbl_nb_sb_char_ARSH:long[16*2]=(
			
				0a002a002a002a002hl,	//nb shr 0
				0800a800a800a800ahl,	//sb shr 0

				0e002e002e002e002hl,	//nb shr 1
				0800a800a800a800ahl,	//sb shr 1

				08800880088008800hl,	//nb shr 2
				0800a800a800a800ahl,	//sb shr 2

				0f800f800f800f800hl,	//nb shr 3
				0800a800a800a800ahl,	//sb shr 3

				08200820082008200hl,	//nb shr 4
				08022802280228022hl,	//sb shr 4

				0fe00fe00fe00fe00hl,	//nb shr 5
				08022802280228022hl,	//sb shr 5

				08080808080808080hl,	//nb shr 6
				08082808280828082hl,	//sb shr 6

				0ff80ff80ff80ff80hl,	//nb shr 7
				08082808280828082hl,	//sb shr 7

				08020802080208020hl,	//nb shr 8
				08202820282028202hl,	//sb shr 8

				0ffe0ffe0ffe0ffe0hl,	//nb shr 9
				08202820282028202hl,	//sb shr 9

				08008800880088008hl,	//nb shr 10
				08802880288028802hl,	//sb shr 10

				0fff8fff8fff8fff8hl,	//nb shr 11
				08802880288028802hl,	//sb shr 11

				08002800280028002hl,	//nb shr 12
				0a002a002a002a002hl,	//sb shr 12

				0fffefffefffefffehl,	//nb shr 13
				0a002a002a002a002hl,	//sb shr 13

				08000800080008000hl,	//nb shr 14
				0800a800a800a800ahl,	//sb shr 14

				0ffffffffffffffffhl,	//nb shr 15
				0800a800a800a800ahl 	//sb shr 15
				);
								
end ".data_nmplv_G";

import from macros.mlb;

begin ".text_nmplv"

///////////////////////////////////////////////////////////////////////////////////////
// 
//
//! \fn void nmppsArshC_16s(nm16s *pSrcVec, int nShift, nm16s *pDstVec, int nSize) 
//!
//! \perfinclude _nmppsArshC_16s.html

global _void._.8.8nmppsArshC_.1short._.0.9._int.9._short._.0.9._int.2 :label;
<_void._.8.8nmppsArshC_.1short._.0.9._int.9._short._.0.9._int.2>
.branch;
	ar5 = sp - 4;
	push ar0,gr0;
	gr0 = [ar5];		//	int				Shift	 :[0, 1, 2, .., 31].
	
	ar0 = vec_tbl_nb_sb_char_ARSH with gr0<<=2;
	ar5-=2;
	ar0+= gr0 with gr0<<=1;//gr0 = Shift*8
	nb1 = [ar0++] with gr7 = gr0<<1;//gr7 = Shift*8*2
	sb  = [ar0];
	ar0 = vec_tbl_w_char_ARSH with gr0 += gr7;//gr0 = Shift*8*2 + Shift*8
	ar0+= gr0;			// w table select 
	rep 12 wfifo=[ar0++],ftw;

	
	push ar5,gr5	with gr0=false;
	push ar6,gr6	with gr0++;
	
//	gr7 = [ar5++]	with gr0++;			// 	int				Shift	:[0, 1, 2, .., 31].
//	gr5 = [ar5++]	with gr6=gr0;		//	int				VecSize,	//Size of input buffer in 8 bit elements. Size=[256, 512, .., n*256].
//	ar6 = [ar5++]	with gr7<<=31;		//	nm32u*	DstVec,		//Output buffer		:long Global[Size/8].
//	ar0 = [ar5++];						//	nm32u*	SrcVec,		//Input buffer		:long Local [Size/8].

	
	gr5 = [ar5++]	with gr0++;			//	int				VecSize,	//Size of input buffer in 8 bit elements. Size=[256, 512, .., n*256].
	ar6 = [ar5++]	with gr6=gr0;		//	nm32u*	DstVec,		//Output buffer		:long Global[Size/8].
	gr7 = [ar5++]	;					// 	int				Shift	:[0, 1, 2, .., 31].
	ar0 = [ar5++] with gr7<<=31;		//	nm32u*	SrcVec,		//Input buffer		:long Local [Size/8].
	

	if =0 delayed goto Even_RightShift	with gr5>>=2;// Size in 64-bit vectors
		nul;
		nul;

	<Odd_RightShift>
	delayed call vec_vsum_shift_data_0;
		wtw;
		nul;
	goto End_RightShift;
	
	<Even_RightShift>
	delayed call vec_vsum_data_0;
		wtw;
		nul;

	<End_RightShift>


	pop ar6,gr6;
	pop ar5,gr5;
	pop ar0,gr0;
	return;
.wait;
end ".text_nmplv";
