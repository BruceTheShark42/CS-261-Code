#ifndef SILICON_MINER_H
#define SILICON_MINER_H

#include "GenericMiner.h"

class SiliconMiner : public GenericMiner
{
public:
	SiliconMiner(int id, const std::string& resource);
	virtual void detect() const override;
};

#endif
