#pragma once
class Quaternion
{
private:
	double s,x,y,z;			//s-скаляр(вещественное число);x,y,z-координаты трехмерного вектора
public:
	Quaternion(void);
	~Quaternion(void);
	Quaternion(double a,double b,double c,double d);
	void Print();						//вывод в общем виде (в виде суммы)
	void PrintOrderedPair();			//вывод в виде упорядоченной пары
	void PrintComplex();				//вывод в виде комплексного числа, зная что k=ij
//	Quaternion operator+(Quaternion q);
	friend Quaternion operator+(Quaternion q1, Quaternion q2);
//	Quaternion operator-(Quaternion q);
	friend Quaternion operator-(Quaternion q1, Quaternion q2);
//	Quaternion operator*(Quaternion q);
	friend Quaternion operator*(Quaternion q1, Quaternion q2);
	Quaternion Conjugate(Quaternion q);				//сопряженное число
	double Module(Quaternion q);
	Quaternion ReverseQuaternion(Quaternion q);		//деление заменяем на умножение на q^(-1)
//	Quaternion operator/(Quaternion q);
	friend Quaternion operator/(Quaternion q1, Quaternion q2);
	Quaternion MultiplicationByNumber(int number);
	double ScalarProduct(Quaternion q1, Quaternion q2);
	double Angle(Quaternion q1, Quaternion q2);
};