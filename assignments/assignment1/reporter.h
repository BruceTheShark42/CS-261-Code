#ifndef REPORTER_H
#define REPORTER_H

#include "productiondb.h"

class reporter
{
public:
	reporter(productiondb& db);
	
	void printFullReport(int year);
	void printStationReport(int year);
private:
	productiondb& db;
	
	static constexpr const char* fileName = "generated_report.txt";
};

#endif
