#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource
{
public:
	Resource(const std::string& name = "");
	Resource(const Resource& resource);
	Resource& operator=(const Resource& resource);
	
	inline const std::string& getName() const noexcept { return name; }
	
	inline int getMonth(int month) const { return months[month]; }
	inline void setMonth(int month, int amount) { total -= months[month]; months[month] = amount; total += amount; }
	
	inline int getTotal() const noexcept { return total; };
	
	bool operator==(const std::string& name) const noexcept { return name == this->name; }
	bool operator<(const Resource& resource) const noexcept { return name < resource.name; }
private:
	std::string name;
	int total = 0;
	int months[12];
};

#endif
