#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	const int x = 30002;
	double array_all[x];
	ifstream F_read;
	F_read.open("read.txt");
	ofstream F_write_first, F_write_second;
	F_write_first.open("write_first.txt");
	F_write_second.open("write_second.txt");
	if (F_read)
	{
		if (!F_read.eof())
		{
			for (int i = 0; i < x; i++)
				F_read >> array_all[i];
			for (int i = 0; i < x; i = i + 2)
			{
				F_write_first << array_all[i] << endl;
				cout << "i " << i << endl;
			}
			for (int i = 1; i < x; i = i + 2)
				F_write_second << array_all[i] << endl;
//			for (int i = 0; i < 30000; i++)
//				cout << "all: " << array_all[i] << endl;
		}
		F_read.close();
		F_write_first.close();
		F_write_second.close();
	}
	return 0;
}