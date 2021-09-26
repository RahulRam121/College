from Graph import Graph

def main():
    
    g = Graph(5)
    
    g.addEdge( 0, 1, 1);
    g.addEdge( 0, 2, 6);
    g.addEdge( 1, 2, 2);
    g.addEdge( 2, 3, 3);
    g.addEdge( 3, 4, 1);
    g.addEdge( 4, 0, 2);    
    
    print("Adjacency Matrix :")
    printMatrix(g.adjMatrix)
    
    apsp(g.adjMatrix, g.size)

def printMatrix(mat):
    
    print()
    for row in mat:
        for val in row:
            print(val,end = " ")
        print()
    print()
      
def apsp(adjMatrix, n):
        
    distMatrix = adjMatrix
    prevMatrix = []
    
    for i in range(n):
        temp = []
        for j in range(n):
            temp.append(i)
        prevMatrix.append(temp)
            
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if(i != j):
                    dist = distMatrix[i][k] + distMatrix[k][j]
                    if(distMatrix[i][j] > dist):
                        distMatrix[i][j] = dist
                        prevMatrix[i][j] = prevMatrix[k][j]
    
    print("Distance Matrix :")
    printMatrix(distMatrix)
    print("Previous Node Matrix :")
    printMatrix(prevMatrix)
    
    print('Shortest Path between every pair of vertices and its distance')
    for i in range(n):
        print(i,'to all nodes\n')
        for j in range(n):            
            if i != j:
                print(i,'to',j)
                path(i, j, prevMatrix)
                print(" =",distMatrix[i][j])
        print()


def path(start, end, prev):
    if start == end:
        print(start,end = "")
    elif (prev[start][end] == -1):
        print('No path exists')
    else:        
        path(start, prev[start][end], prev)
        print("->",end = "")
        print(end,end = "")

if __name__ == '__main__':
   main()