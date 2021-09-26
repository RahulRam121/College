#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <unistd.h>

int main()
{
	int len, server_fd, new_socket, n;
	struct sockaddr_in server_addr, client_addr; 
	char buff[1024], msg[1000];
	
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Socker error");
	}
	
	bzero(&server_addr,sizeof(server_addr));
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(8080);
	
	if(bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
	{
		perror("Bind error: ");
	}
	
	if(listen(server_fd,2) < 0)
	{
		perror("Listen error");
	}
	
	len = sizeof(client_addr);
	
	if((new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &len)) < 0)
	{
		perror("Accept error");
	}
	
	//Receiving the message
	n = read(new_socket, buff, sizeof(buff));
	printf("Message from Client : %s\n",buff);	
	printf("\nEnter message : ");
	scanf("%[^\n]s", msg);
	n = write(new_socket, msg, sizeof(msg));
	
	close(server_fd);
	close(new_socket);
	return 0;
}

