#include "minermgr.h"

#include <iostream>

#include "WaterMiner.h"
#include "SodiumChlorideMiner.h"
#include "IronMiner.h"
#include "SiliconMiner.h"
#include "MagnesiumPotassiumMiner.h"

minermgr::minermgr()
{
	std::ifstream inFile(fileName);
	if (inFile.is_open())
	{
		std::cout << "Warning: \"" << fileName << "\" already exists. It will be overwritten.\n";
		inFile.close();
	}
}

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
	bool success = false;
	std::ofstream file(fileName);
	
	if (file.is_open())
	{
		file << "== Boston Station Miner Manager ==\n"
				"\n"
				"Authenticating with Van Halen facilities...\n"
				"Connected and registered.";
		
		for (const auto miner : miners)
		{
			file << "\n=======\n== Command: start\n";
			miner->start(file);
			file << "\n== Command: detect\n";
			miner->detect(file);
			file << "\n== Command: collect\n";
			miner->collect(file);
			file << "\n== Command: stop\n";
			miner->stop(file);
		}
		
		// For whatever reason, there's an invisible
		// newline character at the end of output1000.txt,
		// so I have to mimic that here.
		file << '\n';
		
		file.close();
		success = true;
	}
	
	std::cout << (success ? "Successfully wrote" : "Failed to write") << " miner report to: \"" << fileName << "\"\n";
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
