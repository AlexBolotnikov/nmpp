//------------------------------------------------------------------------
//
//  $Workfile:: Access.cp $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:16 $
//
//! \if file_doc
//!
//! \file   Access.cpp
//! \author ������ �������
//! \brief  ������� ������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmplv.h"


nm8s*  VEC_Addr(const nm8s*  pBase, int Disp) { return (nm8s*)pBase+Disp; }
nm16s* VEC_Addr(nm16s* pBase, int Disp) { return pBase+Disp; }
nm32s* VEC_Addr(nm32s* pBase, int Disp) { return pBase+Disp; }
