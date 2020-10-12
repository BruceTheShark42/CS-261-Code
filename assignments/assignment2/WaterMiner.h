#ifndef WATER_MINER_H
#define WATER_MINER_H

#include "Miner.h"

class WaterMiner : public Miner
{
public:
	WaterMiner(int id, const std::string& resource);
	
	virtual void detect(std::ofstream& file) const override;
	virtual void collect(std::ofstream& file) const override;
};

#endif
