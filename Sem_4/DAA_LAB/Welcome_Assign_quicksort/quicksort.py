def qsort(mySeq):
    l_arr = list(mySeq)
    quickSort(l_arr, 0, len(mySeq) - 1)        
    if type(mySeq) == tuple:
        return tuple(l_arr)
    else:
        return list(l_arr)

def quickSort(arr, low, high):
    
    if(low >= high):        
        return
    
    p_1, p_2 = doPartition(arr, low, high)
    quickSort(arr, low, p_1-1)
    quickSort(arr, p_2+1, high)
        
    
def doPartition(arr, low, high):
    
    j = low
    k = high
    pivot = arr[low]
    i = j
    
    while i <= k:
        
        if arr[i] < pivot:
            arr[j], arr[i] = arr[i], arr[j]
            j += 1
        
        elif arr[i] > pivot:
            arr[k], arr[i] = arr[i], arr[k]
            k -= 1
            i -= 1
        i += 1
    return j, k


mySeq = [6,3,5,2,8,9]
print(qsort(mySeq))
            