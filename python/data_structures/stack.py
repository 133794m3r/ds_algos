class Stack:
	class Node:
		def __init__(self,val, nxt=None):
			self.value = val
			self.next = nxt

	def __str__(self):
		output = "{"
		tmp = self._first
		for i in range(self._size):
			output += f"|value:{tmp.value} next:{tmp.next} |"
			if i < self._size -1:
				output+=', '
			tmp = tmp.next
		output+= "}"
		return output

	def __init__(self,items=None):
		if items is None:
			self._first = None
			self._last = None
			self._size = 0
		else:
			self._first = self.Node(items[0])
			self._last = self._first
			for item in items[1:]:
				self._first = self.Node(item, self._first)
			self._size = len(items)
	def push(self, value):
		if self._first is None:
			self._first = self.Node(value)
			self._last = self._first
		else:
			self._first = self.Node(value,self._first)
		self._size += 1

	def pop(self):
		if self._first is None:
			return 0
		if self._first == self._last:
			last_ = None
		tmp = self._first.value
		self._first = self._first.next
		self._size -= 1
		return tmp



def main():
	stack = Stack()
	stack.push('A')
	stack.push('B')
	stack.push('C')
	popped = stack.pop()
	print(popped)
	print(stack)
	stack2 = Stack(('A','B','C'))
	print(stack2)

if __name__ == "__main__":
	main()