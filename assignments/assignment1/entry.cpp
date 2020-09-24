#include "entry.h"

entry::entry(int year, int month, int day, const std::string& station, const std::string& resource, int amount)
	: year(year), month(month), day(day), station(station), resource(resource), amount(amount) {}

entry::entry(const entry& e)
	: year(e.year), month(e.month), day(e.day), station(e.station), resource(e.resource), amount(amount) {}

entry& entry::operator=(const entry& e)
{
	year = e.year;
	month = e.month;
	day = e.day;
	station = e.station;
	resource = e.resource;
	amount = e.amount;
}

