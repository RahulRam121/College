#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080

int main()
{
	int server_socket, addr_size, new_socket, client_socket[10],
		max_clients = 10, activity, val, sd, max_sd, opt = TRUE;
		
	struct sockaddr_in server_addr;
	
	char buffer[1024];
	
	fd_set read_fds;
	
	for (int i = 0; i < max_clients; i++)   
        {   
        	client_socket[i] = 0;   
        } 
	
	if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Socker error");
		exit(1);
	}
	
	if( setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 )   
    	{   
        	perror("setsockopt");   
        	exit(1);   
    	} 
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);
	
	if(bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
	{
		perror("Bind error: ");
		exit(1);
	}
	
	if(listen(server_socket,3) < 0)
	{
		perror("Listen error");
		exit(1);
	}
	
	addr_size = sizeof(server_addr);
	
	printf("Waiting for client...\n");
	
	while(TRUE)
	{
		FD_ZERO(&read_fds);
		
		FD_SET(server_socket, &read_fds);
		max_sd = server_socket;
		
		for(int i = 0; i < max_clients; i++)
		{
			sd = client_socket[i];
		
			if(sd > 0)   
			{
				FD_SET(sd, &read_fds); 
			}
			
			if(sd > max_sd)
			{
				max_sd = sd;
			}
		
		}	
		activity = select( max_sd + 1, &read_fds, NULL, NULL, NULL);   
       
		if ((activity < 0) && (errno!=EINTR))   
		{   
			printf("Select error");   
		}
        
		if (FD_ISSET(server_socket, &read_fds))  
		{
			if ((new_socket = accept(server_socket, (struct sockaddr *)&server_addr, (socklen_t*)&addr_size))<0)   
			{   
				perror("Accept error");   
				exit(1);   
			} 
            
			for (int i = 0; i < max_clients; i++)   
			{   
				if( client_socket[i] == 0 )   
				{   
					client_socket[i] = new_socket;                            
					break;   
				}   
			}         
		}
        
		for(int i = 0; i < max_clients; i++)
		{
			sd = client_socket[i];
			if (FD_ISSET(sd, &read_fds))   
			{   
		  
				if ((val = read(sd , buffer, sizeof(buffer)) == 0))  
				{   
					close(sd);   
					client_socket[i] = 0;   
				}   
				else 
				{    
					printf("%s\n", buffer);
					bzero(buffer, sizeof(buffer));
					printf("Server : ");
					scanf(" %[^\n]", buffer);
					if(strcmp(buffer, "exit") == 0)
					{
						printf("Server shutdown successfully!\n");
						exit(0);
					}
					val = write(sd, buffer, sizeof(buffer));   
					
				}   
			}
		}		
	}
	
	return 0;
}

