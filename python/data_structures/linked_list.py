#!/bin/env python3
"""
Python already has a Doubly linked-list in it's list class but I decided to write my own
anyways.
"""

class LinkedList:
	class Node:
		def __init__(self, value_=None, ref_=None):
			self.value = value_
			self.ref = ref_

		def __str__(self):
			return f"{self.value}"

		def __repr__(self):
			# this isn't a true repr as Node can't be called outside of this class but it's good for debugging.
			return "Node({!r}, {!r})".format(self.value, self.ref)

	def __init__(self,values = None):
		self._head = None
		self._length = 0
		self._tail = None
		if values:
			self._head = self.Node(values[0])
			cur = self._head
			for value in values[1:]:
				tmp = self.Node(value)
				cur.ref = tmp
				cur = cur.ref
			self._tail = cur
			self._length = len(values)

	def __str__(self):
		cur = self._head
		output = "["
		while cur:
			output += str(cur)
			cur = cur.ref
			if cur is not None:
				output += ", "


		output += "]"
		return output

	def __repr__(self):
		# Will actually make one later on.
		return repr(self._head)


	def __reversed__(self):
		cur = self._head
		self._tail = cur
		prev = None
		while cur is not None:
			ref = cur.ref
			cur.ref = prev
			prev = cur
			cur = ref

		self._head = prev

	def __len__(self):
		return self._length

	def push(self, value):
		if self._head is None:
			self._head = self.Node(value)
			self._tail = self._head
		else:
			cur = self._head
			while cur.ref is not None:
				cur = cur.ref
			cur.ref = self.Node(value)

			self._tail = cur.ref

		self._length += 1

	def pop(self):
		if self._head is None:
			return None
		popped = self._tail.value			
		if self._length > 1:
			prev = self.get(self._length-2)
			self._tail=prev
			self._tail.ref = None
		else:
			self._tail = None
		self._length-=1
		return popped

	def get(self, idx):
		#if idx < 0 or  idx > self._length:
		if 0 > idx > self._length:
			return None
		cur = self._head
		for i in range(idx):
			cur = cur.ref

		return cur

	def insert(self, idx, value):
		if 0 < idx or idx > self._length:
			return None
		elif self._head is None:
			self._head = self.Node(value)
		elif idx == self._length:
			self.push(value)
		elif idx == 0:
			self._head = self.Node(value, self._head)
		elif idx == self._length:
			self.push(value);
		else:
			prev = self.get(idx - 1)
			prev.ref = self.Node(value, prev.ref)
			#prev.ref = p
			#if idx == self._length:
				#self._tail = p

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
			self._head = tmp.ref
			self._length -= 1
			if self._length == 0:
				self._tail = None
			return tmp;
		else:
			return None

	def unshift(self, value):
		if self._head:
			self._head = self.Node(value, self._head)
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
			remove = prev.ref
			prev.ref = remove.ref
			self._length-=1


	def rev(self):
		self.__reversed__()


if __name__ == "__main__":
	ll = LinkedList([1,2,3])
	ll.push(4)
	print(len(ll))
	print(ll)
	print(ll.get(len(ll)-2))
	ll.pop()
	print(ll)
	ll.remove(1)
	print(ll)
