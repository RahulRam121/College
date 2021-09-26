"""
jar1 - litres of water in jar1, jar2 - litres of water in jar2
Pour all water from the jar1 to jar2 till jar1 becomes empty or
jar2 becomes full.
returns the new value of jar1 and jar2.
"""
def fillOrEmpty(jar1, jar2, max):
    if(max - jar2) < jar1:
        return jar1 - (max-jar2), max
    return 0, jar2+jar1

"""
Check if the new_state is already present in the s_list.
If not append the new_state to the list.
"""
def addToList(new_state):
    for state in s_list:
        if state == new_state:
            return
    queue.append(new_state)
    s_list.append(new_state)
    
"""
Takes a list of successors and print if the goal state is present.
Goal state - jar1 or jar2 should have value 4.
"""
def isFinalState(successors):
    for state in successors:
        if state[0] == 4 or state[1] == 4:
            print("Initial State : (8, 0, 0)")
            print("Final State   :", state)
            return True
    return False

"""
Takes a list of state and prints it.
First tuple in the list is the parent and remaining states are 
its successors.
"""
def printStates(successors):
    first = True
    for state in successors:
        if(first):
            print(state)
            first = False
        else:
            print("  |->", state)
    print()

"""
Takes a state as its input and returns the list of its successors
along with the same state.
"""
def findNextState(state):
    
    max = (8, 5, 3)
    successors =[state]
    
    for i in range(3):
        
        if state[i] != 0:
            next1 = (i+1) % 3
            next2 = (i+2) % 3
            
            if(state[next1] != max[next1]):
                new_state = list(state)
                new_state[i], new_state[next1] = fillOrEmpty(state[i], state[next1], max[next1])  
                successors.append(tuple(new_state))

                if(new_state[i] != 0):
                    new_state[i], new_state[next2] = fillOrEmpty(new_state[i], new_state[next2], max[next2])   
                    successors.append(tuple(new_state))
                
            if(state[next2] != max[next2]):   
                new_state = list(state)
                new_state[i], new_state[next2] = fillOrEmpty(state[i], state[next2], max[next2])
                successors.append(tuple(new_state))

                if(new_state[i] != 0):
                    new_state[i], new_state[next1] = fillOrEmpty(new_state[i], new_state[next1], max[next1])
                    successors.append(tuple(new_state))

    return successors


def main():
    init_state = (8, 0, 0)
    # s_list - list of all discovered states.
    global s_list
    s_list = [init_state]
    # queue - list to perform queue operation in BFS search.
    global queue
    queue = []
    
    print("BFS Search......\n")
    """ BFS part
    **************************************************************************"""
    successors = findNextState(init_state)
    for state in successors:
        addToList(state)
    printStates(successors)
    while(isFinalState(successors) == False):
        successors = findNextState(queue.pop(0))
        for state in successors:
            addToList(state)
        printStates(successors)
    """***********************************************************************"""
    print("Number of states explored : ",len(s_list) - len(queue))


main()