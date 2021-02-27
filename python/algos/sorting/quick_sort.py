def quick_sort(array, start=0):
	def _part( low, high):
		pivot = array[high]
		i = low - 1
		for j in range(low, high):
			if array[j] < pivot:
				i += 1
				array[i], array[j] = array[j], array[i]

		array[i + 1], array[high] = array[high], array[i + 1]
		return i + 1
	def _qsort(low, high):
		if low < high:
			pi = _part( low, high)
			_qsort( low, pi - 1)
			_qsort(pi + 1, high)

	_qsort(start, len(array) - 1)

arr = [3,2,1,6,9,7]
quick_sort(arr)
print(arr)