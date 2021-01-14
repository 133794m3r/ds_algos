class MaxBinaryHeap:
	def __init__(self):
		self._values = []
		self._size = 0

	def shift_up(self):
		idx = self._size
		item = self._values[self._size]
		while idx > 0:
			parent_idx = (idx -1) >> 1
			parent = self._values[parent_idx]
			if item <= parent: break
			self._values[parent_idx], self._values[idx] = item, parent
			idx = parent_idx

	def shift_down(self):
		el = self._values[0]
		idx = 0
		heap_size = self._size
		while idx < heap_size:
			swap_id = idx
			left = (idx << 1) + 1
			right = left+1
			if left < self._size and  self._values[left] < el:
				swap_id = left
			if right < self._size and self._values[swap_id] < self._values[right]:
				swap_id = right

			if swap_id == idx: break

			self._values[idx], self._values[swap_id] = self._values[swap_id], el
			idx = swap_id

	def insert(self,element):
		self._values.append(element)
		self._size += 1
		self.shift_up()

	def get_max(self):
		removed = None
		if self._size > 0:
			removed = self._values[0]
			end = self._values.pop()
			self._values[0] = end
			self._size -= 1
			self.shift_down()
		
		return removed

	def max(self):
		if self._size > 0:
			return self._values[0]
		else:
			return None

