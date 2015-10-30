
#ifndef INCLUDED_nmplv
#define INCLUDED_nmplv









//-----------------------------------------------------------

/*! \ru 
	\page intro �������� 
	\en 
	\page intro Introduction
	\~
	\ingroup nmppsGroup_	
	\ru 
����������� ������ ���������� �������� �������������� ������� �������� �� ��������� ���������� �������� (��������) ��� ����������� NM6405,NM6406, ������ �� �������� � ����� NMC. 

� ������ ���������� ������ ���������� � �������������� �������, �������� ���������, �������������, �����������, �������������� ������������ � �.�. ���������� ������������� ��� ������� ���������� ����������� ���������������� �������� ��� �� ����� �������� ������(�++), ��� � �� ����� ���������� � ������� ����������� ���������� ���� ������������� �������.  ������� ���������� ����� C++ ���������. 

����������� ������� ���������� ����������� �� ����� ���������� � �������������� ��������� ���������� � �������������� ��� ����������� ����������� NMC.  ��� �������� ���������� ���������� �������� ���������� �������� ����������� ���������� ������� ��� ����������� ����� x86, ����������� �� ����� �++. ������ ���������� ��������� ��������� ���������� � �������������� ������ ���������� ���������� ��������� �� ������������ ����������. 
	\en
The purpose of the library is to support the base operations for vector processing on NM6403,NM6404,NM6405 processor. The library �ontains logical and arithmetical functions, operations of comparision, initialization, copying, dat� conversion and so on. The library is meant for fast development of effective user programs as in a high level language(�++) as in assembly language using supported core low-level routines. 

The library functions have a C++ interface. Most of the library functions are implemented in assembly language with using vector core instructions and optimized for the processor architecture. 

For convenience of application programs development the library has implementations of functions for processors of x86 series in C++. These implementations allow to execute application programs written by means of this library on a personal computer. 
	\~
*/
//-------------------------------------------------------------


#include "nmtype.h"
#include "nmdef.h"

	
//-------------------------------------------------------------

/*! \ru 
	\defgroup nmvectype ���� ��������� ������
	\en 
	\defgroup nmvectype Vector data types
	\~
	\ingroup TYPE_Group
	\ru 
� ������ ������� �����������  ����  ��������� ������ � ��������  ����� �������� ������� ����������, ������������� ��������� ����.
�����  �������������� ���������� � �������� ����������.\n

��������� ��������� ���� �������� �  ������� ������������ �����������, ������������ � 64-��������� �����, 
�� ��� ����������� ��������� ����������� �� ������ �  ��������� ������ � �� ������: \n
1. ��������� �� ��������� ������ ������ ������� ������ �������. �.�. �������� � ������ �� ������� 64�. ����. \n
2. ������ �������, ������������ �� ���� �������, ��� �������, ����������� � ��������� ���������, ������������ ���� ������.  \n
   ��������� ����� ������� �� ���������  ������������ ���-��� �����, ����������� � 64�. �����. \n
   ��������: \n
   ��� nm8s  ���������-8 \n
   ��� nm16s ���������-4 \n
   ��� nm32s ���������-2 \n
   ��� nm64s ���������-1 \n
   ���� � �������� ������� ������ ������� ��a������, ��� �������� [32,64,96,128...], �� ��� ��������, ��� ���������� ������� ����� ������ �� ����� ��������� � ���������� 32.\n
3. ���� nm8s , nm16s, nm32s... ���� � ������� ��� ����������� ����������� ����������� ������, �� � ����� ������ �++ �������� �� �������� ,
   ��� ��� ������������ ����� typedef ��� ����������� �� ����������� ����� char, short �  int, ������� ��� ��� � ���� �������  �������� 32-���������� ������ � ����������� NeuroMatrix.
   ������� ��� ��������� ���� ����� ������������ ������ � ���������� *  (nm8s*,nm16s*,... ). ��������  �� sizeof() � �������� ���� ����� ����� ����������� �����������. 
   
\n
����������� ��������� � �������� ����:   \n
1. ������� nm - ������� ��� ������ �������� ���������� ,������������ � 64� ����� (nm8s,nm8u,nm16s.... ).\n
2. ����������� ������ ����������� ����� �������� nm (nm8s,nm8u - �������� �������, nm16s,nm16u - 16�. ������� ).\n
3. ������ s ��� u ������� �������� ��� ����������� ��� ������. \n
4. ��� ������ ��������� ������� �� ��������� ������������ ��������� �������� �������� ��������� ��������, ��� ��������� �����������. 
   ����� ����� ����� ������� � ���� ���-�� �������� ��� � ����� � �������� b. (nm8s7b) \n
	\en
	\~
*/
	
	
	

//-------------------------------------------------------------

/*! \ru 
	\defgroup nmtype ���� ��������� ������
	\en 
	\defgroup nmtype Scalar data types
	\~
	\ingroup TYPE_Group
	\ru 
����������� ������ ���������� �������� �������������� ������� �������� �� ��������� ���������� �������� (��������) ��� ����������� ��������� NeroMatrix. 

� ������ ���������� ������ ���������� � �������������� �������, �������� ���������, �������������, �����������, �������������� ������������ � �.�. ���������� ������������� ��� ������� ���������� ����������� ���������������� �������� ��� �� ����� �������� ������(�++), ��� � �� ����� ���������� � ������� ����������� ���������� ���� ������������� �������.  ������� ���������� ����� C++ ���������. 

����������� ������� ���������� ����������� �� ����� ���������� � �������������� ��������� ���������� � �������������� ��� ����������� ����������� ��������� NeuroMatrix.  ��� �������� ���������� ���������� �������� ���������� �������� ����������� ���������� ������� ��� ����������� ����� x86, ����������� �� ����� �++. ������ ���������� ��������� ��������� ���������� � �������������� ������ ���������� ���������� ��������� �� ������������ ����������. 
	\en
The purpose of the library is to support the base operations for vector processing on NM6403,NM6404,NM6405 processor. The library �ontains logical and arithmetical functions, operations of comparision, initialization, copying, dat� conversion and so on. The library is meant for fast development of effective user programs as in a high level language(�++) as in assembly language using supported core low-level routines. 

The library functions have a C++ interface. Most of the library functions are implemented in assembly language with using vector core instructions and optimized for the processor architecture. 

For convenience of application programs development the library has implementations of functions for processors of x86 series in C++. These implementations allow to execute application programs written by means of this library on a personal computer. 
	\~
*/
	

	
//*****************************************************************************

	/**
    *
    * 
    * \ru
	*	\defgroup vSupport  ������� ��������� 
    * \en
    *   \defgroup vSupport Support functions 
	* \~
    * \ingroup nmppsGroup_	
	*/

#include "vSupport.h"

//*****************************************************************************

	/**
    *
    * \ru
    *     \defgroup vInit ������������� � �����������
    * \en
    *     \defgroup vInit Initialization and copy
    * \~
    * \ingroup nmppsGroup_
	*/

#include "vInit.h"
#include "vInitDev.h"


//*****************************************************************************

	/**
    *
    * \ru
    *     \defgroup vArithmetics �������������� ��������
    * \en
    *     \defgroup vArithmetics Arithmetic functions
    * \~
    * \ingroup nmppsGroup_
	*/

#include "vArithmetics.h"
#include "vArithmeticsDev.h"


//*****************************************************************************

	/**
    *
    * \ru
    *     \defgroup vBitwise ���������� � �������� ��������
    * \en
    *     \defgroup vBitwise Logical and binary operations
    * \~
    * \ingroup nmppsGroup_
	*/


#include "vBitwise.h"

//*****************************************************************************

	/**
    *
    * \ru
    *     \defgroup vSelect �������� ���������
    * \en
    *     \defgroup vSelect Comparision operations
    * \~
    * \ingroup nmppsGroup_
	*/

#include "vSelect.h"

//*****************************************************************************

	/**
	\internal
    *
    * \ru
    *     \defgroup vStat �������������� �������
    * \en
    *     \defgroup vStat Statistical functions
    * \~
	* \ingroup nmppsGroup_
	*/

#include "vStat.h"

//*****************************************************************************

	/**
    *
    * \ru
    *     \defgroup vTransform ������������������ � ���������� 
    * \en
    *     \defgroup vTransform Sort and transformation
    * \~
    *  \ingroup nmppsGroup_
	*/

#include "vTransform.h"

//*****************************************************************************

	




#endif
