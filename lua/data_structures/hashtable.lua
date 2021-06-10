--uncomment if you haven't set your working directory to the starting folder
--package.path = package.path .. ";../?.lua"
require 'util'
HashTable = Class{
	init = function(self,size)
		self.node = function(key,value)
			return {
				key = key,
				value = value
			}
		end
		self._capacity = size or 263
		self._size = 0
		self._buckets = {}
		for i=1,self._capacity do
			table.insert(self._buckets, {})
		end
	end
}

function HashTable:hash(key)
	local h = 0
	local prime =  1000000007
	local multiplier = 263
	for i=1,#key do
		h = (h * multiplier + string.byte(key,i)) % prime
	end
	return h % self._capacity
end

function HashTable:set(key,value)
	local hash = self:hash(key)
	for _,node in ipairs(self._buckets[hash]) do
		if node.key == key then
			node.value = value
			return
		end
	end
	table.insert(self._buckets[hash],self.node(key,value))
end

function HashTable:get(key)
	local idx = self:hash(key)
	if #self._buckets[idx] then
		for _,node in ipairs(self._buckets[idx]) do
			if node.key == key then
				return node.value
			end
		end
	end
	return nil
end

if not pcall(debug.getlocal,4,1) then
	ht = HashTable()
	ht:set('a',3)
	ht:set('b',4)
	print(ht:get('a'))
	print(ht:get('d'))
	ht:set('a',-1)
	print(ht:get('a'))
end