#include "WaterMiner.h"

WaterMiner::WaterMiner(int id, const std::string& resource)
	: Miner(id, resource) {}

void WaterMiner::detect(std::ofstream& file) const
{
	file << "Initiating heat blast.\n"
			"Directional humidity detector activated.\n"
			"Ice located.";
}

void WaterMiner::collect(std::ofstream& file) const
{
	file << "Water vacuums and hoses deployed.\n"
			"Heater turned on. Waiting for the ice to melt.\n"
			"Liquid water moved to collection chamber.\n"
			"Surface pump activated.";
}
