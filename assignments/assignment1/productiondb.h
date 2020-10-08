#ifndef PRODUCTION_H
#define PRODUCTION_H

#include "entry.h"
#include "Station.h"

#include <vector>

class productiondb
{
public:
	productiondb() = default;
	productiondb(const productiondb& db);
	
	inline void addData(const entry& e) { entries.push_back(e); }
	
	std::vector<Station> getStations(int year);
private:
	// year station resource month
	std::vector<entry> entries;
};

#endif
