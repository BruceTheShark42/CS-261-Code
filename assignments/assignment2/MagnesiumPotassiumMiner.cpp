#include "MagnesiumPotassiumMiner.h"
#include <iostream>

MagnesiumPotassiumMiner::MagnesiumPotassiumMiner(int id, const std::string& resource)
	: GenericMiner(id, resource) {}

void MagnesiumPotassiumMiner::detect() const
{
	std::cout << "Releasing oxygen...\n"
				 "Thermal detector activated.\n"
				 "Flammable reaction detected.";
}
