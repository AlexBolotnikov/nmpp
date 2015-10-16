//------------------------------------------------------------------------
//
//  $Workfile:: sResampl $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/01/12 14:09:07 $
//
//! \if file_doc
//!
//! \file   vResize.h
//! \author ������ �������
//! \brief  ����������� ������� ��������� ������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------

#ifndef _S_RESAMPLE_H_INCLUDED_
#define _S_RESAMPLE_H_INCLUDED_

    /**
    \defgroup SIG_ResampleDown2 SIG_ResampleDown2
    \ingroup sResample
    \brief
        \ru ���������� ����� �������� � ����. 
        \en Reduction sample count by factor 2. 
    
		\~
    
	\f[
        pDstVec  = \frac{1}{2} \left( pSrcVec(2*x) + pSrcVec(2*x+1) \right)
    \f]
    
    \param	pSrcVec		
        \ru ������� ������. 
        \en Source signal data. 
		\~
     \param	nSize		
        \ru ������ ������� ������� ������. 
        \en Source data array size. 
		\~
    \retval	pDstVec		
        \ru �������������� ������. 
        \en Destination signal. 
		\~
    \note \ru ��� ���� ����� �������� ������������ ��� ����������,
              ������������ �������� ��������� ����������� ������
              ������������ ���������, ������������� �����. 
          \en To avoid data overflow dynamic range of source
              image should be in interval defined by type. 
    
		\~        
     
    */

    //! \{
void SIG_ResampleDown2(nm8u7b* pSrcVec, nm8u7b* pDstVec, int nSrcVecSize, nm64s* pKernel);
void SIG_ResampleDown2(nm16u15b* pSrcVec, nm16u15b* pDstVec, int nSrcVecSize, nm64s* pKernel);
    //! \}

//\param	pTmpBuf		
//    \ru ��������� ������ ������� 2*nSize. 
//    \en Temporary buffer with size 2*nSize. 

//void SIG_ResampleDown2(nm8u* pSrcVec, nm16u* pDstVec, int nSrcVecSize, nm64s* pKernel, void* pTmpBuf);
void SIG_ResampleDown2(nm8u* pSrcVec,nm16u*	pDstVec,void*	pTmpBuf,int	nSize);

//*****************************************************************************

    /**
		\~
    \defgroup SIG_ResampleUp3Down2 SIG_ResampleUp3Down2
    \ingroup sResample
    \brief
        \ru ����������������� ������� � 3/2 ���� 
        \en Signal resampling by 3/2 times 
		\~
    \ru ����������������� ������� �������������� ������� Polyphase: \n
	    - ����� ��������� �������� ������� ����������� �� 2 ���� 
	    - ���������� ������ ������������ ����� ������ ���. ����� ������� 17 
	    - �� ����������� ������� ���������� ������ 2 ������ 
    \en Signal is resampled using the Polyphase method: \n
	    - Two zeros are inserted between input signal countings
	    - The received signal passes through a low-pass filter. The filter length is 17
	    - Every second counting is selected from the received signal 
	
		\~
	\~
    \param pSrcVec		
        \ru ������� ������. �������� ������� - ����� ����� �� ������. 
        \en Input vec. Vector elements are integer number with sign. 
		\~
    \param nSrcVecSize	
        \ru ������ �������� �������. 
        \en Input vec size. 
		\~
    \retval pDstVec	    
        \ru �������������� ������. �������� ������� ������������ � ������� fixed-point: [12.4] (����� �����-12 ���, ������� -4����)
        \en The result vec. Vector elemts returns in fixed-point format: [12.4] (integer part -12 bits, fractional part - 4 bits)
		\~
    \return \e void 
    
    */
    //! \{
void SIG_ResampleUp3Down2(nm8s* pSrcVec, nm16s* pDstVec, int nSrcVecSize, nm64s* pKernel);
    //! \}
//*****************************************************************************

    /**
    \defgroup SIG_CreateResample SIG_CreateResample
    \ingroup sResample
    \brief
        \ru �������� ���� ��� ������� ����������������� SIG_Resample(). 
        \en Creation of the core for resampling function SIG_Resample(). 
    
		\~
        \ru ������� �������� ������ � �������������� ������� ������� ������������� ��� ������������� � �������� �����������������. 
        \en The functions allcates the memoty and initialize the tables of weight coefficients to use in resample functions. 

		\~
		\~
    \param	nHint	
        \ru ���������� ������(Local ��� Global) � ������� ��������� ��������� ���������. nHint=[MEM_LOCAL,MEM_GLOBAL]. 
        \en Set memoty bank (Local or Global) where auxilary structure would be allocated. 
		\~
	\retval	pKernel	
        \ru ��������� �� ��������� ���������, ���������� ������� ����������� ������� �� ���������� �������. 
        \en Pointer to auxilary structure, which contains filter coefficents in internal format. 

		\~
    \note \ru ������������ ����� ������� ������� SIG_Filter.
          \en This functions is used before call  of SIG_Filter.
		  \~
    */

    //! \{
void SIG_CreateResampleUp3Down2_8s16s(nm64s** pKernel, int nHint=MEM_LOCAL);
void SIG_CreateResampleDown2_8u8u(nm64s** pKernel, int nHint=MEM_LOCAL);
void SIG_CreateResampleDown2_16u16u(nm64s** pKernel, int nHint=MEM_LOCAL);
    //! \}

//*****************************************************************************

    /**
    \defgroup SIG_SetResample SIG_SetResample
    \ingroup sResample
    \brief
        \ru �������� ���� ��� ������� ����������������� SIG_Resample(). 
        \en Creation of the core for resampling function SIG_Resample(). 
    
		\~
        \ru ������� �������������� ������� ������� ������������� ��� ������������� � �������� �����������������. 
        \en The initialize the tables of weight coefficients to use in resample functions. 

		\~
		\~
 	\param	pKernel	
        \ru ��������� �� ��������� ���������, ���������� ������� ����������� ������� �� ���������� �������. 
        \en Pointer to auxilary structure, which contains filter coefficents in internal format. 
		\~
	\return
		\ru ������ ��������������������� ��������� pKernel � 32�. ������
		\en Size of inited structure pKernel in 32 bit words
		\~
    \note \ru ������������ ����� ������� ������� SIG_Filter.
          \en This functions is used before call  of SIG_Filter.

		\~
    \note \ru ������������ ����� ������� ������� SIG_Resample().
          \en This functions is used before call  of SIG_Resample().
		\~ 
		*/

    //! \{
int SIG_SetResampleUp3Down2_8s16s(nm64s* pKernel);
int SIG_SetResampleDown2_8u8u(nm64s* pKernel);
int SIG_SetResampleDown2_16u16u(nm64s* pKernel);
    //! \}


//*****************************************************************************

     /**
    \internal
    \defgroup SIG_Decimate16 SIG_Decimate16
		\ingroup sResample
    */
    //! \{
void SIG_Decimate16(nm8s* pSrcVec,nm8s* pDstVec,int nDstSize);
void SIG_Decimate16(nm16s* pSrcVec,nm16s* pDstVec,int nDstSize);
void SIG_Decimate16(nm32s* pSrcVec,nm32s* pDstVec,int nDstSize);
void SIG_Decimate16(nm64s* pSrcVec,nm64s* pDstVec,int nDstSize);
    //! \}


//*****************************************************************************

    /**
    \defgroup SIG_Resample_perf SIG_Resample_perf
		\ingroup sResample
		\brief 
			\ru ������� ��� ������ ������������������ ������� ���������� SIG_Resample()
			\en Functions for performance estimation of SIG_Filter() functions . 
		
		\~
		\ru �������  ������������ ��������� �����������������: 
        \en The function operation is equivalent to the following pseudoinstructions: 
		\~
		\~
    \code
	void SIG_Resample***_perf(nm16u15b* pSrcVec, nm16u15b* pDstVec, int nSrcVecSize, nm64s* pKernel);
	{
		SIG_SetResample***_***(pKernel); 
		clock_t t0,t1;	
		t0=clock();
		SIG_Resample***(pSrcVec, pDstVec, nSize,pKernel);
		t1=clock();
		exit(t1-t0);
	}
    \endcode


		\~
	\retval	pKernel	
        \ru ��������� �� ��������� ���������, ���������� ������� ����������� ������� �� ���������� �������. 
        \en Pointer to auxilary structure, which contains filter coefficents in internal format. 
		\~
    \param	pSrcVec		
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param	nSrcVecSize		
        \ru ������ �������� ������� � ���������. 
        \en Input vec size in elements. 
		\~
	\retval	pDstVec		
        \ru �������������� ������. 
        \en The result vec. 
	
		\~
    \note \ru ������������� ��������� ��������� ������������ �������������� �������� SIG_SetFilter() � SIG_CreateFilter().
          \en Initialization of Auxilary structure is performed by call of appropriate SIF_SetFilter function and SIG_CreateFilter().

		\~
    \par
    \xmlonly
       <testperf> 
			<param> pSrcVec </param> <values> L G </values>
			<param> pDstVec </param> <values> L G </values>
			<param> pKernel </param> <values> L1 G1 </values>
			<param> nSrcVecSize    </param> <values> 1024 </values>
        </testperf>
		<testperf> 
			<param> pSrcVec </param> <values> L  </values>
			<param> pDstVec </param> <values> G </values>
			<param> pKernel </param> <values> G1 </values>
			<param> nSrcVecSize    </param> <values> 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void SIG_ResampleUp3Down2_perf(nm8s* pSrcVec, nm16s* pDstVec, int nSrcVecSize, nm64s* pKernel);
void SIG_ResampleDown2_perf(nm8u7b* pSrcVec, nm8u7b* pDstVec, int nSrcVecSize, nm64s* pKernel);
void SIG_ResampleDown2_perf(nm16u15b* pSrcVec, nm16u15b* pDstVec, int nSrcVecSize, nm64s* pKernel);
    //! \}
	
	
	
	
	
//! ����� ��� �������
//! \tparam nmbits_in  ��� ����������� ����������� �������� �������. ���������� ���� : nm8s,nm16s,nm32s
//! \tparam nmbits_out ��� ����������� ����������� ��������� �������. ���������� ���� : nm8s,nm16s,nm32s. ����������� �������� ������� �� ������ ��������� ����������� ���������.
//! \par ������
//! \include app\example\Filter\SIG_Filter_16s32s\main.cpp 
template <class nmbits_in, class nmbits_out> class CSIG_ResampleUp3Down2
{
public:
	void (*pfFree32)(void*);	///< ��������� �� ������� ������������ ������ (pKernel)
	int nWeights;				///< ���������� ������������ ��� ������� 
	nm64s* pKernel;				///< ��������� �� ���������� ��������� �������������
	int nKernelSize;			///< ������ ������ ����������� ��� �������� ���������� ��������� �������������

	//! ����������� ��� ������� 
	/*!
	   �������� ������� ������ ��� ���������� ��������� ������������ 
      \param nWeights  ������������� ���������� ������������ ��� �������. nWeights=[3,5,7,9....]. 
      \param malloc32_func  ��������� �� �������  ��������� ������������ ������ 32-���������� �������.
	  \param free32_func  ��������� �� ������� ������������� ����������� ������
    */
	CSIG_ResampleUp3Down2(void* (*malloc32_func)(unsigned),void (*free32_func)(void*));

	
	//! ������� ���������� ����������
	/*!
	\f[
        pDstVec[i]  =  \sum\limits_{j = 0}^{nWeights-1} {pSrcVec[i-nWeights/2] \cdot pWeights[j]}   ,i=0 \ldots  nSize-1
    \f]


      \param pSrcVec ������� ������ 
	  \param pDstVec �������� ������ 
	  \param nSize ������ ������� � ���������
	  \warning ��� ���������� ������ � ��������� nWeights/2 �������� ������������ ����� �� ������� �������� ������� pSrcVec . 
	        ��� ���������� ��������� ������� ���������� �������������� ������������� ���� �������� �� ����� nWeight/2 ������� ��������� ����� ������� � � ����� ������� pSrcVec.
    */
	void  Eval(nmbits_in* pSrcVec, nmbits_out* pDstVec, int nSize);
	
	//! ����������� ������������ ������� ������ pKernel
	~CSIG_ResampleUp3Down2(){
		if (pKernel) 
			pfFree32(pKernel);
	}
	

};

	
#endif // 