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
	int client_fd, count;
	struct sockaddr_in server_addr;
	socklen_t len;
	char buffer[1024], domain[30], address[10][20], temp[20];
	
	if((client_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("Socket error");
	}
	
	bzero(&server_addr,sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(PORT);
	
	while(1)
	{
		bzero(buffer, 1024);
		printf("Enter the server name : ");
		scanf("%s", domain);

		if(strcmp(domain, "exit") == 0){
			close(client_fd);
			printf("Disconnected from server...\n");
			break;
		}
		else
		{
			sendto(client_fd, domain, sizeof(domain), MSG_CONFIRM, (struct sockaddr *)&server_addr, sizeof(server_addr));
		}
		
		recvfrom(client_fd, &buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr*)&server_addr, &len);
		
		if(strcmp(buffer, "") == 0)
		{
			printf("Domain not found!\n");
		}
		else
		{
			count = 0;
			strcpy(temp, "");
			for(int i = 0; i < strlen(buffer); i++)
			{
				if(buffer[i] == ' ')
				{
					strcpy(address[count++], temp);
					strcpy(temp, "");
				}
				else
				{
					strncat(temp, &buffer[i], 1); 
				}
			}
			strcpy(address[count++], temp);
			printf("The IP address is : ");
			for(int i = 0; i < count; i++)
			{
				printf("%s\n", address[i]);
				if((count - i) != 1)
				{
					printf("\t\t    ");
				}
			}
			printf("\n");
		}		
	}
	
	return 0;
}
