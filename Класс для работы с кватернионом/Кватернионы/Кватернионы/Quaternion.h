#pragma once
class Quaternion
{
private:
	double s,x,y,z;			//s-������(������������ �����);x,y,z-���������� ����������� �������
public:
	Quaternion(void);
	~Quaternion(void);
	Quaternion(double a,double b,double c,double d);
	void Print();						//����� � ����� ���� (� ���� �����)
	void PrintOrderedPair();			//����� � ���� ������������� ����
	void PrintComplex();				//����� � ���� ������������ �����, ���� ��� k=ij
//	Quaternion operator+(Quaternion q);
	friend Quaternion operator+(Quaternion q1, Quaternion q2);
//	Quaternion operator-(Quaternion q);
	friend Quaternion operator-(Quaternion q1, Quaternion q2);
//	Quaternion operator*(Quaternion q);
	friend Quaternion operator*(Quaternion q1, Quaternion q2);
	Quaternion Conjugate(Quaternion q);				//����������� �����
	double Module(Quaternion q);
	Quaternion ReverseQuaternion(Quaternion q);		//������� �������� �� ��������� �� q^(-1)
//	Quaternion operator/(Quaternion q);
	friend Quaternion operator/(Quaternion q1, Quaternion q2);
	Quaternion MultiplicationByNumber(int number);
	double ScalarProduct(Quaternion q1, Quaternion q2);
	double Angle(Quaternion q1, Quaternion q2);
};