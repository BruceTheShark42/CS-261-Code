program.exe: main.o arr.o supplied.o
	g++ -o program.exe main.o arr.o supplied.o

main.o: main.cpp arr.h
	g++ -c -g -std=c++11 main.cpp

arr.o: arr.cpp arr.h
	g++ -c -g -std=c++11 arr.cpp

.phony: run
run: program.exe
	./program.exe

.phony: clean
clean:
	rm program.exe main.o arr.o

