#include <iostream>
#include <string>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	//Creating a socket that user IPv4 internet protocol
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	//Checking if the socket was created or not
	if(server_socket == -1){
		std::cerr << "Failed to create a socket.\n";
		return -1;
	}
	else{
		std::cout << "Socket created successfully.\n";
	}
	//Server structure
	std::string ip = "127.0.0.1";
	struct sockaddr_in *server_address = new struct sockaddr_in;
	server_address->sin_family = AF_INET;
	server_address->sin_port = htons(2412);
	inet_pton(AF_INET, ip.c_str(), &server_address->sin_addr.s_addr);
	//Binding to the socket
	int bind_status = bind(server_socket, (struct sockaddr *)server_address, sizeof(*server_address));
	//Checking bind status
	if(bind_status == -1){
		std::cerr << "Failed to bind to the server.\n";
		return -2;
	}
	else{
		std::cout << "Bounded to the server successfully.\n";
	}
	//Start listening on the port
	int listen_status = listen(server_socket, 10);
	//Checking listening status
	if(listen_status == -1){
		std::cerr << "Failed to listen on the port.\n";
		return -3;
	}
	else{
		std::cout << "Listening on the port.\n";
	}
	//Accepted client structure
	struct sockaddr_in *client_address = new struct sockaddr_in;
	socklen_t client_address_length = sizeof(*client_address);
	//Accpeting incoming connection
	int accepted_socket = accept(server_socket, (struct sockaddr *)client_address, &client_address_length);

	char client_ip[14];
	//Converting IPv4 address from binary form to text form
	inet_ntop(AF_INET, &client_address->sin_addr.s_addr, client_ip, 14);
	//Printing the IPv4 address of the connected client
	std::cout << client_ip << " connected to the server.\n";

	size_t len = 1024;
	char buff[len];
	//Recieving data from the client
	while(1){
		
		memset(buff, '\0', len);

		ssize_t recieved = recv(accepted_socket, buff, len, 0);
		if(recieved == 0){
			std::cout << client_ip << " diconnected from the server.\n";
			break;
		}

		std::cout << "Recieved message: " << buff << "\n";
	}

	//Deallocating
	delete client_address;
	delete server_address;
	//Closing the socket
	close(server_socket);
	shutdown(server_socket, SHUT_RDWR);

	return 0;
}
