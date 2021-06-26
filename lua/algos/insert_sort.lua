require '../util'
function insert_sort(array)
	local j = 0
	for i=2,#array do
		local cur = array[i];
		j = i - 1
		while j>=1 and arr[j] > cur do
			array[j+1] = array[j]
			j = j - 1
		end
		array[j+1] = cur
	end
	return array
end

arr = {5,3,2,8,1,6,9,7,4}
arr = insert_sort(arr)
print_r(arr)