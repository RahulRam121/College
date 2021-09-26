#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main()
{
	int client_fd, value;
	struct sockaddr_in server_addr;
	
	char buff[1024], name[10], message[1000];
	
	printf("Connecting to server...\n");
	
	if((client_fd=socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Socket error");
	}
	
	bzero(&server_addr,sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(PORT);
	
	if(connect(client_fd,(struct sockaddr*)&server_addr, sizeof(server_addr)) != 0)
	{
		perror("Connect error");
	}
	else
	{
		printf("Connected to the Server...\n");
	}

	printf("Enter client name : ");
	scanf("%s", name);
	
	while(1)
	{
		bzero(buff, 1024);
		printf("%s : ", name);
		scanf(" %[^\n]", message);
		strcat(buff, name);
		strcat(buff, " : ");
		strcat(buff, message);

		if(strcmp(message, "exit") == 0){
			close(client_fd);
			printf("Disconnected from server...\n");
			break;
		}
		else
		{
			value = write(client_fd, buff, sizeof(buff));
		}
		value = read(client_fd, buff, sizeof(buff));
		printf("Server: %s\n", buff);
		
	}
	
	return 0;
}
