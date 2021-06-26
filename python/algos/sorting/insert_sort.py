def insert_sort(array):
	for i in range(1,len(array)):
		cur = array[i]
		for j in range(i-1,-1,-1):
			if arr[j] < cur:break
			arr[j+1] = arr[j]
		#python is super weird have to do it this way.
		else:
			j = -1
		arr[j+1] = cur
		
arr = [9,7,1,2,4,3,5,6]
insert_sort(arr)
print(arr)
