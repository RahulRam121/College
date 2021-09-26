#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main()
{
	struct sockaddr_in server_addr;
	char buffer[1024], dest[100], SRC_IP[100], DEST_IP[100], SRC_MAC[100], DEST_MAC[100];
	int sockfd;
	int i, count, k;

	printf("\nEnter the IP Address\t: ");
	scanf("%s", dest);
	printf("\nEnter the MAC Address\t: ");
	scanf("%s", DEST_MAC);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd < 0)
	{
		perror("Unable to open socket.\n");
	}

	bzero(&server_addr, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(PORT);

	connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

	bzero(buffer, sizeof(buffer));
	recv(sockfd, buffer, sizeof(buffer), 0);
	printf("\nARP Request Received: %s\n", buffer);

	count = 0;
	k = 0;
	for(i = 0; buffer[i]; i++)
	{
		if(buffer[i] == '|')
		{			
			if(count == 0)
			{
				SRC_MAC[k] = '\0';
			}
			else if(count == 1)
			{
				SRC_IP[k] = '\0';
			}
			else if(count == 3)
			{
				DEST_IP[k] = '\0';
			}
			count++;
			k = 0;
		}
		else if(count == 0)
		{
			SRC_MAC[k++] = buffer[i];
		}
		else if(count == 1)
		{
			SRC_IP[k++] = buffer[i];
		}
		else if(count == 3)
		{
			DEST_IP[k++] = buffer[i];
		}
		
	}

	if(strcmp(dest, DEST_IP) == 0)
	{
		bzero(buffer, sizeof(buffer));
		printf("\nIP Address matches.\n");
		
		strcat(buffer, DEST_MAC);
		strcat(buffer, "|");
		strcat(buffer, DEST_IP);
		strcat(buffer, "|");
		strcat(buffer, SRC_IP);
		strcat(buffer, "|");
		strcat(buffer, SRC_MAC);
		send(sockfd, buffer, sizeof(buffer), 0);
		printf("\nARP Reply Sent: %s\n", buffer);

		bzero(buffer, sizeof(buffer));
		recv(sockfd, buffer, sizeof(buffer), 0);
		printf("\nReceived Packet is: %s\n", buffer);
	}

	else{
		printf("\nIP Address does not match.\n");
	}

	close(sockfd);

	return 0;
}
