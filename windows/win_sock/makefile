# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g -std=c++14
 
# ****************************************************
# Targets needed to bring the executable up to date
 
mypro: main.o a.o b.o serv.o
	$(CC) $(CFLAGS) -o test main.o a.o b.o serv.o
 
# The main.o target can be written more simply
 
main.o: main.cpp a.h b.h serv.h
	$(CC) $(CFLAGS) -c main.cpp
 
b.o: b.cpp
	$(CC) $(CFLAGS) -c b.cpp
a.o: a.cpp
	$(CC) $(CFLAGS) -c a.cpp

serv.o: serv.cpp
	$(CC) $(CFLAGS) -c serv.cppå