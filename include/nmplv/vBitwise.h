//------------------------------------------------------------------------
//
//  $Workfile:: vBitwis $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:02 $
//
//! \if file_doc
//!
//! \file   vLogic.h
//! \author ������ �������
//! \brief  ����������� �������� � ���������� ������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#ifndef _VBITWISE_H_INCLUDED_
#define _VBITWISE_H_INCLUDED_

#ifdef __cplusplus
		extern "C" {
#endif


//#include "Vector.h"

    /**
    \defgroup nmppsNot_ nmppsNot_
    \ingroup vBitwise
    \brief
        \ru ������� ����������� "��". 
        \en Logical NOT function. 
    
		\~
    
	\f[
        pDstVec[i]  =  \overline {pSrcVec[i]},        
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \ru ������� ��������  �������� ���� ����� �������� 
        �������  ��  ���������������. 
    \en The function changes the values of all bits of the 
        input vec elements for the opposite ones. 

		\~
		\~
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 

		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 

		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsNot_64u(nm64u* pSrcVec, nm64u* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsAndC nmppsAndC
    \ingroup vBitwise
    \brief
        \ru ������� ����������� "�" ����� �������� � ����������. 
        \en Logical AND function between vec and constant. 
    
		\~
    
	\f[
        pDstVec[i]  =  pSrcVec[i]  \wedge  nVal,
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nVal     
        \ru ���������. 
        \en Constant. 
		\~
    \param pnVal    
        \ru ��������� �� ���������. 
        \en Pointer to the constant. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstVec 
		    \ru �������������� ������.
        \en Result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pnVal  </param> <values> &amp;n </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize   </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pnVal  </param> <values> &amp;n </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize   </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsAndC_p64u(nm64u* pSrcVec, nm64u* pnVal, nm64u* pDstVec, int nSize);
void nmppsAndC_8u (nm8u* pSrcVec,  uint8b nVal,  nm8u*  pDstVec, int nSize);
void nmppsAndC_16u(nm16u* pSrcVec, uint16b nVal, nm16u* pDstVec, int nSize);
void nmppsAndC_32u(nm32u* pSrcVec, uint32b nVal, nm32u* pDstVec, int nSize);
void nmppsAndC_64u(nm64u* pSrcVec, uint64b nVal, nm64u* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsAnd_ nmppsAnd_
    \ingroup vBitwise
    \brief
        \ru ������� ����������� "�" ����� ����� ���������. 
        \en Logical AND function between two vectors. 
    
		\~
    
	\f[
        pDstVec[i]  =  pSrcVec1[i]  \wedge  pSrcVec2[i]
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> pSrcVec2 </param> <values> G </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsAnd_64u(nm64u* pSrcVec1, nm64u* pSrcVec2, nm64u* pDstVec, int nSize);
    //! \}
	
/**
    \defgroup nmppsAnd4V_ nmppsAnd4V_
    \ingroup vBitwise
    \brief
        \ru ������� ����������� "�" ����� �������� ���������. 
        \en The function of logical AND between four vectors. 
    
		\~
    
	\f[
         pDstVec[i]  =  pSrcVec1[i]  \wedge  pSrcVec2[i] \wedge  pSrcVec3[i] \wedge  pSrcVec4[i]
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
	\param pSrcVec3 
        \ru ������ ������� ������. 
        \en The third input vec. 
		\~
	\param pSrcVec4 
        \ru ��������� ������� ������. 
        \en The fourth input vec. 
		\~	
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> pSrcVec2 </param> <values> G </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsAnd4V_64u(nm64u* pSrcVec1, nm64u* pSrcVec2, nm64u* pSrcVec3, nm64u* pSrcVec4, nm64u* pDstVec, int nSize);
    //! \}
	
	// numVecs>2
void nmppsAndNV_64u(nm64u** pSrcVecs, int numVecs, nm64u* pDstVec, int nSize);	
//*****************************************************************************

    /**
    \defgroup nmppsAndNotV_ nmppsAndNotV_
    \ingroup vBitwise
    \brief
        \ru ������� ����������� "�-��" ����� ����� ���������. 
        \en Logical AND NOT function between two vectors. 
    
		\~
    
	\f[
        pDstVec[i]  =  pSrcVec1[i]  \wedge  not pSrcVec2[i]
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> pSrcVec2 </param> <values> G </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsAndNotV_64u(nm64u* pSrcVec1, nm64u* pSrcVec2, nm64u* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsOrC nmppsOrC
    \ingroup vBitwise
    \brief
        \ru ������� ����������� "���" ����� �������� � ����������. 
        \en The function of logical OR between a vectors and a constant. 
    
		\~
    
	\f[
         pDstVec[i]  =  pSrcVec[i]  \vee  nVal
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nVal     
        \ru ���������. 
        \en Constant. 
		\~
    \param pnVal    
        \ru ��������� �� ���������.
        \en Pointer to constant. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pnVal </param> <values> &amp;n </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pnVal </param> <values> &amp;n </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsOrC_8u (nm8u*  pSrcVec, uint8b  nVal,  nm8u* pDstVec, int nSize);
void nmppsOrC_16u(nm16u* pSrcVec, uint16b nVal, nm16u* pDstVec, int nSize);
void nmppsOrC_32u(nm32u* pSrcVec, uint32b nVal, nm32u* pDstVec, int nSize);
void nmppsOrC_64u(nm64u* pSrcVec, uint64b nVal, nm64u* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsOr nmppsOr
    \ingroup vBitwise
    \brief
        \ru ������� ����������� "���" ����� ����� ���������. 
        \en The function of logical OR between two vectors. 
    
		\~
    
	\f[
         pDstVec[i]  =  pSrcVec1[i]  \vee  pSrcVec2[i]
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> pSrcVec2 </param> <values> G </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsOr_64u(nm64u* pSrcVec1, nm64u* pSrcVec2, nm64u* pDstVec, int nSize);
    //! \}
	
/**
    \defgroup nmppsOr3V_ nmppsOr3V_
    \ingroup vBitwise
    \brief
        \ru ������� ����������� "���" ����� �������� ���������. 
        \en The function of logical OR between four vectors. 
    
		\~
    
	\f[
         pDstVec[i]  =  pSrcVec1[i]  \vee  pSrcVec2[i] \vee  pSrcVec3[i]
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
	\param pSrcVec3 
        \ru ������ ������� ������. 
        \en The third input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> pSrcVec2 </param> <values> G </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsOr3V_64u(nm64u* pSrcVec1, nm64u* pSrcVec2, nm64u* pSrcVec3, nm64u* pDstVec, int nSize);
    //! \}	
	
/**
    \defgroup nmppsOr4V_ nmppsOr4V_
    \ingroup vBitwise
    \brief
        \ru ������� ����������� "���" ����� �������� ���������. 
        \en The function of logical OR between four vectors. 
    
		\~
    
	\f[
         pDstVec[i]  =  pSrcVec1[i]  \vee  pSrcVec2[i] \vee  pSrcVec3[i] \vee  pSrcVec4[i]
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
	\param pSrcVec3 
        \ru ������ ������� ������. 
        \en The third input vec. 
		\~
	\param pSrcVec4 
        \ru ��������� ������� ������. 
        \en The fourth input vec. 
		\~	
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> pSrcVec2 </param> <values> G </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsOr4V_64u(nm64u* pSrcVec1, nm64u* pSrcVec2, nm64u* pSrcVec3, nm64u* pSrcVec4, nm64u* pDstVec, int nSize);
    //! \}

	// numVecs>2
void nmppsOrNV_64u(nm64u** pSrcVecs, int numVecs, nm64u* pDstVec, int nSize);
	
//*****************************************************************************

    /**
    \defgroup nmppsXorC nmppsXorC
    \ingroup vBitwise
    \brief
        \ru ������� ����������� "������������ ���" ����� �������� � ����������. 
        \en Logical Exclusive OR function between a vec and a constant.   
    
		\~
    
	\f[
         pDstVec[i]  =  pSrcVec[i]  \vee  nVal
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nVal     
        \ru ���������. 
        \en Constant. 
		\~
    \param pnVal    
        \ru ��������� �� ���������. 
        \en Pointer to constant. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
            <param> pSrcVec </param> <values> L G </values>
            <param> pnVal </param> <values> &amp;n </values>
            <param> pDstVec </param> <values> L G </values>
            <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
            <param> pSrcVec </param> <values> L </values>
            <param> pnVal </param> <values> &amp;n </values>
            <param> pDstVec </param> <values> G </values>
            <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //--------------------------------------------------------------------
    //! \{
void nmppsXorC_8u (nm8u*  pSrcVec, uint8b  nVal,  nm8u* pDstVec, int nSize);
void nmppsXorC_16u(nm16u* pSrcVec, uint16b nVal, nm16u* pDstVec, int nSize);
void nmppsXorC_32u(nm32u* pSrcVec, uint32b nVal, nm32u* pDstVec, int nSize);		
void nmppsXorC_64u(nm64u* pSrcVec, uint64b nVal, nm64u* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsXor_ nmppsXor_
    \ingroup vBitwise
    \brief
        \ru ������� ����������� "������������ ���" ����� ����� ���������. 
        \en Logical Exclusive OR function between two vectors.   
    
		\~
    
	\f[
         pDstVec[i]  =  pSrcVec1[i]  \vee  pSrcVec2[i]
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> pSrcVec2 </param> <values> G </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsXor_64u(nm64u* pSrcVec1, nm64u* pSrcVec2, nm64u* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsMaskV_ nmppsMaskV_
    \ingroup vBitwise
    \brief
        \ru ������� ����������� ��� � ��������������� ������������� ���� ��������. 
        \en Logical OR function with preliminary masking of two vectors.  
    
		\~
    
	\f[
         pDstVec[i]  =  (pSrcVec1[i] \qquad and \qquad pMaskVec[i])
         \qquad or \qquad (pSrcVec2[i] \qquad and \qquad \overline { pMaskVec[i]} )
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
    \param pMaskVec 
        \ru ������ �����. 
        \en Mask vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pMaskVec </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> pSrcVec2 </param> <values> G </values>
             <param> pMaskVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsMaskV_64u(nm64u* pSrcVec1, nm64u* pSrcVec2, nm64u* pMaskVec, nm64u* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsRShiftC nmppsRShiftC
    \ingroup vBitwise
    \brief
        \ru �������� ��������������� ������ ������. 
        \en Arithmetic shift to the right. 
    
		\~
    
	\f[
        pDstVec[i]  =  pSrcVec[i] >> nShift,
    \f]
    
	\f[
        i = \overline{0 \ldots nSize-1}
    \f]
    
    \ru ������� ��������� �������� ��������������� ������ ������  ����� 
        ��������� �������. 
        �������������� ���� ����������� �������� ����� - ������� �����. 
    \en The functions implement operations of arithmetic shift to the right 
        of vec element bits. 
        The freed bits are filled with sign bit. 

		\~
		\~
    \param	pSrcVec		
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param	nSize		
        \ru ������ ������� � ���������. 
        \en Vectors size in elements. 
		\~
    \param	nShift		
        \ru �������� ���������� �� ������� ������� ����� 
                            �������� ���� ��������� �������. 
        \en This parameter defines for how many positions 
                            vec elements should be shifted. 

		\~
    \retval	pDstVec		
        \ru �������������� ������. 
        \en Result vec. 

		\~
    \return \e void
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nShift </param> <values> 1 </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
             <param> nShift </param> <values> 1 2 3 </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
             <param> nShift </param> <values> 1 </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsRShiftC_8s (nm8s* pSrcVec, int nShift,  nm8s* pDstVec, int nSize);
void nmppsRShiftC_16s(nm16s* pSrcVec, int nShift, nm16s* pDstVec, int nSize);
void nmppsRShiftC_32s(nm32s* pSrcVec, int nShift, nm32s* pDstVec, int nSize);
void nmppsRShiftC_64s(nm64s* pSrcVec, int nShift, nm64s* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsRShiftC_ nmppsRShiftC_
    \ingroup vBitwise
    \brief
        \ru �������� ����������� ������. 
        \en Logical shift operation. 
    
		\~
    
	\f[
        pDstVec[i]  =  pSrcVec[i] >> nShift,
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \ru ������� ��������� �������� ����������� ������ ������  ����� ��������� �������. 
        ����� �������������� �� ����� ���, ���������  �  ��������������� ��������.
        �������������� ���� ����������� ������. 
    \en The functions implement the operations of logical shift to the right of vec element bits. 
        The shift is made for the number of bits indicated in the corresponding operand.
        The freed bits are filled with zeros. 

		\~
		\~
    \param	pSrcVec		
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param	nSize		
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \param	nShift		
        \ru ���������� �� ������� ������� ����� �������� 
                            ���� �������� �������. 
        \en Defines for how many positions the vec element bits should be shifted. 

		\~
    \retval	pDstVec		
        \ru �������������� ������. 
        \en Result vec. 

		\~
    \return \e void
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nShift </param> <values> 1 </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
			 <param> nShift </param> <values> 1 </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
			 <param> nShift </param> <values> 1 </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void  nmppsRShiftC_8u (nm8u* pSrcVec, int nShift,  nm8u* pDstVec, int nSize);
void  nmppsRShiftC_16u(nm16u* pSrcVec, int nShift, nm16u* pDstVec, int nSize);
void  nmppsRShiftC_32u(nm32u* pSrcVec, int nShift, nm32u* pDstVec, int nSize);
void  nmppsRShiftC_64u(nm64u* pSrcVec, int nShift, nm64u* pDstVec, int nSize);
    //! \}



    /**
    \defgroup nmppsRShiftC_AddC_ nmppsRShiftC_AddC_
    \ingroup vBitwise
    \brief
        \ru �������� ����������� ������. 
        \en Logical shift operation. 
    
		\~
    
	\f[
        pDstVec[i]  =  (pSrcVec[i] >> nShift) + nAddVal,
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \ru ������� ��������� �������� ����������� ������ ������  ����� ��������� ������� 
		� ������������ ��������.
        ����� �������������� �� ����� ���, ���������  �  ��������������� ��������.
        �������������� ���� ����������� ������. 
    \en The functions implement the operations of logical shift to the right of vec element bits  
		with constant addition.
		The shift is made for the number of bits indicated in the corresponding operand.
        The freed bits are filled with zeros. 

		\~
		\~
    \param	pSrcVec		
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param	nAddVal		
        \ru ��������� ��� ������������. 
        \en Constant for addition. 
		\~
	\param	nSize		
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \param	nShift		
        \ru ���������� �� ������� ������� ����� �������� ���� �������� �������. 
        \en Defines for how many positions the vec element bits should be shifted. 
		\~
    \retval	pDstVec		
        \ru �������������� ������. 
        \en Result vec. 

		\~
    \return \e void
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
			 <param> nAddVal </param> <values> 0 </values>
			 <param> nShift </param> <values> 1 </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
			 <param> nAddVal </param> <values> 0 </values>
			 <param> nShift </param> <values> 1 </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
			 <param> nAddVal </param> <values> 0 </values>
			 <param> nShift </param> <values> 1 </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsRShiftC_AddC_16u(nm16u *pSrcVec,  int nShift, uint16b nAddVal,  nm16u *pDstVec, int nSize);
    //! \}
void nmppsRShiftC_AddC_8u(nm8u *pSrcVec,   int nShift, uint8b nAddVal,  nm8u  *pDstVec, int nSize);
void nmppsRShiftC_AddC_32u(nm32u *pSrcVec,  int nShift, uint32b nAddVal,  nm32u *pDstVec, int nSize);

//*****************************************************************************

    /**
    \defgroup nmppsDisplaceBits nmppsDisplaceBits
    \ingroup vBitwise
    \brief
		\ru ����������� �������� ����� ������ ��������� ������� � ������� ����� �������
		\en Continuous displacement of bits within binary array in direction to the end of array
		
		\~
		\ru
			������� ������� ���� ������ ��������� ������� �� ��������� ������� (nBits) � ������� ����� �������. 
			������ 64�. ����� ������� ���� ���������� �� ������� ������� ���� �� �����, � ������� ���� 
			������������ � ������� ������� ���������� 64�. �����. �������������� ����� � ������ 64�. ����� 
			����������� �������� ������ 64�. ����� � ������ pnBits.  ��������� ���� ����������� � ������� pDst.
			������ ������ �� 8 ��� : 
			\~
			\verbatim
				pnBits =[AB00000000000000]
				pSrcVec=[0807060504030201][FF0F0E0D0C0B0A09]
				pDstVec=[07060504030201AB][0F0E0D0C0B0A0908]
			\endverbatim
			��������� 8 ��� ������� pDstVec ����� ��������.
			���� �� ��������� pBits ���������� �� ��������� 64�. ����� � ���������� ��������� ������������� 
			����������� ���.
		\en
			Function dispaces bits within binary array by several positions (nBits) in direction to the 
			end of array. Buffer pSrcVec is considered as a bitstream which is contained in 64-bit array.
			Bits at the low part of 64-bit word of input array are dispaced to the higher positions in the same word, 
			and bits at the hightest positions are moved to lowest positions of the next 64-bit word.
			The remaining part at the begining of the first 64-bit word are filled by highest bits of word (pnBits)
			Example of dispacement by 8 positions : 
			\verbatim
				pnBits =[AB00000000000000]
				pSrcVec=[0807060504030201][FF0F0E0D0C0B0A09]
				pDstVec=[07060504030201AB][0F0E0D0C0B0A0908] (last 8 bits of pSrcVec will be lost)
			\endverbatim
			If you point pBits to the last 64-bit word of pSrcVec buffer you will get the cyclical bit shift


		\~
    \param	pSrcVec		
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param	nSize		
        \ru ������ �������� � 64�. ���������. 
        \en Vector size in 64-bit words. 

		\~
    \param	pnBits		
        \ru ��������� �� 64�-�����, ������� ���� �������� ������������ �� ��������������� ��� ������ ������� ����� ������� 64�. �����
        \en Pointer to 64bit word whose highset bit are placed to the remaining low part of the first 64bit-word of array. 

		\~
    \param	nBits		
        \ru ���-�� ������� �� ������� ���������� �������� ��� :nBits=[2,4,6....62].
        \en Value of bit displacement 	:nBits=[2,4,6....62].

		\~
    \retval	pDstVec		
        \ru �������������� ������. 
        \en Result vec. 

		\~
    \return \e void

 
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> pnBits </param> <values> &amp;n </values>
             <param> nBits </param> <values> 2 8 18 </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsFwdShiftBitstream(const nm64u* pSrcVec, nm64u* pDstVec, nm64u* pnBits, int nBits, int nSize);
    //! \}

	
#ifdef __cplusplus
	};
#endif
#endif // _VBITWISE_H_INCLUDED_