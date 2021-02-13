class DoublyLinkedList {
	constructor(values){
		if(arguments.length > 0) {
			this._length = values.length;
			this._head = new DoublyLinkedList.Node(values[0]);
			let current = this._head;
			for (let i = 1; i < this._length; i++) {
				current.next = new DoublyLinkedList.Node(values[i],current);
				current = current.next;
			}
			this._tail = current;
		}
		else{
			this._length = 0;
			this.head = null;
			this._tail = null;
		}
	}

	static Node = class {
		constructor(val=null,prev_=null,next_=null){
			this.value=val;
			this.prev = prev_;
			this.next=next_;
		}
	}

	push(value){
		if(!this._head){
			this._head = new DoublyLinkedList.Node(value);
			this._tail = this._head;
		}
		else{
			let p = new DoublyLinkedList.Node(value,this._tail);
			this._tail.next = p;
			this._tail = p;
		}
		this._length++;
	}

	get(idx){
		if (idx < 0 || idx> this._length){
			return undefined;
		}
		let current = this._head;
		if(idx <= (this._length >>> 1) ){
			let i = 0;
			while(i !== idx){
				current = current.next;
				i++;
			}
		}
		else{
			let i = this._length - 1;
			current = this._tail;
			while (i !== idx){
				current = current.prev;
				i--;
			}
		}

		return current;
	}

	pop(){
		if(!this._head){
			return undefined;
		}
		let tmp = this._tail;
		if(this._length === 1){
			this._head=this._tail=null;
		}
		else{
			this._tail = tmp.prev;
			this._tail.next = null;
		}
		this._length--;
		return tmp.value;
	}

	/**
	 *
	 * @param idx Number
	 * @param value mixed
	 * @returns
	 */
	insert(idx,value){
		if(idx > this._length || idx < 0)
			return undefined;
		else if(idx === 0){
			this.unshift(value);
		}
		else if(idx === this._length){
			this.push(value);
		}
		else{
			let afterNode = this.get(idx);
			let beforeNode = afterNode.prev;
			let newNode = new DoublyLinkedList.Node(value, beforeNode, afterNode);
			beforeNode.next = newNode;
			afterNode.prev = newNode;
			this._length++;
		}
	}

	set(idx,value){
		if( idx > 0 && idx < this._length){
			let p = this.get(idx);
			p.value = value;
		}
	}

	shift(){
		if(this._head){
			let tmp = this._head;
			this._head = tmp.next;
			this._length--;
			if(this._length === 0){
				this._tail = undefined;
			}
			return tmp;
		}
	}

	unshift(value){
		if(this._head){
			this._head = new DoublyLinkedList.Node(value,null,this._head);
		}
		else{
			this._head = new DoublyLinkedList.Node(value);
			this._tail = this._head;
		}
		this._length++;
	}

	remove(idx){
		if(idx < 0 || idx > this._length){
			return undefined;
		}
		else if(idx === this._length - 1){
			this.pop();
		}
		else if(idx === 0){
			this.shift();
		}
		else{
			let prev = this.get(idx-1);
			let remove = prev.next;
			prev.next = remove.next;
			this._length--;
		}
	}

	reverse(){
		let current = this._head
		this._head = this._tail
		this._tail = current

		let prev = null, next = null

		while (current !== null){
			prev = current.prev
			next = current.next
			current.prev = next
			current.next = prev
			current = next
		}
	}

	toString(){
		let current = this._head;
		let output = '['
		for(let i=0; i<this._length; i++){
			output += current.value.toString();
			if(i < this._length - 1){
				output += ', ';
			}
			current = current.next;
		}
		output += ']';
		return output;
	}
	display(){
		console.log(this.toString());
	}

}
function test(){
	const ll = new DoublyLinkedList([4,5]);
	ll.push(6);
	ll.insert(2,222);
	ll.push(7);
	ll.push(8);
	ll.push(9);
	ll.push(10);
	ll.reverse();
	ll.pop();
	ll.set(2,100);
	ll.insert(5,555);
	ll.insert(4,444);
	ll.shift();
	ll.unshift(6);
	ll.remove(5);
	const expected = '[6, 9, 100, 7, 444, 555, 222, 5]';
	if(ll.toString() === expected ){
		console.log("All's clear");
	}
	else{
		console.log(`We got ${ll.toString()} but we expected ${expected}.`)
	}
}
if (typeof module !== 'undefined' && require.main === module) {
	test();
}
