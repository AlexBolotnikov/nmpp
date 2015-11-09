//------------------------------------------------------------------------
//
//  $Workfile:: cInit. $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/01/12 14:01:21 $
//
//! \if file_doc
//!
//! \file   cInit.h
//! \author ������ �������
//! \brief  ����������� ������� ������������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#ifndef _CINIT_H_INCLUDED_
#define _CINIT_H_INCLUDED_

//*****************************************************************************

//*****************************************************************************

    /**
    \defgroup nmppsRand nmppsRand
    \ingroup cInit
    \brief 
        \ru ��������� ���������� ����� � ����������� ��c�����������.
        \en Random number generation with uniform distribution.

		\~
	  \~
    \param nMin		
        \ru ����������� ��������� �������� ���������� �����.
        \en Minimal value for random number.
		\~
    \param nMax    
        \ru ������������ ��������� �������� ���������� �����.
        \en Maximal value for random number.
		\~
    \param nDivisible     
        \ru ��������, �������� ����� ������ ��������� �����.
        \en Random number will be divisible by this value.
		\~
    \return \e int
		\ru ��������� ����� � ��������� ���� [nMin, nMax]. ��� ������� ��� ����������
			������ �������� [-2^31; 2^31-1].
        \en Random number in range [nMin, nMax]. For function without parameters
			this range is [-2^31; 2^31-1].

		\~
    \par
    \xmlonly
        <testperf>
          <param> nMin </param> <values> 0 128 		</values>
          <param> nMax  </param> <values> 10240 </values>
          <param> nDivisible </param> <values> 1 </values>
          <size> 1 </size>
        </testperf>
        <testperf>
          <param> nMin </param> <values> 128 		</values>
          <param> nMax  </param> <values> 1024 10240 </values>
          <param> nDivisible </param> <values> 1 </values>
          <size> 1 </size>
        </testperf>
        <testperf>
          <param> nMin </param> <values> 128 		</values>
          <param> nMax  </param> <values> 10240 </values>
          <param> nDivisible </param> <values> 1 2 </values>
          <size> 1 </size>
        </testperf>

    \endxmlonly
    */
    //! \{
int nmppcRand(int nMin, int nMax, int nDivisible);
int nmppcRand(int nMin, int nMax);
int nmppcRand();
    //! \}


#endif // _CINIT_H_INCLUDED_