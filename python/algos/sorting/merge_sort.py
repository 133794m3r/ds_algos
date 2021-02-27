def merge_sort(array):
	def _merge(start,mid,end):
		i = start
		j = mid+1
		n = 0
		tmp = [0] * ((end-start)+1)
		while i <= mid and j <= end:
			if array[i] <= array[j]:
				tmp[n] = array[i]
				i+=1
			else:
				tmp[n] = array[j]
				j+=1

			n+=1

		for i in range(i,mid+1):
			tmp[n] = array[i]
			n+=1
		for j in range(j,end+1):
			tmp[n] = array[j]
			n+=1

		for i in range(start,end+1):
			array[i] = tmp[i - start]

	def _merge_sort(start,end):
		if start < end:
			mid = (start+end)//2
			_merge_sort(start,mid)
			_merge_sort(mid+1,end)
			_merge(start,mid,end)

	_merge_sort(0,len(array)-1)

arr = [3,2,1,6,9,7]
merge_sort(arr)
print(arr)