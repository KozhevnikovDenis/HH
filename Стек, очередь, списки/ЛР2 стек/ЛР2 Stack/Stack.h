#pragma once
#include "Element.h"
class Stack
{
public:
	Element* first;
	Element* last;
	int count;
	Stack(void);
	~Stack(void);
	void Put(Element* e);
	Element* Get();
	void Print();
};

