#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class entry
{
public:
	entry(int year, int month, int day, const std::string& station, const std::string& resource, int amount);
	
	// Needed for being in a std::unordered_map
	entry() = default;
	entry(const entry& e);
	entry& operator=(const entry& e);
	
	inline int getYear() const noexcept { return year; }
	inline int getMonth() const noexcept { return month; }
	inline int getDay() const noexcept { return day; }
	inline const std::string& getStation() const noexcept { return station; }
	inline const std::string& getResource() const noexcept { return resource; }
	inline int getAmount() const noexcept { return amount; }
private:
	int year = 0;
	int month = 0;
	int day = 0;
	std::string station;
	std::string resource;
	int amount = 0;
};

#endif
