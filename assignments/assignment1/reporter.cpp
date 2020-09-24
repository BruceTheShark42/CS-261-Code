#include "reporter.h"
#include <fstream>
#include <iostream>

reporter::reporter(const productiondb& db)
	: db(db) {}

void reporter::printFullReport(int year)
{
	/*
	// Normally, I'd just return true or false
	// if the function succeeded or failed, but
	// since I'm not allowed to edit showreport.cpp,
	// I can't exactly do that, now can I?
	bool success = false;
	
	if (db.hasEntriesForYear(year))
	{
		std::ofstream file(fileName, std::ofstream::out | std::ofstream::app);
		
		if (file.is_open())
		{
			file << "*******" << year << "*******\n\nStation: ";
			
			success = true;
		}
	}
	
	std::cout << (success ? "Successfully wrote" : "Failed to write") << " full report to: \"" << fileName << "\"\n";
	*/
}

void reporter::printStationReport(int year) {}

