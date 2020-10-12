#ifndef MINER_MGR
#define MINER_MGR

#include <string>
#include <vector>

#include "Miner.h"

class minermgr
{
public:
	minermgr();
	~minermgr();
	
	void addMiner(int id, const std::string& resource);
	void runMiners() const;
private:
	Miner* determineMinerType(int id, const std::string& resource) const;
	
	std::vector<Miner*> miners;
	
	static constexpr const char* fileName = "generated_file.txt";
};

#endif
