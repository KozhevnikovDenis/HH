#pragma once
class Figure
{
public:
	Figure(void);
	//~Figure(void);
	virtual ~Figure(void);
	//double GetSquare();
	virtual double GetSquare();
	//void PrintName();
	virtual void PrintName();
	
};

class Queue
{
public:
	Queue(void);
	~Queue(void);
	Figure* f;
	void Put(Figure*);
	Figure* Get();
	void ShowSquares(Figure*);
};