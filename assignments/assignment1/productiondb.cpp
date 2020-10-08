#include "productiondb.h"
#include <algorithm>
#include <iostream>

productiondb::productiondb(const productiondb& db)
	: entries(db.entries) {}

std::vector<Station> productiondb::getStations(int year)
{
	std::vector<Station> stations;
	
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
				if (!station->hasResource(resource))
					station->addResource(resource);
				station->getResource(resource).setMonth(entry.getMonth(), entry.getAmount());
			}
		}
	}
	
	std::sort(stations.begin(), stations.end());
	for (auto& station : stations)
	{
		auto& resources = station.getResources();
		std::sort(resources.begin(), resources.end());
	}
	
	return stations;
}

