//------------------------------------------------------------------------
//
//  $Workfile:: sFiltrat $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/01/12 14:09:07 $
//
//! \if file_doc
//!
//! \file   vFilter.h
//! \author ������ �������
//! \brief  ����������� ������� ���������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------

#ifndef _SFIR_H_INCLUDED_
#define _SFIR_H_INCLUDED_

#include "nmtype.h"

#ifdef __cplusplus
		extern "C" {
#endif


//*****************************************************************************

    /**
	\internal
    \defgroup SIG_Filter SIG_Filter
		\ingroup sFiltration
		\brief 
			\ru ���������� ����������. 
			\en One-dimensional filtration. 

		\~
		\~
    \param	pSrcVec		
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param	nSize		
        \ru ������ �������� ������� � ���������. 
        \en Input vec size in elements. 
		\~
	\retval	pDstVec		
        \ru �������������� ������. 
        \en The result vec. 
		\~
	\param	pKernel
        \ru ��������� ���������, ���������� ������� ����������� ������� �� ���������� �������. 
        \en Auxilary structure, which contains filter coefficents in internal format. 
	
		\~
    \note \ru ������������� ��������� ��������� ������������ ��������������� �������� SIG_SetFilter() � SIG_CreateFilter().
          \en Initialization of Auxilary structure is performed by call of appropriate SIF_SetFilter function and SIG_CreateFilter().
		\~    
    */
#define NmppsFIRState void

void nmppsFIR_8s16s( nm8s* pSrc, nm16s* pDst, int srcSize,  NmppsFIRState* pState);
int  nmppsFIRInit_8s16s(NmppsFIRState* ppState, int* pTaps, int tapsLen);
int  nmppsFIRInitAlloc_8s16s(NmppsFIRState** ppState, int* pTaps, int tapsLen);
void nmppsFIRFree(NmppsFIRState* pState);

void nmppsFIR_8s( nm8s* pSrc, nm8s* pDst, int srcSize,  NmppsFIRState* pState);
int  nmppsFIRInit_8s(NmppsFIRState* ppState, int* pTaps, int tapsLen);
int  nmppsFIRInitAlloc_8s(NmppsFIRState** ppState, int* pTaps, int tapsLen);
void nmppsFIRFree(NmppsFIRState* pState);


    //! \{
//void SIG_Filter(nm32s* pSrcVec, nm32s* pDstVec, int	nSize,  nm64s* pKernel);
//void SIG_Filter(nm16s* pSrcVec, nm32s* pDstVec, int	nSize,  nm64s* pKernel);
//void nmppsFIR_8s16s( nm8s* pSrcVec, nm32s* pDstVec, int	nSize,  nm64s* pFIRState);
//void SIG_Filter(nm16s* pSrcVec, nm16s* pDstVec, int	nSize,  nm64s* pKernel);
//void SIG_Filter( nm8s* pSrcVec, nm16s* pDstVec, int	nSize,  nm64s* pKernel);
//void SIG_Filter( nm8s* pSrcVec,  nm8s* pDstVec, int	nSize,  nm64s* pKernel);
//    //! \}
//int SIG_GetFilterKernelSize_32s32s(int nSize);	
//int SIG_GetFilterKernelSize_16s16s(int nSize);
//int SIG_GetFilterKernelSize_16s32s(int nSize);
//int SIG_GetFilterKernelSize_8s8s  (int nSize);
//int nmppsFIRGetStateSize_8s16s (int nSize);
//int SIG_GetFilterKernelSize_8s32s (int nSize);
//void nmppsFIRFree(void* state);
//*****************************************************************************

    /**
	\internal
    \defgroup SIG_SetFilter SIG_SetFilter
    \ingroup sFiltration
    \brief
        \ru ������������� ���� ��� ���������� ����������. 
        \en Initialization of the core for one-dimensional filtration. 
    
		\~
        \ru ������� ��������� ������� ������� ������������� �� ��������� ������� 
        ������������� ���� �������������� ��� ������������� � �������� ����������. 
        \en The functions init the table of weight coefficients from the linear array 
        of the conversion window to use in filtration functions. 

		\~
		\~
    \param	pWeights		
        \ru ��������� �� ����������� ������� . 
        \en Pointer to the filter coefficients. 
		\~
    \param	nWeights	
        \ru ������ ���� �������. nWeights=[3,5,7,9....]. 
        \en Size of filter window . 
		\~
	\retval	pKernel	
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
		*/

    //! \{
//int SIG_SetFilter_32s32s(int* pWeights, int nWeights, nm64s* pKernel);
//int SIG_SetFilter_16s16s(int* pWeights, int nWeights, nm64s* pKernel);
//int SIG_SetFilter_16s32s(int* pWeights, int nWeights, nm64s* pKernel);
//int SIG_SetFilter_8s8s  (int* pWeights, int nWeights, nm64s* pKernel);
int nmppsFIRSetCoeff_8s16s (int* pWeights, int nWeights, nm64s* pKernel);
//int SIG_SetFilter_8s32s (int* pWeights, int nWeights, nm64s* pKernel);
    //! \}


/*!
	\defgroup CSIG_FIR ���-���������� 
	\ingroup sFiltration	 
	\brief ��� ���������� 
*/	
//! \{

//! ����� ��� �������
//! \tparam nmbits_in  ��� ����������� ����������� �������� �������. ���������� ���� : nm8s,nm16s,nm32s
//! \tparam nmbits_out ��� ����������� ����������� ��������� �������. ���������� ���� : nm8s,nm16s,nm32s. ����������� �������� ������� �� ������ ��������� ����������� ���������.
//! \par ������
//! \include app\example\Filter\SIG_Filter_16s32s\main.cpp 
//template <class nmbits_in, class nmbits_out> class CSIG_FIR
//{
//public:
//	void (*pfFree32)(void*);	///< ��������� �� ������� ������������ ������ (pKernel)
//	int nWeights;				///< ���������� ������������� ��� ������� 
//	nm64s* pKernel;				///< ��������� �� ���������� ��������� �������������
//	int nKernelSize;			///< ������ ������ ����������� ��� �������� ���������� ��������� �������������
//
//	//! ����������� ��� ������� 
//	/*!
//	   �������� ������� ������ ��� ���������� ��������� ������������� 
//      \param nWeights  ������������� ���������� ������������� ��� �������. nWeights=[3,5,7,9....]. 
//      \param malloc32_func  ��������� �� �������  ��������� ������������ ������ 32-���������� �������.
//	  \param free32_func  ��������� �� ������� ������������� ������������ ������
//    */
//	CSIG_FIR(int nWeights, void* (*malloc32_func)(unsigned), void (*free32_func)(void*));
//	CSIG_FIR(){pKernel=0;};
//
//	//! ����������� ��� ������� 
//	/*!
//	   �������� ������� ������ ��� ���������� ��������� ������������� 
//      \param nWeights  ������������� ���������� ������������� ��� �������. nWeights=[3,5,7,9....]. 
//      \param malloc32_func  ��������� �� �������  ��������� ������������ ������ 32-���������� �������.
//	  \param free32_func  ��������� �� ������� ������������� ������������ ������
//    */
//	int init(int nWeights, void* (*malloc32_func)(unsigned), void (*free32_func)(void*));
//
//	
//	//! ��������� ������������ ������� � �������������� ���������� ��������� �������� ������������� � pKernel
//	/*!
//      \param pWeights  ������������ ������� 
//	  \return ��������� �� ���������� ��������� �������������. 0- ���� ������ ��� ��������� �� ���� ��������.  
//    */
//	void* setWeights(int* pWeights);
//	
//	//! ������� ���������� ����������
//	/*!
//	\f[
//        pDstVec[i]  =  \sum\limits_{j = 0}^{nWeights-1} {pSrcVec[i-nWeights/2] \cdot pWeights[j]}   ,i=0 \ldots  nSize-1
//    \f]
//
//
//      \param pSrcVec ������� ������ 
//	  \param pDstVec �������� ������ 
//	  \param nSize ������ ������� � ���������
//	  \warning ��� ���������� ������ � ��������� nWeights/2 �������� ������������ ����� �� ������� �������� ������� pSrcVec . 
//	        ��� ���������� ��������� ������� ���������� �������������� ������������� ���� �������� �� ����� nWeight/2 ������� ��������� ����� ������� � � ����� ������� pSrcVec.
//    */
//	void  filter(nmbits_in* pSrcVec, nmbits_out* pDstVec, int nSize);
//	
//	//! ����������� ������������ ������� ������ pKernel
//	~CSIG_FIR();	
//
//};

//! \}


//*****************************************************************************

    /**
	\internal
    \defgroup SIG_CreateFilter SIG_CreateFilter
    \ingroup sFiltration
    \brief
        \ru �������� ���� ��� ���������� ����������. 
        \en Creation of the core for one-dimensional filtration. 
    
		\~
        \ru ������� ������� ������� ������� ������������� �� ��������� ������� 
        ������������� ���� �������������� ��� ������������� � �������� ����������. 
        \en The functions generate the table of weight coefficients from the linear array 
        of the conversion window to use in filtration functions. 

		\~
		\~
    \param	pWeights		
        \ru ��������� �� ����������� ������� . 
        \en Pointer to the filter coefficients. 
		\~
    \param	nSize	
        \ru ������ ���� �������. nSize=[3,5,7,9....]. 
        \en Size of filter window . 
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

//		nm64s* SIG_CreateFilter_32s32s(int* pWeights, int nWeights, void * (*malloc_func)(unsigned) );
//		nm64s* SIG_CreateFilter_16s16s(int* pWeights, int nWeights, void * (*malloc_func)(unsigned) );
//		nm64s* SIG_CreateFilter_16s32s(int* pWeights, int nWeights, void * (*malloc_func)(unsigned) );
//		nm64s* SIG_CreateFilter_8s8s  (int* pWeights, int nWeights, void * (*malloc_func)(unsigned) );
//		nm64s* SIG_CreateFilter_8s16s (int* pWeights, int nWeights, void * (*malloc_func)(unsigned) );
//		nm64s* SIG_CreateFilter_8s32s (int* pWeights, int nWeights, void * (*malloc_func)(unsigned) );
    //! \}




#ifdef __cplusplus
		};
#endif

   
#endif // _SFILTRATION_H_INCLUDED_

