#ifndef __PLESSY_H
#define __PLESSY_H

//class I_PlessyCornerDetector ������������ ��� ������ ����������� ����� �� ����������� �� ������ Plessy.
//�� ������ �������� ���������� ����������� ����� � ������������� ���������.
class I_PlessyCornerDetector
{
public:
	//������������ ������ ��� ����� ������. 
	//w, h, ww - ������, ������ � step �������� ��������������.
	virtual void Allocate(int w, int h, int ww) = 0;

	//����������� ������, ���������� ��� ���� ������.
	virtual void DeAllocate() = 0;

	//���������� ���� ����. 
	//w, h, ww - as above. 
	//Picture - �������������� ��������.
	//*px, *py - ������� x � y ��������� ����� (������ �������� ������������ �������, ������������ 
	//	�������� - (w/2)*(h/2).
	//nc - ���������� ��������� �����.
	virtual void FindCorners(unsigned char *Picture, int w, int h, int ww, float *px, float *py, int& nc) = 0;

	//����������� ��������� �������
	virtual void Release() = 0;

	//������������� threshold, �� �������� ��������� Plessy-������. ��� 16s ������ �������� 32.0f. 
	//��� 32f ������ �������� 1/1024.
	//��� ������ �����, ��� ���� "��������" ����
	virtual void SetThreshold(float _threshold)=0;
};

//��� ���������� (float � short ��������������)
enum PCD_TYPE {PCD_32f, PCD_16s};

//������� ������ � ���������� ��������� I_PlessyCornerDetector
I_PlessyCornerDetector* CreatePlessyCornerDetector(PCD_TYPE type);


#endif