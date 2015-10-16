//***************************************************************************
//*                                                                         *
//*                    Neuroprocessor NM6403 SDK v.1.2                      *
//*                                                                         *
//*               Signed Fixed Point 32-bit Routine                         *
//*                                                                         *
//*   ������� �� N    �������� �������� log(1+pow(2,i)) i=0,-1,..-N+1       *
//*             �������� ������������ � Fixed Point ���� �                  *
//*               ���������� �������� =FIXPOINT                             *
//*                                                                         *
//*          16.01.2000 (c) RC Module Inc., Moscow, Russia                  *
//*                                                                         *
//***************************************************************************
//FIXPOINT=16
//N=20
data ".data_nmplc_G" 
global LogTable:word[20]=( 
	00000B172h, // 0x10000*log(1+pow(2,0))
	0000067CDh, // 0x10000*log(1+pow(2,-1))
	000003920h, // 0x10000*log(1+pow(2,-2))
	000001E27h, // 0x10000*log(1+pow(2,-3))
	000000F85h, // 0x10000*log(1+pow(2,-4))
	0000007E1h, // 0x10000*log(1+pow(2,-5))
	0000003F8h, // 0x10000*log(1+pow(2,-6))
	0000001FEh, // 0x10000*log(1+pow(2,-7))
	000000100h, // 0x10000*log(1+pow(2,-8))
	000000080h, // 0x10000*log(1+pow(2,-9))
	000000040h, // 0x10000*log(1+pow(2,-10))
	000000020h, // 0x10000*log(1+pow(2,-11))
	000000010h, // 0x10000*log(1+pow(2,-12))
	000000008h, // 0x10000*log(1+pow(2,-13))
	000000004h, // 0x10000*log(1+pow(2,-14))
	000000002h, // 0x10000*log(1+pow(2,-15))
	000000001h, // 0x10000*log(1+pow(2,-16))
	000000000h, // 0x10000*log(1+pow(2,-17))
	000000000h, // 0x10000*log(1+pow(2,-18))
	000000000h
);
end ".data_nmplc_G"; 
//***************************************************************************
//*                                                                         *
//*                    Neuroprocessor NM6403 SDK v.1.2                      *
//*                                                                         *
//*               Signed Fixed Point 32-bit Routine                         *
//*                                                                         *
//* ������� �� N �������� �������� log(1+pow(2,i)) i=15,14,..,0,-1,..-N+1   *
//*             �������� ������������ � Fixed Point ���� �                  *
//*               ���������� �������� =FIXPOINT                             *
//*                                                                         *
//*          16.01.2000 (c) RC Module Inc., Moscow, Russia                  *
//*                                                                         *
//***************************************************************************
//FIXPOINT=16
//N=31
data ".data_nmplc_G" 
global LogBigTable:word[31]=( 
	00009B441h, // 0x10000*log(1+pow(2,14))
	0000902D3h, // 0x10000*log(1+pow(2,13))
	000085169h, // 0x10000*log(1+pow(2,12))
	00007A007h, // 0x10000*log(1+pow(2,11))
	00006EEB5h, // 0x10000*log(1+pow(2,10))
	000063D83h, // 0x10000*log(1+pow(2,9))
	000058C90h, // 0x10000*log(1+pow(2,8))
	00004DC1Dh, // 0x10000*log(1+pow(2,7))
	000042CA5h, // 0x10000*log(1+pow(2,6))
	000037F1Bh, // 0x10000*log(1+pow(2,5))
	00002D54Dh, // 0x10000*log(1+pow(2,4))
	00002327Dh, // 0x10000*log(1+pow(2,3))
	000019C04h, // 0x10000*log(1+pow(2,2))
	00001193Fh, // 0x10000*log(1+pow(2,1))
	00000B172h, // 0x10000*log(1+pow(2,0))
	0000067CDh, // 0x10000*log(1+pow(2,-1))
	000003920h, // 0x10000*log(1+pow(2,-2))
	000001E27h, // 0x10000*log(1+pow(2,-3))
	000000F85h, // 0x10000*log(1+pow(2,-4))
	0000007E1h, // 0x10000*log(1+pow(2,-5))
	0000003F8h, // 0x10000*log(1+pow(2,-6))
	0000001FEh, // 0x10000*log(1+pow(2,-7))
	000000100h, // 0x10000*log(1+pow(2,-8))
	000000080h, // 0x10000*log(1+pow(2,-9))
	000000040h, // 0x10000*log(1+pow(2,-10))
	000000020h, // 0x10000*log(1+pow(2,-11))
	000000010h, // 0x10000*log(1+pow(2,-12))
	000000008h, // 0x10000*log(1+pow(2,-13))
	000000004h, // 0x10000*log(1+pow(2,-14))
	000000002h, // 0x10000*log(1+pow(2,-15))
	000000001h  // 0x10000*log(1+pow(2,-16))
);
end ".data_nmplc_G"; 
