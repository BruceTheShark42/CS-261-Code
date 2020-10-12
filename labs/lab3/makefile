program.exe: main.o list.o supplied.o
	g++ -o program.exe main.o list.o supplied.o

main.o: main.cpp list.h
	g++ -c -std=c++11 main.cpp

list.o: list.cpp list.h
	g++ -c -std=c++11 list.cpp

.phony: run
run: program.exe
	./program.exe

.phony: clean
clean:
	rm program.exe main.o list.o
