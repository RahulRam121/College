"""
Name   : Rahul Ram M 
Class  : CSE B
Roll No: 185001121
Date   :07-11-2020
CAT 04
"""

"""
heuristic fn - returns the number of elements that are out of order.
"""
def findOutofOrder(state):
    count = 0
    for i in range(len(state)):
        if state[i] != (i+1):
            count += 1
    
    return count

"""
check if all the elements of the list are in order and returns
yes -> True
no -> False
"""
def checkFinal(state):
    i = state[0]
    for j in state:
        if i > j:
            return False
        i = j
        
    return True

"""
successors - successors of a state
add the states from the successors to the open_list that are 
not in closed_list and open_list
"""
def remove_dups(open_list, successors, closed_list):
    for state in successors:
        if state not in open_list and state not in closed_list:
            open_list.append(state)
            
    return open_list

"""
delete the state with least heuristic value and update the open_list
returns the deleted state and updated open_list
"""
def deleteMin(states):
    min_h = 11
    min_index = -1
    
    for i in range(len(states)):
        h = findOutofOrder(states[i])
        if h < min_h:
            min_h = h
            min_index = i
    
    min_state = states[min_index]
    states.pop(min_index)
    return min_state, states

"""
produce successors of the given state
by cutting the first item and place it all possible order
cutting second item and place it all possible order and so on.
Now cut first two elements and paste it in all possible order,
then 2nd two elements and place it all possible orders.
Now 3 elements and so on.
"""
def getSuccessors(state):
    successors = []
    h = findOutofOrder(state)
    for i in range(1, len(state)):
        
        for j in range(len(state)-i):
            tmp = state
            temp = tmp[j:j+i]
            tmp = tmp[0:j]+tmp[j+i:]
            for k in range(len(tmp)):
                new = []
                new = new + tmp
                for l in range(len(temp)):
                    new.insert(k+l, temp[l])
                h1 = findOutofOrder(new)
                if h1 < h:
                    successors.append(new)
            new = []
            new = tmp+temp
            h1 = findOutofOrder(new)
            if h1 < h:
                successors.append(new)
            successors.append(new)
            
    
    return successors

"""
Using Best First Search to get the result.
"""
def BestFS(init_state):
    closed_list = []
    open_list = [init_state]
    
    while(len(open_list) != 0):
        s, open_list = deleteMin(open_list)
        closed_list.append(s)
        if checkFinal(s):
            return closed_list
        else:
            successors = getSuccessors(s)
            open_list = remove_dups(open_list, successors, closed_list)
            
     
def main():
    init_state = [5,4,3,2,1]
    path = BestFS(init_state)
    
    for i in range(len(path)-1):
        print(path[i], '->', end='')
    print(path[len(path)-1])

main()

"""
output:
[5, 4, 3, 2, 1] ->[3, 2, 5, 4, 1] ->[5, 2, 1, 4, 3] ->[3, 2, 4, 1, 5] ->[3, 2, 1, 4, 5] ->[1, 3, 2, 4, 5] ->[1, 2, 3, 4, 5]
"""