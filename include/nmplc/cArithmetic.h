#ifndef _CARITHMETIC_H_INCLUDED_
#define _CARITHMETIC_H_INCLUDED_

#include "nmtype.h"



	/**
	\defgroup SCL_DivC SCL_DivC
	\ingroup <cArithmetic>
	\brief
		\ru ������� ���� ����������� �����
		\en

	\~
	\param *pnSrcA
		\ru ��������� �� �������.
		\en
	\param *pnSrcB
		\ru ��������� �� ��������.
		\en
	\param *Dst
		\ru ��������� �� �������.
		\en
	*/
	//! \{	
void SCL_DivC(nm64sc *pnSrcA, nm64s *pnSrcB, nm64sc *Dst);
    //! \}

	/**
	\defgroup SCL_ProdC SCL_ProdC
	\ingroup cArithmetic
	\brief
		\ru ������������ ���� ����������� �����.
		\en

	\~
	\param *pnSrcA
		\ru ��������� �� ������ ���������.
		\en
	\param *pnSrcB
		\ru ��������� �� ������ ���������.
		\en
	\param *Dst
		\ru ��������� �� ������������.
		\en
	*/
//! \{	
void SCL_ProdC(nm64sc *pnSrcA, nm64sc *pnSrcB, nm64sc *Dst);//ASM
//! \}

#endif
