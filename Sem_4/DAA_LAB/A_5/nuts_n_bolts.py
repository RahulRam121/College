import array as arr
import random

#function to generate array of random numbers
def genRandomArray(n):
	r_arr = arr.array('i',[])
	while (len(r_arr) < n):
		check = 0
		#creating random numbers from 1 to n*n
		rand = random.randrange(1, n*n)
		for j in range(len(r_arr)):
			if rand == r_arr[j]:
				check = 1
		if check == 0:
			r_arr.append(rand)
	return r_arr

#function to shuffle the nuts array to produce bolts array
def modArrayRandom(nuts):
	bolts = arr.array('i',[])
	for i in range(len(nuts)):
		bolts.append(nuts[i])
	random.shuffle(bolts)
	return bolts

#brute force approach to match nuts and bolts
def matchNuts_n_Bolts(nuts, bolts):
	match = {}
	for i in range(len(nuts)):
		for j in range(len(nuts)):
			if nuts[i] == bolts[j]:
				match[i] = j;
	return match
          
#partition function position the pivot in the correct position and return its index    
def partition(tool, low, high, pivot): 
    i = high
    check = 0
    j = 0
    while j <= high and j!=i:
        if check == 0:
            if tool[j] > pivot:
                tool[j], tool[i] = tool[i], tool[j]
                j -= 1
                i -= 1
            elif tool[j] == pivot:
                check = 1
                i = j
        else:
            if tool[j] < pivot:
                tool[j], tool[i] = tool[i], tool[j]
                if j-i != 1:
                    i+=1
                    tool[j], tool[i] = tool[i], tool[j]
                else:
                    i+=1
        j += 1
    return i

#doPartition functoin acts as intermediate between partition and quicksort by providing nuts and bolts array
#separately to partition function
def doPartition(nuts, bolts, low, high):
    pivot = bolts[high]
    pi = partition(nuts, low, high, pivot)
    pi = partition(bolts, low, high, pivot)
    return pi
    
#quicksort function to sort both the array
def quickSort(nuts, bolts, low, high): 
    if low < high: 
        pi = doPartition(nuts, bolts, low, high) 
        quickSort(nuts, bolts, low, pi-1) 
        quickSort(nuts, bolts, pi+1, high)
                    
#length of the array to be genrated
n = int(input("Enter the length of the array :"))
nuts = genRandomArray(n)
bolts = modArrayRandom(nuts)
print("Random array for nuts :")
print(nuts.tolist())
print("Shuffled array for bolts:")
print(bolts.tolist())

match = matchNuts_n_Bolts(nuts, bolts)
print("Dictionary :{index of nut : matching bolt index}")
print(match)

quickSort(nuts, bolts, 0, n-1)
print("Bolts and nuts after sorted using quicksort :")
print(nuts.tolist())
print(bolts.tolist())