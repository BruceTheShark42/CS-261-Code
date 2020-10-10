production.exe: showreport.o productiondb.o entry.o reporter.o Resource.o
	g++ -o production.exe showreport.o productiondb.o entry.o reporter.o Resource.o

showreport.o: showreport.cpp productiondb.h entry.h reporter.h
	g++ -c -std=c++1z showreport.cpp

productiondb.o: productiondb.cpp productiondb.h Storage.h
	g++ -c -std=c++1z productiondb.cpp

entry.o: entry.cpp entry.h
	g++ -c -std=c++1z entry.cpp

reporter.o: reporter.cpp reporter.h
	g++ -c -std=c++1z reporter.cpp

Resource.o: Resource.cpp Resource.h
	g++ -c -std=c++1z Resource.cpp

.phony: clean
clean:
	rm production.exe
	rm *.o

