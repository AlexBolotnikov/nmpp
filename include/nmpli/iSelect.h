#ifndef __ICOMPARE_H
#define __ICOMPARE_H


//*****************************************************************************

    /**
	\internal
    \defgroup IMG_CompareGtC IMG_CompareGtC
    \ingroup iSelect
    \brief
        \ru ������������ ��������� �� ���������� ������. 
        \en Elementwise comparison for threshold exceeding. 
    
		\~
    
	\f[
        pDst(4 \cdot n+i, y) = \left\{
        \begin{array}{*{20}c}
            FFh, & if & pSrcImg(4 \cdot n+i, y) > pThreshold(i) \\
            00h, & if & pSrcImg(4 \cdot n+i, y) \le pThreshold(i) \\
        \end{array} \right.
    \f]
    
	\f[ i = \overline {0 \ldots 3}, 
        \quad n = \overline{0 \ldots nWidth / 4 - 1}, 
        \quad y = \overline{0 \ldots nHeight - 1} \f] 
    
    \ru ������� �������� � �������� ��������� ������ �� 4-� 16-�� ��������� �������
        � ���������� ������� ��������� ����������� � ������� ��������.  
    \en The function receives as a parameter an array of four 16-bit thresholds 
        and compares the source image pixels to these thresholds. 
		\~
    \param pSrcImg    
        \ru ��������� �� ������ ������� ROI ��� ��������� �����������. 
        \en Pointer to the first ROI element for the source image. 

		\~
		\~
    \param nSrcStride \ru ������������ �������� ��� ��������� ����������� 
                         (���������� � 32 ��������� ������). 
                      \en Row-to-row shift for the source image \n
                          (measured in 32-bit words). 
    \param pDstImg    
        \ru ��������� �� ������ ������� ROI ��� ��������������� �����������. 
        \en Pointer to the first ROI element for the result image. 
		\~
    \param nDstStride \ru ������������ �������� ��� ��������������� ����������� 
                          (���������� � 32 ��������� ������). 
                      \en Row-to-row shift for the result image \n
    	                  (measured in 32-bit words). 
    \param pThreshold 
        \ru ��������� �� ������ �� ������� 16-�� ��������� �������. 
        \en Pointer to the array of four 16-bit thresholds. 
		\~
    \param nWidth     
        \ru ������ ROI (���������� � ��������). 
        \en ROI width (measured in pixels). 
		\~
    \param nHeight    
        \ru ������ ROI (���������� � ��������). 
        \en ROI height (measured in pixels). 

		\~
    \return \e int
    
    \restr
        \ru
            - ��������� �� ������ ������� ROI ������ ���� ��������� 
                � ������ �� ������� 64-� ���������� �����; 
            - ������ ROI ������ ���� ������ ����� �������� � 64-� ��������� �����;
            - ������������ �������� ������ ���� ������ ����.
        \en
            - Pointers to the first ROI element should be aligned  
                in memory by the 64-bit word boundary;
            - ROI width should be divisible by the number of pixels in a 64-bit word;
            - Row-to-row shifts should be divisible by two.

    \par
    \xmlonly
        <testperf> 
          <param> pSrcImg </param> <values> L G </values>
          <param> nSrcStride </param>  <values> 64 </values>
          <param> pThreshold </param>  <values> L G </values>
          <param> pDstImg  </param>  <values> L G </values>
          <param> nDstStride </param>  <values> 64 </values>
          <param> nHeight </param>  <values> 128 </values>
          <param> nWidth </param>  <values> 128 </values>
          <size> nWidth*nHeight </size>
         </testperf>
        <testperf> 
          <param> pSrcImg </param> <values> L </values>
          <param> nSrcStride </param>  <values> 64 </values>
          <param> pThreshold </param>  <values> G </values>
          <param> pDstImg  </param>  <values> G </values>
          <param> nDstStride </param>  <values> 64 </values>
          <param> nHeight </param>  <values> 128 </values>
          <param> nWidth </param>  <values> 8 32 128 </values>
          <size> nWidth*nHeight </size>
         </testperf>
    \endxmlonly


    */
    //! \{
int IMG_CompareGtC(nm16s *pSrcImg, int nSrcStride, nm16s *pDstImg, int nDstStride, nm16s *pThreshold, int nWidth, int nHeight);
    //! \}

#endif
