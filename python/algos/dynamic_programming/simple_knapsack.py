"""
This is the simple subset problem of the simple unbounded knapsack
"""

def maximal_bag(max_storage,items,number_of_items):
	slot_bags = [ [-1 for j in range(max_storage+1)] for i in range(number_of_items+1)]
	maximum_items = number_of_items+1
	max_storage_1 = max_storage+1
	for i in range(1,number_of_items+1):
		for j in range(1,max_storage+1):
			if i == 0 or j == 0:
				slot_bags[i][j] = 0
			elif items[i-1] > j:
				slot_bags[i][j] = slot_bags[i-1][j]
			else:
				slot_bags[i][j] = max(items[i-1]+slot_bags[i-1][j -items[i-1]], slot_bags[i-1][j])

	return slot_bags[number_of_items][max_storage]


max_weight = 32
num_items = 20
weights = [i+1 for i in range(5,25)]
best = maximal_bag(max_weight, weights, num_items)
print(best)
