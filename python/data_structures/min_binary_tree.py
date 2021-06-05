class MinBinaryTree:
	class Node:
		def __init__(self,value,left=None,right=None):
			self.value = value
			self.left = left
			self.right = right


	def __init__(self):
		self._root = None

	def insert(self,value):
		if self._root is None:
			self._root = self.Node(value)

	def bubble_up(self):
		pass

	def shift_down(self):
		pass