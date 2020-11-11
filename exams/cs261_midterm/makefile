program.exe: main.o dlist.o supplied.o
	g++ -o program.exe main.o dlist.o supplied.o

main.o: main.cpp dlist.h
	g++ -c -g -std=c++11 main.cpp

dlist.o: dlist.cpp dlist.h
	g++ -c -g -std=c++11 dlist.cpp

.phony: run
run: program.exe
	valgrind ./program.exe

.phony: clean
clean:
	rm program.exe main.o dlist.o
