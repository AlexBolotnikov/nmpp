//------------------------------------------------------------------------
//
//  $Workfile:: iFiltration.h                $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/02/10 12:36:38 $
//
//! \if file_doc
//!
//! \file   vFilter.h
//! \author S. Mushkaev
//! \brief  ����������� ������� ���������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------

#ifndef _IFILTER_H_INCLUDED_
#define _IFILTER_H_INCLUDED_

struct S_IMG_FilterKernel {
#ifdef __NM__
	nm32s* pDispArray;
	nm32s* pWeightMatrix;	
#else 
	nm32s* 	pDispArray;
	nm32s* 	pWeightMatrix;	
	int 	nKerWidth;
	int 	nKerHeight;
#endif
};


struct S_IMG_FilterKernel_32s32s {
#ifdef __NM__
	nm32s* pDispArray;
	nm32s* pWeightMatrix;	
	int nKerWidth;
	int nKerHeight;
#else 
	nm32s* pDispArray;
	nm32s* pWeightMatrix;	
	int nKerWidth;
	int nKerHeight;
#endif
};

	//*****************************************************************************
    /**
    \internal
	\defgroup IMG_SetFilter IMG_SetFilter
    \ingroup iFiltration
    \brief
        \ru ������������� ������������ �������, ������������ ��� ��������� ����������. 
        \en Sets filter coefficients used for two-dimensional filtration. 

		\~
		\~
	\ru 
		������� ������������ ���������������� �������� ��� ������ ������� ���������� \ref IMG_Filter "IMG_Filter".
		������� ��������������� ������ ������������� ������� �� ���������� ������ �������� ������������ � 
		��������� �� � ���� pKernel, ������� � ���������� �� ���� \ref IMG_Filter "IMG_Filter".
		������� � ����� ������� ���������� ����������� �������� � ��������� ����������� 
		��� ������� ��� ���� ����� �����������. 
		������: ������� _16s32s �������, ��� ������� IMG_SetFilter_16s32s()
		����������������� ���� pKernel ��� �������� ��� � ������� 
		IMG_Filter( nm16s * pSrcImg, nm32s* pDstImg, int nWidth, int nHeight, nm64s* pKernel).

    \en The function performs preparatory operations for call of filtration function \ref IMG_Filter "IMG_Filter".
		The function allocates memory for pKernel buffer,trasnforms array of filter coefficients
		to internal storage format and saves into pKernel buffer,
		wich is then used by \ref IMG_Filter "IMG_Filter" function.
		Postfix in function name determines digitcapacity of input and output images for which this kernel would be applied.
		Example: postfix _16s32s means that function IMG_SetFilter_16s32s() will init pKernel for using it in 
		IMG_Filter( nm16s * pSrcImg, nm32s* pDstImg, int nWidth, int nHeight, nm64s* pKernel) function.

		\~
    \param pWeights 
        \ru ��������� �� �������� ������,���������� ������� ������������� ������� ������� nKerWidth*nKerHeight. 
        \en Pointer to the linear array containing the filter coefficients mtr sized nKerWidth*nKerHeight. 
		\~
	\param nKerWidth 
		\ru ������ ���� �������.  nKerWidth=[3,5,7,...]
		\en Width of filter window. nKerWidth=[3,5,7,...]
		\~
	\param nKerHeight
		\ru ������ ���� �������. nKerHeight=[1,3,5,7,...]
		\en Height of filter window. nKerHeight=[1,3,5,7,...]
		\~
	\param nImgWidth 
		\ru ������ ����������� � �������� ������ ������ ����� ��������
		\en Image width the filter is applied to
		\~
	\retval pKernel
		\ru ��������� �� ����, ���������� ������������ ������� �� ���������� �������
		\en Pointer to kernel, wich includes filter coefficients in internal format 
		\~
    \return 
		\ru �������� ������ ����������� ��������� pKernel � 32�. ������.
		\en Actual size of inited structure pKernel in 32bit words.
		\~
    */
    //! \{
int IMG_SetFilter_8s8s  (int* pWeights, int nKerWidth, int nKerHeight, int nImgWidth, nm64s* pKernel);
int IMG_SetFilter_8s16s (int* pWeights, int nKerWidth, int nKerHeight, int nImgWidth, nm64s* pKernel);
int IMG_SetFilter_8s32s (int* pWeights, int nKerWidth, int nKerHeight, int nImgWidth, nm64s* pKernel);
int IMG_SetFilter_16s16s(int* pWeights, int nKerWidth, int nKerHeight, int nImgWidth, nm64s* pKernel);
int IMG_SetFilter_16s32s(int* pWeights, int nKerWidth, int nKerHeight, int nImgWidth, nm64s* pKernel);
int IMG_SetFilter_32s32s(int* pWeights, int nKerWidth, int nKerHeight, int nImgWidth, nm64s* pKernel);
    //! \}

int IMG_GetFilterKernelSize32_8s8s(int nKerWidth, int nKerHeight);
int IMG_GetFilterKernelSize32_8s16s(int nKerWidth, int nKerHeight);
int IMG_GetFilterKernelSize32_8s32s(int nKerWidth, int nKerHeight);
int IMG_GetFilterKernelSize32_16s16s(int nKerWidth, int nKerHeight);
int IMG_GetFilterKernelSize32_16s32s(int nKerWidth, int nKerHeight);
int IMG_GetFilterKernelSize32_32s32s(int nKerWidth, int nKerHeight);
  
//*****************************************************************************

    /**
    \internal
	\defgroup IMG_Filter IMG_Filter
    \ingroup iFiltration
    \brief
        \ru ���������� ����������� ��������� ����������� �������� 
        � �������������� ��������������. 
        \en Image filtration using a two-dimensional central filter 
        with integer coefficients. 
    
		\~
    
	\f[
        pDstImg(x,y) = \sum_{dx = - \Delta x}^{\Delta x} \sum_{dy = - \Delta y}^{\Delta y} pSrcImg(x+dx,y+dy) \cdot pWeights(\Delta x+dx,\Delta y+dy),
    \f]
    
	\f[
        \Delta y = \left[ \frac{nKerHeight}{2} \right], \quad \Delta x = \left[ \frac{nKerWidth}{2} \right]
    \f]
    
    \ru ������������ ������� ��������������� � ������� ������� IMG_SetFilter() ��� IMG_CreateFilter() 
		��� ��������������� ����������� ������� � �������� ������.  
    \en The filter coefficients are set with the help of IMG_SetFilter() or IMG_CreateFilter() functions
		with appropriate digitcapacity of input and output data. 

		\~
		\~
    \param pSrcImg       
        \ru ��������� ��������� �����������. 
        \en Pointer to the source image. 
		\~
    \retval pDstImg          
        \ru ��������� �� �������������� ������������ . 
        \en Pointer to result image. 
		\~
    \param nWidth        
        \ru ������ ����������� (���������� � ��������). ��������� �������� �������� ����.
        \en Width on the output image (measured in pixels). 
		\~
    \param nHeight       
        \ru ������ ����������� (���������� � ��������). 
        \en Height of image (measured in pixels). 
		\~
	\param pKernel
        \ru ��������� �� ��������� ���������, ���������� ������� ����������� ������� �� ���������� �������. 
        \en Pointer to auxilary structure, which contains filter coefficents in internal format. 
		\~
    \return \e void

    \note 
		\ru ������������� ��������� ��������� ������������ �������������� �������� \ref IMG_SetFilter "IMG_SetFilter" ��� \ref IMG_CreateFilter "IMG_CreateFilter" \endlink.
        \en Initialization of Auxilary structure is performed by call of appropriate \ref IMG_SetFilter "IMG_SetFilter" or \ref IMG_CreateFilter "IMG_CreateFilter".
		\~

	\note 
		\ru ������ ������������������ ����������� � ������� ������� IMG_Filter_perf()
		\en Performance of IMG_Filter functions see are avaible here IMG_Filter_perf()
		\~
	
    */
    //! \{
void IMG_Filter( nm8s * pSrcImg, nm8s* pDstImg, int nWidth, int nHeight, nm64s* pKernel);
void IMG_Filter( nm8s * pSrcImg, nm16s* pDstImg, int nWidth, int nHeight, nm64s* pKernel);
void IMG_Filter( nm8s * pSrcImg, nm32s* pDstImg, int nWidth, int nHeight, nm64s* pKernel);
void IMG_Filter( nm16s * pSrcImg, nm16s* pDstImg, int nWidth, int nHeight, nm64s* pKernel);
void IMG_Filter( nm16s * pSrcImg, nm32s* pDstImg, int nWidth, int nHeight, nm64s* pKernel);
void IMG_Filter( nm32s * pSrcImg, nm32s* pDstImg, int nWidth, int nHeight, nm64s* pKernel);
    //! \}



//*****************************************************************************

    /**
    \internal
	\defgroup IMG_Filter_perf IMG_Filter_perf
		\ingroup iFiltration
		\brief 
			\ru ������� ��� ������ ������������������ ������� ���������� IMG_Filter()
			\en Functions for performance estimation of IMG_Filter() functions . 

		\~
		\~
    \param pWeights 
        \ru ��������� �� �������� ������,���������� ������� ������������� ������� ������� nKerWidth*nKerHeight. 
        \en Pointer to the linear array containing the filter coefficients mtr sized nKerWidth*nKerHeight. 
		\~
	\param nKerWidth 
		\ru ������ ���� �������.  nKerWidth=[3,5,7,...]
		\en Width of filter window. nKerWidth=[3,5,7,...]
		\~
	\param nKerHeight
		\ru ������ ���� �������. nKerHeight=[1,3,5,7,...]
		\en Height of filter window. nKerHeight=[1,3,5,7,...]
		\~
    \param pSrcImg       
        \ru ��������� ��������� �����������. 
        \en Pointer to the source image. 
		\~
    \param pDstImg          
        \ru ��������� �� �������������� ������������ . 
        \en Pointer to result image. 
		\~
	\param nImgWidth 
		\ru ������ ����������� � �������� ������ ������ ����� ��������. ��������� �������� �������� ����.
		\en Image width the filter is applied to
		\~
    \param nHeight       
        \ru ������ ����������� (���������� � ��������). 
        \en Height of image (measured in pixels). 
		\~
	\retval pKernel
		\ru ��������� �� ����, ���������� ������������ ������� �� ���������� �������
		\en Pointer to kernel, wich includes filter coefficients in internal format 
	
		\~
    \par
    \xmlonly
       <testperf> 
			<param> pSrcImg </param> <values> L G </values>
			<param> pDstImg </param> <values> L G </values>
			<param> pKernel </param> <values> L1 G1 </values>
			<param> pWeights </param> <values> L </values>
			<param> nKerWidth </param> <values> 5 </values>
			<param> nKerHeight </param> <values> 5 </values>
			<param> nImgWidth </param> <values> 128 </values>
			<param> nImgHeight </param> <values> 128 </values>
			<size> nImgWidth*nImgHeight </size>
        </testperf>
		<testperf> 
			<param> pSrcImg </param> <values> G  </values>
			<param> pDstImg </param> <values> L </values>
			<param> pKernel </param> <values>  L1 </values>
			<param> pWeights </param> <values> L </values>
			<param> nKerWidth </param> <values> 3 5 7 9 </values>
			<param> nKerHeight </param> <values> 1 3 5 7 9 </values>
			<param> nImgWidth </param> <values> 128 </values>
			<param> nImgHeight </param> <values> 128 </values>
			<size> nImgWidth*nImgHeight </size>
        </testperf>
		<testperf> 
			<param> pSrcImg </param> <values> G  </values>
			<param> pDstImg </param> <values> L </values>
			<param> pKernel </param> <values> L1 </values>
			<param> pWeights </param> <values> L </values>
			<param> nKerWidth </param> <values> 5 </values>
			<param> nKerHeight </param> <values> 5 </values>
			<param> nImgWidth </param> <values> 176 352 1024 </values>
			<param> nImgHeight </param> <values> 144 288 </values>
			<size> nImgWidth*nImgHeight </size>
        </testperf>
    \endxmlonly
    */
    //! \{
void IMG_Filter_perf(int* pWeights, int nKerWidth, int nKerHeight, nm8s*  pSrcImg, nm8s*  pDstImg, int nImgWidth, int nImgHeight, nm64s* pKernel);
void IMG_Filter_perf(int* pWeights, int nKerWidth, int nKerHeight, nm8s*  pSrcImg, nm16s* pDstImg, int nImgWidth, int nImgHeight, nm64s* pKernel);
void IMG_Filter_perf(int* pWeights, int nKerWidth, int nKerHeight, nm8s*  pSrcImg, nm32s* pDstImg, int nImgWidth, int nImgHeight, nm64s* pKernel);
void IMG_Filter_perf(int* pWeights, int nKerWidth, int nKerHeight, nm16s* pSrcImg, nm16s* pDstImg, int nImgWidth, int nImgHeight, nm64s* pKernel);
void IMG_Filter_perf(int* pWeights, int nKerWidth, int nKerHeight, nm16s* pSrcImg, nm32s* pDstImg, int nImgWidth, int nImgHeight, nm64s* pKernel);
void IMG_Filter_perf(int* pWeights, int nKerWidth, int nKerHeight, nm32s* pSrcImg, nm32s* pDstImg, int nImgWidth, int nImgHeight, nm64s* pKernel);
    //! \}



	

/*!
	\defgroup CIMG_FIR ���-���������� 
	\ingroup iFiltration	 
	\brief ��������� ��� ���������� 
*/	
//! \{

//! ����� ��� �������
//! \tparam nmbits_in  ��� ����������� ����������� �������� �����������. ���������� ���� : nm8s,nm16s,nm32s,nm64s
//! \tparam nmbits_out ��� ����������� ����������� ��������� �����������. ���������� ���� : nm8s,nm16s,nm32s,nm64s  . ����������� �������� ������� �� ������ ��������� ����������� ���������.
//! \par ������
//! \include app\example\Filter\IMG_Filter_16s32s\main.cpp 
template <class nmbits_in, class nmbits_out> class CIMG_FIR
{
public:
	void (*pfFree32)(void*);	///< ��������� �� ������� ������������ ������ (pKernel)
	int nKerWidth; 				///< ������ ���� ������������ ��� ������� 
	int nKerHeight;				///< ������ ���� ������������ ��� ������� 
	nm64s* pKernel;				///< ��������� �� ���������� ��������� �������������
	int nKernelSize;			///< ������ ������ ����������� ��� �������� ���������� ��������� �������������

	//! ����������� ��� ������� 
	/*!
	   �������� ������� ������ ��� ���������� ��������� ������������ 
		\param nKerWidth  ������ ���� �������. nKerWidth=[3,5,7,...]
		\param nKerHeight ������ ���� �������. nKerHeight=[1,3,5,7,...]
		\param malloc32_func  ��������� �� �������  ��������� ������������ ������ 32-���������� �������.
	    \param free32_func  ��������� �� ������� ������������� ����������� ������
    */
	CIMG_FIR(int nKerWidth, int nKerHeight, void* (*malloc32_func)(unsigned),void (*free32_func)(void*));
	

	//! ��������� ����������� ������� � �������������� ���������� ��������� ���������� ������������� � pKernel
	/*!
      \param pWeights   ������������ ������� 
	  \param nImgWidth  ������ ����������� � �������� ������ ������ ����� ��������. ��������� �������� �������� ����.
	  \return ��������� �� ���������� �������� �������������. 0- ���� ������ ��� ��������� �� ���� ��������.  
    */
	void* SetWeights(int* pWeights, int nImgWidth);
	
	//! ������� ���������� ����������
	/*!
	\f[
        pDstImg[y][x]  =  \sum\limits_{i = 0}^{nKerHeight-1} \sum\limits_{j = 0}^{nKerWidth-1} {pSrcImg[y+i-nKerHeight/2][x+j-nKerWidth/2] \cdot pWeights[i][j]}   ,x=0 \ldots  nImgWidth-1,y=0 \ldots  nImgHeight-1
    \f]


      \param pSrcImg ������� �����������
	  \param pDstImg �������� �����������
	  \param nImgWidth  ������ ����������� � �������� ������ ������ ����� ��������. ��������� �������� �������� ����.
	  \param nImgHeight   ������ ����������� (���������� � ��������). 
  
	  \warning ��� ���������� ������ � ��������� nKerHeight/2 ����� ������������ ����� �� ������� �������� ������� pSrcImg . 
	        ��� ���������� ��������� ������� ���������� �������������� ������������� ���� �������� �� ����� *nImgWidth*(nKernHeight/2+1) ������� ��������� ����� ������� � � ����� ������� pSrcImg.
    */
	void  Filter(nmbits_in* pSrcImg, nmbits_out* pDstImg, int nImgWidth,int nImgHeight);
	
	//! ����������� ������������ ������� ������ pKernel
	~CIMG_FIR();
	

};

//! \}
#endif // _IFILTER_H_INCLUDED_


