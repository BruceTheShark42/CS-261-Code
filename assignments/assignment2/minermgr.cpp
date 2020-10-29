#include "minermgr.h"

#include <iostream>
#include <fstream>

#include "WaterMiner.h"
#include "SodiumChlorideMiner.h"
#include "IronMiner.h"
#include "SiliconMiner.h"
#include "MagnesiumPotassiumMiner.h"

minermgr::~minermgr()
{
	for (auto miner : miners)
		delete miner;
}

void minermgr::addMiner(int id, const std::string& resource)
{
	miners.push_back(determineMinerType(id, resource));
}

void minermgr::runMiners() const
{
	std::cout << "== Boston Station Miner Manager ==\n"
			"\n"
			"Authenticating with Van Halen facilities...\n"
			"Connected and registered.";
	
	for (const auto miner : miners)
	{
		std::cout << "\n=======\n== Command: start\n";
		miner->start();
		std::cout << "\n== Command: detect\n";
		miner->detect();
		std::cout << "\n== Command: collect\n";
		miner->collect();
		std::cout << "\n== Command: stop\n";
		miner->stop();
	}
	
	// For whatever reason, there's an invisible
	// newline character at the end of output1000.txt,
	// so I have to mimic that here.
	std::cout << '\n';
}

Miner* minermgr::determineMinerType(int id, const std::string& resource) const
{
	if (resource == "water") return new WaterMiner(id, resource);
	if (resource == "sodium" || resource == "chloride") return new SodiumChlorideMiner(id, resource);
	if (resource == "iron") return new IronMiner(id, resource);
	if (resource == "silicon") return new SiliconMiner(id, resource);
	if (resource == "magnesium" || resource == "potassium") return new MagnesiumPotassiumMiner(id, resource);
	return nullptr;
}
