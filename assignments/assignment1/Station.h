#ifndef STATION_H
#define STATION_H

#include "Resource.h"

#include <vector>
#include <algorithm>

class Station
{
public:
	Station(const std::string& name);
	
	inline std::vector<Resource>& getResources() { return resources; }
	inline const std::vector<Resource>& getResources() const { return resources; }

	inline void addResource(const std::string& resource) { resources.emplace_back(resource); }
	inline void removeResource(const std::string& resource) { auto it = std::find(resources.begin(), resources.end(), resource); if (it != resources.end()) resources.erase(it); }
	inline bool hasResource(const std::string& resource) const { return std::find(resources.begin(), resources.end(), resource) != resources.end(); }
	
	inline Resource& getResource(const std::string& resource) { return *std::find(resources.begin(), resources.end(), resource); }
	inline const Resource& getResource(const std::string& resource) const { return *std::find(resources.begin(), resources.end(), resource); }
	
	inline const std::string& getName() const noexcept { return name; }
	
	inline bool operator==(const Station& station) const noexcept { return name == station.name; }
	inline bool operator<(const Station& station) const noexcept { return name < station.name; }
private:
	std::string name;
	std::vector<Resource> resources;
};

#endif
