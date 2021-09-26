from minheap import MinHeap

heap = MinHeap()
for i in range(10,1,-1):
	heap.insert(i)

print(heap.items)
