#include <stdio.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "dns.h"

#define PORT 8080

int main()
{

	char result[100], opt[10], domain[20], address[20], buffer[1024];
	int sockfd;
	socklen_t len;
	struct sockaddr_in server_addr, client_addr;
	struct Entry* table = NULL;
	
	// SOCK_DGRAM -UDP
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{	
		perror("Socker error");
		exit(1);
	}
	
	bzero(&server_addr, sizeof(server_addr));
	// assign IP, PORT
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr))) < 0)
	{
		perror("Bind error: ");
		exit(1);	
	}

	len = sizeof(client_addr);
	
	addEntry(&table, "www.yahoo.com", "10.2.45.67");
	addEntry(&table, "www.annauniv.edu", "197.34.53.122");
	addEntry(&table, "www.google.com", "142.89.78.66");
	
	printTable(table);
	
	int flag = 0;
	printf("Do you want to modify (yes/no): ");
	scanf("%s", opt);
	if (strcmp(opt, "yes") == 0)
	{
		printf("Enter domain: ");
		scanf("%s", domain);
		do
		{
			printf("Enter IP address: ");
			scanf("%s", address);
			flag = addEntry(&table, domain, address);

		} while (flag != 1);
	
		printf("\nUpdated table\n");
		printTable(table);
	}
	
	while (1)
	{
		bzero(buffer, 1024);
		recvfrom(sockfd, buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr*)&client_addr, &len);
		printf("Checking and sending IP address for %s\n", buffer);
		strcpy(result,getAddress(table, buffer));
		sendto(sockfd, &result, sizeof(result), MSG_CONFIRM, (struct sockaddr*)&client_addr, len);
	}

	close(sockfd);
}
