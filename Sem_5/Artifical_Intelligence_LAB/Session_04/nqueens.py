from collections import defaultdict 
from copy import deepcopy
class state:
    __slots__=["arr","h"]

    def __init__(self,arr,h=None):
        self.arr=arr
        if(h is None):
            self.h=self.heuristic(self.arr)
        else:
            self.h=h
    
    def heuristic(self,arr):
        h=0
        for i in range(len(arr)):
            for j in range(len(arr)):
                if(i!=j):
                    if(arr[i]==arr[j]):
                        h+=1
        h=h/2
        # print(h)
        k=0
        for j in range(len(arr)):
            diff=j-arr[j]
            for i in range(len(arr)):
                if((i-arr[i])==diff and i!=j):
                    k+=1
        k=k/2

        # print(k)
        t=0
        for j in range(len(arr)):
            diff=j+arr[j]
            for i in range(len(arr)):
                if((i+arr[i])==diff and i!=j):
                    t+=1
        t=t/2
        # print(t)

        return h+t+k


    def successor(self):
        min_h=self.h
        next_states=[]
        next_state=""
        for j in range(len(self.arr)):
            for i in range(len(self.arr)):
                if(i!=self.arr[j]):
                    old=self.arr[j]
                    # print(self.arr)
                    self.arr[j]=i
                    h=self.heuristic(self.arr)
                    if(h<min_h):
                        arr=deepcopy(self.arr)
                        s=state(arr,h)
                        next_states=[]
                        next_state=s
                        min_h=h

                    if(h==min_h):
                        arr=deepcopy(self.arr)
                        s=state(arr,h)
                        next_states.append(s)
                        next_state=s
                        min_h=h
                    self.arr[j]=old
        if(next_state==""):
            return None
        return [next_state.h, next_state]

    def __str__(self):
        return f'arr:{self.arr}, h:{self.h}'


def hillClimbingSearch1(initial):
    currentNode=initial
    equals=defaultdict(list)
    ans=[]
    while(True):
        temp=currentNode.successor()
        if(temp==None):
            break
        value,nextNode=temp[0],temp[1]
       
     
        if(value==0):
            ans=nextNode
            break

        if(value>currentNode.h):
            ans=currentNode

        currentNode=nextNode
    return (ans,equals)


initial=state([1,1,1,1,1,1,1,5])
ns=initial.successor()
# print("These are the worthy next states")
a=hillClimbingSearch1(initial)
print(f'Goal -{a[0]}')

        

    
