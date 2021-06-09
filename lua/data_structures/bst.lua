--uncomment if you haven't set your working directory to the starting folder
--package.path = package.path .. ";../?.lua"
require 'util'

--BinarySearchTree class
BinarySearchTree = Class{}

	--init = function(self)
	--	self.Node = Class{
	--		init = function(self,value,left,right)
	--			self.value = value
	--			self.left = left
	--			self.right = right
	--		end
	--	}
	--	self._root = nil
	--end
--}

function BinarySearchTree:init()

	self.Node = Class{}
	function self.Node:init(value,left,right)
		self.value = value
		self.left = left
		self.right = right
	end
	--self.Node = Class{
	--	init = function(self,value,left,right)
	--		self.value = value
	--		self.left = left
	--		self.right = right
	--	end
	--}
	self._root = nil
end
function BinarySearchTree:find(value)
	if self._root == nil then
		return nil
	end
	local cur = self._root
	while cur do
		if cur.value > value then
			cur = cur.left
		elseif cur.value < value then
			cur = cur.right
		else
			return cur
		end
	end
	return nil
end

function BinarySearchTree:contains(value)
	local cur = self._root
	while cur do
		if cur.value > value then
			cur = cur.left
		elseif cur.value < value then
			cur = cur.right
		else
			return true
		end
	end
	return false
end

function BinarySearchTree:insert(value)
	if self._root == nil then
		self._root = self.Node(value)
	else
		local cur = self._root
		while cur do
			if cur.value > value then
				if cur.left then
					cur = cur.left
				else
					cur.left = self.Node(value)
					return
				end
			elseif cur.value < value then
				if cur.right then
					cur = cur.right
				else
					cur.right = self.Node(value)
					return
				end
			else
				return
			end
		end
	end
end

function BinarySearchTree:_height(node)
	if node == nil then
		return 0
	else
		local x = self:_height(node.left)
		local y = self:_height(node.right)
		return x > y and x+1 or y+1
	end
end


-- get height of the entire tree
function BinarySearchTree:height()
	return self:_height(self._root)
end

-- get height from the given node
function BinarySearchTree:getHeight(node)
	return self._height(node)
end

function BinarySearchTree:bfs()
	local cur = self._root
	-- queue but not really
	local q = {}
	-- traversed values
	local data = {}
	table.insert(self._root)
	while #q do
		cur = table.remove(q)
		table.insert(data,cur.value)
		if cur.left then
			table.insert(cur.left)
		end
		if cur.right then
			table.insert(cur.right)
		end
	end
	return data
end

function BinarySearchTree:preTraverse(data, node)
	table.insert(data,node.value)
	if node.left then self:preTraverse(data,node.left) end
	if node.right then self:preTraverse(data,node.right) end
end

function BinarySearchTree:inTraverse(data, node)
	if node.left then self:inTraverse(data,node.left) end
	table.insert(data,node.value)
	if node.right then self:inTraverse(data, node.right) end
end

function BinarySearchTree:postTraverse(data, node)
	if node.left then self:postTraverse(data,node.left) end
	if node.right then self:postTraverse(data, node.right) end
	table.insert(data, node.value)
end

function BinarySearchTree:preOrder()
	local cur = self._root
	local data = {}
	if cur ~= nil then
		self:preTraverse(data,cur)
	end
	return data
end

function BinarySearchTree:inOrder()
	local cur = self._root
	local data = {}
	if cur ~= nil then
		self:inTraverse(data,cur)
	end
	return data
end

function BinarySearchTree:postOrder()
	local cur = self._root
	local data = {}
	if cur ~= nil then
		self:postTraverse(data,cur)
	end
	return data
end

function BinarySearchTree:_remove(node,key)
	if node == nil then
		return nil
	end
	if node.left == nil and (node.left == node.right ) then
		if node.value == self._root.value then
			self._root = nil
			return nil
		end
		return nil
	end
	if key < node.value then
		node.left = self:_remove(node.left, key)
	elseif key > node.value then
		node.right = self:_remove(node.right,key)
	else
		if self:_height(node.left) > self:_height(node.right) then
			local q = node.left
			while q.right and (node.right ~= nil) do
				q = q.right
			end
			print_r(q)
			node.value = q.value
			node.left = self:_remove(node.left,q.value)
		else
			local q = node.right
			while q.left and (node.left ~= nil) do
				q = q.left
			end
			print_r(q)
			node.value = q.value
			node.right = self:_remove(node.right, q.value)
		end
	end
	return node
end

-- BinarySearchTree:remove will remove a value
-- @param key The key to remove
function BinarySearchTree:remove(key)
	return self:_remove(self._root, key)
end

if not pcall(debug.getlocal,4,1) then
	local bst = BinarySearchTree()
	bst:insert(7)
	bst:insert(6)
	bst:insert(4)
	bst:insert(5)
	bst:insert(3)
	print_r(bst:inOrder())
	bst:remove(3)
	print_r(bst)
	print_r(bst:inOrder())
end
