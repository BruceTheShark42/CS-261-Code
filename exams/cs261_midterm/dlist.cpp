#include "dlist.h"

// put the implmenetation of the required functions here

int copyToArray(node* head, int* intArray)
{
	return copyToArray(head, intArray, 0);
}

int copyToArray(node* head, int* intArray, int index)
{
	if (head != nullptr)
	{
		intArray[index] = head->data;
		index = copyToArray(head->next, intArray, index + 1);
	}
	
	return index;
}

void reverseList(node*& head)
{
	head = reverseListR(head);
}

node* reverseListR(node* head)
{
	node* newHead = nullptr;
	
	if (head != nullptr)
	{
		node* temp = head->next;
		head->next = head->previous;
		head->previous = temp;
		
		newHead = temp != nullptr ? reverseListR(temp) : head;
	}
	
	return newHead;
}
