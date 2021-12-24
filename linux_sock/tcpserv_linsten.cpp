// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>

#define PORT 9080

int main(int argc, char const *argv[])
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	char *hello = "Hello from server";

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) // NOLINT
	{
		perror("socket failed");
		exit(EXIT_FAILURE); // NOLINT
	}

	// Forcefully attaching socket to the port 8080
	// if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt)))
	// {
	// 	perror("setsockopt");
	// 	exit(EXIT_FAILURE);
	// }
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	while (true)
	{
		if (listen(server_fd, 3) < 0)
		{
			perror("listen");
			exit(EXIT_FAILURE);
		}
		if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
								 (socklen_t *)&addrlen)) < 0)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}
		std::string ss = "./tcp_communicate " + std::to_string(new_socket);
		system(ss.data());
		system(ss.data());
		system(ss.data());
	}

		printf("end host\n");
	return 0;
}
