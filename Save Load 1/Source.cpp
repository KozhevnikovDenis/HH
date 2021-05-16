#include "OurFile.h"
int main()
{
	OurFile abstractFile;
	OurFile file1(20, 40, 6), file2(10, 30, 50), file3(31, -79, 5);
	abstractFile.Save(file1);
	abstractFile.Save(file2);
	abstractFile.Save(file3);
	abstractFile.Load();
	return 0;
}