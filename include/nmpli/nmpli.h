
#ifndef INCLUDED_nmpli
#define INCLUDED_nmpli

#include "nmtype.h"
#include "nmdef.h"
#include "nmplv.h"
#include "iDef.h"

#include "warpimg.h"
/*! \ru 
	\page intro �������� 
	\en 
	\page intro Introduction
	\~
    \ingroup IMG_Group
	
	\ru 
����������� ������ ���������� �������� �������������� ������� �������� ��������� ����������� ��� ���������� NM6403, NM6404, NM6405. � ������ ���������� ������ ������� ��������� ����������, �������������� �������� � �������� ��������������. ���������� ������������� ��� ������� ���������� ����������� ���������������� �������� �� ����� �������� ������ � �������������� ����������� ����������� ������� ����������. 

������� ���������� ����� C++ ���������. ����������� ������� ���������� ����������� �� ����� ���������� � �������������� ��������� ���������� � �������������� ��� ����������� ���������� NM6403. 

��� �������� ���������� ���������� �������� ���������� �������� ����������� ���������� ������� ��� ����������� ����� x86, ����������� �� ����� �++. ������ ���������� ��������� ��������� ���������� � �������������� ������ ���������� ���������� ��������� �� ������������ ����������. 
	\en
The purpose of the library is to support the base operations with image processing for NM6403, NM6404, NM6405 processor. Library contains two-dimensional filters, arithmetical operations with images, color conversions. The library is meant for fast development of effective user programs in a high level language using the advantages of this processor architecture. 

The library functions have a C++ interface. Most of the library functions are implemented in assembly language with using vector core instructions and optimized for the processor architecture. 

For convenience of application programs development the library has implementations of functions for processors of x86 series in C++. These implementations allow to execute application programs written by means of this library on a personal computer. 
	\~
*/


//*****************************************************************************

    /**
    * \ru
    *     \defgroup iArithmetics �������������� ��������
    * \en
    *     \defgroup iArithmetics Arithmetics
    * \~
    * \ingroup IMG_Group
    */
#include "iArithmetics.h"

//*****************************************************************************

	/** 
    * \ru
    *     \defgroup iFiltration �������� ����������
    * \en
    *     \defgroup iFiltration Mask filtration
     * \~
    * \ingroup IMG_Group
    */
#include "iFiltration.h"
//*****************************************************************************

    /**
    * \ru
    *     \defgroup iInit ������������� � ����������� 
    * \en
    *     \defgroup iInit Initialization and copy
    * \~
    * \ingroup IMG_Group
    */

#include "iInit.h"
//*****************************************************************************

    /*
	\internal
    * \ru
    *     \defgroup iResample ��������� ��������
    * \en
    *     \defgroup iResample Resampling
    * \~
    * \ingroup IMG_Group
    */

#include "iResample.h"
//*****************************************************************************

    /*
	\internal
    * \ru
    *     \defgroup iSelect �������� �������
    * \en
    *     \defgroup iSelect Select operations
    * \~
    * \ingroup IMG_Group
    */

#include "iSelect.h"

//*****************************************************************************

	/**
	* \ru 
	* 	\defgroup iSupport ������� ��������� 
	* \en
	*     \defgroup iSupport Support functions 
    * \~
    * \ingroup IMG_Group
	*/
#include "iSupport.h"

#include "iFloodFill.h"

#include "iCellTexture.h"

#include "iDeinterlace.h"

#include "iReodering.h"

//*****************************************************************************

	/**
	* \ru 
	* 	\defgroup IMG_Print ������� ������������ ������ ������ 
	* \en
	*	\defgroup IMG_Print Graphic print functions
    * \~
    * \ingroup IMG_Group
	*/
#include "iPrint.h"

#endif
