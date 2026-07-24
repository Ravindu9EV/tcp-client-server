#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(){
	int sock = 0;
	struct sockaddr_in serv_addr;
	char *message = "Hello from client!";
	char buffer[BUFFER_SIZE] = {0};

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) <0){
	printf("Socket creation error!\n");
	return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if(inet_pton(AF_INET, "127.0.0.1",  &serv_addr.sin_addr) <=0) {
		printf("Invalid addres/ Address not supported\n");
		return -1;
	}

	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		printf("Connection failed\n");
		return -1;
	}

	printf("Connected to server at 126.0.0.1:%d\n",PORT);

	send(sock, message, strlen(message),0);
	printf("Message sent to server: %s\n", message);

	int valread = read(sock, buffer, BUFFER_SIZE);
	if(valread >0) {
		printf("Server response: %s\n", buffer);
	}

	close(sock);
	printf("Connection closed. Client terminating. \n");

	return 0;
}
