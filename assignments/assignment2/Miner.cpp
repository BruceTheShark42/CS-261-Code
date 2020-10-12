#include "Miner.h"

Miner::Miner(int id, const std::string& resource)
	: id(id), resource(resource) {}

void Miner::start(std::ofstream& file) const
{
	file << "Miner #" << id << " (" << resource << ") is starting.";
}

void Miner::stop(std::ofstream& file) const
{
	file << "Miner #" << id << " (" << resource << ") is going to standby.";
}
