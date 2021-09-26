# This is a trial exam for CAT-04. Not graded.

# For your convenience, a simple implementation of graph structures
# is provided below.  Your implementation starts at line 171.

# We start with a structure for a vertex
class Vertex:
    """Provides vertex (node) structure for a graph"""

    __slots__ = '_label'

    def __init__(self, obj):
        """Constructor to create a Vertex"""
        self._label = obj

    def label(self):
        """Returns the object associated with the vertex"""
        return self._label

    def __str__(self):
        """This is just for the purpose of printing"""
        return str(self._label)

    def __hash__(self):
        """This allows a vertex to be a key in dict or set"""
        return hash(id(self))

# We now define a simple structure for an edge
class Edge:
    """Provides edge structre for a graph"""

    __slots__ = '_origin', '_destination', '_label'

    def __init__(self, u, v, obj):
        """Constructor for an edge"""
        self._origin = u
        self._destination = v
        self._label = obj

    def endpoints(self):
        """Returns (u,v), the vertices related by this edge"""
        return (self._origin, self._destination)

    def opposite(self, v):
        """Given a vertex, returns the other end of the edge"""
        if (v == self._origin):
            return self._destination
        elif (v == self._destination):
            return self._origin
        else:
            return None

    def label(self):
        """Returns the label (weight) of this edge"""
        return self._label

    def __str__(self):
        """This is just for printing"""
        return '(' + str(self._origin) + ',' + str(self._destination) + ',' + str(self._label) + ')'

    def __hash__(self):
        """An edge may be used as a key"""
        return hash( (self._origin, self._destination) )

# We are now ready for the Graph structure
# Here is a simple implementation based on adjacency map
class Graph:
    """Representation of a graph using adjacency map"""

    def __init__(self, directed=False):
        """Constructor for a graph.
           By default, an undirected graph is created,
           in which case one adjacency map is sufficient.
           If 'directed' parameter is true, then a directed
           graph is created.  For each vertex, two adjacency
           maps are maintained, one for outgoing edges, and the
           other for incoming edges.
        """
        self._outgoing = {}
        self._incoming = {} if directed else self._outgoing

    def __str__(self):
        """This is just for printing"""
        res = '(V={'
        for v in self.vertices():
            res = res + str(v) + ','
        res = res + '}, E={'
        for e in self.edges():
            res = res + str(e) + ','
        res = res + '})'
        return res

    def is_directed(self):
        return self._incoming is not self._outgoing

    def vertex_count(self):
        return len(self._outgoing)

    def vertices(self):
        return self._outgoing.keys()

    def edge_count(self):
        total = sum(len(self._outgoing[v]) for v in self._outgoing)
        return total if self.is_directed() else total // 2

    def edges(self):
        result = set()
        for adj_map in self._outgoing.values():
            result.update(adj_map.values())
        return result

    def get_edge(self, u, v):
        return self._outgoing[u].get(v)

    def degree(self, v, outgoing=True):
        adj = self._outgoing if outgoing else self._incoming
        return len(adj[v])

    def incident_edges(self, v, outgoing=True):
        adj = self._outgoing if outgoing else self._incoming
        for edge in adj[v].values():
            yield edge

    def insert_vertex(self, obj=None):
        v = Vertex(obj)
        self._outgoing[v] = {}
        if self.is_directed():
            self._incoming[v] = {}
        return v

    def find_vertex(self, obj):
        for v in self.vertices():
            if (v.label() is obj):
                return v
        return None

    def insert_edge(self, u, v, obj=None):
        e = Edge(u, v, obj)
        self._outgoing[u][v] = e
        self._incoming[v][u] = e
        return e

# Here is a helper function which may be useful
def gen_graph_from_lists(lv:list, le:list, directed:bool=False) -> (Graph,Vertex,Vertex):
    """
    Generates and returns a graph with source and sink vertices
    
    lv: List of vertex labels
        The first vertex is assumed to be the source and
        second one to be the sink
    le: List of tuples of the form (u,v,w) representing edges with weights
    directed: generate directed or undirected graph
              (by default, undirected graph is generated)
    """
    
    G = Graph(directed)

    V = dict()
    for v in lv:
        V[v] = G.insert_vertex(v)

    for (u,v,w) in le:
        G.insert_edge(V[u], V[v], w)

    return (G,V[lv[0]],V[lv[1]])

# Here is an illustration of how a flow graph may be generated
G1,s,t = gen_graph_from_lists(['s','t','u','v'], [('s','u',20),('s','v',10),('u','v',30),('u','t',10),('v','t',20)],directed=True)
print(G1)

# Now, you can start with your implementation of Ford-Fulkerson algorithm
# You may start with a few helper functions

def BFS(G,s, t, parent):
       
    visited = {}    
    queue = []
            
    queue.append(s)
    visited[s] = True
       
   
    while queue:     
        u = queue.pop(0)
            
        for edge in G.incident_edges(u):
            if(visited.get(edge.endpoints()[1], False) == False and edge.label() > 0):
                visited[edge.endpoints()[1]] = True
                queue.append(edge.endpoints()[1])
                parent[edge.endpoints()[1]] = u
                       
    return True if visited.get(t, False) else False

# And finally implement the 'main' function
def maxflow(g:Graph, s:Vertex, t:Vertex) -> int:
    
    lv = [v.label() for v in g.vertices()]
    le = [(e.endpoints()[0].label(), e.endpoints()[1].label(), e.label()) for e in g.edges()]
      
    # creating residual graph 
    R_graph, s, t = gen_graph_from_lists(lv, le,directed=True)
    #parent stores the information about the parent nodes.
    parent = {}
 
    max_flow = 0 # There is no flow initially
 
    # Augment the flow while there is path from source to sink
    while BFS(R_graph, s, t, parent) :
 
        # Find minimum residual capacity of the edges along the
        # path filled by BFS. Or we can say find the maximum flow
        # through the path found.
        path_flow = float("Inf")
        v = t
        #finding the minimum path flow through the path
        while(v !=  s):
            path_flow = min(path_flow, R_graph.get_edge(parent[v], v).label())
            v = parent[v]
 
        # Add path flow to overall flow
        max_flow +=  int(path_flow)
 
        # update residual capacities of the edges and reverse edges
        # along the path
        v = t
        while(v !=  s):
           
            u = parent[v]
            e = R_graph.get_edge(u, v)
           
            R_graph.insert_edge(u, v, e.label() - path_flow)
            e = R_graph.get_edge(v, u)
            if(e == None):
                R_graph.insert_edge(v, u, path_flow)
            else:
                R_graph.insert_edge(v, u, e.label() + path_flow)
            v = parent[v]
 
    return max_flow

# The following call should print the correct maxflow value (30) of G1
print(maxflow(G1,s,t))