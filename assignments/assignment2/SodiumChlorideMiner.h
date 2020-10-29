#ifndef SODIUM_CHLORIDE_MINER_H
#define SODIUM_CHLORIDE_MINER_H

#include "GenericMiner.h"

class SodiumChlorideMiner : public GenericMiner
{
public:
	SodiumChlorideMiner(int id, const std::string& resource);
	
	virtual void detect() const override;
};

#endif
