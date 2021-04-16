# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g -std=c++14

objects = contact.o contactmanager.o main.o
test: $(objects)
	$(CC) -o test $(objects)

$(filter %.o,$(objects)): %.o: %.cpp
	echo "开始编译"
	$(CC) -c $(CFLAGS)  $< 
	echo $< $@
	#mv $@ ../$@
	echo "编译结束"

clean:
	rm -f *.o