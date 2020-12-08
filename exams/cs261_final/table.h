#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

void build(node*& root);   // supplied
void display(node* root);  // supplied
void destroy(node*& root); // supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */

int copyToArray(node* root, int* array);
void copyToArray(node* root, int* array, int& size);

void copyNonLeaf(node* root, node*& newRoot);
#endif
