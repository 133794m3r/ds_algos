class BinarySearchTree:
	class Node:
		def __init__(self,value, left = None, right = None):
			self.value = value
			self.left = left
			self.right = right
		def __repr__(self):
			return f'{self.value} l->{self.left} r->{self.right}'
		
	_root = None
	def __init__(self):
		self._root = None

	def find(self,value):
		if self._root is None:
			return None
		cur = self._root
		found = False
		while (not found) and cur:
			if cur.value > value:
				cur = cur.left
			elif cur.value < value:
				cur = cur.right
			else:
				return cur
		else:
			return None

	def contains(self,value):
		cur = self._root
		while cur:
			if cur.value > value:
				cur = cur.left
			elif cur.value < value:
				cur = cur.right
			else:
				return True
		else:
			return False

	def insert(self,value):
		if self._root is None:
			self._root = self.Node(value)
			return
		else:
			cur = self._root
			while cur:
				if cur.value > value:
					if cur.left:
						cur = cur.left
					else:
						cur.left = self.Node(value)
						return
				elif cur.value < value:
					if cur.right:
						cur = cur.right
					else:
						cur.right = self.Node(value)
						return
				else:
					return
	def _height(self,node):
		if node is None:
			return 0
		else:
			x = self._height(node.left)
			y = self._height(node.right)
			return x>y and x+1 or y+1

	def get_height(self):
		return self._height(self._root)

	def _remove(self, node, key):
		if node is None:
			return None
		if (node.left == None) and (node.left == node.right):
			if node == self._root:
				self._root = None
				return None

			return None
		if key < node.value:
			node.left = self._remove(node.left, key)
		elif key > node.value:
			node.right = self._remove(node.right, key)
		else:
			if self._height(node.left) > self._height(node.right):
				q = node.left
				while q.right and (node.right is not None):
					q = q.right
				node.value = q.value
				node.left = self._remove(node.left, q.value)
			else:
				q = node.right		
				while q.left and (node.left is not None):
					q = q.left

				node.value = q.value
				node.right = self._remove(node.right, q.value)
		return node

	def bfs(self):
		cur = self._root
		queue = []
		data = []
		queue.append(self._root)
		while len(queue):
			cur = queue.pop(0)
			data.append(cur.value)
			if cur.left: queue.append(cur.left)
			if cur.right: queue.append(cur.right)
		return data

	def pre_traverse(self,data, node):
		data.append(node.value)
		if node.left:
			self.pre_traverse(data, node.left)
		if node.right:
			self.pre_traverse(data, node.right)

	def in_traverse(self, data, node):
		if node.left: self.in_traverse(data, node.left)
		data.append(node.value)
		if node.right: self.in_traverse(data, node.right)

	def post_traverse(self, data, node):
		if node.left: self.post_traverse(data, node.left)
		if node.right: self.post_traverse(data, node.right)
		data.append(node.value)

	def pre_order(self):
		cur = self._root
		data = []
		self.pre_traverse(data, cur)
		return data

	def in_order(self):
		cur = self._root
		data = []
		self.in_traverse(data, cur)
		return data

	def post_order(self):
		cur = self._root
		data = []
		self.post_traverse(data, cur)
		return data

	def remove(self,key):
		return self._remove(self._root, key)

if __name__ == '__main__':
	bst1 = BinarySearchTree()
	"""
	bst1.insert(3)
	bst1.insert(4)
	bst1.insert(5)
	bst1.insert(6)
	bst1.insert(7)
	bst1.insert(8)
	tmp = bst1.bfs()
	print("bfs",tmp)
	dfs = bst1.pre_order()
	print("pre_order",dfs)
	print("in order", bst1.in_order())
	print("post order",bst1.post_order())
	bst1.remove(8)
	print(bst1.contains(3))
	print(bst1.find(3))
	print(bst1.get_height())
	print("pre order -- after removal",bst1.pre_order())
	"""
	bst1.insert(7)
	bst1.insert(6)
	bst1.insert(4)
	bst1.insert(5)
	bst1.insert(3)
	bst1.remove(3)
	print(bst1.in_order())
