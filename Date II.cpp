#include <iostream>
#include <stdio.h>
#include <cmath>

class Node {
	public:
	Node * next;
	Node * prev;
	int val;
	Node(int a);
};

Node::Node(int a)
{
	val = a;
	next=NULL;
	prev=NULL;
}

Node* temp = NULL;
Node* days;

//make circular linked list
for(int i = 0; i < 7; i++)
{
	Node* n = new Node(i);
	if(i == 0)
		days = n;
	n->prev = temp;
	if(prev != NULL)
		temp.next = n;
	n->next = NULL;
	//n->val = i;
	temp = n;
	if(i == 6)
	{
		n->next = days;
		n->val = 0;
	}
}

int calculate(int date, int weekday)
{
	int given_day = date % 7;
	int num_rounds = abs(weekday)/7 + 1;
	int steps = 0;
	if(weekday%7 == 0) num_rounds--;
	//if(num_rounds > 1) steps = steps - 2;
	Node* curr = days;

	if(weekday == 0) return date;

	for(int k = 0; k < given_day - 1; k++)
		curr = curr->next;

	for(int i = 0; i < num_rounds; i++)
	{
		if(weekday > 0)
			curr = curr->next;
		else if(weekday < 0)
			curr = curr->prev;
		steps++;
		
		while(curr->val != weekday%7)
		{
			if(weekday > 0)
				curr = curr->next;
			else if(weekday < 0)
				curr = curr->prev;
			steps++;
		}
	}

	if(weekday > 0) return date + steps;
	if(weekday < 0) return date - steps;
}
			