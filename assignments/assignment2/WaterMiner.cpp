#include "WaterMiner.h"
#include <iostream>

WaterMiner::WaterMiner(int id, const std::string& resource)
	: Miner(id, resource) {}

void WaterMiner::detect() const
{
	std::cout << "Initiating heat blast.\n"
				 "Directional humidity detector activated.\n"
				 "Ice located.";
}

void WaterMiner::collect() const
{
	std::cout << "Water vacuums and hoses deployed.\n"
				 "Heater turned on. Waiting for the ice to melt.\n"
				 "Liquid water moved to collection chamber.\n"
				 "Surface pump activated.";
}
