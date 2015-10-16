#ifndef __SUBPIXEL2D_H
#define __SUBPIXEL2D_H


//class I_2DSubPixelMinPosition ������������ ��� ������ �������������� �������� � ������� 3x3.
//������� ��� ���������� - "��������������" � "������������������"
class I_2DSubPixelMinPosition
{
public:

	//���� ������������� �������
	//S9 - ������ 3x3 � ��������� � ������ ��������.
	//dx, dy - ���������� ����� �������� ������������ ������ �������� 3x3 (S9).
	virtual void Find(float *S9, float& dx, float& dy) = 0;

	//����������� ���������
	virtual void Release() = 0;

};

//��� ���������� ("��������������" � "������������������" ��������������)
enum SPP_TYPE {SPP_par, SPP_trg};


//������� ������ � ���������� ��� ��������� I_2DSubPixelMinPosition.
I_2DSubPixelMinPosition* Create2DSubPixelMinPosition(SPP_TYPE type);


#endif

