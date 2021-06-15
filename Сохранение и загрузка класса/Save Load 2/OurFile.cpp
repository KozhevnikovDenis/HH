#include "OurFile.h"

OurFile::OurFile()
{

}

OurFile::~OurFile()
{

}

void OurFile::Save()
{
	string msg;
	string path = "MyFile.bin";
	fstream fs;
	fs.open(path, fstream::out | fstream::app);	//слева на права: открытие на запись, на добавление в конец без удаления предыдущих данных

	if (!fs.is_open())
		cout << "Error!" << endl;
	else
	{
		cout << "File is open for save." << endl;
//		fs.write((char*)&file, sizeof(OurFile));
		cout << "Enter your massage: ";
		cin >> msg;
		fs << msg << "\n";
	}

	fs.close();
}

void OurFile::Load()
{
	string msg;
	string path = "MyFile.bin";
	fstream fs;
	fs.open(path, fstream::in);	//открытие на чтение, 

	if (!fs.is_open())
		cout << "Error!" << endl;
	else
	{
		cout << "File is open for load." << endl;
		while (!fs.eof())
		{
			msg = "";
			fs >> msg;
			cout << msg << endl;
		}	
	}

	fs.close();
}
