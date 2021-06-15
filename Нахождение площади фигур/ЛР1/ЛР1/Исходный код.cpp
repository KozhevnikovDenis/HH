#include "Figure.h"
#include "Rectangle.h"
#include <conio.h>


void main()
{
	Figure *f;
	Rectangle *r;
	f=new Figure();
	r=new Rectangle();
	r->a=10;
	r->b=20;
	f->PrintName();
	r->PrintName();
	f->GetSquare();
	r->GetSquare();
	delete r;
	delete f;
	getch();
}
	//сверху и снизу разные шаги
/*	
	Figure* f;
	Figure* f2;
	Rectangle* r;
	f=new Figure();
	r=new Rectangle();
	r->a=10;
	r->b=20;
	f2=(Figure*)r;
	f->PrintName();
	f2->PrintName();
	f->GetSquare();
	f2->GetSquare();
	delete f;
	delete f2;
	getch();
	
}


void main()
{
	Figure *f1, *f2, *f3;
	Rectangle *r1, *r2, *r3;
	r1=new Rectangle();
	r2=new Rectangle();
	r3=new Rectangle();
	r1->a=1;r1->b=2;
	r2->a=5;r2->b=7;
	r3->a=15;r3->b=3;
	f1=(Figure*)r1;
	f2=(Figure*)r2;
	f3=(Figure*)r3;
	Queue q;
	q.Put(f1); q.Put(f3); q.Put(f2);
	q.ShowSquares(f1);
	delete f1;
	delete f2;
	delete f3;
	getch();
}*/