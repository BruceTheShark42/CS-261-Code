#include "arr.h"

int main()
{
	node* heads[SIZE] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	build(heads);
	display(heads);
	
	std::cout << "Sum: " << sum(heads) << '\n';
	std::cout << "Removed " << removeTwo(heads) << " two(s).\nWithout twos: ";
	
	display(heads);
	destroy(heads);
	
	return 0;
}

