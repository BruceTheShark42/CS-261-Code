#ifndef WATER_MINER_H
#define WATER_MINER_H

#include "Miner.h"

class WaterMiner : public Miner
{
public:
	WaterMiner(int id, const std::string& resource);
	
	virtual void detect() const override;
	virtual void collect() const override;
};

#endif
