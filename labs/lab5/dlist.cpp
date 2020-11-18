#include "dlist.h"

void duplicate(node* head, node*& newHead)
{
	duplicate(head, newHead, nullptr);
}

void duplicate(node* head, node*& newNode, node* previous)
{
	if (head != nullptr)
	{
		newNode = new node();
		newNode->data = head->data;
		newNode->previous = previous;
		duplicate(head->next, newNode->next, newNode);
	}
	else
		newNode = nullptr;
}

void removeTwo(node*& head)
{
	if (head != nullptr)
	{
		if (head->data == 2)
		{
			// Cache important nodes
			node* previous = head->previous;
			node* toDelete = head;
			
			// Remove the node
			head = head->next;
			delete toDelete;
			
			// Relink the list
			if (head != nullptr)
				head->previous = previous;
			if (previous != nullptr)
				previous->next = head;
			
			// Since a node was just removed,
			// the next node to check is now
			// head.
			removeTwo(head);
		}
		else
			// If the node didn't have a two,
			// just move on to the next node.
			removeTwo(head->next);
	}
}
