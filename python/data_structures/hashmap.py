class HashMap:
	class node:
		def __init__(self, value, prev=None, nxt = None):
			self.value = value
			self.next = nxt
			self.prev = prev
	
	def __init__(self):
		self._node_map = {}
		self._head = None
		self._tail = None

	def __repr__(self):
		string = 'self._node_map =>{'
		for key,value in self._node_map.items():
			string += f'( {key}: *{id(value)}), '
		string += '};\nself.values=>'
		cur = self._head
		while cur:
			string += f'id=*{id(cur)} node({cur.value},*{id(cur.prev)},*{id(cur.next)}), '
			cur = cur.next

		return string
	def __getitem__(self,key):
		return self._node_map[key].value
	
	def __setitem__(self,key,value):
		if self._node_map.get(key,False):
			self._node_map[key].value = value
		else:
			if self._head is None:
				self._head = self.node(value)
				self._tail = self._head
				self._node_map[key] = self._head
			else:
				node = self.node(value,self._tail)
				self._tail.next = node
				self._tail = self._tail.next
				self._node_map[key] = node


	def __delitem__(self,key):
		node = self._node_map.pop(key)
		if node.prev is not None:
			node.prev.next = node.next
		else:
			self._head = node.next


	def __contains__(self, key):
		return self._node_map.get(key,False) != False

if __name__ == "__main__":
	hm = HashMap()
	hm['a'] = 3
	hm['b'] = 4
	hm['c'] = 5
	del hm['c']
	del hm['a']
	print(hm)