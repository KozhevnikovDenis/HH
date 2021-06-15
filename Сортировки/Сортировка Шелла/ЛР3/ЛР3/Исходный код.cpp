#include <stdlib.h>
#include <windows.h>
//#include <stdio.h>
#include <iostream>
using namespace std;

void Generate(int *arr, int num)
{
	srand(GetTickCount());
	for(int i=0;i<num;i++)
		arr[i]=rand();
//	return *(arr+1);
}

void Print(int *ar, int nu)
{
	for(int i=0;i<nu;i++)
		cout << ar[i] << " | ";
}






//void Shell_sorting{}

int increment(long *inc, long size) 
{
	int p1,p2,p3,s;
	p1=p2=p3=1;
	s=-1;
	do
	{
		if (++s%2)							//если s нечетное 
		{
			inc[s]=8*p1-6*p2+1;				//s нечетное
			//inc[s-1] = 8*p1 - 6*p2 + 1;
		}
		else
		{
			inc[s]=9*p1-9*p3+1;				//s четное
			//inc[s-1] = 9*p1 - 9*p3 + 1;
			p2*=2;
			p3*=2;
		}
		p1*=2;
	}
	while(3*inc[s]<size);
	//while(3*inc[s-1] < size);
	return (s>0?--s:0);
}

void shellSort(int *a, long size)
{
	long inc,i,j,*seq;
	int s;
	seq=new long[size];

	// вычисление последовательности приращений
	s=increment(seq,size);
	while (s>=0)
	{
	// сортировка вставками с инкрементами inc[]
		inc=seq[s--];
		for(i=inc;i<size;i++)
		{
			int temp=a[i];
			for(j=i-inc;(j>=0)&&(a[j]>temp);j-=inc)
				a[j+inc]=a[j];
			a[j+inc]=temp;
		}
	}
	delete[] seq;
}


void main()
{
	int *array,n=10000000;
	array=new int[n];
	//int b=Generate(array,n); cout <<"b="<< b << endl;;
	Generate(array,n);
//	Print(array,n);
	DWORD t1,t2;
	t1=GetTickCount();
	shellSort(array,n);
	t2=GetTickCount();
	cout << endl << "Time of sorting=" << t2-t1 << " milliseconds" << endl;
//	Print(array,n);
	delete[] array;
	system("pause");
}
