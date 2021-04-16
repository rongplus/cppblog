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


objects = contactclient/contact.o contactclient/contactmanager.o gtest/contacttest.o gtest/main.o
test: $(objects)
	$(CC) $(CFLAGS) $(INCLUDES) $(LFLAGS) $(LIBS)  -o test $(objects)

$(filter %.o,$(objects)): %.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $(LFLAGS) $(LIBS)  -c $(CFLAGS)  $< -o $@
	echo $< $@

clean:
	rm -f *.o