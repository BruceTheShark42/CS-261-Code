#include "IronMiner.h"
#include <iostream>

IronMiner::IronMiner(int id, const std::string& resource)
	: GenericMiner(id, resource) {}

void IronMiner::detect() const
{
	std::cout << "Magnetometer activated.\n"
				 "Searching for magnetic field deviations.\n"
				 "Iron deposits located.";
}
