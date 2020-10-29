#ifndef MINER_MGR
#define MINER_MGR

#include <string>
#include <vector>

#include "Miner.h"

class minermgr
{
public:
	~minermgr();
	
	void addMiner(int id, const std::string& resource);
	void runMiners() const;
private:
	Miner* determineMinerType(int id, const std::string& resource) const;
	
	std::vector<Miner*> miners;
};

#endif
