// doubly linked list

// why are these included here, they should
// be included in the source file for supplied.o
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

struct node
{
	int data;
	node* previous;
	node* next;
};

/* These functions are already written and can be called to test out your code */
void build(node*& head);   // supplied
void display(node* head);  // supplied
void destroy(node* &head); // supplied

/* *****************YOUR TURN! ******************************** */
// Okay these linked lists are getting REALLY repetitive.
// And I don't mean just this class; I mean the labs for the last
// 3+ CS classes I've taken have all dealt with linked lists in
// one form or another. Seriously whoever designed this must love
// linked lists so much they want to share their happiness with the
// world. I'm not really receiving it that way, however.

void duplicate(node* head, node*& newNode);
void duplicate(node* head, node*& newNode, node* previous);

void removeTwo(node*& head);
