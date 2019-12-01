#This makefile is only used for tests, there is another make file in the directory above which is to be used to build LPL, Please ensure LPL is correctly installed before running This

CC=g++

.PHONY: all clean
.DEFAULT_GOAL := all

all: testhelper.o test-fulloff test-fullon test-setall

testhelper.o: testhelper.cpp testhelper.h
	$(CC) -c testhelper.cpp

test-fulloff: testfulloff.cpp testhelper.o
	$(CC) testfulloff.cpp testhelper.o -o test-fulloff -lpthread -L/usr/lib -lplanklight -L/usr/local/lib -lftd2xx -lboost_thread -lboost_system

test-fullon: testfullon.cpp testhelper.o
	$(CC) testfullon.cpp testhelper.o -o test-fullon -lpthread -L/usr/lib -lplanklight -L/usr/local/lib -lftd2xx -lboost_thread -lboost_system

test-setall: testsetall.cpp testhelper.o
	$(CC) testsetall.cpp testhelper.o -o test-setall -lpthread -L/usr/lib -lplanklight -L/usr/local/lib -lftd2xx -lboost_thread -lboost_system

clean:
	$(RM) *.o test-*
