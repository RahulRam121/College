#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main()
{
	int  server_fd, new_socket, value;
	struct sockaddr_in server_addr, client_addr; 
	char buffer[1024], filename[100];
	socklen_t len;
	long numbytes;
	FILE *fp;
	
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Socker error");
	}
	
	bzero(&server_addr,sizeof(server_addr));
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);
	
	if(bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
	{
		perror("Bind error: ");
	}
	
	if(listen(server_fd,2) < 0)
	{
		perror("Listen error");
	}
	
	len = sizeof(client_addr);
	
	printf("Waiting for client...\n");
	
	if((new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &len)) < 0)
	{
		perror("Accept error");
	}
	
	value = read(new_socket, filename, sizeof(filename));
	printf("File to be transferred is %s\n", filename);
	
	fp = fopen(filename, "r");
	fseek(fp, 0L, SEEK_END);
	numbytes = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	fread(buffer, sizeof(char), numbytes, fp);
	fclose(fp);

	value = write(new_socket, buffer, sizeof(buffer));
	printf("File Transferred!\n");

	close(server_fd);
	close(new_socket);
	return 0;
}

