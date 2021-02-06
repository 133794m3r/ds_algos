from priority_q import PriorityQueue
class WeightedGraph:
	class edge:
		def __init__(self,node,weight):
			self.node = node
			self.weight = weight

		# repr is just for debug purposes.
		def __repr__(self):
			return f'{{ "node":{self.node},"weight":{self.weight} }}'

	def __init__(self):
		self.adj_lists = dict()
		self.vertexes = 0

	def __str__(self):
		return str(self.adj_lists)

	def add_vertex(self,vertex):
		if not self.adj_lists.get(vertex,False):
			self.adj_lists[vertex] = []
			self.vertexes +=1

	def add_edge(self,src,dest,weight):
		for edge in self.adj_lists[src]:
			if edge.node == dest:
				return
		self.adj_lists[src].append(self.edge(dest,weight))
		self.adj_lists[dest].append(self.edge(src,weight))

	def remove_edge(self,v1,v2):
		for idx in range(self.adj_lists[v1].length):
			if self.adj_lists[v1][idx].node == v2:
				del self.adj_lists[v1][idx]
				break
		for idx in enumerate(self.adj_lists[v1].length):
			if self.adj_lists[v1][idx].node == v2:
				del self.adj_lists[v1][idx]
				break


	def remove_vertex(self,v1):
		while self.adj_lists[v1]:
			tmp = self.adj_lists[v1][0]
			self.remove_edge(v1,tmp.node)
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


	def shortest_path(self,start,finish):
		nodes = PriorityQueue()
		distances = {}
		previous = {}
		# close enough to infinity for this purposes.
		infinity = 1<<64
		path = []
		smallest = None
		for vertex in self.adj_lists.keys():
			if vertex == start:
				distances[vertex] = 0
				nodes.enqueue(vertex,0)
			else:
				distances[vertex] = infinity
				nodes.enqueue(vertex,infinity)
			previous[vertex] = None

		while len(nodes):
			smallest = nodes.dequeue().value
			if smallest == finish:
				while previous[smallest]:
					path.append(smallest)
					smallest = previous[smallest]
				break
			if smallest or distances[smallest] != infinity:
				for neighbor in self.adj_lists[smallest]:
					candidate = distances[smallest] + neighbor.weight
					next_neighbor = neighbor.node
					if candidate < distances[next_neighbor]:
						distances[next_neighbor] = candidate
						previous[next_neighbor] = smallest
						nodes.enqueue(next_neighbor, candidate)

		path.reverse()
		return [smallest]+path


if __name__ == "__main__":
	graph = WeightedGraph()
	graph.add_vertex("a")
	graph.add_vertex("b")
	graph.add_vertex("c")
	graph.add_vertex("d")
	graph.add_vertex("e")
	graph.add_vertex("f")
	graph.add_edge("a","b", 4)
	graph.add_edge("a","c", 2)
	graph.add_edge("b","e", 3)
	graph.add_edge("c","d", 2)
	graph.add_edge("c","f", 4)
	graph.add_edge("d","e", 3)
	graph.add_edge("d","f", 1)
	graph.add_edge("e","f", 1)

	print(graph.shortest_path("a", "f"))
