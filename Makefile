#Variables
CC=g++
CP=cp
CFLAGS=-fPIC

#Create a .so that can be use by a linux machine
shared: pldevice.o pldeviceartnet.o pldeviceenttecpro.o plenttecutilities.o  pluniverse.o pldevices.o
	$(CC) -shared  -Wl,-soname,libplanklight.so -o libplanklight.so \
	-L/usr/local/lib -lftd2xx \
	pldevice.o pldeviceartnet.o pldeviceenttecpro.o plenttecutilities.o  pluniverse.o

#Copy the shared .so file into the computers library directory
install: shared
	$(CP) libplanklight.so /usr/lib/libplanklight.so

#BEGIN: Compile all required classes
pldevice.o: pldevice.cpp pldevice.h
	$(CC) -fPIC -c pldevice.cpp

pldeviceartnet.o: pldeviceartnet.cpp pldeviceartnet.h
	$(CC) -fPIC -c pldeviceartnet.cpp

pldeviceenttecpro.o: pldeviceenttecpro.cpp pldeviceenttecpro.h
	$(CC) -fPIC -c pldeviceenttecpro.cpp

plenttecutilities.o: plenttecutilities.cpp plenttecutilities.h
	$(CC) -fPIC -c plenttecutilities.cpp

pldevices.o: pldevices.cpp pldevices.h
	$(CC) -fPIC -c pldevices.cpp

pluniverse.o: pluniverse.cpp pluniverse.h
	$(CC) -fPIC -c pluniverse.cpp

#END

#Clean up everything this file creates
clean:
	$(RM) *.o libplanklight.so libplanklight.a
