# This is CAT-04 Final!
# Do NOT discuss this exercise with anyone during the exam
# Do NOT send your code or copy code from elsewhere
# You are free to dicuss the exercise after the exam is over!

u = [(1, 0), (3, 11), (9, 13), (12, 0), (16, 7)]
v = [(14, 0), (19, 3), (22, 18), (23, 3), (29, 13)]

# First version of merging two outlines
def merge1_outlines(u,v):
	i=j=k=0
	w=[]
	lu=len(u)
	lv=len(v)
	while i<lu and j<lv:
		if(u[i][0]<=v[j][0]):
			w.append(u[i])
			i=i+1
		else:
			w.append(v[j])
			j=j+1

	while i<lu:
		w.append(u[i])
		i=i+1

	while j<lv:
		w.append(v[j])
		j=j+1

	return w

# Seconf version of merging two outlines
def merge2_outlines(u,v):
	i=j=k=0
	w=[]
	lu=len(u)
	lv=len(v)
	while i<lu and j<lv:
		if(u[i][0]<=v[j][0]):
			m=max(u[i][1],v[j][1])
			t=(u[i][0],m)
			w.append(t)
			i=i+1
		else:
			m=max(u[i][1],v[j][1])
			t=(v[j][0],m)
			w.append(t)
			j=j+1

	while i<lu:
		w.append(u[i])
		i=i+1

	while j<lv:
		w.append(v[j])
		j=j+1

	return w

# Third and final version of merging two outlines
def merge3_outlines(u,v):
	'''Combines u and v from left to right with correct heights and no rerundant corners'''
	i=j=k=0
	w=[]
	lu=len(u)
	lv=len(v)
	while i<lu and j<lv:
		if(u[i][0]<=v[j][0]):
			m=max(u[i][1],v[j][1])
			t=(u[i][0],m)
			if w!=[]:
				if(w[-1][1]==m):
					if(w[-1][0]<u[i][0]):
						w.pop(-1)
			w.append(t)
			i=i+1
		else:
			m=max(u[i][1],v[j][1])
			t=(v[j][0],m)
			if w!=[]:
				if(w[-1][1]==m):
					if(w[-1][0]<v[j][0]):
						w.pop(-1)
			w.append(t)
			j=j+1

	while i<lu:		
		if w!=[]:
			if(w[-1][1]==u[i][1]):
				if(w[-1][0]<u[i][0]):
					w.pop(-1)		
		w.append(u[i])
		i=i+1

	while j<lv:
		if w!=[]:
			if(w[-1][1]==v[j][1]):
				if(w[-1][0]<v[j][0]):
					w.pop(-1)		
		w.append(v[j])
		j=j+1

	return w
  

# Here is the "main" function to construct an outline of given rectangles
def construct_outline(rs):
    '''constructs an outline of a list of rectangles'''
    if not rs:
        return []
    if len(rs)==1:
        return rs[0]

    mid = len(rs) // 2
    u = construct_outline(rs[:mid])
    v = construct_outline(rs[mid:])
    return merge3_outlines(u, v)

# As stated in the problem, a sample set of rectangles could be
rs = [ [(1,0),(5,11)], [(2,0),(7,6)], [(3,0),(9,13)], [(12,0),(16,7)], [(14,0),(25,3)], [(19,0),(22,18)], [(23,0),(29,13)], [(24,0),(28,4)] ]

# You may check the output produced
print(construct_outline(rs))