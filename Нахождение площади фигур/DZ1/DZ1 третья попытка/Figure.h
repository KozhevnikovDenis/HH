#pragma once
class Figure
{
public:
	Figure(void);
	virtual ~Figure(void);
	virtual double GetSquare();
	virtual void PrintName();

	Figure* prev;
	Figure* next;
	double value;
};

class Queue
{
public:
	Queue(void);
	~Queue(void);
	void Put(Figure* f);
	Figure* Get();
	void ShowSquares();

	Figure* first;
	Figure* last;
	int count;
};