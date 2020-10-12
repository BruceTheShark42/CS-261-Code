#include "IronMiner.h"

IronMiner::IronMiner(int id, const std::string& resource)
	: GenericMiner(id, resource) {}

void IronMiner::detect(std::ofstream& file) const
{
	file << "Magnetometer activated.\n"
			"Searching for magnetic field deviations.\n"
			"Iron deposits located.";
}
