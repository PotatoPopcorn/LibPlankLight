CC=g++
CFLAGS=-I.

output:
	$(CC) -o output

pldevice: pldevice.cpp pldevice.h
	$(CC) -c pldevice.cpp

pldeviceenttecpro: pldeviceenttecpro.cpp pldeviceenttecpro.h
	$(CC) -c pldeviceenttecpro.cpp

pluniverse: pluniverse.cpp pluniverse.h
	$(CC) -c pluniverse.cpp

clean:
	$(RM) *.o output
