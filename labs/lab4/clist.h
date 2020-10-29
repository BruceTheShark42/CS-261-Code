#ifndef CLIST_H
#define CLIST_H

#include <iostream>
#include <cstring>
#include <cctype>


struct node
{
	int data;
	node* next;
};

/* These functions are already written and can be called to test out your code */
void build(node*& head);
void display(node* head);
void destroy(node* &head);
void duplicate(node*& new_copy);

/****************** YOUR TURN! *********************************/
// Write your function prototype here:

void addHead(node*& head, int data);

void myDisplay(node* head);
void myDisplay(node* head, node* node);

#endif
