def insert_sort(array):
	for i in range(1,len(array)):
		cur = array[i]
		for j in range(i-1,-1,-1):
			if arr[j] < cur: break
			arr[j+1] = arr[j]
		arr[j+1] = cur

arr = [3,2,1,6,9,7]
insert_sort(arr)
print(arr)