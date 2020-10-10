#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource
{
public:
	Resource(const std::string& name = "");
	
	inline const std::string& getName() const noexcept { return name; }
	
	inline int getMonth(int month) const { return months[month]; }
	inline void addToMonth(int month, int amount) { months[month] += amount; total += amount; }
	
	inline int getTotal() const noexcept { return total; };
	
	inline bool operator==(const std::string& name) const noexcept { return name == this->name; }
	inline bool operator<(const Resource& resource) const noexcept { return name < resource.name; }
private:
	std::string name;
	int total = 0;
	int months[12]{ 0 };
};

#endif
