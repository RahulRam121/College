#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080

int main()
{
	int socket_fd, value;
	struct sockaddr_in server_addr;
	FILE *fp;
	char buffer[1024], filename[100];
	
	if((socket_fd=socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Socket error");
	}
	
	bzero(&server_addr,sizeof(server_addr));
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(PORT);
	
	if(connect(socket_fd,(struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
	{
		perror("Connect error");
	}
	
	printf("Enter the path of file : ");
	scanf("%s", filename);
	value = write(socket_fd, filename, sizeof(filename));
	
	value = read(socket_fd, buffer, sizeof(buffer));
	printf("FIle Transferred!\n");
	
	printf("Save the file in path : ");
	scanf("%s", filename);
		
	fp = fopen(filename, "w");
	fprintf(fp, "%s", buffer);
	fclose(fp);
	
	close(socket_fd);
	return 0;
}
