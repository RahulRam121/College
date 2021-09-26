from Graph import Graph
from itertools import permutations
     
#hamiltonian circiut using backtracking
def hamiltonian1(adjMatrix, n):
    for s in permutations(range(n)):
        if(checkEdges(adjMatrix, s)):
            print(s)

def checkEdges(adjMatrix, seq):
    if(adjMatrix[seq[len(seq)-1]][seq[0]] == 0):
        return False
    for i in range(len(seq) - 1):
        if(adjMatrix[seq[i]][seq[i+1]] == 0):
            return False
    return True

#hamiltonian circiut using backtracking with pruning
def hamiltonian2(adjMatrix, n):
    vertices = []
    for i in range(n):
        vertices.append(i)
        pruning(adjMatrix, vertices, n-1, n)
        vertices.pop()
        
#nested for loop using recursion
def pruning(adjMatrix, vertices, loop, n):
    #if n vertices are included in the list,
    if loop == 0:
        #check if first and last vertex have an edge
        if adjMatrix[vertices[n-1]][vertices[0]] == 1:
            #if yes, print the list(hamiltonian cycle)
            print(vertices)
    else:
        for i in range(n):
            #append i to the vertices
            vertices.append(i)
            #if vertices is in the safe state call recusively
            if(isSafeState(adjMatrix, vertices)):
                pruning(adjMatrix, vertices, loop-1, n)
                #when inner loop completes its iteration, pop a vertex from list(vertices)
                vertices.pop()
            #else pop and append next i vertex
            else:
                vertices.pop()
                    
def isSafeState(adjMatrix, vertices):
    n = len(vertices)
    #check if the last vertex is repeated
    for i in range(n - 1):
        if vertices[n-1] == vertices[i]:
            return False
    #check if there is any edge between vertices[n-1] and vertices[n-2]
    if adjMatrix[vertices[n - 2]][vertices[n - 1]] == 0:
        return False
    return True

def printGraph(adjMatrix):
    for row in adjMatrix:
        for val in row:
            print(val, end = " ")
        print()

def main():
    #graph with seven vertices
    n = 7
    g = Graph(n)
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 5);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 6);
    g.addEdge(2, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 3);
    g.addEdge(5, 6);
    g.addEdge(3, 6);
    
    print("Adjacency Marix:\n")
    printGraph(g.adjMatrix)
    print("\nHamiltonian circuits using Backtracking:")
    #hamiltonian circiut using backtracking
    hamiltonian1(g.adjMatrix, n)
    print("\nHamiltonian circuits using Backtracking with Pruning:")
    #hamiltonian circuits using backtracking with pruning
    hamiltonian2(g.adjMatrix, n)
    
if __name__ == '__main__':
	main()
