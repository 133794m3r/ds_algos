--[[
By Macarthur Inbody
License LGPLv3 6/6/21

]]

--package.path = package.path .. ";../?.lua"
require 'util'

--[[
methods to write
pop()
push(value)
shift() get the value at the head and remove it
unshift() place value at the head
insert(idx,value) adds a value at a certain index
get(idx) gets the node at the referred to index
remove(idx) removes the node at the specified index
reverse() reverses the LinkedList in place
]]

DblLinkedList = Class{}

function DblLinkedList:init()
	self.Node = Class{
		init = function(self,value,prev,next)
			self.value = value
			self.prev = prev
			self.next = next
		end
	}
	self._head = nil
	self._tail = nil
	self._length = 0
end

-- remove the head node
function DblLinkedList:shift()
	if self._head then
		local tmp = self._head
		self._head = tmp.next
		self._head.prev = nil
		self._length = self._length - 1
		if self._length == 0 then
			self._tail = nil
		end
		return tmp
	else
		return nil
	end
end

function DblLinkedList:unshift(value)
	if self._head then
		self._head = self.Node(value,nil,self._head)
	else
		self._head = self.Node(value)
		self._tail = self._head
	end
end

function DblLinkedList:push(value)
	if self._head == nil then
		self._head = self.Node(value)
		self._tail = self._head
	else
		local p  = self.Node(value,self._tail)
		self._tail.next = p
		self._tail = self._tail.next
	end
	self._length = self._length + 1
end

function DblLinkedList:pop(idx)
	local popped
	if self._head == nil then
		return nil
	end
	if idx and (idx > 1 or idx < self._length) then
		popped = self:get(idx)
	else
		popped = self._tail
		self._tail = self._tail.prev
		self._tail.next = nil
	end
	self._length = self._length - 1
	return popped
end

function DblLinkedList:get(idx)
	if idx < 1 or idx > self._length then
		return nil
	end
	local cur
	if idx > (self._length / 2) then
		cur = self._tail
		for i=1,idx-1 do
			cur = cur.prev
		end
	else
		cur = self._head
		for i=1,idx-1 do
			cur = cur.next
		end
	end
	return cur
end

function DblLinkedList:stringify()
	local os = '['
	local cur = self._head
	while cur.next ~= nil do
		os = os .. tostring(cur.value) .. ","
		cur = cur.next
	end
	return os .. tostring(cur.value) .. "]"
end

function DblLinkedList:insert(idx,value)
	if 1 > idx or idx > self._length then
		return nil
	end
	local cur = self:get(idx)
	local old_prev = cur.prev
	local new_node = self.Node(value,old_prev, cur)
	old_prev.next = new_node
	cur.prev = new_node
	self._length = self._length + 1
end

-- change the value of the node at the given index to the value given
function DblLinkedList:set(idx,value)
	if idx < 1 or idx > self._length then
		return nil
	end
	local Node = self:get(idx)
	Node.value = value
end

function DblLinkedList:reverse()
	local prev = nil
	local cur = self._head
	local next = nil
	self._head = self._tail
	self._tail = cur
	while cur do
		next = cur.next
		cur.next = prev
		cur.prev = next
		prev = cur
		cur = next
	end
end

function DblLinkedList:len()
	return self._length
end

if not pcall(debug.getlocal,4,1) then
	ll = DblLinkedList()
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
	ll:insert(2,-11)
	print(ll:stringify())
	ll:reverse()
	print(ll:stringify())
end
