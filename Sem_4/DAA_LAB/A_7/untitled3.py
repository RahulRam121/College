from Node import Node
class MinHeap:
    def __init__(self):
        self.items = [Node]
        
    def size(self):
    	return len(self.items)

    def parent(self, i):
    	return (i - 1) //2

    def left(self, i):
    	return 2 * i + 1
    
    def right(self, i):
    	return 2 * i + 2

    def get(self, i):
    	return self.items[i].dist
    
    def get_min(self):
        if self.size() == 0:
                return None
        return self.items[0].dist
        
    def min_heapify(self, i):
        l = self.left(i)
        r = self.right(i)
        if (l <= self.size() - 1 and self.get(l) < self.get(i)):
            smallest = l
        else :
            smallest = i
        if (r <= self.size() - 1 and self.get(r) < self.get	(smallest)):
            smallest = r
        if (smallest != i):
            self.swap(smallest, i)
            self.min_heapify(smallest)

    def swap(self, i, j):
	    self.items[i], self.items[j] = self.items[j], self.items[i]

    def insert(self, key):
        index = self.size()
        self.items.append(key)
        while (index != 0):
            p = self.parent(index)
            if self.get(p) > self.get(index):
                self.swap(p, index)
            index = p

    def delete_min(self):
        if self.size() == 0:
            return None
        smallest = self.get_min()
        self.items[0] = self.items[-1]
        del self.items[-1]
        self.max_heapify(0)
        return self.min_heapify(0)
        return smallest
