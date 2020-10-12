#include "list.h"

#include <iostream>

int main()
{
	node* head = nullptr;
	build(head);
	std::cout << "Head:\n";
	display(head);
	
	node* newHead;
	duplicate(head, newHead);
	std::cout << "\nNewHead:";
	display(newHead);
	
	removeTwo(newHead);
	std::cout << "\nNewHead without twos:";
	display(newHead);
	std::cout << "\nHead:";
	display(head);
	
	destroy(head);
	destroy(newHead);
	
	return 0;
}
