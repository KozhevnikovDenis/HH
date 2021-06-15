#include "Queue.h"
#include <stdio.h>

Queue::Queue(void)
{
	first=0;
	last=0;
	count=0;
}


Queue::~Queue(void)
{
}

void Queue::Put(Element* e)
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

	printf("Element %d added to queue\n",e->value);
}

Element* Queue::Get()
{
	Element* e;

	if (first==0)
		return 0;
	e=first;
	first=first->next;
	first->prev = 0;
	e->next = 0;
	count--;

	printf("Element %d removed from queue\n",e->value);
	return e;
}

void Queue::Print()
{
	if(count<1)
	{
		printf("Queue is empty\n");
		return;
	}

	Element* e;
	e=first;
	while(e!=0)
	{
//		printf("%d, ",e->value);
		e=e->next;
	}
	printf("\n");
}


void Queue::Multiplication()
{
	Element* e;
	e=first;
	int mltpl=1;
	while(e!=0)
	{
		mltpl*=e->value;
		printf("%d, ",e->value);
		e=e->next;
	}
	printf("\nMultiplication=%d\n",mltpl);
}