#include "nmplv.h"

struct S_VEC_WAdd2V
{
	nm32s pWfifo[40];
};
/*
	\defgroup VEC_WAdd2V_Set VEC_WAdd2V_Set
	\ingroup vArithmetics
    \fn void VEC_WAdd2V_Set8(int W1,int W2, S_VEC_WAdd2V* kerW);

    \perfinclude _VEC_WAdd2V_Set8__Fii12S_VEC_WAdd2VP.html
    \brief
        \ru ������������ ������� �� ���� ��������. 
        \en Generation of the vec of two vectors elementwise minima. 

   \ru  ������� ������� ��� ������� �� ������ � �������� �������� �������� ��
	 \en
   
   \~
   \param W1
      \ru ������ ������� �����������. ������� 16 ������� ���
   \param W2
      \ru ������ ������� �����������. ������� 16 ������� ���
   \param kerW  
      \ru ��������� �� 20 ������� ���� ����������: 0,0,0,0,w1,w1a,w1b,w1c,0,0,0,0,
          \  w2,w2a,w2b,w2c,0,0,0,0 ���
          \  w1a=w1<<16,w1b=w1<<32,w1c=w1<<48; � ����������  ��� w2.
*/
   //! \{    
void VEC_WAdd2V_Set8(int W1,int W2, S_VEC_WAdd2V* kerW);
void VEC_WAdd2V_Set16(int W1,int W2, S_VEC_WAdd2V* kerW);
void VEC_WAdd2V_Set32(nm64s W1,nm64s W2, S_VEC_WAdd2V* kerW);
   //! \}


/*
	\defgroup VEC_WAdd2V_Exe VEC_WAdd2V_Exe
	\ingroup vArithmetics
    \fn void VEC_WAdd2V_Set8(int W1,int W2, S_VEC_WAdd2V* kerW);

    \perfinclude _VEC_WAdd2V_Set8__Fii12S_VEC_WAdd2VP.html
    \brief
        \ru ������������ ������� �� ���� ��������. 
        \en Generation of the vec of two vectors elementwise minima. 

   \ru  ������� ������� ��� ������� �� ������ � �������� �������� �������� ��
	 \en
   
   \~
   \param W1
      \ru ������ ������� �����������. ������� 16 ������� ���
   \param W2
      \ru ������ ������� �����������. ������� 16 ������� ���
   \param kerW  
      \ru ��������� �� 20 ������� ���� ����������: 0,0,0,0,w1,w1a,w1b,w1c,0,0,0,0,
          \  w2,w2a,w2b,w2c,0,0,0,0 ���
          \  w1a=w1<<16,w1b=w1<<32,w1c=w1<<48; � ����������  ��� w2.


  \par
	\xmlonly
	 <testperf> 
			<param> pSrcVec1 </param> <values> L G </values>
			<param> pSrcVec2 </param> <values> L G </values>
			<param> pDstVec </param> <values> L G </values>
			<param> kerW </param> <values> L G </values>
			<param> nSize </param> <values> 8 128 1024 10240 </values>
			<size> nSize </size>
	 </testperf>
	\endxmlonly



*/
   // \{    
/* ������ �������� ���������� w1*Vec1 + w2*Vec2 �� �������������� �������������� ������� ��
    ����� ����� w1 � w2.
    pDstVec[i]=W1*pSrcVec1[i]+W2*pSrcVec2[i] ��� W1 � W2 ��������� �������������� ������������
    VEC_WAdd2V_Set8( W1, W2, kerW);
*/
void VEC_WAdd2V_Exe(nm8s* pSrcVec1,nm8s* pSrcVec2, S_VEC_WAdd2V* kerW, nm16s* pDstVec, int nSize);

// ������ �������� ���������� Vec1 � Vec2 �� �������������� �������������� ������� � w1,w2
void VEC_WAdd2V_Exe(nm16s* pSrcVec1,nm16s* pSrcVec2, S_VEC_WAdd2V* kerW, nm32s* pDstVec, int nSize);
// ������ �������� ���������� Vec1 � Vec2 �� �������������� �������������� ������� � w1,w2
void VEC_WAdd2V_Exe(nm32s* pSrcVec1,nm32s* pSrcVec2, S_VEC_WAdd2V* kerW, nm64s* pDstVec, int nSize);
   //! \}


//! 
//! \perfinclude _VEC_WAdd2V__FPciPciPSsi.html
//!				 
void VEC_WAdd2V(nm8s* pSrcVec1,int W1,nm8s* pSrcVec2,int W2, nm16s* pDstVec, int nSize)
{
	S_VEC_WAdd2V kerW;
	VEC_WAdd2V_Set8(W1,W2,&kerW);
	VEC_WAdd2V_Exe(pSrcVec1,pSrcVec2, &kerW, pDstVec, nSize);
}

//! 
//! \perfinclude _VEC_WAdd2V__FPSsiPSsiPii.html
//! 
void VEC_WAdd2V(nm16s* pSrcVec1,int W1,nm16s* pSrcVec2,int W2, nm32s* pDstVec, int nSize)
{
	S_VEC_WAdd2V kerW;
	VEC_WAdd2V_Set16(W1,W2,&kerW);
	VEC_WAdd2V_Exe(pSrcVec1,pSrcVec2, &kerW, pDstVec, nSize);
}
//! 
//! \perfinclude _VEC_WAdd2V__FPilPilPli.html
//! 
void VEC_WAdd2V(nm32s* pSrcVec1, nm64s W1,nm32s* pSrcVec2, nm64s W2, nm64s* pDstVec, int nSize)
{
	S_VEC_WAdd2V kerW;
	VEC_WAdd2V_Set32(W1,W2, &kerW);
	VEC_WAdd2V_Exe(pSrcVec1,pSrcVec2, &kerW, pDstVec, nSize);
}

