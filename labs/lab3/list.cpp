#include "list.h"

void duplicate(node* head, node*& newHead)
{
	if (head != nullptr)
	{
		newHead = new node();
		newHead->data = head->data;
		duplicate(head->next, newHead->next);
	}
	else
		newHead = nullptr;
}

void removeTwo(node*& head)
{
	removeTwo(nullptr, head);
}

// Yes, I copied my own code from the previous lab.
// It's practically the same thing, just without
// returning the number of twos removes. Why is
// this lab easier than the previous one?
void removeTwo(node* prev, node*& node)
{
	if (node != nullptr)
	{
		if (node->data == 2)
		{
			if (prev != nullptr)
			{
				// Must do this because node is a reference to prev->next,
				// so node cannot be modified directly.
				auto newNode = node->next;
				delete node;
				prev->next = newNode;
				node = newNode;
			}
			else
			{
				// Since prev is gaurenteed to be nullptr here,
				// we can use it for other things; in this case,
				// it's being used as a temporary node.
				prev = node;
				node = node->next;
				delete prev;
				prev = nullptr;
			}
			
			removeTwo(prev, node);
		}
		else
			removeTwo(node, node->next);
	}
}
