#include "Miner.h"
#include <iostream>

Miner::Miner(int id, const std::string& resource)
	: id(id), resource(resource) {}

void Miner::start() const
{
	std::cout << "Miner #" << id << " (" << resource << ") is starting.";
}

void Miner::stop() const
{
	std::cout << "Miner #" << id << " (" << resource << ") is going to standby.";
}
