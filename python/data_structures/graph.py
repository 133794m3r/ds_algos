import queue1
class Graph:
	def __init__(self):
		self.adj_lists = {}
		self.vertexes = 0

	def __str__(self):
		return str(self.adj_lists)

	def add_vertex(self,vertex):
		if not self.adj_lists.get(vertex,False):
			self.adj_lists[vertex] = []
			self.vertexes +=1

	def add_edge(self,src,dest):
		if dest in self.adj_lists[src]:
			return
		self.adj_lists[src].append(dest)
		self.adj_lists[dest].append(src)

	def remove_edge(self,v1,v2):
		self.adj_lists[v1].remove(v2)
		self.adj_lists[v2].remove(v1)

	def remove_vertex(self,v1):
		x = self.adj_lists[v1]
		while self.adj_lists[v1]:
			v2 = self.adj_lists[v1][0]
			self.remove_edge(v1,v2)
		self.adj_lists.pop(v1)
		self.vertexes -=1

	def dfs(self,start,visited=None):
		stack = [start]
		if visited is None:
			visited = {start: 1}
		result = []
		while stack:
			current = stack.pop()
			result.append(current)
			for neighbor in self.adj_lists[current]:
				if not visited.get(neighbor):
					stack.append(neighbor)
					visited[neighbor] = 1

		return result

	def valid_path(self,start,end):
		result = self.dfs(start)
		if end in result:
			return True
		else:
			return False

	def sections(self):
		components = 0
		visited = {k:False for k in self.adj_lists.keys()}
		for vertex in self.adj_lists.keys():
			if not visited[vertex]:
				components += 1
				self.dfs(vertex,visited)
		return components

	def bfs(self,s,t):
		n = len(self.adj_lists)
		distances = {k:n for k in self.adj_lists.keys()}
		distances[s] = 0
		q = queue1.Queue()
		q.enqueue(s)
		while len(q):
			v = q.dequeue()
			for u in self.adj_lists[v]:
				if distances[u] == n:
					q.enqueue(u)
					distances[u] = distances[v] + 1

		return -1 if distances[t] == n else distances[t]

	def is_bipartite(self,start=None):
		#bugged
		visited = {}
		partition = {}
		if start is None:
			start = list(self.adj_lists.keys())[0]
		for k in self.adj_lists.keys():
			visited[k] = False
			partition[k] = -1

		visited[start] = True
		partition[start] = 0
		q = queue1.Queue()
		q.enqueue(start)
		while len(q):
			v = q.dequeue()
			for u in self.adj_lists[v]:
				if partition[u] == partition[v]:
					return 0
				else:
					if not visited[u]:
						visited[u] = True
						partition[u] = 1 - partition[v]
						q.enqueue(u)
		return 1

if __name__ == '__main__':
	g = Graph()
	g.add_vertex('a')
	g.add_vertex('b')
	g.add_vertex('c')
	g.add_vertex('d')
	g.add_vertex('e')
	g.add_vertex('f')
	g.add_edge('a','b')
	g.add_edge('a','c')
	g.add_edge('b','d')
	g.add_edge('c','e')
	g.add_edge('d','e')
	g.add_edge('d','f')
	g.add_edge('e','f')
	print(g)
	g.remove_vertex('b')
	print(g)
	print(g.dfs('a'))
	g = Graph()
	g.add_vertex('a')
	g.add_vertex('b')
	g.add_vertex('c')
	g.add_vertex('d')
	g.add_edge('a','b')
	g.add_edge('c','b')
	print('vp',g.valid_path('a','d'))
	print('sections',g.sections())
	g.add_edge('a','d')
	print('vertices_passed',g.bfs('b','d'))
	print('bipartite',g.is_bipartite('a'))
