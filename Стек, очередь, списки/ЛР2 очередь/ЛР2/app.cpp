#include "Element.h"
#include "Queue.h"
#include <conio.h>
void main ()
{
	Element e1, e2, e3, e4, e5;
	e1.value = 10;
	e2.value = 20;
	e3.value = 30;
	e4.value = 40;
	e5.value = 50;
	Queue q;
	q.Put(&e2);
	q.Put(&e3);
	q.Put(&e1);
	q.Put(&e5);
	q.Put(&e4);
	q.Print();
	q.Multiplication();
	q.Get();
	q.Get();
	q.Print();
	q.Multiplication();
	getch();
}