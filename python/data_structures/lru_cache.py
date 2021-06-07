class LRUCache:
	class node:
		def __init__(self, key, value, prev=None, nxt=None):
			self.value = value
			self.key = key
			self.next = nxt
			self.prev = prev

		def __repr__(self):
			return f'node({self.key}, {self.value}, *{id(self.prev)}, *{id(self.next)})'

	def __init__(self,capacity):
		if capacity == 0:
			raise ValueError(f'Capacity must be >0 not {capacity}')
		self._node_map = {}
		self._head = None
		self._tail = None
		self._max_size = capacity

		self._cur_size = 0

	def __repr__(self):
		string = 'self._node_map =>{'
		for key, value in self._node_map.items():
			string += f'( {key}: *{id(value)}), '
		string += '};\nself.values=>'
		cur = self._tail
		while cur:
			string += f'id:*{id(cur)} {cur},'
			cur = cur.next

		return string

	def __move_head(self,node):
		node.next = None
		node.prev = self._head
		self._head.next = node
		self._head = node

	def __getitem__(self, key):
		node = self._node_map.get(key,None)
		if node is None:
			return None

		if self._head != node:
			self.__del_node(node)
			self.__move_head(node)
			self._cur_size+=1
		return node.value

	def get(self,key):
		return self.__getitem__(key)

	def __del_node(self, node):
		if not self._head:
			return

		if node.prev:
			node.prev.next = node.next
		if node.next:
			node.next.prev = node.prev

		if node.next is None and node.prev is None:
			self._head = None
			self._tail = None

		if self._tail == node:
			self._tail = node.next
			self._tail.prev = None
		self._cur_size -= 1

	def __setitem__(self, key, value):
		if self._node_map.get(key, False):
			self._node_map[key].value = value
		else:
			if self._head is None:
				self._head = self.node(key,value)
				self._tail = self._head
				self._node_map[key] = self._head
			else:
				node = self.node(key,value)
				if self._cur_size == self._max_size:
					del self._node_map[self._tail.key]
					self.__del_node(self._tail)
				self.__move_head(node)
				self._node_map[key] = node
			self._cur_size += 1

	def set(self,key,value):
		self.__setitem__(key,value)

	def __delitem__(self, key):
		node = self._node_map.pop(key)
		self.__del_node(node)
		self._cur_size -= 1
		return node.value

	def evict(self, key):
		return self.__delitem__(key)

	def __contains__(self, key):
		return self._node_map.get(key, False) != False


if __name__ == "__main__":
	lru = LRUCache(2)
	lru.set('a',3)
	lru.set('b',4)
	lru.get('a')
	print(lru)
	lru.set('c',4)
	print(lru)
	lru.set('d',5)
	print(lru)

