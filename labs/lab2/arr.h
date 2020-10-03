#ifndef ARR_H
#define ARR_H

#include <iostream>
#include <cstring>
#include <cctype>

const int SIZE = 5; // The size of the array of head pointers

struct node
{
	int data;
	node* next;
};

// These functions are already written and can be called to test out your code
void build(node** heads);   // supplied
void display(node** heads); // supplied
void destroy(node** heads); // supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:
int sum(node** heads);
int sum(node* node);
int removeTwo(node** heads);
int removeTwo(node* prev, node*& node);

#endif

