#include "nmtype.h"

int SIG_SetResampleDown2_8u8u(nm64s* pKernel)
{
	pKernel[0]=0x00000000000000001l;
	pKernel[1]=0x00000000000000001l;
	pKernel[2]=0x00000000000000100l;
	pKernel[3]=0x00000000000000100l;
	pKernel[4]=0x00000000000010000l;
	pKernel[5]=0x00000000000010000l;
	pKernel[6]=0x00000000001000000l;
	pKernel[7]=0x00000000001000000l;
	pKernel[8]=0x00000000100000000l;
	pKernel[9]=0x00000000100000000l;
	pKernel[10]=0x00000010000000000l;
	pKernel[11]=0x00000010000000000l;
	pKernel[12]=0x00001000000000000l;
	pKernel[13]=0x00001000000000000l;
	pKernel[14]=0x00100000000000000l;
	pKernel[15]=0x00100000000000000l;
	return 16<<1;
}