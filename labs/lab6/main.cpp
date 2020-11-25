#include "table.h"
#include <iostream>

int main()
{
	node* root = nullptr;
	build(root);
	display(root);
	
	node* newRoot;
	duplicate(root, newRoot);
	std::cout << "\nHere's the copy.";
	display(newRoot);
	
	std::cout << "\nRemoving 100 from the tree.\n";
	remove(newRoot, 100);
	std::cout << "\nAfter removing 100";;
	display(newRoot);
	
	std::cout << "Here's the original tree.";
	display(root);
	
	destroy(root);
	destroy(newRoot);
	return 0;
}
