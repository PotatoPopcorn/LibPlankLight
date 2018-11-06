#Variables
CC=g++
CP=cp
CFLAGS=-fPIC

#Create a .so that can be use by a linux machine
shared: pldevice pldeviceartnet pldeviceenttecpro plenttecutilities plnetworkutilities pluniverse
	$(CC) -shared  -Wl,-soname,libplanklight.so -o libplanklight.so \
	-L/usr/local/lib -lftd2xx \
	pldevice.o pldeviceartnet.o pldeviceenttecpro.o plenttecutilities.o plnetworkutilities.o pluniverse.o

#Copy the shared .so file into the computers library directory
install: shared
	$(CP) libplanklight.so /usr/lib/libplanklight.so

#BEGIN: Compile all required classes
pldevice: pldevice.cpp pldevice.h
	$(CC) -fPIC -c pldevice.cpp

pldeviceartnet: pldeviceartnet.cpp pldeviceartnet.h
	$(CC) -fPIC -c pldeviceartnet.cpp

pldeviceenttecpro: pldeviceenttecpro.cpp pldeviceenttecpro.h
	$(CC) -fPIC -c pldeviceenttecpro.cpp

plenttecutilities: plenttecutilities.cpp plenttecutilities.h
	$(CC) -fPIC -c plenttecutilities.cpp

plnetworkutilities: plnetworkutilities.cpp plnetworkutilities.h
	$(CC) -fPIC -c plnetworkutilities.cpp

pluniverse: pluniverse.cpp pluniverse.h
	$(CC) -fPIC -c pluniverse.cpp
#END

#BEGIN: Tests of code, used on lighting systems which the devs have access to, fairly useless but included to show how to use the code.
# Turn off all the lights
test-EnttecOff: testenttecoff.cpp shared install
	$(CC) -o test-EnttecOff testenttecoff.cpp \
	-L/usr/lib/ -lplanklight -L/usr/local/lib -lftd2xx -lboost_thread -lboost_system

# Show how many enttec devices are connected
test-ConnectedEnttecDevices: testconnectedenttecdevices.cpp shared install
	$(CC) -o test-ConnectedEnttecDevices testconnectedenttecdevices.cpp \
	-L/usr/lib/ -lplanklight -L/usr/local/lib -lftd2xx -lboost_thread -lboost_system

# Useless test
test-EnttecOcean: testenttecocean.cpp shared install
	$(CC) -o test-EnttecOcean testenttecocean.cpp \
	-L/usr/lib/ -lplanklight -L/usr/local/lib -lftd2xx -lboost_thread -lboost_system

# Useless test
test-EnttecLoading: testenttecloading.cpp shared install
	$(CC) -o test-EnttecLoading testenttecloading.cpp \
	-L/usr/lib/ -lplanklight -L/usr/local/lib -lftd2xx -lboost_thread -lboost_system
#END

#Clean up everything this file creates
clean:
	$(RM) *.o test-* libplanklight.so libplanklight.a
