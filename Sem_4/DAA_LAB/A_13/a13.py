import math
from minHeap import BinaryHeap

def main():

    n = 3
    initState = [[3, 2, 7],[5, 8, -1],[1, 4, 6]]
    goalState = [[1, 2, 3],[4, 5, 6],[7, 8, -1]]
    
    printMatrix(initState)

    bestFirst(initState, goalState, goalState, n)
    
    heap = BinaryHeap()
    path = []
    path.append(initState)
    Astar(initState, goalState, goalState, path, heap, n)
	
def getMinMoves(newState, goalState, n):
    
    minMoves = 0
    for i in range(n):
        for j in range(n):            
            if goalState[i][j] >= 0:
                minMoves += getMoves(newState, goalState, i, j, n)
	
    return minMoves
			
def getMoves(newState, goalState, x , y, n):
	
    for k in range(n):
        for l in range(n):
            
            if goalState[x][y] == newState[k][l]:
                
                i = k
                j = l
                break;
    return abs(x - i) + abs(y - j)

def bestFirst(newState, goalState, prevState, n):

    x, y = findSpace(newState, n)
    newMin = math.inf
    tempState = list(map(list, newState))
    
    for i in range(-1, 2):
        for j in range(-1, 2):            
            if (i != 0 or j != 0) and (i == 0 or j == 0):
                if (isSafe(x+i, y+j, n)):
                    tempState[x][y] -= 1
                    tempState[x][y], tempState[x+i][y+j] = tempState[x+i][y+j], tempState[x][y]                    
                    if(getMinMoves(tempState, goalState, n) < newMin and isEqual(prevState, tempState, n) == False):                        
                        newMin = getMinMoves(tempState, goalState, n)                        
                        temp1State = list(map(list, tempState))                           
                    tempState = list(map(list, newState))
    
    printArrow()
    printMatrix(temp1State)
    x, y = findSpace(temp1State, n)
    if getMinMoves(temp1State, goalState, n) != 0:        
        bestFirst(temp1State, goalState, newState, n)
    else:
        print('Number of Moves :',abs(temp1State[x][y]) - 1)
        
def Astar(newState, goalState, prevState, path, heap, n):
    x, y = findSpace(newState, n)
    newMin = math.inf
    tempState = list(map(list, newState))
    
    for i in range(-1, 2):
        for j in range(-1, 2):            
            if (i != 0 or j != 0) and (i == 0 or j == 0):
                if (isSafe(x+i, y+j, n)):
                    tempState[x][y] -= 1
                    tempState[x][y], tempState[x+i][y+j] = tempState[x+i][y+j], tempState[x][y]
                    heap.insert(tempState, goalState, n)
                    if(getMinMoves(tempState, goalState, n) < newMin and isEqual(prevState, tempState, n) == False):                        
                        newMin = getMinMoves(tempState, goalState, n)                        
                        temp1State = list(map(list, tempState))                           
                    tempState = list(map(list, newState))
    
    if(isEqual(temp1State, goalState, n) == False):
        if totalMinMoves(temp1State, goalState, n) < totalMinMoves(heap.get_min(), goalState, n) + findLevel(tempState, n):
            path.append(temp1State)
            Astar(temp1State, goalState, newState, path, heap, n)
        else:
            temp1State = list(map(list, heap.extract_min(goalState, n)))
            newLevel = findLevel(temp1State, n)
            while(findLevel(path.pop(), n) != newLevel):
                pass
            path.append(temp1State)
            
            Astar(temp1State, goalState, newState, path, heap, n)
    else:
        path.append(temp1State)
        x, y = findSpace(temp1State, n)
        printPath(path)
        print('Number of Moves :',abs(temp1State[x][y]) - 1)
        
            
def findLevel(curState, n):
    x, y = findSpace(curState, n)
    return abs(curState[x][y])
 
def isEqual(prevState, currentState, n):
    for i in range(n):
        for j in range(n):
            if prevState[i][j] >= 0:
                if prevState[i][j] != currentState[i][j]:
                    return False
    return True

def totalMinMoves(newState, goalState, n):
    x, y = findSpace(newState, n)
    return getMinMoves(newState, goalState, n) + findLevel(newState, n) - 1

def findSpace(newState, n):
    
    for i in range(n):
        for j in range(n):
            if newState[i][j] < 0:
                return i, j

def isSafe(x, y, n):
    if x<n and x>=0 and y<n and y>=0:
        return True
		
def printMatrix(matrix):
    for row in matrix:
        for val in row:
            if val >= 0:
                print(val, end = " ")
            else:
                print(" ", end = " ")
        print()	

def printPath(path):
    for state in path:
        printMatrix(state)
        printArrow()
        
def printArrow():
    print('   |')
    print('   |')
    print('   |')
    print('  \|/')
if __name__ == '__main__':
    main() 
