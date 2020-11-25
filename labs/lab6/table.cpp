#include "table.h"

void duplicate(node* head, node*& newHead)
{
	if (head != nullptr)
	{
		newHead = new node();
		newHead->data = head->data;
		newHead->left = nullptr;
		newHead->right = nullptr;
		
		duplicate(head->left, newHead->left);
		duplicate(head->right, newHead->right);
	}
}

void remove(node*& root, int data)
{
	if (root != nullptr)
	{
		// data will either be found in the left subtree or not at all.
		if (root->data > data)
			remove(root->left, data);
		// data will either be found in the right subtree or not at all.
		else if (root->data < data)
			remove(root->right, data);
		// By this point, root->data can only be data, so remove it accordingly.
		// No children
		else if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}
		// Only right child
		else if (root->left == nullptr)
		{
			node* temp = root;
			root = root->right;
			delete temp;
		}
		// Only left child
		else if (root->right == nullptr)
		{
			node* temp = root;
			root = root->left;
			delete temp;
		}
		// Both children
		else
		{
			node* minNode = getMinNode(root->right);
			root->data = minNode->data;
			remove(root->right, minNode->data);
		}
	}
}

// Will fail if root is nullptr, but will only ever be used when that is not the case, so it's fine.
node* getMinNode(node* root)
{
	return root->left != nullptr ? getMinNode(root->left) : root;
}
