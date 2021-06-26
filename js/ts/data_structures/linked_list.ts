class LinkedList{
	private _head: LinkedList.node | null;
	private _tail: LinkedList.node | null;
	private len: number;
	constructor(){
		this._head = null;
		this._tail = null;
		this.len = 0;
	}
	push(value:any){
		if(this._head == null) {
			this._head = new LinkedList.node(value);
			this._tail = this._head;
		}
		else{
			let p:LinkedList.node = new LinkedList.node(value);
			this._tail.next = p;
			this._tail = p;
		}
		this.len++;
	}
	get(idx:number):null | LinkedList.node{
		let cur:LinkedList.node = this._head;
		if(idx > this.len || idx < 0)
			return null;
		for(let i:number = 0; i < idx; i++){
			cur = cur.next;
		}
		return cur;
	}
	pop(){
		if(this._head === null)
			return;
		let node: LinkedList.node = null;
		node = this.get(this.len - 2);
		let t:LinkedList.node = this._tail;
		node.next = null;
		return t;
	}
}
//have to emulate inner classes due to typescript's way of doing things.
module LinkedList{
	export class node {
		public next: null | node;
		public val: any;
		constructor(val:any,next:null | node=null){
			this.val = val;
			this.next = next;
		}
	}
}

function main(){
	return 0;
}