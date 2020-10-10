#include "productiondb.h"
#include <algorithm>

productiondb::productiondb(const productiondb& db)
	: entries(db.entries) {}

std::vector<Storage<Resource>> productiondb::getStations(int year) const
{
	// If I had more time, which is not your fault
	// in the slightest, I would convert this to
	// use a std::map just like getTotals so it
	// would be that much simpler.
	std::vector<Storage<Resource>> stations;
	
	for (const auto& entry : entries)
	{
		if (entry.getYear() == year)
		{
			// Get the corresponding Station
			auto station = std::find(stations.begin(), stations.end(), entry.getStation());
			if (station == stations.end())
			{
				// If this Station does not yet exist, create it
				// and set the Station iterator to its place.
				stations.emplace_back(entry.getStation());
				
				// If the vector didn't have to grow, this
				// wouldn't be necessary, but since it's
				// possible that it did while adding the
				// Station, then the previous end would
				// be invalid.
				station = stations.end() - 1;
			}
			
			// Add the Resource to the Station
			auto& resource = entry.getResource();
			if (entry.getAmount() != 0)
			{
				if (!station->has(resource))
					station->add(resource);
				station->get(resource).addToMonth(entry.getMonth(), entry.getAmount());
			}
		}
	}
	
	std::sort(stations.begin(), stations.end());
	for (auto& station : stations)
	{
		auto& resources = station.get();
		std::sort(resources.begin(), resources.end());
	}
	
	return stations;
}

productiondb::TotalResources productiondb::getTotals(int year) const
{
	TotalResources resources;
	
	for (const auto& entry : entries)
		if (entry.getYear() == year)
			resources[entry.getResource()][entry.getStation()] += entry.getAmount();
	
	return resources;
}

