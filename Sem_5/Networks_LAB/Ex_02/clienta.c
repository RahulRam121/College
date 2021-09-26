#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <unistd.h>

int main()
{
	int socket_fd, n, len;
	struct sockaddr_in server_addr, client_addr;
	
	char msg[1000], buff[1024];
	
	if((socket_fd=socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Socket error");
	}
	
	bzero(&server_addr,sizeof(server_addr));
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(8080);
	
	if(connect(socket_fd,(struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
	{
		perror("Connect error");
	}
	
	//Sending Message
	printf("Enter message : ");
	scanf("%[^\n]s", msg);
	n = write(socket_fd, msg, sizeof(msg));
	
	n = read(socket_fd, buff, sizeof(buff));	
	printf("Message from Server : %s\n", buff);
	
	close(socket_fd);
	return 0;
}
