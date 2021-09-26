class node:
    dist=0
    currnode=prevnode=''
    def __init__(self,dist,currnode,prevnode):
     self.dist=dist
     self.prevnode=prevnode
     self.currnode=currnode
    def __str__(self):
        return "%d %s %s"%(self.dist,self.currnode,self.prevnode)
def insert_c(h,x):
     h1=h+[node(0,'','')]
     size=len(h)+1
     i=size-1
     while(h1[i//2].dist>x.dist and i>0):
        h1[i]=h1[i//2]
        i=i//2
     h1[i]=x
     #for val in h1:print(val)
     return h1

def buildHeap_c(lst):
    h=[node(999,'','')]
    for x in lst:
        h=insert_c(h,x)
    #for val in h:print(val)
    return h

def deleteMin_c(h):
    if(len(h)==1):
        print("Heap is empty...")
        return
    size=len(h)-1
    min=h[1]
    last=h[size]
    i=1
    while(i*2<=size):

        child=i*2
        if(child!=size and h[child+1].dist<h[child].dist):
            child=child+1
        if(last.dist > h[child].dist):
            h[i]=h[child]
        else:
            break;

        i=child

    h[i]=last
    h=h[:-1]
    return h,min
    
def djikstra(graph,start):
    pq=[node(0,start,start)]
    cost={vertex :[float('infinity'),start] for vertex in graph}
    #for vertex in graph:print(vertex)
    cost[start]=[0,start] #initialising distance of source vertex
    pq=buildHeap_c(pq)
    pq=insert_c(pq,node(0,start,start))
    #for v in pq:print(v)
    while(len(pq)>2):
        pq,n=deleteMin_c(pq)
        if(n.dist>cost[n.currnode][0]):continue
        for nearby,old_dist in graph[n.currnode].items():
            new_dist=n.dist+old_dist
            if(new_dist<cost[nearby][0]):
                cost[nearby][0]=new_dist
                cost[nearby][1]=n.currnode
                pq=insert_c(pq,node(new_dist,nearby,n.currnode))
    return cost

    





graph1={
    'a':{'b':3,'c':5,'d':4,},
    'b':{'a':3,'e':3,'f':6},
    'c':{'a':5,'d':5,'g':4},
    'd':{'a':4,'c':2,'e':1,'h':5},
    'e':{'b':3,'d':1,'f':2,'i':4},
    'f':{'b':6,'e':2,'j':5},
    'g':{'c':4,'h':3,'k':6},
    'h':{'d':5,'g':3,'i':6,'k':7},
    'i':{'e':4,'h':6,'j':3,'l':5},
    'j':{'f':5,'i':3,'l':9},
    'k':{'g':6,'h':7,'l':8},
    'l':{'i':5,'j':9,'k':8}
    
}
final_cost={}
final_cost=djikstra(graph1,'a')
print("DJIKSTRA ALGORITHM")
print("vertex\t distance\t previousvertex\n")
for val,key in final_cost.items():
    print(val,"\t",key[0],"\t",key[1])
    
    
