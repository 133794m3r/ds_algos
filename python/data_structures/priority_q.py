class PriorityQueue:
	class Node:
		def __init__(self, val, priority):
			self.value = val
			self.priority=priority
		def __gt__(self, other):
			return self.priority > other.priority

		def __lt__(self, other):
			return not self.__gt__(other)

		def __eq__(self, other):
			return self.priority == other.priority

		def __ge__(self, other):
			return self.__gt__(other) or self.__eq__(other)

		# repr is just for debug purposes.
		def __repr__(self):
			return f'{self.value}:{self.priority}'

	def __init__(self):
		self._values = []
		self._size = 0

	def __len__(self):
		return self._size

	#def __str__(self):
	#	return { str(p): v for p,v in self._values }

	def __repr__(self):
		tmp = ''
		for i,v in enumerate(self._values):
			tmp += f'{v.value}:{v.priority}'
			if i < self._size:
				tmp += ', '
		return tmp

	def shift_up(self):
		idx = self._size - 1
		while idx > 0:
			parent = (idx -1) >> 1
			if self._values[idx] >= self._values[parent]: break
			self._values[parent], self._values[idx] = self._values[idx], self._values[parent]
			idx = parent

	def enqueue(self, value, priority):
		self._values.append(self.Node(value, priority))
		self._size += 1
		self.shift_up()

	def push(self,value,priority=0):
		self.enqueue(value,priority)
		
	def dequeue(self):
		highest = None
		if self._size > 1:
			highest = self._values[0]
			end = self._values.pop()
			self._values[0] = end
			self._size -= 1
			self.shift_down()
		elif self._size == 1:
			highest = self._values.pop()
			self._size = 0
		
		return highest
	
	def pop(self):
		return self.dequeue()
	
	def shift_down(self):
		idx = 0
		while True:
			swap_id = idx
			left = (idx << 1) + 1
			right = left+1
			if left < self._size:
				if self._values[left] < self._values[idx]:
					swap_id = left
			if right < self._size and self._values[swap_id] > self._values[right]:
						swap_id = right

			if swap_id == idx: break

			self._values[idx], self._values[swap_id] = self._values[swap_id], self._values[idx]
			idx = swap_id


if __name__ == "__main__":
	pq = PriorityQueue()
	#close enough to infinity for testing purposes.
	inf = (1<<64)-1
	pq.enqueue("a",0)
	pq.enqueue("b",inf)
	print(pq)
	pq.enqueue("c",inf)
	pq.enqueue("d",inf)
	pq.enqueue("e",inf)
	pq.enqueue("f",inf)
	print(pq)
	print(pq.dequeue())
	pq.enqueue("b",4)
	pq.enqueue("c",2)
	print(pq)
	pq.dequeue()
	pq.enqueue("d",4)
	print(pq._size)
	print(pq)
