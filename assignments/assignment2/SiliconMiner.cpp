#include "SiliconMiner.h"

SiliconMiner::SiliconMiner(int id, const std::string& resource)
	: GenericMiner(id, resource) {}

void SiliconMiner::detect(std::ofstream& file) const
{
	file << "Sample grinder activated.\n"
			"10 um seive applied.\n"
			"Infrared laser activated.\n"
			"Spectrophotometer activated and results analyzed.\n"
			"Silica vein located.";
}
