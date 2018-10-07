CC=g++
CP=cp
CFLAGS=-fPIC

shared: pldevice pldeviceenttecpro pluniverse
	$(CC) -shared  -Wl,-soname,libplanklight.so -o libplanklight.so \
	-L/usr/local/lib -lftd2xx \
	pldevice.o pldeviceenttecpro.o pluniverse.o
	$(CP) libplanklight.so /usr/lib/libplanklight.so

pldevice: pldevice.cpp pldevice.h
	$(CC) -fPIC -c pldevice.cpp

pldeviceenttecpro: pldeviceenttecpro.cpp pldeviceenttecpro.h
	$(CC) -fPIC -c pldeviceenttecpro.cpp

pluniverse: pluniverse.cpp pluniverse.h
	$(CC) -fPIC -c pluniverse.cpp

test-EnttecOff: testenttecoff.cpp shared
	$(CC) -o test-EnttecOff testenttecoff.cpp \
	-L/usr/lib/ -lplanklight -L/usr/local/lib -lftd2xx -lboost_thread -lboost_system

test-EnttecOcean: testenttecocean.cpp shared
	$(CC) -o test-EnttecOcean testenttecocean.cpp \
	-L/usr/lib/ -lplanklight -L/usr/local/lib -lftd2xx -lboost_thread -lboost_system

test-EnttecLoading: testenttecloading.cpp shared
	$(CC) -o test-EnttecLoading testenttecloading.cpp \
	-L/usr/lib/ -lplanklight -L/usr/local/lib -lftd2xx -lboost_thread -lboost_system

clean:
	$(RM) *.o test-* libplanklight.so libplanklight.a
