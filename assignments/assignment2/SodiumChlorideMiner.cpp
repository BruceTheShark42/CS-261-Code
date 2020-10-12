#include "SodiumChlorideMiner.h"

SodiumChlorideMiner::SodiumChlorideMiner(int id, const std::string& resource)
	: GenericMiner(id, resource) {}

void SodiumChlorideMiner::detect(std::ofstream& file) const
{
	file << "Steam blasting...\n"
			"Salinity detector activated.\n"
			"Concentration vector of NaCl detected.";
}
