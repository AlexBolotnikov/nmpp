//-----------------------------------------------------------------------------
//
// $Workfile:: SadV16.asm                             $
//
// Vector processing library
//
// $Revision: 1.1 $        $Date: 2004/11/22 13:50:13 $
//
//! \if file_doc
//!
//! \file   SadV16.asm
//! \author Sergey Mushkaev
//! \breif  Weight table
//! 
//! \endif 
//!
//----------------------------------------------------------------------------


data ".data_nmplv_G"
	global _VEC_TBL_Diagonal_00000001h_Interlace_G:	long[5] = (
		0000000000000000hl,		0000000000000001hl,	
		0000000000000000hl,		0000000100000000hl,	
		0000000000000000hl);
end ".data_nmplv_G";

data ".data_nmplv_L"
	global _VEC_TBL_Diagonal_00000001h_Interlace_L:	long[5] = (
		0000000000000000hl,		0000000000000001hl,	
		0000000000000000hl,		0000000100000000hl,	
		0000000000000000hl);
end ".data_nmplv_L";

