#ifndef PRODUCTION_H
#define PRODUCTION_H

#include "entry.h"
#include "Category.h"

class productiondb
{
public:
	productiondb() = default;
	productiondb(const productiondb& db);
	
	inline void addData(const entry& e) { entries.push_back(e); }
	/*
	inline std::vector<entry> getYearEntries(int year) const noexcept { return years.get(year, entries); }
	inline std::vector<entry> getStationEntries(const std::string& station) const noexcept { return stations.get(station, entries); }
	inline std::vector<entry> getResourceEntries(const std::string& resource) const noexcept { return resources.get(resource, entries); }
	inline std::vector<entry> getMonthEntries(int month) const noexcept { return months.get(month, entries); }
	*/
private:
	// year station resource month
	std::vector<entry> entries;
	
	// What can be done as of right now I think
	//Collection<Category<int, entry>, Category<std::string, entry>, Category<std::string, entry>, Category<int, entry>> categories;
	// What I want it to look like
	//Collection<entry, int, std::string, std::string, int> categories;
	Category<int, entry> years;
	Category<std::string, entry> stations;
	Category<std::string, entry> resources;
	Category<int, entry> months;
};

#endif
