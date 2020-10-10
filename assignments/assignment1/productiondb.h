#ifndef PRODUCTION_H
#define PRODUCTION_H

#include "entry.h"
#include "Storage.h"
#include "Resource.h"

#include <vector>
#include <map>

class productiondb
{
public:
	//                              Resource              Station      Amount
	using TotalResources = std::map<std::string, std::map<std::string, int>>;
	
	productiondb() = default;
	productiondb(const productiondb& db);
	
	inline void addData(const entry& e) { entries.push_back(e); }
	
	std::vector<Storage<Resource>> getStations(int year) const;
	TotalResources getTotals(int year) const;
private:
	std::vector<entry> entries;
};

#endif
