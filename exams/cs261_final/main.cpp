#include "table.h"
#include <iostream>

int main()
{
	node* root = nullptr;
	build(root);
	display(root);
	
	/* Place code here to declare your array and then call copyToArray. After 
	 * creating the copy, write a loop to print out all of the values from 
	 * the array.*/
	std::cout << "Copying the tree to an array.\nThe resulting array: ";
	int array[100];
	int size = copyToArray(root, array);
	for (int i = 0; i < size; i++)
		std::cout << array[i] << ' ';
	
	/* Place code here to declare a new tree variable and then call 
	 * copyNonLeaf. After copying, add code to print out your new tree. */
	std::cout << "\nCopying the non-leaf nodes.\nHere's the tree without the previous leaf nodes.";
	node* newRoot = nullptr;
	copyNonLeaf(root, newRoot);
	display(newRoot);
	destroy(newRoot);
	
	display(root);
	destroy(root);
	return 0;
}
