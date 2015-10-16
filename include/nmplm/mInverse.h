//------------------------------------------------------------------------
//
//  $Workfile:: mInverse.h  $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/01/12 14:03:24 $
//
//! \if file_doc
//!
//! \file   mtrInverse.h
//! \author ������ �������
//! \brief  ��������� �������.
//!
//! \endif
//!
//------------------------------------------------------------------------

#ifndef _MINVERSE_H_INCLUDED_
#define _MINVERSE_H_INCLUDED_

//*****************************************************************************

	/*
    *
    * \if Russian
    *     \defgroup mInverse ��������� �������
    * \endif
    * \if English
    *     \defgroup mInverse Matrix inverse
    * \endif
    * \ingroup mtr
	*/

//*****************************************************************************

    /**
	\internal
    \defgroup MTR_fpResolve_Gauss MTR_fpResolve_Gauss
    \ingroup mInverse
    \brief
        \ru ������� ������� �������� ��������� ������� ������. 
        \en Solve linear system by Gauss method . 
    
		\~
	
	\f[
		A \cdot x = b
	\f]
    
    \param	pSrcMtrA		
        \ru ����������� ������� ��������� A. 
        \en Square system mtr A. 
		\~
    \param	pSrcVecB		
        \ru ��������� ������. 
        \en Free vec b. 
		\~
    \param	nSize			
        \ru ������ �������. 
        \en Matrix size. 
		\~
    \retval	pDstVecX		
        \ru ������ ������� x. 
        \en Solution vec. 
		\~
    \return \e void
    
    \restr 
        \ru ����� �������� �������� �� ������������ - 
              �������� ������� �� ����. 
        \en The function implements Gauss method without
              leading element selection. 
		\~
    \note \ru ������� � ������ ������ �� ��������������. 
          \en The function is not optimized yet. 
		\~
    \par
    \xmlonly
        <testperf> 
             <param> pSrcMtrA </param> <values> L G </values>
             <param> pSrcVecB </param> <values> L G </values>
             <param> pDstVecX </param> <values> L G </values>
             <param> nSize </param> <values> 3 6 </values>
             <size> nSize*nSize </size>
        </testperf>
    \endxmlonly
    *///--------------------------------------------------------------------
    //! \{
void MTR_fpResolve_Gauss(double* pSrcMtrA, double* pSrcVecB, double* pDstVecX, int nSize);
    //! \}


//*****************************************************************************

    /**
	\internal
    \defgroup MTR_fpResolve_PivotGauss MTR_fpResolve_PivotGauss
    \ingroup mInverse
    \brief
        \ru ������� ������� �������� ��������� ������� ������ � ������� 
        �������� ��������. 
        \en Solve system of linear equations by Gauss method with leading
        element selection. 
    
		\~
    
	\f[
    	A \cdot X = B
    \f]
    \param	pSrcMtrAB   
        \ru ������� ��������� A, ����������� 
                            ������ �������� B. 
        \en Equation mtr A augmented with 
                            vec B from the right. 
		\~
    \param	nSize     
        \ru ������ �������. 
        \en Matrix height. 
		\~
    \retval	pDstVecX    
        \ru ������ ������� X. 
        \en Solution vec X. 
		\~
    \return \e void
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcMtrAB </param> <values> L G </values>
             <param> pDstVecX </param> <values> L G </values>
             <param> nSize </param> <values> 3 6 </values>
             <size> nSize*nSize </size>
        </testperf>
    \endxmlonly
    */
    //! \{
void MTR_fpResolve_PivotGauss(double* pSrcMtrAB, double* pDstVecX, int nSize);
    //! \}

#endif // _MINVERSE_H_INCLUDED_