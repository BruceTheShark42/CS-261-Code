GCC = g++ -c -g -std=c++17
OBJ = main.o table.o
NAME = program.exe

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) supplied.o

main.o: main.cpp table.h
	$(GCC) main.cpp

table.o: table.cpp table.h
	$(GCC) table.cpp

.phony: run
run: $(NAME)
	valgrind --tool=memcheck --leak-check=full ./$(NAME)

.phony: clean
clean:
	rm $(NAME) $(OBJ)
