--[[
Min Heap using an array to store the tree.
]]


--uncomment if you haven't set your working directory to the starting folder
--package.path = package.path .. ";../?.lua"
require 'util'

MinBinaryHeap = Class{}

function MinBinaryHeap:init()
	self._values = {}
	self._size = 0
end

function MinBinaryHeap:siftUp()
	local idx = self._size
	local item = self._values[idx]
	local parentIdx = 0
	local parent
	while idx > 1 do
		--parentIdx = math.floor((idx) / 2)
		parentIdx = bit.rshift(idx,1)
		parent = self._values[parentIdx]
		if item >= parent then
			return
		end
		self._values[parentIdx] = item
		self._values[idx] = parent
		idx = parentIdx
	end
end

function MinBinaryHeap:siftDown()
	local smallest
	local index = 1
	while true do
		smallest = index
		local left, right = bit.lshift(index,1),bit.lshift(index,1)+1
		if left <= self._size and self._values[left] < self._values[index] then
			smallest = left
		end

		if right <= self._size and self._values[right] < self._values[smallest] then
			smallest = right
		end

		if smallest ~= index then
			local tmp = self._values[index]
			self._values[index] = self._values[smallest]
			self._values[smallest] = tmp
			index = smallest
		else
			return
		end

	end
end

function MinBinaryHeap:insert(element)
	table.insert(self._values,element)
	self._size = self._size + 1
	self:siftUp()
end

function MinBinaryHeap:extractMin()
	local removed = nil
	if self._size > 0 then
		print('before')
		print_r(self._values)
		removed = self._values[1]
		self._values[1] = table.remove(self._values)
		self._size = self._size - 1
		self:siftDown()
	end
	return removed
end

function MinBinaryHeap:getMin()
	if self._size > 0 then
		return self._values[1]
	end
	return nil
end

if not pcall(debug.getlocal,4,1) then
	heap = MinBinaryHeap()
	heap:insert(3)
	heap:insert(2)
	heap:insert(4)
	heap:insert(5)
	heap:insert(7)
	heap:insert(1)
	--print_r(heap._values)
	print(heap:extractMin())
	--print_r(heap._values)
	print(heap:extractMin())
	--print_r(heap._values)
	print(heap:extractMin())
	--print_r(heap._values)
	print(heap:extractMin())
	--print_r(heap._values)
	print(heap:extractMin())
	--print_r(heap._values)
	print(heap:extractMin())
end