--uncomment if you haven't set your working directory to the starting folder
--package.path = package.path .. ";../?.lua"
require 'util'

Stack = Class{
	init = function(self)
		self._size = 0
		self._head = nil
		self._tail = nil
		self.node = Class{
			init = function(self,val,next)
				self.value = val
				self.next = next
			end
		}
	end
}

function Stack:push(value)
	if self._head == nil then
		self._head = self.node(value)
		self._tail = self._head
	else
		self._head = self.node(value,self._head)
	end
	self._size = self._size + 1
end

function Stack:pop()
	local popped
	if self._size == 0 then
		return nil
	elseif self._size == 1 then
		popped = self._head.value
		self._head = nil
		self._tail = nil
	else
		popped = self._head.value
		self._head = self._head.next
	end
	self._size = self._size -1
	return popped
end

if not pcall(debug.getlocal,4,1) then
	s = Stack()
	s:push(1)
	s:push(2)
	s:push(3)
	s:push(4)
	print(s:pop())
	print(s:pop())
	print(s:pop())
	print(s:pop())
end