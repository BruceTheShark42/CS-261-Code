production.exe: showreport.o productiondb.o entry.o reporter.o
	g++ -o production.exe showreport.o productiondb.o entry.o reporter.o

showreport.o: showreport.cpp productiondb.h entry.h reporter.h
	g++ -c -std=c++11 showreport.cpp

productiondb.o: productiondb.cpp productiondb.h Category.h
	g++ -c -std=c++11 productiondb.cpp

entry.o: entry.cpp entry.h
	g++ -c -std=c++11 entry.cpp

reporter.o: reporter.cpp reporter.h
	g++ -c -std=c++11 reporter.cpp

.phony: clean
clean:
	rm production.exe
	rm *.o

