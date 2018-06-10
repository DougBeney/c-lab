#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {
	// Creating a Socket
	int my_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	// Specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(6969);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// connect and check if error
	int status = connect(my_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	if (status == -1) {
		printf("There was an error making a connection to the server");
	}

	// Receive data from server
	char server_response[256];
	recv(my_socket, &server_response, sizeof(server_response), 0);

	// Print data
	printf("The server sent: %s\n", server_response);

	// close socket
	close(my_socket);

	return 0;
}
