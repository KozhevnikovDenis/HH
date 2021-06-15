
#include <stdlib.h>
#include <windows.h>
#include <iostream>
using namespace std;

void Generate(int *&arr, int &num)
{
	srand(GetTickCount());
	for(int i=0;i<num;i++)
		arr[i]=rand();
}

void Print(int *&ar, int &nu)
{
	for(int i=0;i<nu;i++)
		cout << ar[i] << " | ";
}

int setmin(int *&a, int &n)
{
	int min=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]<=min)
			min=a[i];
	}
	cout<<endl<<"Min/GuardElement="<<min<<endl;
	return min;
}

void insertSortGuarded(int *&a, int &n)
{
	int i,j,backup,x;
	backup=a[0];
	a[0]=setmin(a,n);
	for (i=1; i < n; i++)
	{       
		x = a[i];
		for (j=i-1; a[j] > x; j--)
			a[j+1] = a[j];
		a[j+1] = x;
	}
	for ( j=1; j<n && a[j] < backup; j++)
		a[j-1] = a[j];
	a[j-1] = backup;
}












void main()
{
	int *array,n=1000;
	array=new int[n];
	Generate(array,n);
//	Print(array,n);
	DWORD t1,t2;
	t1=GetTickCount();
	insertSortGuarded(array,n);
	t2=GetTickCount();
	cout << endl << "Time of sorting=" << t2-t1 << " milliseconds" << endl;
//	Print(array,n);
	delete[] array;
	system("pause");
}

