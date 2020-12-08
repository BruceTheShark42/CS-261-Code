#include "table.h"

int copyToArray(node* root, int* array)
{
	int size = 0;
	copyToArray(root, array, size);
	return size;
}

void copyToArray(node* root, int* array, int& size)
{
	if (root != nullptr)
	{
		copyToArray(root->left, array, size);
		array[size++] = root->data;
		copyToArray(root->right, array, size);
	}
}

void copyNonLeaf(node* root, node*& newRoot)
{
	if (root != nullptr)
	{
		if (root->left != nullptr || root->right != nullptr)
		{
			newRoot = new node();
			newRoot->data = root->data;
			newRoot->left = nullptr;
			newRoot->right = nullptr;
			
			copyNonLeaf(root->left, newRoot->left);
			copyNonLeaf(root->right, newRoot->right);
		}
	}
}
