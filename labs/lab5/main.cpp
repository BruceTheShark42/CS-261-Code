#include "dlist.h"

int main()
{
	node* head = nullptr;
	build(head);
	display(head);
	
	node* newHead;
	duplicate(head, newHead);
	std::cout << "\nHere is the duplicate:";
	display(newHead);
	
	removeTwo(newHead);
	std::cout << "\nHere is the duplicate with 2s removed:";
	display(newHead);
	
	std::cout << "\nHere is the old list:";
	display(head);
	
	destroy(head);    
	destroy(newHead);
	return 0;
}
