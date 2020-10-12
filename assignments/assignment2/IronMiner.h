#ifndef IRON_MINER_H
#define IRON_MINER_H

#include "GenericMiner.h"

class IronMiner : public GenericMiner
{
public:
	IronMiner(int id, const std::string& resource);
	virtual void detect(std::ofstream& file) const override;
};

#endif
