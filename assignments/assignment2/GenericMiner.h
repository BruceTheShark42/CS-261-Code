#ifndef GENERIC_MINER_H
#define GENERIC_MINER_H

#include "Miner.h"

class GenericMiner : public Miner
{
public:
	GenericMiner(int id, const std::string& resource);
	
	virtual void collect() const override;
};

#endif
