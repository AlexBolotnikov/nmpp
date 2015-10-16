 #ifndef __IARITHMETICS_H
#define __IARITHMETICS_H
#include "iDef.h"


//*****************************************************************************

    /**
	\internal
    \defgroup IMG_AddCnvArshI IMG_AddCnvArshI
    \ingroup iArithmetics
    \brief
        \ru ������������ ����������� ���������������� �����������. 
        \en Elementwise addition of the converted image. 
    
		\~
    
	\f[
        pSrcDstImg(x, y) += Convert(pSrcImg(x, y) >> nShift)
    \f]
    
	\f[ x = \overline{0 \ldots nWidth-1}, \quad 
        y = \overline{0 \ldots nHeight-1} \f]
    
    \param pSrcDstImg   
        \ru ��������� �� ������ ������� ROI ����������� �����������. 
        \en Pointer on the first ROI element of the replaceable image. 
		\~
    \param nSrcDstStride \ru ������������ �������� ��� ����������� ����������� \n
                             (���������� � 32-� ��������� ������). 
                         \en Row-to-row shift for the replaceable image \n
                             (measured in 32-bit words). 
    \param pSrcImg      
        \ru ��������� �� ������ ������� ROI ��� ������������� �����������. 
        \en Pointer to the first ROI element for the added image. 
		\~
    \param nSrcStride   \ru ������������ �������� ��� ������������� ����������� \n
                            (���������� � 32-� ��������� ������). 
                        \en Row-to-row shift for the added image \n
                             (measured in 32-bit words). 
    \param nShift       
        \ru ���������� ����� ��� �� ������� �������������� ���������� ������������ 
                            �����������. 
        \en Determines the number of bits for which the added image is preliminary shifted. 
		\~
    \param nWidth     
        \ru ������ ROI (���������� � ��������). ��������� �������� �������� ����.
        \en ROI width (measured in pixels). 
		\~
    \param nHeight    
        \ru ������ ROI (���������� � ��������). 
        \en ROI height (measured in pixels). 
		\~
    \return \e void
    
    \restr
    -   \ru ��������� �� ������ ������� ROI ������ ���� ��������� 
            � ������ �� ������� 64-� ���������� �����;
        \en Pointers to the first ROI element should be aligned
            in memory by the 64-bit word boundary;
		\~
    -   \ru ������ ROI ������ ���� ������ ����� �������� ��������������� �����������
            � 64-� ��������� �����;
        \en ROI width should be divisible by the number of pixels of the result image
            in a 64-bit word;
		\~
    -   \ru ������������ �������� ������ ���� ������ ����;
        \en Row-to-row shifts should be divisible by two;
		\~
    -   \ru �������� ��������� nShift ������ ���� ������ 2.
        \en nShift parameter value should be divisible by two.
        
		\~
    \par
    \xmlonly
        <testperf> 
             <param> pSrcImg </param> <values> L G </values>
             <param> pSrcDstImg </param> <values> L G </values>
             <param> nSrcStride </param> <values> 128 </values>
             <param> nSrcDstStride </param> <values> 64 </values>
             <param> nShift </param> <values> 2 </values>
             <param> nHeight </param> <values> 64 </values>
             <param> nWidth </param> <values> 64 </values>
             <size> nWidth*nHeight </size>
        </testperf>
        <testperf> 
             <param> pSrcImg </param> <values> G </values>
             <param> pSrcDstImg </param> <values> G </values>
             <param> nSrcStride </param> <values> 128 </values>
             <param> nSrcDstStride </param> <values> 64 </values>
             <param> nShift </param> <values> 2 </values>
             <param> nHeight </param> <values> 64 </values>
             <param> nWidth </param> <values> 8 32 64 </values>
             <size> nWidth*nHeight </size>
        </testperf>
    \endxmlonly
    */
    //! \{
void IMG_AddCnvArshI(nm16s* pSrcDstImg,  int nSrcDstStride, nm32s* pSrcImg, int nSrcStride, int nShift, int nWidth, int nHeight); 
    //! \}

//*****************************************************************************

    /**
	\internal
    \defgroup IMG_SubCnvArshI IMG_SubCnvArshI
    \ingroup iArithmetics
    \brief
        \ru ������������ ��������� ���������������� �����������. 
        \en Elementwise subtraction of a converted image. 
    
		\~
    
	\f[
        pSrcDstImg(x, y) -= Convert(pSrcImg(x, y) >> nShift)
    \f]
    
	\f[ x = \overline{0 \ldots nWidth-1}, \quad 
        y = \overline{0 \ldots nHeight-1} \f]
    
    \param pSrcDstImg    
        \ru ��������� �� ������ ������� ROI ��� ��������������� �����������. 
        \en Pointer to the first ROI element for the result image. 
		\~
    \param nSrcDstStride  \ru ������������ �������� ��� ��������������� �����������
                              (���������� � 32-� ��������� ������). 
    		              \en Row-to-row shift for the result image \n
    	                      (measured in 32-bit words). 
    \param pSrcImg       
        \ru ��������� �� ������ ������� ROI ��� ����������� �����������. 
        \en Pointer to the first ROI element for the deducted image. 
		\~
    \param nSrcStride \ru ������������ �������� ��� ��������������� �����������
                          (���������� � 32-� ��������� ������). 
                      \en Row-to-row shift for the result image \n
    	                  (measured in 32-bit words). 
    \param nShift     
        \ru ���������� ����� ��� �� ������� �������������� ���������� ���������� 
                          �����������. 
        \en Defines for how many bits the deducted image is preliminary shifted. 
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
    -   \ru ��������� �� ������ ������� ROI ������ ���� ��������� 
            � ������ �� ������� 64-� ���������� �����;
        \en Pointers to the first ROI element should be aligned  
            in memory by the 64-bit word boundary;
		\~
    -   \ru ������ ROI ������ ���� ������ ����� �������� ��������������� �����������
            � 64-� ��������� �����;
        \en ROI width should be divisible by the number of pixels of the result image 
            in a 64-bit word;
		\~
    -   \ru ������������ �������� ������ ���� ������ ����;
        \en Row-to-row shifts should be divisible by two;
		\~
    -   \ru �������� ��������� nShift ������ ���� ������ 2.
        \en nShift parameter value should be divisible by two.
    
		\~
    \par
    \xmlonly
        <testperf> 
             <param> pSrcImg </param> <values> L G </values>
             <param> pSrcDstImg </param> <values> L G </values>
             <param> nSrcStride </param> <values> 128 </values>
             <param> nSrcDstStride </param> <values> 64 </values>
             <param> nShift </param> <values> 2 </values>
             <param> nHeight </param> <values> 64 </values>
             <param> nWidth </param> <values> 64 </values>
             <size> nWidth*nHeight </size>
        </testperf>
        <testperf> 
             <param> pSrcImg </param> <values> G </values>
             <param> pSrcDstImg </param> <values> L </values>
             <param> nSrcStride </param> <values> 128 </values>
             <param> nSrcDstStride </param> <values> 64 </values>
             <param> nShift </param> <values> 2 </values>
             <param> nHeight </param> <values> 64 </values>
             <param> nWidth </param> <values> 8 32 64 </values>
             <size> nWidth*nHeight </size>
        </testperf>
    \endxmlonly
    */
    //! \{

void IMG_SubCnvArshI(nm16s * pSrcDstImg,  int nSrcDstStride,  nm32s * pSrcImg, int nSrcStride, int nShift, int nWidth, int nHeight);
    //! \}

//*****************************************************************************

    /**
	\internal
    \defgroup IMG_AddI IMG_AddI
    \ingroup iArithmetics
    \brief
        \ru ������������ �������� ���� �����������. 
        \en Elementwise addition of two images. 
    
		\~
    
	\f[
        pSrcDstImg(x, y) += pSrcImg(x, y)
    \f]
    
	\f[ x = \overline{0 \ldots nWidth-1}, \quad 
        y = \overline{0 \ldots nHeight-1} \f]
    
    \param pSrcImg       
        \ru ��������� �� ������ ������� ROI ��� ������������� �����������. 
        \en Pointer to the first ROI element for the added image. 
		\~
    \param nSrcStride \ru ������������ �������� ��� ��������������� ����������� \n
                          (���������� � 32-� ��������� ������). 
                      \en Row-to-row shift for the result image \n
                          (measured in 32-bit words). 
    \param pSrcDstImg    
        \ru ��������� �� ������ ������� ROI ��� ��������������� �����������. 
        \en Pointer to the first ROI element for the result image. 
		\~
    \param nSrcDstStride \ru ������������ �������� ��� ����������� ����������� \n
                             (���������� � 32-� ��������� ������).    
                         \en Row-to-row shift for the replaceable image \n
                             (measured in 32-bit words). 
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
            - ������ ROI ������ ���� ������ ����� �������� 
                � 64-� ��������� �����; 
            - ������������ �������� ������ ���� ������ ����.
        \en
            - Pointers to the first ROI element should be aligned 
                in memory by the 64-bit word boundary; 
            - ROI width should be divisible by the number of pixels 
                in a 64-bit word; 
            - Row-to-row shifts should be divisible by two. 

    \par
    \xmlonly
        <testperf> 
             <param> pSrcImg </param> <values> L G </values>
             <param> pSrcDstImg </param> <values> L G </values>
             <param> nSrcStride </param> <values> 128 </values>
             <param> nSrcDstStride </param> <values> 128 </values>
             <param> nHeight </param> <values> 128 </values>
             <param> nWidth </param> <values> 128 </values>
             <size> nWidth*nHeight </size>
        </testperf>
        <testperf> 
             <param> pSrcImg </param> <values> G </values>
             <param> pSrcDstImg </param> <values> L </values>
             <param> nSrcStride </param> <values> 128 </values>
             <param> nSrcDstStride </param> <values> 128 </values>
             <param> nHeight </param> <values> 128 </values>
             <param> nWidth </param> <values> 8 64 128 </values>
             <size> nWidth*nHeight </size>
        </testperf>
    \endxmlonly
    */
    //! \{

void IMG_AddI(nm16s* pSrcDstImg, int nSrcDstStride, nm16s *pSrcImg,  int nSrcStride, int nWidth, int nHeight);
    //! \}

//*****************************************************************************

    /**
	\internal
    \defgroup IMG_SubI IMG_SubI
    \ingroup iArithmetics
    \brief
        \ru ������������ ��������� ���� �����������. 
        \en Elementwise subtraction of two images. 
    
		\~
    
	\f[
        pSrcDstImg(x, y) -= pSrcImg(x, y)
    \f]
    
	\f[ x = \overline{0 \ldots nWidth-1}, \quad 
        y = \overline{0 \ldots nHeight-1} \f]
    
    \param pSrcImg       
        \ru ��������� �� ������ ������� ROI ��� ����������� �����������. 
        \en Pointer to the first ROI element for the deducted image. 
		\~
    \param nSrcStride \ru ������������ �������� ��� ��������������� �����������
                          (���������� � 32-� ��������� ������). 
                      \en Row-to-row shift for the result image \n
    	                  (measured in 32-bit words). 
    \param pSrcDstImg    
        \ru ��������� �� ������ ������� ROI ��� ����������� �����������. 
        \en Pointer to the ROI origin for replacing image. 
		\~
    \param nSrcDstStride 
        \ru ������������ �������� ��� ����������� �����������
                            (���������� � 32-� ��������� ������). 
        \en Row-to-row shift for the replaceable image 
                            (measured in 32-bit words). 
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
            - ������ ROI ������ ���� ������ ����� �������� 
                � 64-� ��������� �����; 
            - ������������ �������� ������ ���� ������ ����.
        \en 
            - Pointers to the first ROI element should be aligned  
                in memory by the 64-bit word boundary;
            - ROI width should be divisible by the number of pixels 
                in a 64-bit word; 
            - Row-to-row shifts should be divisible by two. 
    
		\~
    \par
    \xmlonly
        <testperf> 
             <param> pSrcImg </param> <values> L G </values>
             <param> pSrcDstImg </param> <values> L G </values>
             <param> nSrcStride </param> <values> 128 </values>
             <param> nSrcDstStride </param> <values> 128 </values>
             <param> nHeight </param> <values> 128 </values>
             <param> nWidth </param> <values> 128 </values>
             <size> nWidth*nHeight </size>
        </testperf>
        <testperf> 
             <param> pSrcImg </param> <values> G </values>
             <param> pSrcDstImg </param> <values> L </values>
             <param> nSrcStride </param> <values> 128 </values>
             <param> nSrcDstStride </param> <values> 128 </values>
             <param> nHeight </param> <values> 128 </values>
             <param> nWidth </param> <values> 8 64 128 </values>
             <size> nWidth*nHeight </size>
        </testperf>
    \endxmlonly
    */
    //! \{

void IMG_SubI(nm16s* pSrcDstImg, int nSrcDstStride, nm16s *pSrcImg, int nSrcStride,  int nWidth, int nHeight);

    //! \}

//*****************************************************************************

    /**
	\internal
    \defgroup IMG_Halfsum IMG_Halfsum
    \ingroup iArithmetics
    \brief
        \ru ������������ ���������� ���� ������ �����������. 
        \en Elementwise halfsum of two blocks of images. 
    
		\~
    
	\f[
        pSrcDstImg(x, y) = pSrcMtr1(x, y) + pSrcMtr2(x, y) / 2
    \f]
    
	\f[ x = \overline{0 \ldots nWidth-1}, \quad 
        y = \overline{0 \ldots nHeight-1} \f]
    
    \param pSrcMtr1       
        \ru ��������� �� ������ ������� ROI ������� �����������. 
        \en Pointer to the first ROI element of the first image. 
		\~
    \param nSrcStride1 \ru ������������ �������� ��� ������� �����������
                          (���������� � 32-� ��������� ������). 
                      \en Row-to-row shift for the first image \n
    	                  (measured in 32-bit words). 
    \param pSrcMtr2       
        \ru ��������� �� ������ ������� ROI ������� �����������. 
        \en Pointer to the first ROI element of the second image. 
		\~
    \param nSrcStride1 \ru ������������ �������� ��� ������� �����������
                          (���������� � 32-� ��������� ������). 
                      \en Row-to-row shift for the second image \n
    	                  (measured in 32-bit words).
    \param pDstMtr       
        \ru ��������� �� ������ ������� ROI ����������. 
        \en Pointer to the first ROI element of the result. 
		\~
    \param nDstStride \ru ������������ �������� ��� ����������
                          (���������� � 32-� ��������� ������). 
                      \en Row-to-row shift for the result \n
    	                  (measured in 32-bit words).
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
            - ������ ROI ������ ���� ������ ����� �������� 
                � 64-� ��������� �����; 
            - ������������ �������� ������ ���� ������ ����.
        \en 
            - Pointers to the first ROI element should be aligned  
                in memory by the 64-bit word boundary;
            - ROI width should be divisible by the number of pixels 
                in a 64-bit word; 
            - Row-to-row shifts should be divisible by two. 
    
		\~
    \par
    \xmlonly
        <testperf> 
             <param> pSrcMtr1 </param> <values> L G </values>
             <param> pSrcMtr2 </param> <values> L G </values>
             <param> pDstMtr </param> <values> L G </values>
             <param> nSrcStride1 </param> <values> 128 </values>
             <param> nSrcStride2 </param> <values> 128 </values>
             <param> nDstStride </param> <values> 128 </values>
             <param> nHeight </param> <values> 128 </values>
             <param> nWidth </param> <values> 128 </values>
             <size> nWidth*nHeight </size>
        </testperf>
        <testperf> 
             <param> pSrcMtr1 </param> <values> G </values>
             <param> pSrcMtr2 </param> <values> G </values>
             <param> pDstMtr </param> <values> L </values>
             <param> nSrcStride1 </param> <values> 128 </values>
             <param> nSrcStride2 </param> <values> 128 </values>
             <param> nDstStride </param> <values> 128 </values>
             <param> nHeight </param> <values> 128 </values>
             <param> nWidth </param> <values> 8 64 128 </values>
             <size> nWidth*nHeight </size>
        </testperf>
    \endxmlonly
    */
    //! \{

void IMG_Halfsum(nm16s* pSrcMtr1, int nSrcStride1, nm16s* pSrcMtr2, 
        int nSrcStride2, nm16s* pDstMtr, int nDstStride,  int nWidth,int nHeight);

    //! \}


	/**
	\defgroup IMG_WAdd2I IMG_WAdd2I
	\ingroup iArithmetics
	\brief
		\ru ���������� ������������ ���� ������ � ������������ ���������
		\en

	\~
	\param pSrcImg1
		\ru ������ �������� �����������
		\en 
	\param nMulVal1
		\ru 1-�� ��������� 
		\en
	\param pSrcImg2
		\ru ������ �������� �����������
		\en
	\param nMulVal2
		\ru 2-�� ���������
		\en
	\param nAddVal
		\ru ������������ ���������  
		\en
	\param pDstImg
		\ru �������������� �����������
		\en
	\param nSize
		\ru ������ ����������� � ��������
		\en

    \par
    \xmlonly
        <testperf> 
             <param> pSrcImg1 </param> <values> L G </values>
             <param> pSrcImg2 </param> <values> L G </values>
             <param> pDstImg </param> <values> L G </values>
             <param> nMulVal1 </param> <values> n </values>
             <param> nMulVal2 </param> <values> m </values>
             <param> nAddVal </param> <values> nn </values>
             <param> nSize </param> <values> 128 </values>
             <size> nSize </size>
        </testperf>
        <testperf> 
             <param> pSrcImg1 </param> <values> G </values>
             <param> pSrcImg2 </param> <values> G </values>
             <param> pDstImg </param> <values> L </values>
             <param> nMulVal1 </param> <values> n </values>
             <param> nMulVal2 </param> <values> m </values>
             <param> nAddVal </param> <values> nn </values>
             <param> nSize </param> <values> 128 1024 10240 </values>
             <size> nSize </size>
        </testperf>
    \endxmlonly

	*/
	//! \{
void IMG_WAdd2I(RGB32_nm10s* pSrcImg1, int nMulVal1, RGB32_nm10s* pSrcImg2, int nMulVal2, int nAddVal, RGB32_nm10s* pDstImg, int nSize);
	//! \}


	/**
	\defgroup IMG_Rsh2 IMG_Rsh2
	\ingroup iArithmetics
	\brief
		\ru ����������� ����� �������� ��������� ����������� �� 2 ���� ������
		\en

	\~
	\param pSrcImg
		\ru ������� �����������
		\en 
	\param pDstImg
		\ru �������� ����������� 
		\en
	\param nSize
		\ru ������ ����������� � ��������
		\en

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
void IMG_Rsh2(RGB32_nm10u* pSrcImg, RGB32_nm10u* pDstImg, int nSize);
	//! \}
#endif
