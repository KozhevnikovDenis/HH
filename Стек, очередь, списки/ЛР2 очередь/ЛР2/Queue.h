#pragma once
#include "Element.h"
class Queue
{
public:
	Element* first;
	Element* last;
	int count;

	Queue(void);
	~Queue(void);
	void Put(Element* e);
	Element* Get();
	void Print();
	void Multiplication();
};
