#include "clist.h"

int main()
{
	node* head = nullptr;
	build(head);
	display(head);
	
	// Feel free to edit any of the code in this file.
	
	addHead(head, 42);
	std::cout << "After adding 42 to the head.\n";
	display(head);
	
	std::cout << "\nMy version of the display function.\n";
	myDisplay(head);
	
	display(head); // resulting list after your function call!
	destroy(head);
	
	return 0;
}
