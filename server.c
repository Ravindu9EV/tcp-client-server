#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


#define PORT 8080
#define BUFFER_SIZE 1024

int main(){
	int server_fd,new_socket;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[BUFFER_SIZE] = {0};
	char *response = "Message recieved by server!";
	
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0))==0){
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}

	if(setsockopt(server_fd,SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))){
		perror("Setsockopt failed");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);


	if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
		perror("Bind failed");
		exit(EXIT_FAILURE);
	}
	
	if(listen(server_fd,3)<0){
		perror("Listen failed");
		exit(EXIT_FAILURE);
	}
	printf("Server is running on port %d\n",PORT);
	printf("waiting for client connections...\n");
	
	if((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
		perror("Accept failed");
		exit(EXIT_FAILURE);
	}
	
	printf("Client connected!\n");

	int valread = read(new_socket, buffer, BUFFER_SIZE);
	if(valread > 0) {
		printf("Message recieved from client: %s\n", buffer);
		
		send(new_socket, response, strlen(response), 0);
		printf("Response sent to client: %s\n", response);
	}

	close(new_socket);
	close(server_fd);
	printf("Connection closed. server shutting down.\n");
	
	return 0;

}
