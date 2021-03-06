//***************************************************************************/
//*                                                                         */
//*                    Neuroprocessor NM6403 SDK v.1.2                      */
//*                                                                         */
//*				Signed Fixed Point 32-bit Routine                           */
//*                                                                         */
//*             ��������� ����� � ������������� �������                     */
//*                                                                         */
//*                                                                         */
//*                1999 (c) RC Module Inc., Moscow, Russia                  */
//***************************************************************************/
//	Arg1 - Dividend
//  Arg2 - Divisor
//--------------------------
//	Res1 - 
//const FIXPOINT=16; //��������� �������� ����� � 32-� ��������� �����

// begin ".text_nmpl�"
//! \fn  int SCL_FixMul32(int nX, int nY)
//!
//! \perfinclude _SCL_FixMul32__Fii.html
/*
global _SCL_FixMul32 :label;
<_SCL_FixMul32>
.branch;
	ar5=ar7-4;
	push ar0,gr0;
	push ar1,gr1;
	gr1=[ar5++]; //Arg1
	gr7=[ar5++]; //Arg2
	//������������ �����
	ar5=ar7 with gr0 = gr1*:gr7;
	.repeat 15;
	gr0 = gr1 *gr7;
	.endrepeat;
	// ���������� ���������� � fixed-point ���� - ����� �������� �����
	with gr0<<=32-FIXPOINT;
    with gr7>>=FIXPOINT;
    with gr7= gr0 or gr7;
	pop ar1,gr1;
	pop ar0,gr0;
return ;
.wait;

end ".text_nmpl�";
*/

int SCL_FixMul32(int a, int b) {
	long long r=a;
	r*=b;
	r>>=(16);
	return r;
}
