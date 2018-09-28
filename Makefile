CC=g++
CFLAGS=-fPIC

output: pldevice pldeviceenttecpro pluniverse
	$(CC) -shared -Wl,-soname,libplanklight.so.1 -o libplanklight.so.1.0 \
	-L/usr/local/lib -lftd2xx \
	pldevice.o pldeviceenttecpro.o pluniverse.o

pldevice: pldevice.cpp pldevice.h
	$(CC) -fPIC -c pldevice.cpp

pldeviceenttecpro: pldeviceenttecpro.cpp pldeviceenttecpro.h
	$(CC) -fPIC -c pldeviceenttecpro.cpp

pluniverse: pluniverse.cpp pluniverse.h
	$(CC) -fPIC -c pluniverse.cpp

clean:
	$(RM) *.o libplanklight.so.1.0
