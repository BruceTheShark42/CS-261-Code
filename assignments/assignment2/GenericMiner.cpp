#include "GenericMiner.h"
#include <iostream>

GenericMiner::GenericMiner(int id, const std::string& resource)
	: Miner(id, resource) {}

void GenericMiner::collect() const
{
	std::cout << "Impact hammer positioned.\n"
				 "Impact hammer activated for 15 seconds.\n"
				 "Debris scoop activated.\n"
				 "Debris elevator activated.\n"
				 "Debris collection complete.";
}
