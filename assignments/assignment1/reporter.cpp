#include "reporter.h"
#include <fstream>
#include <iostream>
#include <iomanip>

reporter::reporter(productiondb& db)
	: db(db)
{
	std::ifstream inFile(fileName);
	if (inFile.is_open())
	{
		std::cout << "Warning: \"" << fileName << "\" already exists. It will be overwritten.\n";
		inFile.close();
		
		// Erase the contents of the file
		std::ofstream outFile(fileName);
		outFile.close();
	}
}

void reporter::printFullReport(int year)
{
	// Normally, I'd just return true or false
	// if the function succeeded or failed, but
	// since I'm not allowed to edit showreport.cpp,
	// I can't exactly do that, now can I?
	bool success = false;
	std::ofstream file(fileName, std::ofstream::out | std::ofstream::app);
	
	if (file.is_open())
	{
		file << "*******" << year << "*******\n";
		
		auto stations = db.getStations(year);
		for (const auto& station : stations)
		{
			file << "\nStation: " << station.getName() << "\n\n                Jan     Feb     Mar     Apr     May     Jun     Jul     Aug     Sep     Oct     Nov     Dec     Tot\n";
			auto resources = station.getResources();
			for (const auto& resource : resources)
			{
				file << std::setfill(' ') << std::setw(11) << std::left << resource.getName();
				
				for (int i = 0; i < 12; i++)
					file << std::setfill(' ') << std::setw(8) << std::right << resource.getMonth(i);
				file << std::setfill(' ') << std::setw(8) << std::right << resource.getTotal() << '\n';
			}
			file << '\n';
		}
		
		file << '\n';
		file.close();
		success = true;
	}
	
	std::cout << (success ? "Successfully wrote" : "Failed to write") << " year " << year << "'s full report to: \"" << fileName << "\"\n";
}

void reporter::printStationReport(int year)
{
	
}

