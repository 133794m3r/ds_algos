class HashTable:
	class Node:
		def __init__(self,key,value):
			self.key = key
			self.value = value

		def __str__(self):
			return f"Node({self.key},{self.value})"
		def __repr__(self):
			return self.__str__()

	def __str__(self):
		return str(self._buckets)


	def __init__(self,num_buckets = 263):
		self._num_buckets = num_buckets
		self._buckets = [ [] for _ in range(num_buckets)]

	def _hash(self,key):
		prime = 1000000007
		multiplier = 263
		hash = 0
		for x in key:
			hash = (hash * multiplier + ord(x)) % prime
		return hash % self._num_buckets

	def set(self, key, value):
		if key is not str:
			key = str(key)
		index = self._hash(key)
		for node in self._buckets[index]:
			if node.key == key:
				node.value = value
				break
		else:
			self._buckets[index].append(self.Node(key,value))

	def get(self, key):
		if key is not str:
			key = str(key)
		idx = self._hash(key)
		if not self._buckets[idx]:
			return None
		else:
			for node in self._buckets[idx]:
				if node.key == key:
					return node.value
			else:
				return None


def main():
	ht = HashTable(20)
	ht.set('b',100)
	ht.set('a',30)
	ht.set('c',40)
	print(ht)
	print(ht.get('a'))

if __name__ == "__main__":
	main()
