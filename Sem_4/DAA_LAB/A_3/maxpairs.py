import time,random

n = [1000, 2000, 3000, 10000]

#countPairs1 follows bubblesort algorithm
def countPairs1(arr):
	
	count = 0;
	length = len(arr)
	for i in range(0,length):
		for j in range(i,length):
			if(arr[i] > arr[j]):
				count+=1;
	return count;

#countPairs2 follows mergesort algorithm
def countPairs2(arr, n): 
    temp_arr = [0]*n 
    return mergeSort(arr, temp_arr, 0, n-1) 
  
def mergeSort(arr, temp_arr, left, right): 
  
    count = 0
  
    if left < right: 
  
        mid = (left + right)//2
  
        count += mergeSort(arr, temp_arr, left, mid)   
        count += mergeSort(arr, temp_arr, mid + 1, right) 
        count += merge(arr, temp_arr, left, mid, right) 
        
    return count 
  
def merge(arr, temp_arr, left, mid, right): 
    i = left     
    j = mid + 1  
    k = left     
    count = 0
  
    while i <= mid and j <= right: 
  
        if arr[i] <= arr[j]: 
            temp_arr[k] = arr[i] 
            k += 1
            i += 1
        else: 
            temp_arr[k] = arr[j] 
            count += (mid-i + 1) 
            k += 1
            j += 1
            
    while i <= mid: 
        temp_arr[k] = arr[i] 
        k += 1
        i += 1
  
    while j <= right: 
        temp_arr[k] = arr[j] 
        k += 1
        j += 1
  
    for loop_var in range(left, right + 1): 
        arr[loop_var] = temp_arr[loop_var] 
          
    return count



print("Size\tMethod\t\tNo_of_pairs\tT(n)")
li = []

for value in n:
    
    #creating array of random numbers
    arr = random.sample(range(1, value+1), value)
    
    start = time.time()
    inversions = countPairs1(arr)
    ttime = time.time() - start
    print("%d\tBubble_sort\t%11d\t%f"%(value,inversions,ttime))
        
    start = time.time()
    inversions = countPairs2(arr, len(arr))
    ttime = time.time() - start
    print("%d\tmerge_sort\t%11d\t%f"%(value,inversions,ttime))

print()
print("Time COmplexity of Bubble_sort algorithm is O(n^2)")
print()
print("Time COmplexity of Merge_sort algorithm is O(nlogn)")
