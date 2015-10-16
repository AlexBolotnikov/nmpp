//------------------------------------------------------------------------
//
//  $Workfile:: vStat.h  $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:02 $
//
//! \if file_doc
//!
//! \file   vMinMax.h
//! \author ������ �������
//! \brief  ����������� ������� ������ �������� � ���������
//!
//! \endif
//!
//------------------------------------------------------------------------

 
#ifndef _VSTAT_H_INCLUDED_
#define _VSTAT_H_INCLUDED_
    /**
	\internal
    \defgroup VEC_Crc VEC_Crc
    \ingroup vStat
		\brief 
		    \ru ������� ������������ ����.
		    \en Cyclic code calculation.

		\~
	  \~
		\param pSrcVec
			\ru ������� ������.
			\en Input vec.
		\~
		\param nSize
			\ru ������ �������� �������.
			\en Input vec size.

		\~
		\retval nCrc
			\ru ����������� ���.
			\en Cyclic code.

		\~
    \par
    \xmlonly
				<testperf>
          <param> pSrcVec </param> <values> L G 		</values>
          <param> nCrc  </param> <values> nn 		</values>
          <param> nSize     </param> <values> 10240 	</values>
				</testperf>
				<testperf>
          <param> pSrcVec </param> <values> G 		</values>
          <param> nCrc  </param> <values> nn 		</values>
          <param> nSize     </param> <values> 8 128 1024 10240 	</values>
				</testperf>

    \endxmlonly
    */
    //! \{
void VEC_Crc(unsigned int* pSrcVec, int nSize, unsigned int& nCrc);
inline void VEC_Crc(nm64s* pSrcVec, int nSize, unsigned int& nCrc) { return VEC_Crc((unsigned*)pSrcVec, nSize<<1, nCrc); }
inline void VEC_Crc(nm32s* pSrcVec, int nSize, unsigned int& nCrc) { return VEC_Crc((unsigned*)pSrcVec, nSize, nCrc); }
inline void VEC_Crc(nm16s* pSrcVec, int nSize, unsigned int& nCrc) { return VEC_Crc((unsigned*)pSrcVec, nSize>>1, nCrc); }
inline void VEC_Crc(nm8s*  pSrcVec, int nSize, unsigned int& nCrc) { return VEC_Crc((unsigned*)pSrcVec, nSize>>2, nCrc); }
inline void VEC_Crc(nm64u* pSrcVec, int nSize, unsigned int& nCrc) { return VEC_Crc((unsigned*)pSrcVec, nSize<<1, nCrc); }
inline void VEC_Crc(nm16u* pSrcVec, int nSize, unsigned int& nCrc) { return VEC_Crc((unsigned*)pSrcVec, nSize>>1, nCrc); }
inline void VEC_Crc(nm8u*  pSrcVec, int nSize, unsigned int& nCrc) { return VEC_Crc((unsigned*)pSrcVec, nSize>>2, nCrc); }


    //! \}
	


//*****************************************************************************
	/**
	\internal
    \defgroup VEC_SadV16 VEC_SadV16
    \ingroup vStat
	\brief 
		\ru ����� ���������� ��������� ���� �������� (SAD) �������� � 16 ��������� 
		\en Sum of absolute differences (SAD) between two array with size of 16 numbers 

		\~
	\param pSrc1
		\ru ������ �� 16 ���������. 
        \en array of 16 numbers
		\~
	\param pSrc2
		\ru ������ �� 16 ���������. 
        \en array of 16 numbers
		\~
	\return int		
		\ru SAD. 
        \en SAD

		\~
  \par
	\xmlonly
	 <testperf> 
			<param> pSrc1 </param> <values> L G </values>
			<param> pSrc2 </param> <values> L G </values>
			<size> 1 </size>
	 </testperf>
	\endxmlonly
    */

    //! \{
int VEC_SadV16(nm16s* pSrc1,nm16s* pSrc2);
int VEC_SadV16(nm8s*  pSrc1,nm8s*  pSrc2);
    //! \}


#endif // _VSTAT_H_INCLUDED_