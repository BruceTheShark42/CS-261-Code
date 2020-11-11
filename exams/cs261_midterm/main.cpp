#include "dlist.h"

int main()
{
	node* head = nullptr;
	build(head);
	display(head);
	
	// PLEASE PUT YOUR CODE HERE to call the function assigned
	std::cout << "\nCalling copyToArray.\n";
	int array[100]; // I don't know the max amount of elements, but I think this is enough
	int size = copyToArray(head, array);
	std::cout << "Here are the contents of the array:\n";
	for (int i = 0; i < size; i++)
		std::cout << array[i] << ' ';
	std::cout << '\n';
	
	std::cout << "Calling reverseList.\n";
	reverseList(head);
	
	display(head);
	destroy(head);    
	return 0;
}
