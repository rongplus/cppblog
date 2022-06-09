# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g -std=c++14
# define any directories containing header files other than /usr/include
#
INCLUDES = -I/Users/admin/work/git/googletest/googletest/include -I/Users/admin/work/git/googletest/googlemock/include 

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = -L/Users/admin/work/git/googletest/build/lib

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lgtest -lgmock

# ****************************************************
# Targets needed to bring the executable up to date
 
mypro: main.o mock.o gassert.o expect.o parameter.o
	$(CC) $(CFLAGS) $(INCLUDES) $(LFLAGS) $(LIBS) -o test main.o mock.o parameter.o expect.o gassert.o
 
# The main.o target can be written more simply
 
main.o: main.cpp gassert.h expect.h parameter.h mock.h
	$(CC) $(CFLAGS) $(INCLUDES) -c main.cpp
 
gassert.o: gassert.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c gassert.cpp
mock.o: mock.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c mock.cpp

expect.o: expect.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c expect.cpp

parameter.o: parameter.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c parameter.cpp