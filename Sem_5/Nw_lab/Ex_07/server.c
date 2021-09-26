#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define max_r 20

int ham_calc(int position,int len, int data[])
{
	int count=0, i, j;
	i = position - 1;
	while(i < len)
	{
		for(j = i; j < i+position; j++)
		{
			if(data[j] == 1)
				count++;
		}
		i = i + 2*position;
	}
	if(count%2 == 0)
		return 0;
	else
		return 1;
}

char* convertToString(int n_len, int e_data[])
{
	char *code = malloc(n_len + 1);
	for(int i = 0; i < n_len; i++)
	{
		code[i] = e_data[i] + '0';
	}
	return code;
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
	int data[100], n_data[200];
	int n_len, r, i, count, position, e_index = 4; 
	char tmp_data[100], code[200];
	
	int len, server_fd, new_socket, n;
	struct sockaddr_in server_addr, client_addr; 
	char buffer[1024];
	
	printf("Input data: ");
	scanf("%s", tmp_data);
	
	// convert string to integer array.
	for(i = 0; i < strlen(tmp_data); i++)
	{
		data[i] = tmp_data[i] - 48;
	}
	
	// find the number of reduntant bits.
	for(i = 1; i < max_r; i++)
	{
		if((int)pow(2, i) >= (strlen(tmp_data) + i + 1))
		{
			r = i;
			break;
		}
	}
	
	printf("Number of redundant bits needed is: %d\n", r);
	
	// length of new data array.
	n_len = strlen(tmp_data) + r;
	
	// filling the reduntant bits as -1.
	for(i = 0; i < r; i++)
	{
		n_data[(int)pow(2, i) - 1] = -1;
	}
	
	// filling the message bits in the reverse order.
	count = 0;
	for(i = n_len-1; i >= 0; i--)
	{
		if(n_data[i] != -1)
		{
			n_data[i] = data[count++];
		}
	}
	
	// filling the reduntant bits with correct parity.
	for(i = 0; i < r; i++)
	{
		position = (int)pow(2, i);
		n_data[position - 1] = ham_calc(position, n_len, n_data);
	}
	
	// reversing the data bits.
	for(i = 0; i < n_len/2; i++)
	{
		int temp = n_data[i];
		n_data[i] = n_data[(n_len-1) - i];
		n_data[(n_len-1) - i] = temp;
	}
	
	strcpy(code, convertToString(n_len, n_data));
	
	printf("Data with redundant bits: %s\n", code);
	
	// introducing error in the code.
	if(n_data[e_index] == 1)
		n_data[e_index] = 0;
	else
		n_data[e_index] = 1;
	
	strcpy(code, convertToString(n_len, n_data));
	
	printf("Introduce error in data: %s\n", code);
	
	//----------------------------------------------------------------------
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
		perror("Bind error");
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
	
	strcpy(buffer, code);
	
	write(new_socket, buffer, sizeof(buffer));
	
	close(server_fd);
	close(new_socket);
	//----------------------------------------------------------------------
	
	return 0;
}


