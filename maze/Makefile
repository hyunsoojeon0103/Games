CC = g++
CFLAGS = -c -g -Wall
LFLAGS = -g -o

main: main.o maze.o
	$(CC) $(LFLAGS) main main.o maze.o

main.o: main.cpp maze.hpp
	$(CC) $(CFLAGS) main.cpp

maze.o: maze.hpp maze.cpp maze_node.hpp
	$(CC) $(CFLAGS) maze.cpp

.PHONY: clean
clean:
	rm -f a.out main *.o
