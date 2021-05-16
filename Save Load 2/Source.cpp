#include "OurFile.h"
int main()
{
	OurFile abstractFile;
	int value;
	cout << "1 - Save." << endl;
	cout << "2 - Load." << endl;
	cout << "Enter number: ";
	cin >> value;
	if (value == 1)
	{
		abstractFile.Save();
	}
	if (value == 2)
	{
		abstractFile.Load();
	}
	return 0;
}