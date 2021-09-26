from Graph import Graph

def main():
    
    g = Graph(4)
    
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(3, 2);    
    g.addEdge(3, 0);
    
    print('Adjacency Matrix: ')
    printMatrix(g.adjMatrix)
    
    closure(g.adjMatrix, g.size)

def closure(adjMatrix, n):
    
    closureMatrix = adjMatrix
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                closureMatrix[i][j] = closureMatrix[i][j] or closureMatrix[i][k] and closureMatrix[k][j]
    
    print('Transitive Closure Matrix :')
    printMatrix(closureMatrix)
    
    print('Reachability Status:\n')
    reachability(closureMatrix, n)
    
def reachability(closureMatrix, n):
    
    for i in range(n):
        for j in range(n):
            print(i,'to',j, end = " ")
            if(closureMatrix[i][j]):
                print('path exists')
            else:
                print('path does not exists')
        print()
            

def printMatrix(mat):
    
    print()
    for row in mat:
        for val in row:
            print(val,end = " ")
        print()
    print()


if __name__ == '__main__':
   main()