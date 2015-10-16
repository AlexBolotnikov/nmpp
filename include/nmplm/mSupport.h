//------------------------------------------------------------------------
//
//  $Workfile:: mSupport.h              $
//
//  <�������� ����������>
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.2 $      $Date: 2005/06/23 15:15:15 $
//
//! \if file_doc
//!
//! \file   mtrMalloc.h
//! \author ������� �����
//! \brief  ������������� ������ ��� �����������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#ifndef __MSUPPORT_H
#define __MSUPPORT_H

#include "nmplv.h"

//*****************************************************************************

	/*
    *
    * \if Russian 
    *     \defgroup mSupport ������� ��������� 
    * \endif
    * \if English
    *     \defgroup mSupport Support functions 
    * \endif
    * \ingroup mtr
	*/

//*****************************************************************************

    /**
    \defgroup MTR_Malloc MTR_Malloc
    \ingroup mSupport
    \brief
        \ru ������������� ������ ��� ������ ����������. 
        \en Memory allocation for library matrixis.
    
		\~
        \ru ������ � ����� �������������� ������ ������������� �� ������ 
        64-� ���������� �����. 
        \en Begin and end of the allocated memory are being 
        aligned to 64-bit word.

		\~
    \~
    \param nHeight    
        \ru ����� ����� � �������. 
        \en Number of rows in mtr. 
		\~
    \param nWidth 
        \ru ����� �������� � �������. 
        \en Number of columns in mtr. 
		\~
    \param hint     
        \ru ����� ����� ������. ����� ��������� �������� 
                        MEM_LOCAL, MEM_GLOBAL. 
        \en Number of memory bank. Admissible values for memory bank
                        are MEM_LOCAL, MEM_GLOBAL. 

		\~
    \note \ru ������, �������������� � ������� ������� MTR_Malloc ������
              ������������� � ������� ������� MTR_Free. 
          \en Memory allocated by function MTR_Malloc should be 
              deallocated by function MTR_Free. 
			  \~
    */
    //! \{
inline void MTR_Malloc(nm1** pptr,   int nHeight, int nWidth, int hint = MEM_LOCAL) { VEC_Malloc((nm64s**)pptr, (nHeight*nWidth>>6) +1, hint);}
inline void MTR_Malloc(nm2s** pptr,  int nHeight, int nWidth, int hint = MEM_LOCAL) { VEC_Malloc((nm64s**)pptr, (nHeight*nWidth>>5) +1, hint);}
inline void MTR_Malloc(nm4s** pptr,  int nHeight, int nWidth, int hint = MEM_LOCAL) { VEC_Malloc((nm64s**)pptr, (nHeight*nWidth>>4) +1, hint);}
inline void MTR_Malloc(nm8s** pptr,  int nHeight, int nWidth, int hint = MEM_LOCAL) { VEC_Malloc((nm64s**)pptr, (nHeight*nWidth>>3) +1, hint);}
inline void MTR_Malloc(nm16s** pptr, int nHeight, int nWidth, int hint = MEM_LOCAL) { VEC_Malloc((nm64s**)pptr, (nHeight*nWidth>>2) +1, hint);}
inline void MTR_Malloc(nm32s** pptr, int nHeight, int nWidth, int hint = MEM_LOCAL) { VEC_Malloc((nm64s**)pptr, (nHeight*nWidth>>1) +1, hint);}
inline void MTR_Malloc(nm64s** pptr, int nHeight, int nWidth, int hint = MEM_LOCAL) { VEC_Malloc((nm64s**)pptr, (nHeight*nWidth   )   , hint);}

inline void MTR_Malloc(nm2u** pptr,  int nHeight, int nWidth, int hint = MEM_LOCAL) { VEC_Malloc((nm64s**)pptr, (nHeight*nWidth>>5) +1, hint);}
inline void MTR_Malloc(nm4u** pptr,  int nHeight, int nWidth, int hint = MEM_LOCAL) { VEC_Malloc((nm64s**)pptr, (nHeight*nWidth>>4) +1, hint);}
inline void MTR_Malloc(nm8u** pptr,  int nHeight, int nWidth, int hint = MEM_LOCAL) { VEC_Malloc((nm64s**)pptr, (nHeight*nWidth>>3) +1, hint);}
inline void MTR_Malloc(nm16u** pptr, int nHeight, int nWidth, int hint = MEM_LOCAL) { VEC_Malloc((nm64s**)pptr, (nHeight*nWidth>>2) +1, hint);}
inline void MTR_Malloc(nm32u** pptr, int nHeight, int nWidth, int hint = MEM_LOCAL) { VEC_Malloc((nm64s**)pptr, (nHeight*nWidth>>1) +1, hint);}
inline void MTR_Malloc(nm64u** pptr, int nHeight, int nWidth, int hint = MEM_LOCAL) { VEC_Malloc((nm64s**)pptr, (nHeight*nWidth   )   , hint);}

    //! \}

//*****************************************************************************

    /**
    \defgroup MTR_Free MTR_Free
    \ingroup mSupport
    \brief
        \ru ������������ ������ ��� ������. 
        \en Memory deallocation for matrixis. 

		\~
		\~
    \note \ru ������ ������� ������ ���������� ������ ���
              ��������, �������������� � ������� ������� 
              MTR_Malloc.
          \en This function should be called only for matrixis
              allocated by MTR_Malloc functions. 
			  \~
    */
    //! \{

inline void MTR_Free(void* ptr) {VEC_Free(ptr);}
    //! \}

//*****************************************************************************

    /**
    \defgroup MTR_Addr MTR_Addr
    \ingroup mSupport
    \brief
        \ru ���������� ����� ������ ������, ���������� ��������� �������. 
        \en Returns address of memory cell that contains
        the mtr element. 
    
		\~
        \ru ���������� ��� ���������� NeuroMatrix ���������� �����, ����������� 
            � ������ �� 32 ����. 
        \en Implementation for NeuroMatrix processor returns an addres aligned 
            with 32 bits in the memory.

		\~
		\~
    \param pMtr     
        \ru ������� �������. 
        \en Input mtr. 
		\~
    \param nWidth
        \ru ������ ������� � ���������. 
        \en Matrix width in elements. 
   
		\~
    \param nY    
        \ru ����� ������. 
        \en Row index. 
	
		\~
	\param nX    
        \ru ����� �������. 
        \en Column index. 

		\~
    \return         
        \ru ����� ������ ������. 
        \en Address of memory cell. 

		\~
    \note 
        \ru ��� ��������� ������ �� PC �������� ������������� �������
            ADDR(ptr, index), ������� ������������ �� PC ��� 
            (ptr+index), � �� NM ��� ����� ������� MTR_Addr. 
        \en To increase perfomance on PC it's possible to use macros
            ADDR(ptr, index) that equivalent to (ptr+index) expression. 

		\~
    \par
    \xmlonly
        <testperf> 
             <param> pMTR   </param> <values> L G </values>
             <param> nWidth </param> <values> 4 </values>
             <param> nY     </param> <values> 2 </values>
             <param> nX     </param> <values> 2 </values>
             <size> 1 </size>
        </testperf>
    \endxmlonly
    */
    //! \{
inline nm1*   MTR_Addr(nm1*   pMTR, int nWidth, int nY, int nX)	{	return (nm1*)  ((int*)pMTR+((nWidth*nY+nX)>>5));}
inline nm2s*  MTR_Addr(nm2s*  pMTR, int nWidth, int nY, int nX)	{	return (nm2s*) ((int*)pMTR+((nWidth*nY+nX)>>4));}
inline nm4s*  MTR_Addr(nm4s*  pMTR, int nWidth, int nY, int nX)	{	return (nm4s*) ((int*)pMTR+((nWidth*nY+nX)>>3));}
inline nm8s*  MTR_Addr(nm8s*  pMTR, int nWidth, int nY, int nX)	{	return (nm8s*) ((int*)pMTR+((nWidth*nY+nX)>>2));}
inline nm16s* MTR_Addr(nm16s* pMTR, int nWidth, int nY, int nX)	{	return (nm16s*)((int*)pMTR+((nWidth*nY+nX)>>1));}
inline nm32s* MTR_Addr(nm32s* pMTR, int nWidth, int nY, int nX)	{	return (nm32s*)((int*)pMTR+(nWidth*nY+nX));}
inline nm64s* MTR_Addr(nm64s* pMTR, int nWidth, int nY, int nX) {	return (nm64s*)((int*)pMTR+((nWidth*nY+nX)<<1));}

inline nm2u*  MTR_Addr(nm2u*  pMTR, int nWidth, int nY, int nX)	{	return (nm2u*) ((int*)pMTR+((nWidth*nY+nX)>>4));}
inline nm4u*  MTR_Addr(nm4u*  pMTR, int nWidth, int nY, int nX)	{	return (nm4u*) ((int*)pMTR+((nWidth*nY+nX)>>3));}
inline nm8u*  MTR_Addr(nm8u*  pMTR, int nWidth, int nY, int nX)	{	return (nm8u*) ((int*)pMTR+((nWidth*nY+nX)>>2));}
inline nm16u* MTR_Addr(nm16u* pMTR, int nWidth, int nY, int nX)	{	return (nm16u*)((int*)pMTR+((nWidth*nY+nX)>>1));}
inline nm32u* MTR_Addr(nm32u* pMTR, int nWidth, int nY, int nX)	{	return (nm32u*)((int*)pMTR+(nWidth*nY+nX));}
inline nm64u* MTR_Addr(nm64u* pMTR, int nWidth, int nY, int nX) {	return (nm64u*)((int*)pMTR+((nWidth*nY+nX)<<1));}

    //! \}
//*****************************************************************************

    /**
    \defgroup MTR_SetVal MTR_SetVal
    \ingroup mSupport
    \brief
        \ru ���������� ����� � ������� ������. 
        \en Set mtr element. 
    
		\~
    
	\f[
        pMtr[nY][nX] =  nVal
    \f]
    \param pMtr   
        \ru �������. 
        \en Matrix. 
		\~
    \param nWidth    
        \ru ������ ������� � ���������
        \en Matrix width in elements 
		\~
	\param nY
		\ru ����� ������
		\en Row index
		\~
	\param nX
		\ru ����� �������
		\en Column index
		\~
    \param nVal  
        \ru �������� �������� 
        \en Value of the element. 
		\~
    \return \e void
    
    \par
    \xmlonly
        <testperf> 
             <param> pMtr	</param> <values> L G </values>
			 <param> nWidth	</param> <values> 18 </values>
			 <param> nY		</param> <values> 2  </values>
			 <param> nX		</param> <values> 2  </values>
             <param> nVal    </param> <values> 3 </values>
             <size> 1 </size>
        </testperf>
    \endxmlonly
    */
    //! \{
inline void MTR_SetVal(nm1*  pMtr,   int nWidth,  int nY, int nX, int1b nVal)	{ VEC_SetVal(pMtr, nY*nWidth+nX,nVal);}

inline void MTR_SetVal(nm2s* pMtr,   int nWidth,  int nY, int nX, int2b nVal)	{ VEC_SetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_SetVal(nm4s* pMtr,   int nWidth,  int nY, int nX, int4b nVal)	{ VEC_SetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_SetVal(nm8s* pMtr,   int nWidth,  int nY, int nX, int8b nVal)	{ VEC_SetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_SetVal(nm16s* pMtr,  int nWidth,  int nY, int nX, int16b nVal)	{ VEC_SetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_SetVal(nm32s* pMtr,  int nWidth,  int nY, int nX, int32b nVal)	{ VEC_SetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_SetVal(nm64s* pMtr,  int nWidth,  int nY, int nX, int64b nVal)	{ VEC_SetVal(pMtr, nY*nWidth+nX,nVal);}

inline void MTR_SetVal(nm2u* pMtr,	 int nWidth,  int nY, int nX, uint2b nVal)	{ VEC_SetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_SetVal(nm4u* pMtr,   int nWidth,  int nY, int nX, uint4b nVal)	{ VEC_SetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_SetVal(nm8u* pMtr,   int nWidth,  int nY, int nX, uint8b nVal)	{ VEC_SetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_SetVal(nm16u* pMtr,  int nWidth,  int nY, int nX, uint16b nVal)	{ VEC_SetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_SetVal(nm32u* pMtr,  int nWidth,  int nY, int nX, uint32b nVal)	{ VEC_SetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_SetVal(nm64u* pMtr,  int nWidth,  int nY, int nX, uint64b nVal)	{ VEC_SetVal(pMtr, nY*nWidth+nX,nVal);}
    //! \}

//*****************************************************************************
	
	/**
    \defgroup MTR_GetVal MTR_GetVal
    \ingroup mSupport
    \brief
        \ru ��������� �������� �������� ������. 
        \en Get mtr element. 
    
		\~
    
	\f[
        nVal=pMtr[nY][nX]
    \f]
    \param pMtr   
        \ru �������. 
        \en Matrix. 
		\~
    \param nWidth    
        \ru ������ ������� � ���������
        \en Matrix width in elements 
		\~
	\param nY
		\ru ����� ������
		\en Row index
		\~
	\param nX
		\ru ����� �������
		\en Column index
		\~
    \retval nVal  
        \ru �������� �������� 
        \en Value of the element. 
		\~
    \return \e void
    
    \par
    \xmlonly
        <testperf> 
             <param> pMtr	</param> <values> L G </values>
			 <param> nWidth	</param> <values> 18 </values>
			 <param> nY		</param> <values> 2  </values>
			 <param> nX		</param> <values> 2  </values>
             <param> nVal   </param> <values> n </values>
             <size> 1 </size>
        </testperf>
    \endxmlonly
    */
    //! \{
inline void MTR_GetVal(nm1*  pMtr,   int nWidth,  int nY, int nX, int1b& nVal)  { VEC_GetVal(pMtr, nY*nWidth+nX,nVal);}

inline void MTR_GetVal(nm2s* pMtr,   int nWidth,  int nY, int nX, int2b& nVal)  { VEC_GetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_GetVal(nm4s* pMtr,   int nWidth,  int nY, int nX, int4b& nVal)  { VEC_GetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_GetVal(nm8s* pMtr,   int nWidth,  int nY, int nX, int8b& nVal)  { VEC_GetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_GetVal(nm16s* pMtr,  int nWidth,  int nY, int nX, int16b& nVal) { VEC_GetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_GetVal(nm32s* pMtr,  int nWidth,  int nY, int nX, int32b& nVal) { VEC_GetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_GetVal(nm64s* pMtr,  int nWidth,  int nY, int nX, int64b& nVal) { VEC_GetVal(pMtr, nY*nWidth+nX,nVal);}

inline void MTR_GetVal(nm2u* pMtr,	 int nWidth,  int nY, int nX, uint2b& nVal) { VEC_GetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_GetVal(nm4u* pMtr,   int nWidth,  int nY, int nX, uint4b& nVal) { VEC_GetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_GetVal(nm8u* pMtr,   int nWidth,  int nY, int nX, uint8b& nVal) { VEC_GetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_GetVal(nm16u* pMtr,  int nWidth,  int nY, int nX, uint16b& nVal){ VEC_GetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_GetVal(nm32u* pMtr,  int nWidth,  int nY, int nX, uint32b& nVal){ VEC_GetVal(pMtr, nY*nWidth+nX,nVal);}
inline void MTR_GetVal(nm64u* pMtr,  int nWidth,  int nY, int nX, uint64b& nVal){ VEC_GetVal(pMtr, nY*nWidth+nX,nVal);}


    //! \}
    
//*****************************************************************************

    /**
    \internal
    \defgroup MTR_GetCol MTR_GetCol
    \ingroup mSupport
    \brief
        \ru �������� �� ������� ���� �������. 
        \en ********************************. 
		\~
    \param	pSrcMtr		
        \ru �������� �������. 
        \en Source mtr. 
		\~
		\param nCol
		    \ru ����� ����������� �������.
		    \en *************************.
		\~
    \param	nHeight		
        \ru ����� ����� �������� �������. 
        \en Row count in source mtr. 
		\~
    \param	nWidth		
        \ru ����� �������� �������� �������. 
        \en Column count in source mtr. 
		\~
    \retval	pDstVec		
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcMtr </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nCol </param> <values> 4 </values>
             <param> nHeight </param> <values> 64 </values>
             <param> nWidth </param> <values> 128 </values>
             <size> nWidth*nHeight </size>
        </testperf>
        <testperf> 
             <param> pSrcMtr </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
             <param> nCol </param> <values> 4 </values>
             <param> nHeight </param> <values> 64 </values>
             <param> nWidth </param> <values> 8 32 128 </values>
             <size> nWidth*nHeight </size>
        </testperf>
    \endxmlonly
    */
    //! \{
void MTR_GetCol( nm64sc *pSrcMtr, nm64sc *pDstVec, int nCol, int nHeight, int nWidth);
//void MTR_GetCol( nm16sc *pSrcMtr, nm16sc *pDstVec, int nCol, int nHeight, int nWidth); //pc version is not available!
    //! \}
    
#endif
