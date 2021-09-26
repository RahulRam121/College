import math
from minHeap import BinaryHeap

def main():

    n = 3
    initState = [[7, 2, 4], [5, -1, 6], [8, 3, 1]]
    goalState = [[-1, 1, 2], [3, 4, 5], [6, 7, 8]]
    print("Greedy Best-First Search: ")
    printMatrix(initState)
    
    bestFirst(initState, goalState, goalState, n)
    
    heap = BinaryHeap()
    path = []
    path.append(initState)
    print("A* Search: ")
    Astar(initState, goalState, goalState, path, heap, n)
	
# means h(n) or manhattan distance
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
    # coordinates of free space in the tiles matrix.
    x, y = findSpace(newState, n)
    newMin = math.inf
    # copying newState to tempState using list(map())
    tempState = list(map(list, newState))
    
    # loop -1, 0, 1 -> decrease 1, no change, increase 1 to the value of x.
    for i in range(-1, 2):
        # loop -1, 0, 1 -> decrease 1, no change, increase 1 to the value of y.
        for j in range(-1, 2):   
            # both i and j cannot be 0(same state - tile space)
            if (i != 0 or j != 0) and (i == 0 or j == 0):
                # check if adding i and j to x and y still in the limits.
                if (isSafe(x+i, y+j, n)):
                    # decrement by 1 to the tile space indicating the change in the state.
                    tempState[x][y] -= 1
                    # next state -> by replacing tiles at x,y by x+i,y+j
                    tempState[x][y], tempState[x+i][y+j] = tempState[x+i][y+j], tempState[x][y]
                    # inserting the new state to the heap, depending on the A* value.
                    heap.insert(tempState, goalState, n)
                    # finding the state with next min value and assigning the state to temp1State.
                    # making sure that the state is not the previous state.
                    if(getMinMoves(tempState, goalState, n) < newMin and isEqual(prevState, tempState, n) == False):    
                        # new min value
                        newMin = getMinMoves(tempState, goalState, n)                        
                        # new min state
                        temp1State = list(map(list, tempState))                           
                    tempState = list(map(list, newState))
    
    # If the min state is not the goal state
    if(isEqual(temp1State, goalState, n) == False):
        # if f(n) < f(n-1) + g(n-1)
        # means if the current min is smaller than the previous, continue with the new min state.
        if totalMinMoves(temp1State, goalState, n) < totalMinMoves(heap.get_min(), goalState, n) + findLevel(tempState, n):
            # then append the node to the path
            path.append(temp1State)
            # recursive call for Astar()
            Astar(temp1State, goalState, newState, path, heap, n)
        else:
            # else extract min state from heap and assign it to temp1State
            temp1State = list(map(list, heap.extract_min(goalState, n)))
            newLevel = findLevel(temp1State, n)
            # pop() all the states from the current level.
            while(findLevel(path.pop(), n) != newLevel):
                pass
            # append the temp1State to the path.
            path.append(temp1State)
            # recursive call for Astar()
            Astar(temp1State, goalState, newState, path, heap, n)
    else:
        # append the state to the path
        path.append(temp1State)
        # get the coordinates of the space.
        x, y = findSpace(temp1State, n)
        printPath(path)
        # find the number of levels by subtracting the abs value of the free tile by 1.
        print('Number of Moves :',abs(temp1State[x][y]) - 1)
        
# each state has a level from -1 to infi placed at free space in the tiles matrix
# where -1 for init state and some negative value for goal state.            
def findLevel(curState, n):
    x, y = findSpace(curState, n)
    return abs(curState[x][y])

# check if prevState is equal to the curentState
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

# find the coordinates of the space blank space.
def findSpace(newState, n):
    
    for i in range(n):
        for j in range(n):
            if newState[i][j] < 0:
                return i, j

# Returns if the index is within the range.
def isSafe(x, y, n):
    if x<n and x>=0 and y<n and y>=0:
        return True

# prints the matrix.	
def printMatrix(matrix):
    for row in matrix:
        for val in row:
            if val >= 0:
                print(val, end = " ")
            else:
                print(" ", end = " ")
        print()	

# prints the path from init to goal state.
def printPath(path):
    for state in path:
        printMatrix(state)
        printArrow()

# prints arrow.    
def printArrow():
    print('  |')
    print('  V')
    
if __name__ == '__main__':
    main() 
