#include "clist.h"
#include <iostream>

void addHead(node*& head, int data)
{
	node* last = head;
	while (last->next != head)
		last = last->next;
	
	node* newHead = new node();
	newHead->data = data;
	newHead->next = head;
	
	last->next = newHead;
	head = newHead;
}

void myDisplay(node* head)
{
	std::cout << "myDisplay: ";
	if (head != nullptr)
	{
		std::cout << head->data << " -> ";
		myDisplay(head, head->next);
	}
	std::cout << '\n';
}

void myDisplay(node* head, node* node)
{
	std::cout << node->data;
	
	if (head != node)
	{
		std::cout << " -> ";
		myDisplay(head, node->next);
	}
}
