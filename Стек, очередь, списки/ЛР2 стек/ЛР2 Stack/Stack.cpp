#include "Stack.h"
#include <stdio.h>
#include <iostream>
using namespace std;

Stack::Stack(void)
{
	first=0;
	last=0;
	count=0;
}


Stack::~Stack(void)
{
}

void Stack::Put(Element* e)
{
	if (e==0)
		return;

	e->prev=last;

	if (count<1)
	{
		last=e;
		first=e;
	}

	last->next=e;
	last=e;
	count++;

	printf("Element %d added to stack\n",e->value);
}

Element* Stack::Get()
{
	Element* e;

	if (last==0)
		return 0;
	e=last;
	last=last->prev;
	last->next = 0;
	e->prev = 0;
	count--;

	printf("Element %d removed from stack\n",e->value);
	return e;
}

void Stack::Print()
{
	/*
	if(count<1)
	{
		printf("Stack is empty\n");
		return;
	}

	Element* e;
	e=last;
	printf("Stack: ");
	while(e!=0)
	{
		printf("%d, ",e->value);
		e=e->prev;
	}
	printf("\n");
	/*/

	if(count < 1)
{
cout << "Queue is empty";
return;
}
Element* e;
e = first;
while(e != 0)
{
cout << e->value << ", ";
e = e->next;
}
cout << endl;
}