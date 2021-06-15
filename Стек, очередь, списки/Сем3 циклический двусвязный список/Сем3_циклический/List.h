#pragma once
class List
{
public:
	List(void);
	~List(void);

	List *next;
	List *prev;
	int value;

	List *add_head(int a);
	List *add_element(List *l,int count);
	List *delete_element(List *l);
//	List *delete_head(List *root);
	List *change_head(List *root);
	void Print(List *l);
	void Print_revers(List *l);
};

