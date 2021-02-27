from math import floor, log10


def num_digits(num):
	if num < 0:
		num *= -1
	return floor(log10(num))+1

def most_digits(array):
	max_digits = 0
	for num in array:
		max_digits = max(max_digits,num_digits(num))
	return max_digits

def count_sort(array, n, exp):
	buckets = [0 for _ in range(n)]
	count = [0,0,0,0,0,0,0,0,0,0,0]
	for i in range(n):
		count[(array[i] // exp) % 10]+=1
	for i in range(1,10):
		count[i] += count[i-1]

	for i in range(n-1,-1,-1):
		c = count[(array[i] // exp) % 10] - 1

		buckets[count[(array[i] // exp) % 10] - 1] = array[i]
		count[(array[i] // exp) % 10] -= 1
	for i in range(n):
		array[i] = buckets[i]


def radix_sort(array):
	length = len(array)
	exp = 1
	max_digits = most_digits(array)
	for i in range(max_digits):
		count_sort(array,length,exp)
		exp*=10
arr = [3,2,1,6,9,7]
radix_sort(arr)
print(arr)