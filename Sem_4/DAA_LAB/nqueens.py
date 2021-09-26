from itertools import permutations

def nqueens(n):
    for s in permutations(n):
        print(s)
        if(n == len(set(s[i]+i for i in range(n))) == len(set(s[i]-i for i in range(n)))):
            
            yield s
            
            
nqueens(4)