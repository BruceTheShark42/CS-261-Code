// list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;;
};

void build(node*& root);   // supplied
void display(node* root);  // supplied
void destroy(node*& root); // supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
 
void duplicate(node* head, node*& newHead);
void remove(node*& root, int data);
//node* remove(node* root, int data);
node* getMinNode(node* root);
