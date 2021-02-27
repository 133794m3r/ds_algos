def select_sort(array):
	arr_len = len(array)
	for i in range(0, arr_len):
		lowest = i
		for j in range(i+1, arr_len):
			if array[j] < array[i] :
				lowest = j
		if i != lowest:
			array[i], array[lowest] = array[lowest], array[i]

arr = [3,2,1,6,9,7]
select_sort(arr)
print(arr)
