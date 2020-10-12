#ifndef MAGNESIUM_POTASSIUM_MINER_H
#define MAGNESIUM_POTASSIUM_MINER_H

#include "GenericMiner.h"

class MagnesiumPotassiumMiner : public GenericMiner
{
public:
	MagnesiumPotassiumMiner(int id, const std::string& resource);
	virtual void detect(std::ofstream& file) const override;
};

#endif
