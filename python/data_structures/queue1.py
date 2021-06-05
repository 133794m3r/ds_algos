class Queue:
	class Node:
		def __init__(self, value, next_=None):
			self.value = value
			self.next = next_

	def __init__(self,values:iter=None,n:int=0):
		if values is None:
			self._first = None
			self._last = None
			self._size = 0
		else:
			self._first = self.Node(values[0])
			self._last = self._first
			for value in values:
				tmp = self.Node(value)
				self._last.next = tmp
				self._last = tmp
			self._size = len(values)

	def enqueue(self, value):
		if self._first is None:
			self._first = self.Node(value)
			self._last = self._first
		else:
			tmp = self.Node(value)
			self._last.next = tmp
			self._last = tmp
		self._size+=1

	def dequeue(self):
		if self._first is None:
			return None
		else:
			if self._first == self._last:
				self._last = None
			tmp = self._first
			self._first = self._first.next
			self._size -= 1
			return tmp.value
	def __repr__(self):
		os = "{\n"
		tmp = self._first
		for i in range(self._size):
			os += "| value:"
			os += tmp.value
			os += ", addr: "
			os += str(id(tmp.next))
			os += "|\t"
			tmp = tmp.next
		os += "\n}"

		return os
	def __len__(self):
		return self._size
if __name__ == '__main__':
	queue = Queue()
	queue.enqueue('a')
	queue.enqueue('b')
	queue.enqueue('c')
	v =  queue.dequeue()
	print(v)
	queue2 = Queue1("ABC", 3)
	print(queue)
	print(queue2)
	print(queue2.dequeue())

