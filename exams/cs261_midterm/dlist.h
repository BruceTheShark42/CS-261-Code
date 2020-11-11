#ifndef DLIST_H
#define DLIST_H
//doubly linked list
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
/* place your prototype here */
int copyToArray(node* head, int* intArray);
int copyToArray(node* head, int* intArray, int index);

void reverseList(node*& head);
node* reverseListR(node* head);

#endif
