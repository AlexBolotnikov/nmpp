
#ifndef INCLUDED_nmplm
#define INCLUDED_nmplm

#include "nmtype.h"
#include "nmdef.h"
#include "nmpp.h"


/*! \ru 
	\page intro �������� 
	\en 
	\page intro Introduction
	\~
	\ingroup MTR_Group
	\ru 
����������� ������ ���������� �������� �������������� ������� �������� �� ��������� ������ ��� ����������� NM6403, NM6404, NM6405. � ������ ���������� ������ �������������� �������� ��� ���������. ���������� ������������� ��� ������� ���������� ����������� ���������������� �������� ��� �� ����� �������� ������(�++). 

������� ���������� ����� C++ ���������. ����������� ������� ���������� ����������� �� ����� ���������� � �������������� ��������� ���������� � �������������� ��� ����������� ���������� NM6403. 

��� �������� ���������� ���������� �������� ���������� �������� ����������� ���������� ������� ��� ����������� ����� x86, ����������� �� ����� �++. ������ ���������� ��������� ��������� ���������� � �������������� ������ ���������� ���������� ��������� �� ������������ ����������. 
	\en
The purpose of the library is to support the base operations with matrixes on NM6403, NM6404, NM6405 processors. The library �ontains arithmetical functions. The library is meant for fast development of effective user programs in a high level language(�++) . 

The library functions have a C++ interface. Most of the library functions are implemented in assembly language with using vector core instructions and optimized for the processor architecture. 

For convenience of application programs development the library has implementations of functions for processors of x86 series in C++. These implementations allow to execute application programs written by means of this library on a personal computer. 
	\~
*/



//*****************************************************************************

	/**
    *
    * \ru 
    *     \defgroup mSupport ������� ��������� 
    * \en
    *     \defgroup mSupport Support functions 
    * \~
    * \ingroup MTR_Group
	*/
#include "mSupport.h"

//*****************************************************************************
    //--------------------------------------------------------------------
    //! \ru
    //!     \defgroup mInit ������������� � �����������
    //! \en
    //!     \defgroup mInit Initialization and copy
	//! \~
    //! \ingroup MTR_Group
    //--------------------------------------------------------------------

#include "mInit.h"

//*****************************************************************************

	/**
    *
    * \ru
    *     \defgroup mMatrixVector ��������-��������� ��������
    * \en
    *     \defgroup mMatrixVector Vector-mtr operations.
    * \~
    * \ingroup MTR_Group
	*/
#include "mMatrixVector.h"
#include "mMatrixVectorDev.h"
//*****************************************************************************
#include "mInverse.h"

//#include "profile\profdata.h"



#endif
