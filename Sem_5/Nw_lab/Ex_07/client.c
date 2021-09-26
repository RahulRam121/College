#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int ham_calc(int position,int len, int data[])
{
	int count=0, i, j;
	i = position - 1;
	while(i < len)
	{
		for(j = i; j < i+position && j < len; j++)
		{
			if(data[j] == 1)
			{
				count++;
			}
		}
		i = i + 2*position;
	}
	if(count%2 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void printBinary(int len, int data[])
{
	for(int i = 0; i < len; i++)
	{
		printf("%d", data[i]);
	}
	printf("\n");
}

int main()
{
	int data[200], c_data[100], rbits[20];
	int len, r, i, count, position, e_index; 
	char code[200];
	
	//--------------------------------------------------------------------------------
	int socket_fd;
	struct sockaddr_in server_addr;
	char buffer[1024];
	
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
	
	read(socket_fd, buffer, sizeof(buffer));

	
	close(socket_fd);
	//--------------------------------------------------------------------------------
	
	strcpy(code, buffer);
	
	len = strlen(code);
	
	// convert string to integer array.
	for(i = 0; i < len; i++)
	{
		data[i] = code[i] - 48;
	}
	
	printf("Data received: ");
	printBinary(len, data);
	
	// reversing the data array.
	for(i = 0; i < len/2; i++)
	{
		int temp = data[i];
		data[i] = data[(len-1) - i];
		data[(len-1) - i] = temp;
	}
	
	// find the number of redundant bits.
	i = 0;
	while((int)pow(2, i) < (len + i + 1))
	{
		i++;
	}
	r = i;
	
	// extracting the redundant bits and placing it in separate array.
	for(i = 0; i < r; i++)
	{
		position = (int)pow(2, i);
		rbits[i] = ham_calc(position, len, data);
	}
	
	// calculating the value of the rbits array.
	// binary to decimal conversion.
	e_index = 0;
	for(i = 0; i < r; i++)
	{
		if(rbits[i] == 1)
		{
			e_index += (int)pow(2, i);
		}
	}
	
	// reversing the rbits array.
	for(i = 0; i < r/2; i++)
	{
		int temp = rbits[i];
		rbits[i] = rbits[(r-1) - i];
		rbits[(r-1) - i] = temp;
	}
	
	printf("Calculated redundant bits: ");
	printBinary(r, rbits);
	
	// correcting the data.
	e_index--;
	if(e_index >= 0)
	{
		if(data[e_index] == 1)
			data[e_index] = 0;
		else
			data[e_index] = 1;
	}
	
	// assigning the rbits as -1.
	for(i = 0; i < r; i++)
	{
		position = (int)pow(2, i);
		data[position-1] = -1;
	}
	
	count = 0;
	for(i = 0; i < len; i++)
	{
		if(data[i] != -1)
		{
			c_data[count++] = data[i];
		}
	}
	
	printf("Corrected data: ");
	printBinary(len - r, c_data);
	
	return 0;
}

