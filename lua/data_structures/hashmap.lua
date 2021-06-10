--uncomment if you haven't set your working directory to the starting folder
--package.path = package.path .. ";../?.lua"
require 'util'
HashMap = Class{
	init = function(self)
		self._head = nil
		self._tail = nil
		self._node_map = {}
		self.node = function(value,prev,nxt)
			return {
				value = value,
				prev = prev,
				next = nxt
			}
		end
	end
}
function HashMap:get(key)
	local v = self._node_map[key]
	v = v.value or nil
	return v
end

function HashMap:set(key,value)
	local v = self._node_map[key]
	if v ~= nil then
		self._node_map[key].value = value
	elseif self._head == nil then
		self._head = self.node(value)
		self._tail = self._head
		self._node_map[key] = self._head
	else
		local node = self.node(value,self._tail)
		self._tail.next = node
		self._tail = self._tail.next
		self._node_map[key] = node
	end
end

function HashMap:del(key)
	local node = self._node_map[key]
	if node == nil then
		return
	end
	if node.prev ~= nil then
		if node.next ~= nil then
			node.next.prev = node.prev
		end
		node.prev.next = node.next
	else
		self._head = node.next
		self._head.prev = nil
	end
	self._node_map[key] = nil
end
if not pcall(debug.getlocal,4,1) then
	hm = HashMap()
	hm:set('a',3)
	hm:set('b',4)
	hm:set('c',5)
	print_r(hm._node_map)
	print(hm:get('a'))
	print_r(hm._node_map)
	hm:del('a')
	print_r(hm._node_map)
end
