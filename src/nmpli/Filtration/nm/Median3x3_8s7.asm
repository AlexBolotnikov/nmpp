//------------------------------------------------------------------------
//
//  $Workfile:: ResizeDown2Y_C7.as              $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/02/10 12:36:39 $
//
//! \if file_doc
//!
//! \file   ResizeDown2Y_C7.asm
//! \author S. Mushkaev
//! \brief  Median filter 3x3 (9.0 - clocks per pixel)
//!
//! \endif
//!
//------------------------------------------------------------------------

//***************************************************************************/
//*                                                                         */
//*                    Neuroprocessor NM6403 SDK v.1.0                      */
//*                                                                         */
//*              Median filter 3x3 for 8bit-pixel matrix 384x288            */
//*                                                                         */
//*                 Filter performance :  9.0 - cycles per pixel            */
//*                 Src - In Local                                          */
//*                 Dst - In Global                                         */
//*                 Text - In Local                                         */ 
//*                                                                         */
//*                1999 (c) RC Module Inc., Moscow, Russia                  */
//***************************************************************************/
                                                                                       
global _CopyFrame__FPcPci: label;
global _void._.8.8CopyFrame.1char._.0.9._char._.0.9._int.2 :label;
global _ShiftLeft__FPcPci:label;
global _void._.8.8ShiftLeft.1char._.0.9._char._.0.9._int.2 :label;
global _ShiftRight__FPcPci:label;
global _void._.8.8ShiftRight.1char._.0.9._char._.0.9._int.2 :label;

//--------- Matrix parameters --------------------------------------------------------
// Width=384;				// ����������� ������� �� � (������ ������� � 8�. ���������) (������ 8)
// Height=288;			// ����������� ������� �� Y (������ ������  � ������� ) (������ 32) 
//------------------------------------------------------------------------------------
// Max_X=Width/8;		// ����������� ������� �� � � 64-������ �������� 
// Max_Y=Height;			// ����������� ������� �� Y � ������� 
// Max_Y_32 = Height/32;	// ������ ������� � ������ �� 32 ������� � ������


//**************** LOCAL ************************************************************
data ".data_nmpli_L"
	Width2_8:word;
	Height_32:word;

	//global	_SrcMatrix	:long[Max_X*Max_Y] = (0hl dup Max_X*Max_Y); // �������� ������
	//--------------------------------------------------------
	L0		:word;//long [Height] = ( 0hl dup Height );		// ������������� �����
	L1		:word;//long [Height] = ( 0hl dup Height );		// ������������� �����
	L2		:word;//long [Height] = ( 0hl dup Height );		// ������������� �����
 	ShiftMatrix : long [32] =  // �������, ����������� ������ 3 �������� �������� �� ������ ��������, ��� ����������� �� ����������� ��������� ����� �����
				(
				// ***** ����� ������� ����� �� ���� ���� ***** 
					// ����� ������������ ������� �� 8 ��� �����
					0000000000000100hl,
					0000000000010000hl,
					0000000001000000hl,
					0000000100000000hl,
					0000010000000000hl,
					0001000000000000hl,
					0100000000000000hl,
					0000000000000000hl,
					// ������� �������� ����� �� �������(��������) ������� � ������� ���� ������������
					0000000000000000hl,
					0000000000000000hl,
					0000000000000000hl,
					0000000000000000hl,
					0000000000000000hl,
					0000000000000000hl,
					0000000000000000hl,
					0000000000000001hl,
				//***** C���� ������� ������ �� ���� ���� ****
					// ����� ������������ ������� �� 8 ��� ������
					0000000000000000hl,
					0000000000000001hl,
					0000000000000100hl,
					0000000000010000hl,
					0000000001000000hl,
					0000000100000000hl,
					0000010000000000hl,
					0001000000000000hl,
					// ������� �������� ����� �� ������(��������) ������� � ������� ���� ������������
					0100000000000000hl,
					0000000000000000hl,
					0000000000000000hl,
					0000000000000000hl,
					0000000000000000hl,
					0000000000000000hl,
					0000000000000000hl,
					0000000000000000hl
				);
	AR6 : word =0;												// ������ ��� �������� ar6
	GR5 : word =0;
		
end ".data_nmpli_L";

//**********  Global ********************
data ".data_nmpli_G"
	//global  _DstMatrix	:long [Max_X*Max_Y] = (0hl dup Max_X*Max_Y);	// �������������� �������
	//------------------------------------------------------------
	ShiftRightMask	:long = 0FEFEFEFEFEFEFEFEhl;			// ����� ��� ������ ������
	G0	:word;//long [Height] = ( 0hl dup Height );				// ������������� �����
	G1	:word;//long [Height] = ( 0hl dup Height );				// ������������� �����
	G2	:word;//long [Height] = ( 0hl dup Height );				// ������������� �����
	GDiffMask :word;//long [Height] = ( 0hl dup Height );			// ������ ��� �������� �������� ������������ ��������
	//-------------------------------------------------------------
end ".data_nmpli_G";

macro PUSH_REGS()
    push ar0, gr0;
    push ar1, gr1;
    push ar2, gr2;
    push ar3, gr3;
    push ar4, gr4;
    push ar5, gr5;
    push ar6, gr6;
end PUSH_REGS;

macro POP_REGS()
    pop ar6, gr6;
    pop ar5, gr5;
    pop ar4, gr4;
    pop ar3, gr3;
    pop ar2, gr2;
    pop ar1, gr1;
    pop ar0, gr0;
end POP_REGS;


macro WTW_REG(reg)
.wait;
   nb1 = reg;
   //nb1 = 80808080h;
   wtw;											
.branch;
end WTW_REG;

//*********** TEXT ****************
begin ".text_nmpli"


//////////////////////////////////////////////////////////////////////////////////////////
//																						//
//    ��������� ���������� ������ ���� �������� ��������� � ������� ������� ��������	//
//    � ������ �������. C���� ������� ������� ����� � ������ �� ���� �������			//
//																						//
//////////////////////////////////////////////////////////////////////////////////////////
<ShiftLR> 
.branch;
	//------- INPUT PARAMETERS --------------------------------------
	//ar0 = Src1				// �������� �������			(Global)
	//ar4 = L0;				// ������� ��������� ������	(Local)
	//ar5 = G0;				// ������� ��������� �����	(Global)
	//ar6 = ShiftMatrix			// ������� ������			(Local)
	//---------------------------------------------------------------
	nul;
	ar1 = ar0 - 2; 				// ����� �������� ������� ���. ������� ����������� � SrcMatrix  
	ar2 = ar0 + 2;				// ������ �������� ������� ���. ������� ����������� � SrcMatrix  
	gr0 = [Width2_8];				// ��� ������ ��� ����������������� ���������� �����. ������� 
	gr6 = -2*32 with gr1=gr0;	// ����. ��� �������������� ar6 + ��� ������ ��� ����������������� ���������� �����. ������� 
	gr7 = [Height_32] with gr2=gr0;// ����. ������� + ��� ������ ��� ����������������� ���������� ������. �������    
	gr3 = 80808080h with gr7--;
	<ShiftLRColumn>
		rep 32 ram = [ar0++gr0],ftw with vsum ,data,0;		//G* �����. ������� SrcMatrix => RAM �� ������� ������ (����� � ��������� ����) 
		WTW_REG(gr3);
		rep 32 data = [ar1++gr1],ftw with vsum ,data,afifo;	//G* ������� �������� ����� �� ����� ������� � ������� ���� ������� ���������� ������(����� � ��������� ����)
		ar6=ar6 + gr6 ;										//* �������������� ��������� �� Shift Matrix
		WTW_REG(gr3);
		rep 32 [ar4++] = afifo, ftw with vsum , ram,0;		//G ������ ������� ��������� ������ � L0
		WTW_REG(gr3);
		rep 32 wfifo = [ar6++];								//L* �������� ������ ������
		rep 32 data = [ar2++gr2],ftw with vsum ,data,afifo;	//G* ������� �������� �������� �� ������ ������� � ������� ������� ������� ���������� �����(������ � ��������� ����)
		WTW_REG(gr3);		
	if <>0 delayed goto ShiftLRColumn 	with gr7--;								//*
		rep 32 [ar5++] = afifo;								//L* ������ ������� ��������� ����� � G0
		nul;
												
return;
.wait;

//////////////////////////////////////////////////////////////////////////////////////////
//																						//
//    ��������� ��������� � ������ ������������ � ������������� �� ����	��������		//
//		DstMin=Min(Src1,SrcMatrix); -> Local											//
//		DstMax=Max(Src1,SrcMatrix); -> Global											//
//																						//
//////////////////////////////////////////////////////////////////////////////////////////
<Dst_MinL_MaxG> 
.branch;
//.wait;
//------------ INPUT PARAMETERS ----------------
 	//ar0 = Src1;	������ ������������ ������	// Local 
	//ar1 = Src2;	������ ��.������ -DstMatrix	// Global 
	//ar4 = DiffMask; �������� ����� ���������	// Global 
	//ar3 = DstMin;	  �������(��������)			// Local  
	//ar6 = DstMax;	  ��������(��������)		// Global 
//---------------------------------------------
	gr4 = ar7;
	gr1 = [Width2_8];
	gr6 = [Height_32] ;
	
	ar2 = ar1 with gr2 = gr1;
	ar7 = ar1 with gr7 = gr1;
	ar5 = ar4 with gr6--;
	
	<Dst_MinL_MaxG_Column>
		rep 32  ram = [ar0++];							//* ��������  1 ������� �� Src1
		rep 32 data = [ar1++gr1] with ram - data;		// ��������� 2 ������� �� �������
		rep 32 [ar4++]= afifo with activate afifo;		// ������ � DiffMask ��������, ��������� ����� ���������
		
		rep 32 data = [ar2++gr2] with mask afifo,ram,data;	// ������ ��������� �� 1 � 2 �������
		rep 32 [ar3++] = afifo;							//* ������ �������� � DstMin
		rep 32 data = [ar5++] with activate data ;		//* �������� �� DiffMask �������� � ��������� ����� ���������
	
	if <>0  delayed goto Dst_MinL_MaxG_Column with gr6--;
		rep 32 data = [ar7++gr7] with mask afifo,data,ram; // ������ ���������� �� 1 � 2 �������
		rep 32 [ar6++]=afifo;							//* ������ ��������� � DstMax
		
	ar7 = gr4;
return;
.wait;


//////////////////////////////////////////////////////////////////////////////////////////
//																						//
//    ��������� ��������� � ������ ������������ � ������������� �� ����					//
//		DstMin=Min(Src1,Src2); -> Local													//
//		DstMax=Max(Src1,Src2); -> Global												//
//																						//
//////////////////////////////////////////////////////////////////////////////////////////
<MinL_MaxG> 
.branch;
//.wait;
//------------ INPUT PARAMETERS ----------------
 	//ar0 = Src1;	������ ������������ ������	// Local  
	//ar1 = Src2;	������ ������������	������	// Global 
	//ar4 = DiffMask; �������� ����� ���������	// Global 
	//ar3 = DstMin;	  �������(��������)			// Local  
	//ar6 = DstMax;	  ��������(��������)		// Global 
//---------------------------------------------
	gr6 = ar7;
	gr1 = [Width2_8];
	gr7 = [Height_32] ;
	
	ar2 = ar1 with gr2 = gr1;
	ar7 = ar1 with gr2 = gr1;
	ar5 = ar4 with gr7--;
	
	<MinL_MaxG_Column>
		rep 32  ram = [ar0++];							//* ��������  1 ������� �� Src1
		rep 32 data = [ar1++] with ram - data;			// ��������� 2 ������� �� �������
		rep 32 [ar4++]= afifo with activate afifo;		// ������ � DiffMask ��������, ��������� ����� ���������
		
		rep 32 data = [ar2++] with mask afifo,ram,data;	// ������ ��������� �� 1 � 2 �������
		rep 32 [ar3++] = afifo;							//* ������ �������� � DstMin
		rep 32 data = [ar5++] with activate data ;		//* �������� �� DiffMask �������� � ��������� ����� ���������
			
		
	if <>0  delayed goto MinL_MaxG_Column with gr7--;
		rep 32 data = [ar7++] with mask afifo,data,ram; // ������ ���������� �� 1 � 2 �������
		rep 32 [ar6++]=afifo;							//* ������ ��������� � DstMax
		
	ar7 = gr6;
return;
.wait;


//////////////////////////////////////////////////////////////////////////////////////////
//																						//
//    ��������� ��������� � ������ ������������ � ������������� �� ����					//
//		DstMin=Min(Src1,Src2); -> Global
//		DstMax=Max(Src1,Src2); -> Local
//																						//
//////////////////////////////////////////////////////////////////////////////////////////
<MaxL_MinG>
.branch;
//.wait;
//------------ INPUT PARAMETERS ----------------
 	//ar0 = Src1;	������ ������������ ������	// Local  
	//ar1 = Src2;	������ ������������	������	// Global 
	//ar4 = DiffMask; �������� ����� ���������	// Global 
	//ar3 = DstMin;	  �������(��������)			// Local  
	//ar6 = DstMax;	  ��������(��������)		// Global 
//---------------------------------------------
	gr6 = ar7;
	gr1 = [Width2_8];
	gr7 = [Height_32] ;
	
	ar2 = ar1 with gr2 = gr1;
	ar7 = ar1 with gr2 = gr1;
	ar5 = ar4 with gr7--;
	
	<MaxL_MinG_Column>
		rep 32  ram = [ar0++];							//* ��������  1 ������� �� Src1
		rep 32 data = [ar1++] with data - ram ;			// ��������� 2 ������� �� �������
		rep 32 [ar4++]= afifo with activate afifo;		// ������ � DiffMask ��������, ��������� ����� ���������
		
		rep 32 data = [ar2++] with mask afifo,ram,data;	// ������ ���������� �� 1 � 2 �������
		rep 32 [ar3++] = afifo;							//* ������ ��������� � DstMax
		rep 32 data = [ar5++] with activate data ;		//* �������� �� DiffMask �������� � ��������� ����� ���������
			
		
	if <>0  delayed goto MaxL_MinG_Column with gr7--;
		rep 32 data = [ar7++] with mask afifo,data,ram; // ������ ��������� �� 1 � 2 �������
		rep 32 [ar6++]=afifo;							//*������ �������� � DstMin 
		
	ar7 = gr6;
return;
.wait;

//////////////////////////////////////////////////////////////////////////////////////////
//																						//
//    ��������� ��������� � ������ ������������ �� ���� ���������						//
//	  Dst=Min( Min(Src1,Src2),Src3)														//
//																						//
//////////////////////////////////////////////////////////////////////////////////////////
<MinMin>  
.branch;
//.wait;
	//------- INPUT PARAMETERS -------------------------------------
	//ar0 = Src1; ������ ������������ ������		Global
	//ar1 = Src2; ������ ������������ ������		Global
	//ar3 = Src3; ������ ������������� ������		Global
	//ar6 = DstMin ; ��������� ���������			Local
	//--------------------------------------------------------------
	gr7 = [Height_32];			// �������
	ar4 = ar1;				// ������ ������������ �������	
	ar2 = ar3 with gr7--;	// ������ ������������ �������	
	<MinMin_Column>
		rep 32 ram = [ar0++];							//* ��������  Src1
		rep 32 data = [ar4++] with ram - data ;			// ��������� Src2 �� Src1
 		rep 32 with activate afifo;						// ��������� ����� ��������� 
		rep 32 data = [ar1++] with mask afifo,ram,data; // ������ ��������� �� Src1 � Src2
		rep 32 [ar6],ram= afifo;						// ����������� ��������� � RAM
		rep 32 data = [ar2++] with ram - data;			// ��������� Src3 �� Min(Src1,Src2)
		rep 32 with activate afifo;						// ��������� ����� ��������� 
	if <>0 delayed goto MinMin_Column with gr7--;		
		rep 32 data = [ar3++] with mask afifo,ram,data;	// ������ ��������� �� Src3 � Min(Src1,Src2)
		rep 32 [ar6++]=afifo;							//* ������ �������� � DstMin
return;
.wait;
//////////////////////////////////////////////////////////////////////////////////////////
//																						//
//    ��������� ��������� � ������ ������������ �� ���� ���������						//
//	  Dst=Max( Min(Src1,Src2),Src3)														//
//																						//
//////////////////////////////////////////////////////////////////////////////////////////
<MinMax> 
.branch;
	//------- INPUT PARAMETERS -------------------------------------
	//ar0 = Src1; ������ ������������ ������		Global
	//ar1 = Src2; ������ ������������ ������		Global
	//ar3 = Src3; ������ ������������� ������		Global
	//ar6 = Dst ; ��������� ���������				Local
	//--------------------------------------------------------------
	gr7 = [Height_32];			// �������
	ar4 = ar1;				// ������ ������������ �������	
	ar2 = ar3 with gr7--;	// ������ ������������ �������	
	<MinMax_Column>
		rep 32 ram  = [ar0++];							//* ��������  Src1
		rep 32 data = [ar4++] with ram - data ;			// ��������� Src2 �� Src1
 		rep 32 with activate afifo;						// ��������� ����� ��������� 
		rep 32 data = [ar1++] with mask afifo,ram,data;	//* ������ ��������� �� Src1 � Src2
		rep 32 [ar6],ram= afifo;						// ����������� ��������� � RAM
		rep 32 data = [ar2++] with ram - data;			// ��������� Src3 �� Min(Src1,Src2)
		rep 32 with activate afifo;						// ��������� ����� ��������� 
	if <>0 delayed goto MinMax_Column with gr7--;		
		rep 32 data = [ar3++] with mask afifo,data,ram;	//������ ���������� �� Src3 � Min(Src1,Src2)
		rep 32 [ar6++]=afifo;							//* ������ ���������� � DstMax
return;
.wait;


//////////////////////////////////////////////////////////////////////////////////////////
//																						//
//			Dst=Max(Min(Max(Max(Src1,Src2),Src3),Src4),Src5) 							//
//																						//
//////////////////////////////////////////////////////////////////////////////////////////

<MaxMaxMinMax> 
.branch;
//.wait;
	//------- INPUT PARAMETERS -------------------------------------
	//ar4 = Src1; ������ ������������ ������    (Global)
	//gr1 = Src2; ������ ������������ ������	(Global)
	//gr2 = Src3; ������ ������������ ������ 	(Global)
	//gr4 = Src4; ��������� ������������ ������ (Global)
	//gr6 = Src5; ����� ������������ ������		(Global)
	//ar3 = Dst ; ��������� 					(Local)
	//--------------------------------------------------------------
	ar0 = 0;
	gr5 = 2*32 with gr0=gr1;
	gr7 = [Height_32];										// �������
	gr3 = [Width2_8] with gr7--;
	<MaxMaxMinMaxColumn>
		rep 32 ram = [ar4++];							//* ��������  Src1
			ar1 = ar0 + gr0;							//ar1=Src2
			ar2 = ar0 + gr0 with gr0 = gr2 noflags;				//ar2=Src2
		rep 32 data = [ar1++] with data - ram ;			// ��������� Src2 �� Src1
		rep 32 with activate afifo;						// ��������� ����� ��������� 
		rep 32 data = [ar2++] with mask afifo,ram,data;	//* ������ Max(Src1,Src2)
		rep 32 [ar4],ram= afifo;						// ������ ���������� ���������� � RAM
			ar1 = ar0 + gr0;							//ar1=Src3
			ar2 = ar0 + gr0 with gr0 = gr4 noflags;				//ar2=Src3
		rep 32 data = [ar1++] with data - ram;			// ��������� Src3 �� Max(Src1,Src2)
		rep 32 with activate afifo;						// ��������� ����� ��������� 
		rep 32 data = [ar2++] with mask afifo,ram,data;	// ������ Max(Max(Src1,Src2),Src3)
		rep 32 [ar4],ram=afifo;							// ������ ���������� ���������� � RAM
			ar1 = ar0 + gr0;							//ar1=Src4
			ar2 = ar0 + gr0 with gr0 = gr6 noflags;				//ar2=Src4
		rep 32 data = [ar1++] with ram - data ;			// ��������� Max(Max(Src1,Src2),Src3) �� Src4
		rep 32 with activate afifo;						// ��������� ����� ��������� 
		rep 32 data = [ar2++] with mask afifo,ram,data;	// ������ Min(Max(Max(Src1,Src2),Src3),Src4)
		rep 32 [ar4],ram = afifo;						// ������ ���������� ���������� � RAM
			ar1 = ar0 + gr0 with gr1+=gr5 noflags;		//ar1=Src5, Src2=Src2+2*32
			ar2 = ar0 + gr0 with gr2+=gr5 noflags;		//ar2=Src5,	Src3=Src3+2*32
			with gr4+=gr5 noflags;								//			Src4=Src4+2*32
			with gr6+=gr5 noflags;								//			Src5=Src5+2*32
			with gr0 = gr1 noflags;
		rep 32 data = [ar1++] with data - ram;			// ��������� Src5 �� Min(Max(Max(Src1,Src2),Src3),Src4)
		rep 32 with activate afifo;						// ��������� ����� ��������� 
	if <>0  delayed goto MaxMaxMinMaxColumn with gr7--;							
		rep 32 data = [ar2++] with mask afifo,ram,data;	// ������ Max(Min(Max(Max(Src1,Src2),Src3),Src4),Src5)
		rep 32 [ar3++gr3] = afifo;						// ������ ���������� ����������

return;
.wait;


///////////////////////////////////////////////////////////////////////////////////////
//***********************************************************************************//
//*																					*//
//*	��������� ��������� ���������� ����� 3�3 ��� �������� �� 8-��������� ���������	*//
//*																					*//
//***********************************************************************************//
///////////////////////////////////////////////////////////////////////////////////////
//global _IMG_Median3x3__F5nm8s7P5nm8s7PiiPvPv :label;
//<_IMG_Median3x3__F5nm8s7P5nm8s7PiiPvPv>
<_void._.8.8IMG_Median3x3.1class._nm8s7._.0.9._class._nm8s7._.0.9._int.9._int.9._void._.0.9._void._.0.2>
global _IMG_Median3x3__FPcPciiPvPv :label;
global _void._.8.8IMG_Median3x3.1char._.0.9._char._.0.9._int.9._int.9._void._.0.9._void._.0.2 :label;
<_IMG_Median3x3__FPcPciiPvPv>
<_void._.8.8IMG_Median3x3.1char._.0.9._char._.0.9._int.9._int.9._void._.0.9._void._.0.2>
.branch;
    ar5 = ar7 - 2;
    PUSH_REGS();
//******* ��������������� �������� WFIFO *******************************************************
	ar6 = ShiftMatrix;	// ������� ������
	gr3 = 80808080h;      
	nb1 = gr3;
	f1cr= 80808080h;
	sb  = 02020202h;
	rep 32 wfifo = [ar6++],ftw;
	WTW_REG(gr3);
	[AR6]=ar6;			// ���������� ar6

//***[0]****************************************************************************************
	ar0 = [--ar5];				// Src - SrcMatrix ������� �������
	ar4 = [--ar5];				// Dst - DstMatrix ������� ��������,��������� �� ��� ������ 
	gr0 = [--ar5];				// Width
	gr4 = [--ar5] with gr0>>=2;	// Height
	gr1 = [--ar5];				// Local Buffer
	gr2 = [--ar5];				// Global Buffer
	gr7 = gr4<<1;
	[L0]=gr1 with gr1+=gr7;
	[L1]=gr1 with gr1+=gr7;
	[L2]=gr1;
	[G0]=gr2 with gr2+=gr7;
	[G1]=gr2 with gr2+=gr7;
	[G2]=gr2 with gr2+=gr7;
	[GDiffMask]=gr2;
	[Width2_8]=gr0 with gr4>>=5;
	[Height_32]=gr4;

	//call ShiftRight;
//*******************************************************************************************
	ar1 = ar0;//[ar5++];		// �������� ������� - DstMatrix (_SrcMatrx-��������� �� 1 ��� ������)
	ar2 = ar4;//[ar5++];		// �������������� ������� -SrcMatrix
	gr5 = [Width2_8];			// ������� = ����� �������
	gr1 = 2 with gr5>>=1;		// ��� �������� �� ������� � �������
	[GR5]=gr5 with gr2 = gr1;	// ��� �������� �� ������� � �������;
    push ar5, gr5;
	push ar2,gr2;		// DstMatrix=> stack
	push ar1,gr1;		// SrcMatrix=> stack

	<AllColumn>
	//***[1]*****************************************************************************************		
		pop ar1,gr1;
		ar0 = ar1;			// Src1- _SrcMatrix;
		push ar1,gr1;
		ar4 = [G0];			// Dst1- ������� ��������� �����
		ar5 = [L0];			// Dst2- ������� ��������� ������
		delayed call ShiftLR;
		ar6 = [AR6];
		[AR6] = ar6;
	//***[2]*****************************************************************************************
		ar0 = [L0];			// Src1 - ������� ��������� ����� 
		ar1 = [G0];			// Src2 - ������� ��������� ������
		ar4 = [GDiffMask];	
		ar3 = [L1];			// DstMax - ��������
		delayed call MaxL_MinG;
		ar6 = [G1];			// DstMin - �������
	//***[3]*****************************************************************************************		
		pop ar0,gr0;
		ar1 = ar0;			// Src2- _DstMatrix;
		ar0 = ar0 + gr0;	// ������� � ��������� �������
		push ar0,gr0;
		ar0 = [L1];			// Src1 - �������� �� [1]
		ar4 = [GDiffMask];	
		ar3 = [L0];			// DstMin - ������� 
		delayed call Dst_MinL_MaxG;
		ar6 = [G0];			// DstMax - ��������
	//***[4]****************************************************************************************
		ar0 = [L0];			// Src1 - ������� �� [3]
		ar1 = [G1];			// Src2 - ������� �� [2]
		ar4 = [GDiffMask];	
		ar3 = [L1];			// DstMax - ��������
		delayed call MaxL_MinG;
		ar6 = [G2];			// DstMin - �������
	//***[5]*****************************************************************************************
		ar0 = [G0];			// Src1 - �������� �� [3]
		ar3 = [G0];			// Src3 - �������� �� [3] 
		ar6 = [L0];			// DstMin - ������� 
		delayed call MinMin;
			ar1 = ar0-2;	// Src2 - �������� �� [3]
	//***[7]*****************************************************************************************
		ar0 = [L1];			// Src1 - �������� �� [4]
		ar4 = [GDiffMask];
		ar3 = [L2];			// DstMin - ������� 
		ar6 = [G0];			// DstMax - ��������
		delayed call MinL_MaxG;
			ar1 = ar0+2;	// Src2 - �������� �� [4]
	//***[8]*****************************************************************************************
		ar0 = [L1];
		ar1 = [G0];			// Src2 - �������� �� [7]	
		ar3 = [L2];			// Src3 - ������� ��  [7]	
		ar6 = [G1];			// Dst - �������
		delayed call MinMax;
			ar0-=2;			// Src1 - �������� �� [4]	
	//***[10]*****************************************************************************************
		ar0 = [L0];			// Src1 - ������� �� [6]
		ar1 = [G1];			// Src2 - ������� �� [8]
		ar4 = [GDiffMask];
		ar3 = [L1];			// DstMin - ������� 
		delayed call MinL_MaxG;	
			ar6 = [G0];		// DstMax - ��������
	//***[11]*****************************************************************************************
		pop ar1,gr1;
		 pop ar5,gr5;
		  ar3 = ar5;		// Dst - _SrcMatrix;
		  ar5 = ar5 + gr5;	// ������� � ��������� �������
		 push ar5,gr5;
		push ar1,gr1;

		gr4 = [G2];						// �������� �� [4]
		ar4 = gr4 with gr1 = gr4 - gr5; // Src1 G2-2;  
										// Src2
		gr6 = [L1] with gr2 = gr4 + gr5;// Src5 G2+2
										// Src3
		delayed call MaxMaxMinMax;
			gr4 = [G0];						// Src4
	//********************************************************************************************
		gr5=[GR5];
		gr5--;
	if <>0 delayed goto AllColumn;
		[GR5]=gr5;
//***[15]*****************************************************************************************
	pop ar1,gr1;
	pop ar1,gr1;
    pop ar5, gr5;
	//ar0 = [--ar5];	// Src1 - ��������������� ������� 
	//ar4 = [--ar5];	// Dst - ������� , ��������� ����� �� ���� ���
	//call ShiftLeft;
//***********************************************************************************************
	ftw;
	nul;
	
    POP_REGS();
	return;
.wait;

<_CopyFrame__FPcPci>
<_void._.8.8CopyFrame.1char._.0.9._char._.0.9._int.2>
.branch;
    ar5 = ar7 - 2;
    push ar0, gr0;
    push ar4, gr4;

    ar0 = [--ar5];  //  Source Buffer; Size: SIZE8
    ar4 = [--ar5];  //  Result Buffer; Size: SIZE8
    gr0 = [--ar5];	//  Length in chars
    gr0>>=8;
	gr0--;
	<CL7>    
    if > delayed goto CL7 with gr0--;
		rep 32 data = [ar0++] with data;
		rep 32 [ar4++] = afifo;

    pop ar4, gr4;
    pop ar0, gr0;
    return;
.wait;


//////////////////////////////////////////////////////////////////////////////////////////
//																						//
//	C���� ������� �� ���� ��� ����� - �������������� 7-���������� �� ������ �			//
//        8-���������� ���������� �����													//
//																						//
//////////////////////////////////////////////////////////////////////////////////////////
<_ShiftLeft__FPcPci> 
<_void._.8.8ShiftLeft.1char._.0.9._char._.0.9._int.2>
.branch;
	//------- INPUT PARAMETERS --------------------------------------
	//ar0 = _Src; (_SrcMatrix)				// ������� ��������� �����	
	//ar4 = _Dst; (_DstMatrix)				// ������� ��������� ������ 
	//---------------------------------------------------------------
    ar5 = ar7 - 2;
    push ar0, gr0;
    push ar4, gr4;

    ar0 = [--ar5];  //  Source Buffer; Size: SIZE8
    ar4 = [--ar5];  //  Result Buffer; Size: SIZE8
    gr0 = [--ar5];  //	Length in chars
    with gr0>>=8;
	nb1 = 80808080h with gr0--;
	wtw;

	<ShiftLeftAll_>	
	if > delayed goto ShiftLeftAll_ with gr0--;
		rep 32 data = [ar0++] with  data+data;	//* C���� ������� �� ���� ��� ����� 
		rep 32 [ar4++] = afifo;					//* ������ ������� ��������� ������ � G0

	pop ar4,gr4;
	pop ar0,gr0;
return;
.wait;
//////////////////////////////////////////////////////////////////////////////////////////
//																						//
//	C���� ������� �� ���� ��� ����� - �������������� 8-����������� ����������� ����� �	//
//         7-��������� �� ������														//
//																						//
//////////////////////////////////////////////////////////////////////////////////////////
<_ShiftRight__FPcPci> 
<_void._.8.8ShiftRight.1char._.0.9._char._.0.9._int.2>
.branch;
	//------- INPUT PARAMETERS --------------------------------------
	//ar0 = _SrcMatrix;				//L �������� ������� 
	//ar4 = _DstMatrix;				//G ������� ��������,��������� �� ��� ������
	//ar6 = ShiftRightMask			//G ����� ��� ������ ������
	//---------------------------------------------------------------
    ar5 = ar7 - 2;
    push ar0, gr0;
    push ar4, gr4;

	ar4 = ShiftRightMask; // ������� ������
	rep 32 ram = [ar4];	  // ����� ��� ������ ������

	
	ar0 = [--ar5];  //  Source Buffer; Size: SIZE8
    ar4 = [--ar5];  //  Result Buffer; Size: SIZE8
    gr0 = [--ar5];  //	Length in chars
    with gr0>>=8;
    with gr0--;

	<ShiftRightAll_>	
 	if <>0 delayed goto ShiftRightAll_ with gr0--;			
		rep 32 data = [ar0++] with  mask ram, shift data, 0;	//* ������� �������� �������� �� ������ ������� � ������� ������� ������� ���������� �����
		rep 32 [ar4++] = afifo;									//* ������ ������� ��������� ������
	
	pop ar4,gr4;
	pop ar0,gr0;
	return;
.wait;

end ".text_nmpli";