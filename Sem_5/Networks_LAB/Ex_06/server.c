#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8080

int main()
{
	struct sockaddr_in server_addr, client_addr;
	char buffer[1024];
	char SRC_IP[100], DEST_IP[100], SRC_MAC[100], DEST_MAC[100], DATA[100], PKT[600];	
	int client_sockets[10], max_sd, fd, sockfd, newfd, ping;
	int k, i, count; 
	socklen_t len;
	fd_set newfds;

	printf("\nEnter the details of packet received.\n");
	printf("Destination IP\t: ");
	scanf("%s", DEST_IP);
	printf("Source IP\t: ");
	scanf("%s", SRC_IP);
	printf("Source MAC\t: ");
	scanf("%s", SRC_MAC);
	printf("16 bit data\t: ");
	scanf("%s", DATA);
	
	printf("\nDeveloping ARP Request packet\n");
	strcpy(PKT, "");
	strcat(PKT, SRC_MAC);	
	strcat(PKT, "|");
	strcat(PKT, SRC_IP);
	strcat(PKT, "|");
	strcat(PKT, "00-00-00-00-00-00");
	strcat(PKT, "|");
	strcat(PKT, DEST_IP);
	
	printf("\t%s\n", PKT);
	printf("\tThe ARP Request packet is broacasted.\n");
	printf("Waiting for ARP Reply...\n");

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd < 0)
	{
		perror("Unable to open socket.\n");
	}

	bzero(&server_addr, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);

	if(bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
	{
		perror("Bind error occurred.\n");
	}

	listen(sockfd, 5);
	
	for(i = 0; i < 10; i++)
	{
		client_sockets[i] = 0;
	}

	len = sizeof(client_addr);

	while(1)
	{
		FD_ZERO(&newfds);		//Clears socket set.
		FD_SET(sockfd, &newfds);	//Add sockfd to socket set.
		
		max_sd = sockfd;

		for(i = 0; i < 10; i++){
			fd = client_sockets[i];
			
			if(fd > 0){
				FD_SET(fd, &newfds);
			}

			if(fd > max_sd){		//Store the max valued FD.
				max_sd = fd;
			}
		}

		
		//Wait indefinitely till any client pings.
		ping = select(max_sd+1, &newfds, NULL, NULL, NULL);

		if(ping < 0){
			perror("Select error occurred.\n");
		}

		//if sockfd change => new connection request.
		if(FD_ISSET(sockfd, &newfds)){
			newfd = accept(sockfd, (struct sockaddr*)&client_addr, &len);
			
			if(newfd < 0){
				perror("Unable to accept the new connection.\n");
			}

			strcpy(buffer, PKT);
			send(newfd, buffer, sizeof(buffer), 0);

			//Add the new client on an empty slot.
			for(i = 0; i < 10; i++){
				if(client_sockets[i] == 0){
					client_sockets[i] = newfd;
					break;
				}
			}
		}
	
		// checking for any response from any connected clients.
		for(i = 0; i < 10; i++)
		{
			fd = client_sockets[i];
			bzero(buffer, sizeof(buffer));

			//Check for change in FD
			if(FD_ISSET(fd, &newfds))
			{
				recv(fd, buffer, sizeof(buffer), 0);

				//Check ARP response
				if(buffer[0])
				{
					printf("\nARP Reply received: %s\n", buffer);
					count = 0;
					k = 0;
					for(i = 0; buffer[i]; i++)
					{
						if(count == 0)
						{
							DEST_MAC[k++] = buffer[i];
						}
						if(buffer[i] == '|')
						{
							break;
						}
					}
					DEST_MAC[k] = '\0';

					printf("\nSending the packet to: %s\n", DEST_MAC);
					bzero(buffer, sizeof(buffer));

					strcat(buffer, SRC_MAC);	
					strcat(buffer, "|");
					strcat(buffer, SRC_IP);
					strcat(buffer, "|");
					strcat(buffer, DEST_IP);
					strcat(buffer, "|");
					strcat(buffer, DEST_MAC);
					strcat(buffer, "|");
					strcat(buffer, DATA);
					
					send(newfd, buffer, sizeof(buffer), 0);
					printf("\nPacket Sent: %s\n", buffer);
				}
				else
				{
					close(fd);   
					client_sockets[i] = 0;
				}
			}
		}
	}

	return 0;
}

