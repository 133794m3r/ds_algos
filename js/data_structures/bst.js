const Queue = require('./queue');
class BinarySearchTree{
	static Node = class{
		constructor(val,lt=null,rt=null){
			this.value = val;
			this.left = lt;
			this.right = rt;
		}
		toString(){
			return `{ ${this.value} left:${this.left} right:${this.right} }`;
		}
	};

	constructor(){
		this._root = null;
	};

	find(value) {
		if (this._root == null) return undefined;
		let cur = this._root;
		let found = false;
		while (!found && cur) {
			if (cur.value > value)
				cur = cur.left;
			else if (cur.value < value)
				cur = cur.right;
			else
				found = true
		}
		return cur.value;
	};

	contains(value){
		//hack to avoid having to rewrite the code.
		return (this.find(value) !== undefined);
	};

	insert(value){
		if(!this._root) {
			this._root = new BinarySearchTree.Node(value);
		}
		else{
			let cur = this._root;
			while(cur) {
				if (cur.value > value) {
					if (cur.left) cur = cur.left;
					else {
						cur.left = new BinarySearchTree.Node(value);
						return;
					}
				}
				else if (cur.value < value) {
					if (cur.right) cur = cur.right;
					else {
						cur.right = new BinarySearchTree.Node(value);
						return;
					}
				}
				else return;
			}
		}
	};

	_height(node){
		let x,y;
		if(node === null){
			return 0;
		}
		x = this._height(node.left);
		y = this._height(node.right);
		return x>y?x+1:y+1;
	}

	bfs(){
		let cur = this._root;
		let q = new Queue();
		let data = [];
		q.enqueue(this._root);
		while(q.size()){
			cur = q.dequeue().value;
			data.push(cur.value);
			if(cur.left) q.enqueue(cur.left);
			if(cur.right) q.enqueue(cur.right);
		}
		return data;
	}
	preTraverse(data, node){
		data.push(node.value);
		if(node.left) this.preTraverse(data,node.left);
		if(node.right) this.preTraverse(data, node.right);
	}
	inTraverse(data,node){
		if(node.left) this.inTraverse(data,node.left);
		data.push(node.value);
		if(node.right) this.inTraverse(data, node.right);
	}
	postTraverse(data,node){
		if(node.left) this.postTraverse(data,node.left);
		if(node.right) this.postTraverse(data, node.right);
		data.push(node.value);
	}

	preOrder(){
		let cur = this._root;
		let data = [];
		this.preTraverse(data,cur);
		return data;
	}
	inOrder(){
		//let cur = this.root;
		let data = [];
		this.inTraverse(data,this._root);
		return data;
	}
	postOrder(){
		let cur = this._root;
		let data = [];
		this.postTraverse(data,cur);
		return data;
	}
	_remove(node,key){
		if(!node)
			return null
		if(! (node.left || node.right) ){
			if(node === this._root){
				this._root = null;
			}
			return null;
		}
		if(key < node.value){
			node.left = this._remove(node.left,key);
		}
		else if(key > node.value){
			node.right = this._remove(node.right,key);
		}
		else{
			let q;
			if(this._height(node.left) > this._height(node.right)){
				q = node.left;
				while(q && node.right !== null){
					q = q.right;
				}
				node.value = q.value;
				node.left = this._remove(node.left,q.value);
			}
			else{
				q = node.right;
				while(q && node.left !== null){
					q = q.left;
				}
				node.value = q.value;
				node.right = this._remove(node.right, q.value);
			}
		}
		return node;
	}
	remove(key){
		return this._remove(this._root, key).value;
	}
	height(){
		return this._height(this._root);
	}
}
if(typeof module !== 'undefined') {

	//module.exports = BinarySearchTree;
	if(require.main === module) {
		let bst = new BinarySearchTree();
		bst.insert(10);
		bst.insert(6);
		bst.insert(15);
		bst.insert(3);
		bst.insert(8);
		bst.insert(20);
		console.log(bst);
		let tmp = bst.bfs();
		console.log(tmp);
		tmp = bst.preOrder();
		console.log('pre', tmp);
		console.log('in', bst.inOrder());
		console.log('post', bst.postOrder());
		console.log(bst.height());
		console.log(bst.remove(3))
		console.log(bst.inOrder());
	}
}
