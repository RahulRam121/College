import array,random,time,math

n_values1 = array.array('i',[100, 200, 300, 400, 500])
n_values2 = array.array('i',[300, 400, 500, 600, 700])
n_values3 = array.array('i',[100000, 200000, 300000, 400000, 500000])

#finding the max sequence sum by using brute-force 
def findMaxSequence1(arr):
	
	MaxSum = 0
	length = len(arr)

	for i in range(0,length):
		for j in range(i,length):
			ThisSum = 0
			for k in range(i,j+1):
				ThisSum += arr[k]
			if(ThisSum > MaxSum):
				MaxSum = ThisSum
    #print(MaxSum)	

#finding the max sequence sum by using dynamic programming
def findMaxSequence2(arr):
	
	MaxSum = 0
	length = len(arr)

	for i in range(0,length):
		ThisSum = 0
		for j in range(i,length):
			ThisSum += arr[j]
			if ThisSum > MaxSum:
				MaxSum = ThisSum
    #print(MaxSum)

#checking max sequence sum by third method
def findMaxSequence3(arr):

	MaxSum = ThisSum = 0

	for i in arr:
		ThisSum += i
		if MaxSum < ThisSum:
			MaxSum = ThisSum
		if ThisSum < 0:
			ThisSum = 0
	#print(MaxSum)	

def genRandomArray(n):
    r_arr = array.array('i',[])
    for i in range(0,n):
        #creating random numbers from -50 to 50
        rand = random.randrange(-50, 51)
        r_arr.append(rand)
    return r_arr

def printReport1(n_values):
    
    print("Brute-Force Examination")
    print("n_value\tT(n)\t\tlogn\t\tn\t\tn^2\t\tn^3\t\t2^n")    
    for n in n_values:        
        arr = genRandomArray(n)  
        time1 = 0
        for j in range(0,5):
            s_time = time.time()        
            findMaxSequence1(arr)
            e_time = time.time()    
            time1 += (e_time - s_time)
        time1 /= 5
        print("%d\t%.9E\t%.9E\t%.9E\t%.9E\t%.9E\t%.9E"%(n, time1, time1/(math.log(n,10)), time1/n, time1/(n*n), time1/(n*n*n), time1/(2^n)))
    print()
 
    
def printReport2(n_values):
    
    print("Dunamic Programming")
    print("n_value\tT(n)\t\tlogn\t\tn\t\tn^2\t\tn^3\t\t2^n")    
    for n in n_values:        
        arr = genRandomArray(n)  
        time1 = 0
        for j in range(0,5):
            s_time = time.time()        
            findMaxSequence2(arr)
            e_time = time.time()    
            time1 += (e_time - s_time)
        time1 /= 5
        print("%d\t%.4E\t%.4E\t%.4E\t%.4E\t%.4E\t%.4E"%(n, time1, time1/(math.log(n,10)), time1/n, time1/(n*n), time1/(n*n*n), time1/(2^n)))
    print()

    
def printReport3(n_values): 
    
    print("MaxSum without checking all sequence")
    print("n_value\tT(n)\t\tlogn\t\tn\t\tn^2\t\tn^3\t\t2^n")    
    for n in n_values:        
        arr = genRandomArray(n)  
        time1 = 0
        for j in range(0,5):
            s_time = time.time()        
            findMaxSequence3(arr)
            e_time = time.time()    
            time1 += (e_time - s_time)
        time1 /= 5
        print("%d\t%.7E\t%.7E\t%.7E\t%.7E\t%.7E\t%.7E"%(n, time1, time1/(math.log(n,10)), time1/n, time1/(n*n), time1/(n*n*n), time1/(2^n)))
    print()


printReport1(n_values1)
printReport2(n_values2)
printReport3(n_values3)