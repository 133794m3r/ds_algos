#ifndef _BST_HXX
#define _BST_HXX
//Using STL's queue instead of my own as no reason to use it when theirs is likely better than my own in terms of perf.
#include <queue>
#include <vector>
template <typename T> class BinarySearchTree {
  private:
	struct Node{
		T value;
		Node *left;
		Node *right;
		Node(T val,Node *lt=nullptr, Node *rt=nullptr){
			value=val;
			left=lt;
			right=rt;
		}
	};
	Node *root_;
	size_t height_;
  public:
	BinarySearchTree(){
		root_ = nullptr;
		height_ = 0;
	}

	T find(const T value){
		if(!root_){
			return 0;
		}
		Node *cur = root_;
		bool found = false;
		while(!found && cur){
			if(cur->value > value){
				cur = cur->left;
			}
			else if(cur->value < value){
				cur = cur->right;
			}
			else{
				found = true;
			}
		}
		return cur->value;
	}

	bool contains(const T value){
		Node *cur = root_;
		while(cur){
			if(cur->value > value){
				cur = cur->left;
			}
			else if(cur->value < value){
				cur = cur->right;
			}
			else{
				return true;
			}
		}
		return false;
	}

	void insert(const T value){
		if(!root_){
			root_ = new Node(value);
			return;
		}
		else{
			Node *cur=root_;
			while(cur){
				if(cur->value > value){
					if (cur->left) {
						cur = cur->left;
					}
					else {
						cur->left = new Node(value);
						break;
					}
				}
				else if(cur->value < value){
					if(cur->right){
						cur = cur->right;
					}
					else {
						cur->right = new Node(value);
						break;
					}
				}
				else{
					break;
				}
			}
		}
	}

	std::vector<T> bfs(){
		Node *cur = root_;
		std::queue<Node*> queue;
		std::vector<T> data;
		queue.push(root_);
		while(queue.size()){
			cur = queue.front();
			queue.pop();
			data.push_back(cur->value);
			if(cur->left) queue.push(cur->left);
			if(cur->right) queue.push(cur->right);
		}
		return data;
	}

	void pre_traverse(std::vector<T> &data, Node *node){
		data.push_back(node->value);
		if(node->left) pre_traverse(data, node->left);
		if(node->right) pre_traverse(data, node->right);
	}

	void in_traverse(std::vector<T> &data, Node *node){
		if(node->left) in_traverse(data, node->left);
		data.push_back(node->value);
		if(node->right) in_traverse(data, node->right);
	}

	void post_traverse(std::vector<T> &data, Node *node){
		if(node->left) post_traverse(data, node->left);
		if(node->right) post_traverse(data, node->right);
		data.push_back(node->value);
	}

	std::vector<T> pre_order(){
		Node *cur = root_;
		std::queue<Node*> queue;
		std::vector<T> data;
		pre_traverse(data, cur);
		return data;
	}
	std::vector<T> in_order(){
		Node *cur = root_;
		std::queue<Node*> queue;
		std::vector<T> data;
		in_traverse(data, cur);
		return data;
	}
	std::vector<T> post_order(){
		Node *cur = root_;
		std::queue<Node*> queue;
		std::vector<T> data;
		post_traverse(data, cur);
		return data;
	}

	void _remove(Node *node){
		if(node->left) _remove(node->left);
		if(node->right) _remove(node->right);
		delete node;
	}

	int _height(Node *node){
		int x,y;
		if(node == nullptr){
			return 0;
		}
		x = _height(node->left);
		y = _height(node->right);
		return x>y?x+1:y+1;
	}

	void node_height(Node *node){
		return _height(node);
	}

	int get_height(){
		height_ = _height(root_);
		return height_;
	}
	Node *_remove(Node *node, T key){
		if(!node){
			return 0;
		}
		if(! (node->left && node->right)){
			if(node == root_){
				root_ = nullptr;
			}
			delete node;
			return 0;
		}
		if(key < node->value){
			node->left = _remove(node->left, key);
		}
		else if(key > node->value){
			node->right = _remove(node->right, key);
		}
		else{
			Node *q;
			if(_height(node->left) > _height(node->right)){
				q = node->left;
				while(q && node->right != nullptr){
					q = q->right;
				}
				node->value = q->value;
				node->left = _remove(node->left, q->value);
			}
			else{
				q = node->right;
				while(q && node->left != nullptr){
					q = q->left;
				}
				node->value = q->value;
				node->right = _remove(node->right, q->value);
			}
		}
		return node;
	}
	T remove(T key){
		return _remove(root_, key)->value;
	}
	~BinarySearchTree(){
		Node *cur =root_;
		//recursively remove nodes in post order.
		_remove(cur);
	}
};


#endif //_BST_HXX
