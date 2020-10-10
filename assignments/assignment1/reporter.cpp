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
			auto resources = station.get();
			for (const auto& resource : resources)
			{
				file << std::setw(11) << std::left << resource.getName() << std::right;
				
				for (int i = 0; i < 12; i++)
					file << std::setw(8) << resource.getMonth(i);
				file << std::setw(8) << resource.getTotal() << '\n';
			}
			file << '\n';
		}
		
		file.close();
		success = true;
	}
	
	std::cout << (success ? "Successfully wrote" : "Failed to write") << " year " << year << "'s full report to: \"" << fileName << "\"\n";
}

void reporter::printStationReport(int year)
{
	bool success = false;
	std::ofstream file(fileName, std::ofstream::out | std::ofstream::app);
	
	if (file.is_open())
	{
		file << "*******" << year << "*******\n           ";
		
		// TODO: This calling of getStations is really not necessary.
		// It sure makes it easier though!
		auto stations_ = db.getStations(year);
		for (const auto& station : stations_)
			file << std::setw(11) << station.getName();
		file << '\n';
		
		// I ran out of time and this was the fastest,
		// albeit not most efficient nor object oriented
		// approach. I only ran out of time because I
		// took a week break between when I first started
		// working on this assignment and when I resumed
		// to work on other courses I'm enrolled in.
		std::map<std::string, int> totalTotals;
		
		auto resources = db.getTotals(year);
		for (const auto& [resource, stations] : resources)
		{
			file << std::setw(11) << std::left << resource << std::right;
			
			auto stations_It = stations_.begin();
			for (auto stationsIt = stations.begin(); stations_It != stations_.end(); stations_It++)
			{
				
				file << std::setw(11);
				if (stationsIt != stations.end() && stationsIt->first == stations_It->getName())
				{
					totalTotals[stationsIt->first] += stationsIt->second;
					file << stationsIt->second;
					stationsIt++;
				}
				else
					file << 0;
			}
			
			file << '\n';
		}
		
		file << "      Total";
		for (const auto& [station, total] : totalTotals)
			file << std::setw(11) << total;
		
		file << "\n\n";
		file.close();
		success = true;
	}
	
	std::cout << (success ? "Successfully wrote" : "Failed to write") << " year " << year << "'s station report to: \"" << fileName << "\"\n";
}

