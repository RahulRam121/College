#include <stdio.h>
#include <stdlib.h>

// Define maximum number of vertices in the graph
#define N 9

// Data structure to store graph
struct Graph {
	// An array of pointers to Node to represent adjacency list
	struct Node* head[N];
};

// A data structure to store adjacency list nodes of the graph
struct Node {
	int dest, weight;
	struct Node* next;
};

// data structure to store graph edges
struct Edge {
	int src, dest, weight;

};

// Function to create an adjacency list from specified edges
struct Graph* createGraph(struct Edge edges[], int n)
{
	unsigned i;

	// allocate memory for graph data structure
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

	// initialize head pointer for all vertices
	for (i = 0; i < N; i++)
		graph->head[i] = NULL;

	// add edges to the directed graph one by one
	for (i = 0; i < n; i++)
	{
		// get source and destination vertex
		int src = edges[i].src;
		int dest = edges[i].dest;
		int weight = edges[i].weight;

		// allocate new node of Adjacency List from src to dest
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->dest = dest;
		newNode->weight = weight;

		// point new node to current head
		newNode->next = graph->head[src];

		// point head pointer to new node
		graph->head[src] = newNode;
	}

	return graph;
}

// Function to print adjacency list representation of graph
void printGraph(struct Graph* graph)
{
	int i;
	for (i = 0; i < N; i++)
	{
		// print current vertex and all ts neighbors
		struct Node* ptr = graph->head[i];
		while (ptr != NULL)
		{
			printf("%d -> %d (%d)\t", i, ptr->dest, ptr->weight);
			ptr = ptr->next;
		}

		printf("\n");
	}
}

// Weighted Directed Graph Implementation in C
int main(void)
{
	// input array containing edges of the graph (as per above diagram)
	// (x, y, w) tuple in the array represents an edge from x to y having weight w
	struct Edge edges[] =
	{
		{ 0, 1, 70 },{1,0,70}, {0,2,340},{2,0,340},{1,3,200},{3,1,200},{2,3,143},{3,2,143},{2,7,168},{7,2,168},{7,6,450},{6,7,450},
		{6,5,85},{5,6,85},{4,5,157},{5,4,157},{4,8,206},{8,4,206},{3,4,132},{4,3,132},{3,8,59},{8,3,59},{7,4,236},{4,7,236},{2,3,143},
		{3,2,143},{1,3,200},{3,1,200}										
	};

	// calculate number of edges
	int n = sizeof(edges)/sizeof(edges[0]);

	// construct graph from given edges
	struct Graph *graph = createGraph(edges, n);

	// print adjacency list representation of graph
	printGraph(graph);

	return 0;
}

