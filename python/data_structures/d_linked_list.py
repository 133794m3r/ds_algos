"""
Doubly linked list version. Just for coding practice.
"""

class DoublyLinkedList:
	class Node:
		def __init__(self, value_=None, prev=None,nxt=None):
			self.value = value_
			self.prev = prev
			self.nxt = nxt

		def __str__(self):
			return f"{self.value}"

		def __repr__(self):
			# this isn't a true repr as Node can't be called outside of this class but it's good for debugging.
			return "Node({!r}, {!r}, {!r})".format(self.value, self.prev, self.nxt)

	def __init__(self,values = None):
		self._head = None
		self._length = 0
		self._tail = None
		if values:
			self._head = self.Node(values[0])
			cur = self._head
			for value in values[1:]:
				tmp = self.Node(value, cur)
				cur.nxt = tmp
				cur = cur.nxt

			self._tail = cur
			self._length = len(values)

	def __str__(self):
		cur = self._head
		output = "["
		while cur:
			output += str(cur)
			cur = cur.nxt
			if cur is not None:
				output += ", "


		output += "]"
		return output

	# def __repr__(self):
	# 	# Will actually make one later on.
	# 	//return repr(self._head)



	def __reversed__(self):
		cur = self._head
		self._head = self._tail
		self._tail =cur
		prev = None
		nxt = None
		while cur is not None:
			nxt  = cur.nxt
			cur.nxt = prev
			cur.prev = nxt
			prev = cur
			cur = nxt


	def __len__(self):
		return self._length

	def push(self, value):
		if self._head is None:
			self._head = self.Node(value)
			self._tail = self._head
		else:
			p = self.Node(value,self._tail)
			self._tail.nxt = p
			self._tail = p

		self._length += 1

	def pop(self):
		if self._head is None:
			return -1
		popped = self._tail
		if self._length == 1:
			self._head = self._tail = None
		else:
			self._tail=popped.prev
			self._tail.nxt = None

		self._length-=1
		return popped.value

	def get(self, idx):
		if idx < 0 or  idx > self._length:
			return None
		cur = self._head
		# for i in range(idx):
		# 	cur = cur.nxt
		if idx <= (self._length//2):
			i = 0
			while i != idx:
				cur = cur.nxt
				i+=1
		else:
			i = self._length - 1
			cur = self._tail
			while i != idx:
				cur = cur.prev
				i-=1
		return cur

	def insert(self, idx, value):
		if 0 > idx > self._length:
			return None
		elif self._head is None:
			self._head = self.Node(value)
		elif idx == self._length:
			self.push(value)
		elif idx == 0:
			self._head = self.Node(value, self._head)
		else:
			cur = self.get(idx)
			# need 2 pointers since Python doesn't actually
			# update the pointers the way you'd think it would.
			old_prev = cur.prev
			new_node = self.Node(value, old_prev, cur)
			old_prev.nxt = new_node
			cur.prev = new_node


		self._length += 1

	def set(self, idx, value):
		if self._length > idx < 0:
			return None
		else:
			p = self.get(idx)
			p.value = value

	def shift(self):
		if self._head:
			tmp = self._head
			self._head = tmp.nxt
			self._head.prev = None
			self._length -= 1
			if self._length == 0:
				self._tail = 0
		else:
			return None

	def unshift(self, value):
		if self._head:
			self._head = self.Node(value, None, self._head)
		else:
			self._head = self.Node(value)
			self._tail = self._head

	def remove(self, idx):
		if idx  < 0 or idx > self._length:
			return None
		if idx == self._length - 1:
			self.pop()
		elif idx == 0:
			self.shift()
		else:
			prev = self.get(idx-1)
			remove = prev.nxt
			prev.nxt = remove.nxt
			self._length-=1


	def rev(self):
		self.__reversed__()



if __name__ == "__main__":
	ll = DoublyLinkedList()
	ll.push(4)
	ll.push(5)
	ll.push(6)
	ll.insert(2,222)
	ll.push(7)
	ll.push(8)
	ll.push(9)
	ll.push(10)
	ll.rev()
	ll.pop()
	ll.set(2,100)
	ll.insert(5,555)
	ll.insert(4,444)
	ll.shift()
	ll.unshift(6)
	ll.remove(5)
	print(ll)
