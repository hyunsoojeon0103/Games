CC = g++
CFLAGS = -c -g -Wall
LFLAGS = -g -o

main: main.o funcs.o
	$(CC) $(LFLAGS) main main.o funcs.o

funcs.o: funcs.cpp funcs.hpp
	$(CC) $(CFLAGS) funcs.cpp

main.o:	main.cpp bst_node.hpp animal.hpp funcs.hpp
	$(CC) $(CFLAGS) main.cpp

.PHONY: clean
clean:
	rm -f *.o main a.out
