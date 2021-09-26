class BinaryHeap:
    def __init__(self):
        self.states = []
 
    def size(self):
        return len(self.states)
 
    def parent(self, i):
        return (i - 1)//2
 
    def left(self, i):
        return 2*i + 1
 
    def right(self, i):
        return 2*i + 2
 
    def get(self, i):
        return self.states[i]
 
    def get_min(self):
        if self.size() == 0:
            return None
        return self.states[0]
 
    def extract_min(self, goalState, n):
        if self.size() == 0:
            return None
        smallest = self.get_min()
        self.states[0] = self.states[-1]
        del self.states[-1]
        self.min_heapify(0, goalState, n)
        return smallest
 
    def min_heapify(self, i, goalState, n):
        l = self.left(i)
        r = self.right(i)
        if (l <= self.size() - 1 and self.totalMinMoves(self.get(l), goalState, n) < self.totalMinMoves(self.get(i), goalState, n)):
            smallest = l
        else:
            smallest = i
        if (r <= self.size() - 1 and self.totalMinMoves(self.get(r), goalState, n) < self.totalMinMoves(self.get(smallest), goalState, n)):
            smallest = r
        if (smallest != i):
            self.swap(smallest, i)
            self.min_heapify(smallest, goalState, n)
 
    def swap(self, i, j):
        self.states[i], self.states[j] = self.states[j], self.states[i]
    
    def findSpace(self, newState, n):
    
        for i in range(n):
            for j in range(n):
                if newState[i][j] < 0:
                    return i, j

    def findLevel(self, curState, n):
        x, y = self.findSpace(curState, n)
        return abs(curState[x][y])- 1
    
    def totalMinMoves(self, newState, goalState, n):
        x, y = self.findSpace(newState, n)
        return self.getMinMoves(newState, goalState, n) + self.findLevel(newState, n) - 1
        
    def getMinMoves(self, newState, goalState, n):
    
        minMoves = 0
        for i in range(n):
            for j in range(n):            
                if goalState[i][j] >= 0:
                    minMoves += self.getMoves(newState, goalState, i, j, n)
	
        return minMoves
    
    def getMoves(self, newState, goalState, x , y, n):
	
        for k in range(n):
            for l in range(n):
                
                if goalState[x][y] == newState[k][l]:
                    
                    i = k
                    j = l
                    break;
        return abs(x - i) + abs(y - j)

 
    def insert(self, curstate, goalState, n):
        index = self.size()
        self.states.append(curstate)
 
        while (index != 0):
            p = self.parent(index)
            if self.totalMinMoves(self.get(p), goalState, n) > self.totalMinMoves(self.get(index), goalState, n):
                self.swap(p, index)
            index = p