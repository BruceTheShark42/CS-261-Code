# I've been putting off using variables for whatever
# reason, but I finally actually used them.
GCC = g++ -c -g -std=c++11
OBJ = main.o dlist.o
NAME = program.exe

$(NAME): $(OBJ) supplied.o
	g++ -o $(NAME) $(OBJ) supplied.o

main.o: main.cpp dlist.h
	$(GCC) main.cpp

dlist.o: dlist.cpp dlist.h
	$(GCC) dlist.cpp

.phony: run
run: program.exe
	valgrind --tool=memcheck --leak-check=full ./$(NAME)

.phony: clean
clean:
	rm $(NAME) $(OBJ)
