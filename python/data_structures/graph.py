class Graph:
	def __init__(self):
		self.adj_lists = dict()
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

	def dfs(self,start):
		stack = [start]
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


