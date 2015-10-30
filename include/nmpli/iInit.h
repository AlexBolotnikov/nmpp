#ifndef __ICONVERT_H
#define __ICONVERT_H

#include "iCellTexture.h"
#include "iDef.h"

//*****************************************************************************

    /**
	\internal
    \defgroup IMG_ArshCnv IMG_ArshCnv
    \ingroup iInit
    \brief
        \ru �������������� ����� ��� ��������� �����������. 
        \en Conversion of types for image elements.  
    
		\~
    
	\f[
        pDst(x,y) = Convert(pSrcImg(x,y) >> nShift)
    \f]
    
	\f[ x = \overline{0 \ldots nWidth-1}, \quad 
        y = \overline{0 \ldots nHeight-1} 
    \f]
    
    \ru ������� ����������� ��� ��������� ����� ��������� ������� ��������. 
    \en The function converts a type of elements by means of most significant bits truncation. 

		\~
		\~
    \param pSrcImg       
        \ru ��������� �� ������ ������� ROI ��� ��������� �����������. 
        \en Pointer to the first ROI element for the source image. 
		\~
    \param nSrcStride \ru ������������ �������� ��� ��������� �����������
                          (���������� � 32-� ��������� ������).  
    		          \en Row-to-row shift for the source image \n
    	                  (measured in 32-bit words). 
    \param pDstImg    
        \ru ��������� �� ������ ������� ROI ��� ��������������� �����������. 
        \en Pointer to the first ROI element for the result image. 
		\~
    \param nDstStride \ru ������������ �������� ��� ��������������� �����������
                          (���������� � 32-� ��������� ������). 
    		          \en Row-to-row shift for the result image \n
    	                  (measured in 32-bit words). 
    \param nShift     
        \ru ���������� ����� ��� �� ������� �������������� ���������� �������� 
                          �����������. 
        \en Defines for how many bits the source image is preliminary shifted. 
		\~
    \param nWidth     
        \ru ������ ROI (���������� � ��������). 
        \en ROI width (measured in pixels). 
		\~
    \param nHeight    
        \ru ������ ROI (���������� � ��������). 
        \en ROI height (measured in pixels). 

		\~
    \return \e void 
    
    \restr
        \ru
            - ��������� �� ������ ������� ROI ������ ���� ��������� 
              � ������ �� ������� 64-� ���������� �����;
            - ������ ROI ������ ���� ������ ����� �������� ��������������� �����������
              � 64-� ��������� �����;
            - ������������ �������� ������ ���� ������ ����.
            - �������� ��������� nShift ������ ���� ������ 2.
        \en
            - Pointers to the first ROI element should be aligned  
                in memory by the 64-bit word boundary; 
            - ROI width should be divisible by the number of pixels of the result image 
                in a 64-bit word; 
            - Row-to-row shifts should be divisible by two;
            - nShift parameter value should be divisible by two. 

    \par
    \xmlonly
        <testperf> 
          <param> pSrcImg </param> <values> L G </values>
          <param> nSrcStride </param>  <values> 128 </values>
          <param> nShift </param>  <values> 2 </values>
          <param> pDstImg  </param>  <values> L G </values>
          <param> nDstStride </param>  <values> 64 </values>
          <param> nHeight </param>  <values> 128 </values>
          <param> nWidth </param>  <values> 128 </values>
          <size> nWidth*nHeight </size>
        </testperf>
        <testperf> 
          <param> pSrcImg </param> <values> L </values>
          <param> nSrcStride </param>  <values> 128 </values>
          <param> nShift </param>  <values> 2 </values>
          <param> pDstImg  </param>  <values> G </values>
          <param> nDstStride </param>  <values> 64 </values>
          <param> nHeight </param>  <values> 128 </values>
          <param> nWidth </param>  <values> 8 32 128 </values>
          <size> nWidth*nHeight </size>
        </testperf>
    \endxmlonly
    */
    //! \{
void IMG_ArshCnv(nm32s* pSrcImg, int nSrcStride, nm16s* pDstImg,  int nDstStride, int nShift, int nWidth, int nHeight); 
    //! \}


//    \ru ������� ������������ �������� RGB ����� 8-� ��������� ��������������
//        � 10-�� ���������. ������� ��������� ����������� ������������� 
//        � 32-� ������� �����. ���������� RGB �������� ������� 3 �����, 
//        � ������� ���� �� ������������.\n 
//        ������� ��������� ����������� ������������� � 32-� ������� �����. 
//        ���������� RGB �������� 3 ������� 10-�� ������� ����, 
//        � ���������� 2 ���� �� ������������. 
//    \en Function converts RGB elements from 8-bits presentation in 10-bits.
//        Source elements are locate in 32-bits word. Components RGB occupy 
//        low three bytes. Hi byte is not use.\n
//        Output elements are locate in 32-bits word too. Components RGB 
//        occupy three low 10-bits fields, but stayed two bits are not used.
// \~

    /**
    \defgroup IMG_Cnv IMG_Cnv
    \ingroup iInit
    \brief
        \ru �������������� ����� ��� ��������� �����������.
        \en Conversion of types for image elements.  
    
		\~
    \ru ������� ������������ �������� RGB ����� 8-� ��������� ��������������
        � 10-�� ���������.  
    \en Function converts RGB elements between 8-bits presentation and 10-bits.
    
		\~
		\~
    \param pSrcImg       
        \ru ��������� �� ������ ������� ��������� �����������. 
        \en Pointer to the first element of the source image. 
		\~
    \param pDstImg    
        \ru ��������� �� ������ ������� ��������������� �����������. 
        \en Pointer to the first element of the result image. 
		\~
    \param nSize 
        \ru ���������� ��������� � �����������. 
        \en Quantity of elements. 

		\~
    \return \e void 
    
    \restr
        \ru
            - ��������� �� ����������� ������ ���� ��������� 
              � ������ �� ������� 64-� ���������� �����;
        \en
            - Pointers to the images should be aligned in memory 
              by the 64-bit word boundary; 

    \par
    \xmlonly
        <testperf> 
          <param> pSrcImg </param> <values> L G </values>
          <param> pDstImg  </param>  <values> L G </values>
          <param> nSize </param>  <values> 128 </values>
          <size> nSize </size>
        </testperf>
        <testperf> 
          <param> pSrcImg </param> <values> L </values>
          <param> pDstImg  </param>  <values> G </values>
          <param> nSize </param>  <values> 8 32 128 </values>
          <size> nSize </size>
        </testperf>
    \endxmlonly
    */
    //! \{
void IMG_Cnv(RGB32_nm8u* pSrcImg, RGB32_nm10u* pDstImg, int nSize); 
void IMG_Cnv(RGB32_nm10u* pSrcImg, RGB32_nm8u* pDstImg, int nSize); 
    //! \}



// ������� �������� �������� �����: [ 0RGB0RGB ] ( ��� ������� )
// 0.299=4c8b,   0.587=9646,   0.114=1d2f 
//--------------------------------------------
//            255
//pDstGray[i]=CLIP(0.299*R+0.587*G+0.114*B);
//            0
//            +127
//
//pDstGray[i]=CLIP(0.299*(R-128)+0.587*(G-128)+0.114*B(-128) +128);
//            -128
// ��� 0.299=4c8b,   0.587=9646,   0.114=1d2f 
//--------------------------------------------
//            255
//pDstGray[i]=CLIP(0.299*R+0.587*G+0.114*B);
//            0
// ��� 0.299=4c8b,   0.587=9646,   0.114=1d2f 

	/**
	\defgroup IMG_RGB32ToGray IMG_RGB32ToGray
	\ingroup iInit
	\brief
		\ru �������������� �������� �� RGB � �������
		\en

	\~
	\param pRGB
		\ru ����, �� 4 ����� �� �������. ������� ������ B, G, R, 0.
		\en
	\param pDstGray
		\ru ��������� � ���� 32 ������ ����� �����, � �������
            �������� ������ �������� ������� 24 ����. ��� ���������
            ������������� �������� ��������� �������� ���� 16..23,
            ��������, � ������� 
           nmppsClipArshCnv_Add_32s(nm32s* pSrcVec, int nClipFactor,int nShift, nm64u* nAddValue,nm8s* pDstVec, int nSize);
           � ����������� nClipFactor=24,  nShift=16.
		\en
	\param nSize 
		\ru ���������� �������� �� ����� � ������. nSize=[64,128,192,...]
		\en
	\param pTmpBuf
        \ru ��������� ������ �������� nm32s[nSize] . 
        \en Temporary array with size of  nm32s[nSize]. 

		\~
    \par
    \xmlonly
        <testperf> 
          <param> pRGB </param> <values> L G </values>
          <param> pDstGray  </param>  <values> L G </values>
          <param> pTmpBuf </param> <values> L G </values>
          <param> nSize </param>  <values> 128 </values>
          <size> nSize </size>
        </testperf>
        <testperf> 
          <param> pRGB </param> <values> L </values>
          <param> pDstGray  </param>  <values> G </values>
          <param> pTmpBuf </param> <values> G </values>
          <param> nSize </param>  <values> 8 32 128 </values>
          <size> nSize </size>
        </testperf>
    \endxmlonly

	*/
   //!  \{ 
void IMG_RGB32ToGray(RGB32_nm8u* pRGB, nm32u* pDstGray, int nSize);
void IMG_RGB32ToGray(RGB32_nm8u* pRGB, nm32s* pDstGray, int nSize);
void IMG_RGB32ToGray(RGB32_nm8u*  pRGB, nm8s* pDstGray, int nSize, void *pTmpBuf);

void IMG_RGB32ToGray(RGB32_nm10s* pRGB, nm32s* pDstGray, int nSize);
void IMG_RGB32ToGray(RGB32_nm10s* pRGB, nm32u* pDstGray, int nSize);
void IMG_RGB32ToGray(RGB32_nm10s* pRGB, nm8s*  pDstGray, int nSize, void *pTmpBuf);
  //! \}






	/**
	\internal
	\defgroup IMG_GrayToRGB242424242424242424 IMG_GrayToRGB242424242424242424
	\ingroup iInit
	\brief
		\ru �������������� �� ����������� ������� � RGB24 
		\en Gray to RGB24 conversion
		\~
	\~
	\param pSrcImg
		\ru ������� �����������
		\en Input image
		\~
	\param pDstImg
		\ru �������� ����������� 
		\en Output image
		\~
	\param nSize
		\ru ������ ����������� � ��������
		\en Size of image in pixels
		\~
	*/
	//! \{ 
void IMG_GrayToRGB242424242424242424(nm8u* pSrcImg, RGB24_nm8u* pDstImg, int nSize);
void IMG_RGB24ToGray(RGB24_nm8u* pRGB, nm8u* pDstGray, int nSize);
	//! \}
#endif
