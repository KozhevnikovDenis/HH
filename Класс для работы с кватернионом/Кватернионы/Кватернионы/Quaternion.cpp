#include "Quaternion.h"
#include <stdio.h>
#include <math.h>


Quaternion::Quaternion(void)
{
	s=0;x=0;y=0;z=0;
}


Quaternion::~Quaternion(void)
{
}


Quaternion::Quaternion(double a,double b,double c,double d)
{
	s=a;x=b;y=c;z=d;
}


void Quaternion::Print()
{
	/*if(s%10>9&&x%10>9&&y%10>9&&z%10>9)
	{
		printf("%+f%+fi%+fj%+fk\n",s,x,y,z);
		return;
	}*/
	printf("%-.3f%+.3fi%+.3fj%+.3fk\n",s,x,y,z);
	if(x==0&&y==0&&z==0&&s!=0)
		printf("It is scalar quaternion\n");		//скалярный кв
	if(x!=0&&y!=0&&z!=0&&s==0)
		printf("It is vector quaternion\n");		//векторный кв
}


void Quaternion::PrintOrderedPair()
{
	printf("[%-.3f, %+.3fi%+.3fj%+.3fk]\n",s,x,y,z);
	if(x==0&&y==0&&z==0&&s!=0)
		printf("It is scalar quaternion\n");
	if(x!=0&&y!=0&&z!=0&&s==0)
		printf("It is vector quaternion\n");
}


void Quaternion::PrintComplex()
{
	printf("(%-.3f%+.3fi)+(%-.3f%+.3fi)j\n",s,x,y,z);
	if(x==0&&y==0&&z==0&&s!=0)
		printf("It is scalar quaternion\n");
	if(x!=0&&y!=0&&z!=0&&s==0)
		printf("It is vector quaternion\n");
}


Quaternion operator+(Quaternion q1, Quaternion q2)
{
		Quaternion temp;
		temp.s=q1.s+q2.s;
		temp.x=q1.x+q2.x;
		temp.y=q1.y+q2.y;
		temp.z=q1.z+q2.z;
		return temp;
//	return Quaternion(q1.s+q2.s, q1.x+q2.x, q1.y+q2.y, q1.z+q2.z);
}


/*Quaternion Quaternion::operator+(Quaternion q)
{
	Quaternion temp;
	temp.s=s+q.s;
	temp.x=x+q.x;
	temp.y=y+q.y;
	temp.z=z+q.z;
	return temp;
}*/


Quaternion operator-(Quaternion q1, Quaternion q2)
{
	Quaternion temp;
	temp.s=q1.s-q2.s;
	temp.x=q1.x-q2.x;
	temp.y=q1.y-q2.y;
	temp.z=q1.z-q2.z;
	return temp;
//	return Quaternion(q1.s-q2.s,q1.x-q2.x,q1.y-q2.y,q1.z-q2.z);
}


/*Quaternion Quaternion::operator-(Quaternion q)
{
	Quaternion temp;
	temp.s=s-q.s;
	temp.x=x-q.x;
	temp.y=y-q.y;
	temp.z=z-q.z;
	return temp;
}*/


Quaternion operator*(Quaternion q1, Quaternion q2)
{
	Quaternion temp;
	temp.s = q1.s*q2.s - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z;
	temp.x = q1.s*q2.x + q2.s*q1.x + q1.y*q2.z - q2.y*q1.z;
	temp.y = q1.s*q2.y + q2.s*q1.y + q1.z*q2.x - q2.z*q1.x;
	temp.z = q1.s*q2.z + q2.s*q1.z + q1.x*q2.y - q2.x*q1.y;
	return temp;
	/*return Quaternion(q1.s*q2.s - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z,
						q1.s*q2.x + q2.s*q1.x + q1.y*q2.z - q2.y*q1.z,
						q1.s*q2.y + q2.s*q1.y + q1.z*q2.x - q2.z*q1.x,
						q1.s*q2.z + q2.s*q1.z + q1.x*q2.y - q2.x*q1.y);*/
}


/*Quaternion Quaternion::operator*(Quaternion q)
{
	Quaternion temp;
	temp.s = s*q.s - x*q.x - y*q.y - z*q.z;
	temp.x = s*q.x + q.s*x + y*q.z - q.y*z;
	temp.y = s*q.y + q.s*y + z*q.x - q.z*x;
	temp.z = s*q.z + q.s*z + x*q.y - q.x*y;
	return temp;
}*/


Quaternion Quaternion::Conjugate(Quaternion q)
{
	Quaternion temp;
	temp.s=s;
	temp.x=-1*x;
	temp.y=-1*y;
	temp.z=-1*z;
	return temp;
}


double Quaternion::Module(Quaternion q)
{
//	printf("Module of quaternion |q|=%.3f\n",sqrt(q.s*q.s+q.x*q.x+q.y*q.y+q.z*q.z));
	if(sqrt(q.s*q.s+q.x*q.x+q.y*q.y+q.z*q.z)==1)
		printf("It is single quaternion\n");		//еденичный кв
	return sqrt(q.s*q.s+q.x*q.x+q.y*q.y+q.z*q.z);
}


Quaternion Quaternion::ReverseQuaternion(Quaternion q)
{
	Quaternion abstract;
	q=Conjugate(abstract);
	Quaternion temp;
	/*temp.s=q.s/(q.s*q.s+q.x*q.x+q.y*q.y+q.z*q.z);
	temp.x=-1*q.x/(q.s*q.s+q.x*q.x+q.y*q.y+q.z*q.z);
	temp.y=-1*q.y/(q.s*q.s+q.x*q.x+q.y*q.y+q.z*q.z);
	temp.z=-1*q.z/(q.s*q.s+q.x*q.x+q.y*q.y+q.z*q.z);*/
	temp.s=(q.s)/(s*s+x*x+y*y+z*z);
	temp.x=(q.x)/(s*s+x*x+y*y+z*z);
	temp.y=(q.y)/(s*s+x*x+y*y+z*z);
	temp.z=(q.z)/(s*s+x*x+y*y+z*z);
	return temp;
}


Quaternion operator/(Quaternion q1, Quaternion q2)
{
	Quaternion abstract;
	abstract=q2.ReverseQuaternion(abstract);
//	q2=q2.ReverseQuaternion(abstract);
	Quaternion temp;
	temp.s = q1.s*abstract.s - q1.x*abstract.x - q1.y*abstract.y - q1.z*abstract.z;
//	temp.s = q1.s*q2.s - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z;
	temp.x = q1.s*abstract.x + abstract.s*q1.x + q1.y*abstract.z - abstract.y*q1.z;
	temp.y = q1.s*abstract.y + abstract.s*q1.y + q1.z*abstract.x - abstract.z*q1.x;
	temp.z = q1.s*abstract.z + abstract.s*q1.z + q1.x*abstract.y - abstract.x*q1.y;
	return temp;
}


/*Quaternion Quaternion::operator/(Quaternion q)		//перепроверить
{
	Quaternion abstract;
	abstract=ReverseQuaternion(q);
	Quaternion temp;
	temp.s = s * kek.s - x*kek.x - y*kek.y - z*kek.z;
	temp.x = s*q.x + q.s*x + y*q.z - q.y*z;
	temp.y = s*q.y + q.s*y + z*q.x - q.z*x;
	temp.z = s*q.z + q.s*z + x*q.y - q.x*y;
	return temp;
}*/


Quaternion Quaternion::MultiplicationByNumber(int number)
{
	Quaternion temp;
	temp.s=number*s;
	temp.x=number*x;
	temp.y=number*y;
	temp.z=number*z;
	return temp;
}


double Quaternion::ScalarProduct(Quaternion q1, Quaternion q2)
{
//	printf("Scalar product=%.3f\n",q1.s*q2.s+q1.x*q2.x+q1.y*q2.y+q1.z*q2.z);
	return q1.s*q2.s+q1.x*q2.x+q1.y*q2.y+q1.z*q2.z;
}


double Quaternion::Angle(Quaternion q1, Quaternion q2)
{
//	printf("Angle=%.3f\n",acos(ScalarProduct(q1,q2)/(Module(q1)*Module(q2)))*180/3.14);
	return acos(ScalarProduct(q1,q2)/(Module(q1)*Module(q2)))*180/3.14;
}