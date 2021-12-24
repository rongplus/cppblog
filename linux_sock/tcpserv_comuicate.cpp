// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>

#define PORT 9080
int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std ::cout << "New socker" << std::endl;
		return 0;
	}
	else
		std::cout << "New client coming=====" << argv[1] << std::endl;

	char buffer[1024] = {0};
	char *hello = "Hello from server";
	int server_fd, new_socket, valread;
	new_socket = atoi((const char *)argv[1]);
	valread = read(new_socket, buffer, 1024);
	for (int n = 0; n < 4; n++)
	{
		printf("received: == %s ==\n", buffer);
		send(new_socket, hello, strlen(hello), 0);
		printf("Hello message sent\n");
		valread = read(new_socket, buffer, 1024);
	}

	return 0;
}
