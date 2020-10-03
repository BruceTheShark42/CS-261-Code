#include "arr.h"

int sum(node** heads)
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
		count += sum(heads[i]);
	return count;
}

int sum(node* node)
{
	return node != nullptr ? node->data + sum(node->next) : 0;
}

int removeTwo(node** heads)
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
		count += removeTwo(nullptr, heads[i]);
	return count;
}

int removeTwo(node* prev, node*& node)
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
			
			return 1 + removeTwo(prev, node);
		}
		else
			return removeTwo(node, node->next);
	}
	return 0;
}

