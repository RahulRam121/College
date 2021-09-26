import math

class Graph(object):
    
    def __init__(self, size):
        
        self.adjMatrix = []    
        self.size = size
        
        for i in range(size):
            
            temp = []
            
            for j in range(size):
                if(i == j):
                    temp.append(0)
                else:
                    temp.append(math.inf)
                    
            self.adjMatrix.append(temp)
            
        

    def addEdge(self, v1, v2, weight):
        
        self.adjMatrix[v1][v2] = weight
    