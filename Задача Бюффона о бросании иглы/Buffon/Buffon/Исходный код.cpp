#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void main()
{
	double x; // x координата центра иглы 
	double k; // угол межу проекцией и иглой
	double l = 0.9; // длина иглы
	int intersection = 0; // положительный результат (пересечение)
	double own_pi;
	double projection_x; //проекция пловины игры на ось х
	double cosine_value; //значение косинуса
	double probability; //значение вероятности классичесокй
	int needles_nember; //колво иголок
	int interval = 1; //интервал между нитками

	srand(GetTickCount());

	cout << "Enter number of needles: ";
	cin >> needles_nember;

	for (int i=0; i<needles_nember; i++)
	{
		/*x = ((double)(rand()%11))/10;         // random x (0.0 to 1.0)
		k = (double)(rand()%181);*/

		x = 1.0*rand()/RAND_MAX;
		k = 180.0*rand()/RAND_MAX;
		

		if (k==-1)
		cout<<"x="<<x<<" "<<"k="<<k<<endl;

		if (k > 90)
			cosine_value = cos((180-k)*3.14159265/180);
		if (k < 90)
			cosine_value = cos(k*3.14159265/180);
		if (k == 90)
			cosine_value = 0.0;

		projection_x = 0.5*l*cosine_value; 

		if (x >= 0.55 && x+projection_x >= 1)
			intersection++;
		if (x <= 0.45 && x-projection_x <= 0)
			intersection++;
	}

	probability = (double)intersection/(double)needles_nember;
	own_pi = (2*l)/(interval*probability);

	if (needles_nember == 0 || probability == 0)
	{cout << "Error!"; getch(); return;}

	cout << "Number of intersection = " << intersection << endl;
	cout << "Probability of intersection = " << probability << endl;
	cout << "Own PI = " << own_pi << endl;

	getch();
}