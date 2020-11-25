GCC = g++ -c -g -std=c++11
OBJ = main.o table.o
NAME = program.exe

# since supplied.o will never change, I don't need have make to update main when it changes
$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) supplied.o
	
main.o: main.cpp table.h
	$(GCC) main.cpp
	
table.o: table.cpp table.h
	$(GCC) table.cpp
	
.phony: run
run: program.exe
	valgrind --tool=memcheck --leak-check=full ./$(NAME)
	
.phony: clean
clean:
	rm $(NAME) $(OBJ)
