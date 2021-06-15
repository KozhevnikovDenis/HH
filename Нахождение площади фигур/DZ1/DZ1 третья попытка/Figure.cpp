#include "Figure.h"
#include <iostream>
using namespace std;


Figure::Figure(void)
{
//	cout << "Figure Constructor called!" << endl;
	prev = nullptr; next = nullptr; value = 0;
}

Figure::~Figure(void)
{
//	cout << "Figure Destructor called!" << endl;
}

double Figure::GetSquare()
{
	cout << "Common Figure can't have a square!" << endl;
	return 0;
}

void Figure::PrintName()
{
	cout << "Abstract Figure" << endl;
}

Queue::Queue(void)
{
	first = 0;
	last = 0;
	count = 0;
}

Queue::~Queue(void)
{
}

void Queue::Put(Figure* f)
{
	if (f == 0)
		return;
	f->prev = last;
	if (count < 1)
	{
		last = f;
		first = f;
	}
	last->next = f;
	last = f;
	count++;
	cout << "Element " << f->value << " added to queue" << endl;
}

Figure* Queue::Get()
{
	Figure* f;
	if (first == 0)
		return 0;
	f = first;
	first = first->next;
	first->prev = 0;
	f->next = 0;
	count--;
	cout << "Element " << f->value << " removed from queue" << endl;
	return f;
}

void Queue::ShowSquares()
{
	if(count < 1)
	{
		cout << "Queue is empty";
		return;
	}
	Figure* f;
	f = first;
	cout << "Queue:  ";
	while(f != 0)
	{
		
		cout << f->value << "  ";
		f = f->next;
	}
	cout << endl;
	f=first;
	while(f!=0)
	{
		cout << f->value << " - square of ";
		f->PrintName();
		f=f->next;
	}
}