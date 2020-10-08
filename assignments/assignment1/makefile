production.exe: showreport.o productiondb.o entry.o reporter.o Station.o Resource.o
	g++ -o production.exe showreport.o productiondb.o entry.o reporter.o Station.o Resource.o

showreport.o: showreport.cpp productiondb.h entry.h reporter.h
	g++ -c -std=c++11 showreport.cpp

productiondb.o: productiondb.cpp productiondb.h Station.h
	g++ -c -std=c++11 productiondb.cpp

entry.o: entry.cpp entry.h
	g++ -c -std=c++11 entry.cpp

reporter.o: reporter.cpp reporter.h
	g++ -c -std=c++11 reporter.cpp

Station.o: Station.cpp Station.h Resource.h
	g++ -c -std=c++11 Station.cpp

Resource.o: Resource.cpp Resource.h
	g++ -c -std=c++11 Resource.cpp

.phony: clean
clean:
	rm production.exe
	rm *.o

