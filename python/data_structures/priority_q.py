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

	def __init__(self):
		self._values = []
		self._size = 0

	def __str__(self):
		return { str(p): v for p,v in self._values }

	def __repr__(self):
		tmp = ''
		for i,v in enumerate(self._values):
			tmp += f'{v.val}:{v.priority}'
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


	def dequeue(self):
		highest = None
		if self._size > 0:
			highest = self._values[0]
			end = self._values.pop()
			self._values[0] = end
			self._size -= 1
			self.shift_down()

		return highest

	def shift_down(self):
		el = self._values[0]
		idx = 0
		heap_size = self._size
		while idx < heap_size:
			swap_id = idx
			left = (idx << 1) + 1
			right = left+1
			if left < self._size:
				if self._values[left] < el:
					swap_id = left
			if right < self._size and self._values[swap_id] < self._values[right]:
						swap_id = right

			if swap_id == idx: break

			self._values[idx], self._values[swap_id] = self._values[swap_id], el
			idx = swap_id
