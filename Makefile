CC=g++
CFLAGS=-I.

output:
	$(CC) -o output

pluniverse: pluniverse.cpp pluniverse.h
	$(CC) -c pluniverse.cpp

clean:
	$(RM) *.o output
