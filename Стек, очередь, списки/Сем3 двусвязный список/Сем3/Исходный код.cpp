#include "List.h"
#include <conio.h>
#include <iostream>
using namespace std;
void main()
{
	List l,*head,*current;
	int number;
	cout << "Enter head-root-element = "; cin >> number;
	head=l.add_head(number);
	current=head;
	for (int i=0;i<9;i++)										//список из 10 элементов
	{
		cout << "Enter elemnet = ";
		cin >> number;
		current=l.add_element(current,number);
	}

	cout << endl;

	l.Print(head);
	l.Print_revers(head);
	current=head->next->next->next;								//удаляем четвертый элемент списка
	l.delete_element(current);
	l.Print(head);
	l.Print_revers(head);

	cout << endl;

	List *head_2=l.delete_head(head);							//новый коревой узел
	l.Print(head_2);
	l.Print_revers(head_2);
	current=head_2->next->next->next->next->next->next;			//удаляем седьмой элемент списка
	l.delete_element(current);
	l.Print(head_2);
	l.Print_revers(head_2);
/*
	List l1,*head1,*current1;
	int number1;
	cout << "Enter elemnet = ";
	cin >> number1;
	cin >> current1;
	current1=head1;
	current1=l.add_element(current1,number1);
//	List *l1=new List();
//	l1->Put(head);
//	l1->Print(head);
	l.Print(head1);*/

	_getch();
}