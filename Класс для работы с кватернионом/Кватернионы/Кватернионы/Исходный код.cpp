#include "Quaternion.h"
#include <stdlib.h>
#include <stdio.h>
void main()
{
	Quaternion q;
	Quaternion q1(5,10,15,22);
	Quaternion q2(1,-8,21,23);
	Quaternion q3(2,9,-20,34);
	Quaternion q4(3,11,19,25);
	Quaternion q5(4,12,18,-26);
	Quaternion q6(6,13,-17,27);
	Quaternion q7(7,14,16,28);
	Quaternion q8(29,84,41,36);
	q1.Print();
	q2.PrintOrderedPair();
	q3.PrintComplex();
	printf("\n");
//	Quaternion sum;
//	sum=q1+q2; 
//	sum.Print();
	printf("Sum q1 and q2: "); (q1+q2).Print();
	printf("Difference q3 and q4: "); (q3-q4).Print();
	printf("Product q5 and q6: "); (q5*q6).Print();
	printf("\n");
	printf("Conjugate number for q5: "); (q5.Conjugate(q)).Print();
	printf("Module for q5: %.3f",q.Module(q5));
	printf("\n");
	printf("Reverse quaternion for q6: "); (q6.ReverseQuaternion(q)).Print();
	printf("Reverse quaternion for q8: "); (q8.ReverseQuaternion(q)).Print();
	printf("Quotient q8 and q6: "); (q8/q6).Print();
	printf("\n");
	printf("Multiplying q2 by number 49: "); (q2.MultiplicationByNumber(49)).Print();
	printf("Scalar product q3 and q5: %.3f",q.ScalarProduct(q3,q5));
	printf("\n");
	printf("Angle between q4 and q8: %.3f grad",q.Angle(q4,q8));
	printf("\n");
	system("pause");
}