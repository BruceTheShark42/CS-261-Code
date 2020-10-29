#include "SodiumChlorideMiner.h"
#include <iostream>

SodiumChlorideMiner::SodiumChlorideMiner(int id, const std::string& resource)
	: GenericMiner(id, resource) {}

void SodiumChlorideMiner::detect() const
{
	std::cout << "Steam blasting...\n"
				 "Salinity detector activated.\n"
				 "Concentration vector of NaCl detected.";
}
