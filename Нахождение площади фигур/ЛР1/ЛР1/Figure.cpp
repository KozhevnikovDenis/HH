#include "Figure.h"
#include <stdio.h>
#include <conio.h>


Figure::Figure(void)
{
	printf("Figure Constructor called!\n");
}


Figure::~Figure(void)
{
	printf("Figure Destructor called!\n");
}

double Figure::GetSquare()
{
	printf("Common Figure can't have a square!\n");
	return 0;
}

void Figure::PrintName()
{
	printf("Abstract Figure\n");
}

Queue::Queue(void)
{
	printf("constr\n");
}
Queue::~Queue(void)
{
	printf("destr\n");
}
void Queue::ShowSquares(Figure*)
{
	printf("jopa=%s\n",&f);
}
void Queue::Put(Figure*)
{
//	getch()=Get();
}
