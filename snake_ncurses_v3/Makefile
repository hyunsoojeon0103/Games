CC = g++
CFLAGS = -c -g -Wall 
LFLAGS = -g -o 
LDLIBS = -lncurses

main:	main.o snake.o fruit.o
	$(CC) $(LFLAGS) main main.o snake.o fruit.o $(LDLIBS)

snake.o: snake.cpp snake.h segment.h
	$(CC) $(CFLAGS) snake.cpp

main.o:	main.cpp 
	$(CC) $(CFLAGS) main.cpp

fruit.o: fruit.cpp segment.h
	$(CC) $(CFLAGS) fruit.cpp

.PHONY:	clean
clean:
	rm -f a.out *.o main
