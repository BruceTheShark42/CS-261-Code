#include "entry.h"

entry::entry(int year, int month, int day, const std::string& station, const std::string& resource, int amount)
	: year(year), month(month - 1), day(day), station(station), resource(resource), amount(amount) {}
