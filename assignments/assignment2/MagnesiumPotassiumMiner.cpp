#include "MagnesiumPotassiumMiner.h"

MagnesiumPotassiumMiner::MagnesiumPotassiumMiner(int id, const std::string& resource)
	: GenericMiner(id, resource) {}

void MagnesiumPotassiumMiner::detect(std::ofstream& file) const
{
	file << "Releasing oxygen...\n"
			"Thermal detector activated.\n"
			"Flammable reaction detected.";
}
