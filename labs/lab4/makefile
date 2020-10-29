program.exe: main.o clist.o supplied.o
	g++ -o program.exe main.o clist.o supplied.o

main.o: main.cpp clist.h
	g++ -c main.cpp

clist.o: clist.cpp clist.h
	g++ -c clist.cpp

.phony: run
run: program.exe
	./program.exe

.phony: clean
clean:
	rm program.exe main.o clist.o
