#include <iostream>
#include <string>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	//Creating socket that uses IPv4 internet protocol
	int client_socket = socket(AF_INET, SOCK_STREAM, 0);
	//Checking if socket was created or not.
	if(client_socket == -1){
		std::cerr << "Failed to create a socket.\n";
		return -1;
	}
	else{
		std::cout << "Socket created successfully.\n";
	}
	//Server structure
	std::string server_ip = "127.0.0.1";
	struct sockaddr_in *server_address = new struct sockaddr_in;
	server_address->sin_family = AF_INET;
	server_address->sin_port = htons(2412);
	inet_pton(AF_INET, server_ip.c_str(), &server_address->sin_addr.s_addr);
	//Connecting to the server
	int connect_status = connect(client_socket, (struct sockaddr *)server_address, sizeof(*server_address));
	//Checking if client connected to the server or not.
	if(connect_status == -1){
		std::cerr << "Failed to connect to the server.\n";
		return -2;
	}
	else{
		std::cout << "Connected to the server successfully.\n";
	}
	
	std::string msg;
	//Sending data to the server
	while(1){
		std::cout << "Enter the message: ";
		std::getline(std::cin >> std::ws, msg);
		if(strcmp(msg.c_str(), "exit") == 0)
			break;
		send(client_socket, msg.c_str(), strlen(msg.c_str()), 0);
			
	}
	//Deallocating 
	delete server_address;
	//Closing the socket
	close(client_socket);

	return 0;
}
