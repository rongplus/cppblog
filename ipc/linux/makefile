
all:server client
 
client:share_client.cpp common.cpp
	gcc -o $@ $^
server:share_server.cpp common.cpp
	gcc -o $@ $^
