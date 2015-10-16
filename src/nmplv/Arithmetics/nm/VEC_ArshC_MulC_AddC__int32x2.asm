
extern vec_vsum_data_vr:label;
extern tbl_sb_nm32_EvenARSH:long;
begin ".text_nmplv"

// void VEC_ArshC_MulC_AddC(int32x2* dataSparseSrc,  int32x2& preshiftArg, int32x2& mulArg, int32x2& addArg, int32x2 *dataSparseDst,  int size, int stepSparseSrc=1, int stepSparseDst=1);
global "_void._.8.8VEC_ArshC_MulC_AddC.1class._int32x2._.0.9._class._int32x2._.6.9._class._int32x2._.6.9._class._int32x2._.6.9._class._int32x2._.0.9._int.9._int.9._int.2" : label;
       <_void._.8.8VEC_ArshC_MulC_AddC.1class._int32x2._.0.9._class._int32x2._.6.9._class._int32x2._.6.9._class._int32x2._.6.9._class._int32x2._.0.9._int.9._int.9._int.2>

.branch;
	ar5 = ar7-2;

	push ar0, gr0;
	push ar1, gr1;
	push ar5, gr5;
	push ar6, gr6;

	ar0 = [--ar5]; // [in] dataSparseSrc
	// ---------- parse preshiftArg and select sb ----
	ar6 = [--ar5]; // [in] preshiftArg 
	nb1 = 80000000h;
	ar1 = tbl_sb_nm32_EvenARSH;
	gr1 = [ar6++];
	sbl = [ar1+=gr1];
	
	ar1 = tbl_sb_nm32_EvenARSH;
	gr1 = [ar6++];
	sbh = [ar1+=gr1];
	// ---------- parse mulArg and load weights ----
	ar6 = [--ar5]; // [in] mulArg 
	
	ar1,gr1 = [ar6];// ar1=lo, gr1=hi
	ar6,gr6 = [ar6]	with gr1 = false ;
	ar6 = gr1;	
	[ar7++] = ar6,gr6 with gr6=false;
	[ar7++] = ar6,gr6; // 0,0
	[ar7++] = ar1,gr1;
	[ar7++] = ar6,gr6; // 0,0
	rep 4 wfifo=[--ar7] ,ftw,wtw;
	//------------ parse other params ---------------- 
	ar1 = [--ar5]; // [in] addArg 
	ar6 = [--ar5]; // [out] dataSparseDst 
	gr5 = [--ar5]; // [in] size (in long)
	gr0 = [--ar5]; // [in] stepSparseSrc  =1 
	delayed call vec_vsum_data_vr;					
		gr6 = [--ar5]	with gr0<<=1; // [in] stepSparseDst =1
		vr=[ar1] 		with gr6<<=1;

	pop ar6, gr6;
	pop ar5, gr5;
	pop ar1, gr1;
	pop ar0, gr0;

	return;
.wait;

end ".text_nmplv";
