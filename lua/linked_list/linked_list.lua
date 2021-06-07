--uncomment if you haven't set your working directory to the starting folder
--package.path = package.path .. ";../?.lua"
require 'util'
--[[
Methods


Note: The indexes are based on 1 as this is lua
]]

LinkedList = Class{}

function LinkedList:init()
	self.Node = Class{}
	function self.Node:init(value,ref)
		self.value = value
		self.next = ref
	end
	self._head = nil
	self._length = 0
	self._tail = nil
end

function LinkedList:get(idx)
	if idx < 1 or idx > self._length then
		return nil
	end

	local cur = self._head

	for i=1,idx-1 do
		print(cur.value)
		cur = cur.next
	end
	return cur
end

function LinkedList:push(value)
	if self._head == nil then
		self._head = self.Node(value)
		self._tail = self._head
	else
		local cur = self._head
		while(cur.next ~= nil) do
			cur = cur.next
		end
		cur.next = self.Node(value)
		self._tail = cur.next
	end
	self._length = self._length +  1
end

function LinkedList:pop(idx)
	if self._head == nil then
		return nil
	end
	local popped
	if idx then
		local prev = self:get(idx-1)
		popped = prev.next
		prev.next = prev.next.next
	else
		popped = self._tail.value
		if self._length > 1 then
			local prev = self:get(self._length-1)
			print_r(prev)
			self._tail = prev
			self._tail.next = nil
		else
			self._tail = nil
		end
	end
	self._length = self._length - 1
	return popped
end

function LinkedList:reverse()
	local cur = self._head
	self._head = self._tail
	self._tail = cur
	local prev = nil

	while(cur ~= nil) do
		local next = cur.next
		cur.next = prev
		prev = cur
		cur = next
	end
	self._head = prev
end

function LinkedList:insert(idx,value)
	if 1 > idx or idx > self._length then
		return nil
	end
	local prev = self:get(idx)
	prev.next = self.Node(value, prev.next)
	self._length = self._length + 1
end

function LinkedList:set(idx,value)
	if idx < 1 or idx > self._length then
		return nil
	end
	local Node = self:get(idx)
	Node.value = value
end

function LinkedList:len()
	return self._length
end

function LinkedList:shift()
	if self._head then
		local tmp = self._head
		self._head = tmp.next
		self._length = self._length - 1
		if self._length == 0 then
			self._tail = nil
		end
		return tmp
	else
		return nil
	end
end

function LinkedList:remove(idx)
	if 1 < idx or idx > self._length then
		return nil
	end
	if idx == self._length - 1 then
		self:pop()
	elseif idx == 0 then
		self:shift()
	else
		local prev = self:get(idx-1)
		local removed = prev.next
		prev.next = removed.next
		self._length = self._length - 1
	end
end

function LinkedList:unshift(value)
	if self._head then
		self._head = self.Node(value, self._head)
	else
		self._head = self.Node(value)
		self._tail = self._head
	end
end

function LinkedList:stringify()
	local os = '['
	local cur = self._head
	while cur.next ~= nil do
		os = os .. tostring(cur.value) .. ","
		cur = cur.next
	end
	return os .. tostring(cur.value) .. "]"
end

if not pcall(debug.getlocal,4,1) then
	ll = LinkedList()
	ll:push(1)
	ll:push(2)
	ll:push(3)
	ll:push(4)
	ll:push(5)
	ll:push(6)
	print(ll:stringify())
	ll:pop()
	ll:pop()
	print(ll:stringify())
	ll:shift()
	ll:unshift(11)
	print(ll:stringify())
	ll:pop(2)
	print(ll:stringify())
	-- nil test
	print(ll:get(0))
end