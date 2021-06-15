#include "List.h"
#include <iostream>
using namespace std;


List::List(void)
{
	next=nullptr;
	prev=nullptr;
	value=0;
}


List::~List(void)
{
}


List *List::add_head(int a)
{
	List *l;
	l=new List();
	l->value=a;
//	l->next=nullptr;
//	l->prev=nullptr;
	l->next=l;
	l->prev=l;
	return l;
}

List *List::add_element(List *l,int count)
{
	List *temp,*p;
	temp=new List();
	p=l->next;
	l->next=temp;
	temp->value=count;
	temp->next=p;
	temp->prev=l;
//	if(p!=nullptr)
//		p->prev=temp;
	p->prev=temp;
	return temp;
}


List *List::delete_element(List *l)
{
	List *prev,*next;
	prev=l->prev;
	next=l->next;
//	if (prev!=nullptr)
//		prev->next=l->next;
	prev->next=l->next;
//	if (next!=nullptr)
//		next->prev=l->prev;
	next->prev=l->prev;
	delete l;
	return(prev);
}


/*List *List::change_head(List *left, List *right)
{
	List *temp_left, *temp_right;
	temp_right=right->next;
	temp_left=left->prev;
	return (temp_left,temp_right);
}*/

List *List::change_head(List *root)
{
	List *temp;
	temp=root->next;
	temp->prev=root;
	return(temp);
}


void List::Print(List *l)
{
	List *p;
	p=l;
	do
	{
		cout << " " << p->value;
		p=p->next;
	}
//	while (p!=nullptr);
	while (p!=l);
	cout << endl;
}


void List::Print_revers(List *l)
{
	List *p;
	p=l;
	/*while (p->next!=nullptr)
		p=p->next;
	do
	{
		cout << " " << p->value;
		p=p->prev;
	}
	while (p!=nullptr);*/
	do
	{
		p=p->prev;
		cout << " " << p->value;
	}
	while (p!=l);
	cout << endl;
}