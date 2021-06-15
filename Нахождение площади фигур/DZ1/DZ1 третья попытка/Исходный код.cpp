#include "Figure.h"
#include "Rectangle.h"
#include "Romb.h"
#include <conio.h>

/*void main()
{
	Figure *f, *f2; f=new Figure();
	Rectangle *r; r=new Rectangle();
	r->GetSquare();
	f2=(Rectangle*)r;
	f->PrintName();
	f2->PrintName();
//	r->PrintName();
	f->GetSquare();
	f2->GetSquare();
//	r->GetSquare();
	delete f;
	delete f2;
//	delete r;
	_getch();
}*/

void main()
{
	Figure *f1, *f2, *f3, *f4, *f5, *f6;
	Rectangle *re1, *re2, *re3;
	Romb *ro1, *ro2, *ro3;
	re1=new Rectangle();
	re2=new Rectangle();
	re3=new Rectangle();
	ro1=new Romb();
	ro2=new Romb();
	ro3=new Romb();
	f1=(Rectangle*)re1; f1->value=re1->GetSquare();
	f2=(Rectangle*)re2; f2->value=re2->GetSquare();
	f3=(Rectangle*)re3; f3->value=re3->GetSquare();
	f4=(Romb*)ro1; f4->value=ro1->GetSquare();
	f5=(Romb*)ro2; f5->value=ro2->GetSquare();
	f6=(Romb*)ro3; f6->value=ro3->GetSquare();
	Queue q;
	q.Put(f5);
	q.Put(f1);
	q.Put(f3);
	q.Put(f6);
	q.Put(f4);
	q.Put(f2);
	q.ShowSquares();
	q.Get();
	q.Get();
	q.ShowSquares();
	delete f1;
	delete f2;
	delete f3;
	delete f4;
	delete f5;
	delete f6;
	_getch();
}