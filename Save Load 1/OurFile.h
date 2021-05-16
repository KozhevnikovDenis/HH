#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
class OurFile
{
private:
	int x, y, z;
public:
	OurFile();
	OurFile(int x, int y, int z);
	~OurFile();
	void Save(OurFile file);
	void Load();
	void Print();
};

