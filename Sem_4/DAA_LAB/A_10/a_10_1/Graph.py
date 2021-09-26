class Graph(object):
    
    def __init__(self, size):
        
        self.adjMatrix = []
        self.size = size
        
        for i in range(size):
            temp = []
            for j in range(size):
                    temp.append(False)
            self.adjMatrix.append(temp)            

    def addEdge(self, v1, v2):
        
        self.adjMatrix[v1][v2] = True
        
    def toString(self):
        for row in self.adjMatrix:
            for val in row:            
                print(val,end = " ")
            print()