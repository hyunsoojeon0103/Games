CC = g++
CFLAGS = -c -g -Wall
LFLAGS = -g -o

main: main.o bsShip.o bsOcean.o
	$(CC) $(LFLAGS) main main.o bsShip.o bsOcean.o

main.o: main.cpp bsShip.h bsOcean.h
	$(CC) $(CFLAGS) main.cpp

bsShip.o: bsShip.cpp bsShip.h
	$(CC) $(CFLAGS) bsShip.cpp

bsOcean.o: bsOcean.cpp bsOcean.h
	$(CC) $(CFLAGS) bsOcean.cpp

.PHONY: clean
clean:
	rm -f a.out main *.o
