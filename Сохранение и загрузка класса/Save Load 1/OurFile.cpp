#include "OurFile.h"

OurFile::OurFile()
{
	x = 0;
	y = 0;
	z = 0;
}

OurFile::OurFile(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

OurFile::~OurFile()
{

}

void OurFile::Save(OurFile file)
{
	string path = "MyFile.bin";
	ofstream fout;
	fout.open(path, ofstream::app);

	if (!fout.is_open())
		cout << "Error!" << endl;
	else
	{
		cout << "File is open for save." << endl;
		fout.write((char*)&file, sizeof(OurFile));
	}

	fout.close();
}

void OurFile::Load()
{
	string path = "MyFile.bin";
	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
		cout << "Error!" << endl;
	else
	{
		cout << "File is open for load." << endl;
		OurFile file;
		while (fin.read((char*)&file, sizeof(OurFile)))
			file.Print();
	}

	fin.close();
}

void OurFile::Print()
{
	cout << "X = " << x << "\tY = " << y << "\tZ = " << z << endl;
}