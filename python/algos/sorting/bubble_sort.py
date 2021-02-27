def bubble_sort(array):
	length = len(array)
	swapped = False
	for i in range(length,0,-1):
		for j in range(0,i):
			if array[j] > array[j+1]:
				array[j], array[j+1] = array[j+1], array[j]
				swapped = True

		if not swapped: break

arr = [3,2,1,6,9,7]
bubble_sort(arr)
print(arr)