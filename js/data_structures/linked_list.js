class LinkedList {
	constructor(values){
		if(arguments.length === 0){
			this._head=null;
			this._tail=null;
			this._length=0;
		}
		else{
			this._length = values.length;
			this._head = new LinkedList.Node(values[0]);
			let current = this._head;
			for(let i=1; i<this._length; i++) {
				current.next = new LinkedList.Node(values[i]);
				current = current.next;
			}
			this._tail = current;

		}
	}
	static Node = class {
		value = null;
		next = null;
		constructor(val=null,next=null){
			this.value=val;
			this.next=next;
		}
	}
	push(value){
		if(!this._head){
			this._head = new LinkedList.Node(value);
			this._tail = this._head;
		}
		else{
			let p = new LinkedList.Node(value);
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
		let i = 0;
		while(i !== idx){
			current = current.next;
			i++;
		}
		return current;
	}
	pop(){
		if(!this._head){
			return undefined;
		}
		let popped = this._tail.value;
		if(this._length > 1) {
			this._tail = this.get(this._length - 2);
			this._tail.next = undefined;
		}
		else{
			this._head = undefined;
			this._tail = this._head;
		}
		this._length--;
		return popped;
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
			let prev = this.get(idx - 1);
			prev.next = new LinkedList.Node(value, prev.next);
		}
		this._length++;
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
			this._head = new LinkedList.Node(value,this._head);
		}
		else{
			this._head = new LinkedList.Node(value);
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
		else{
			let prev = this.get(idx-1);
			let remove = prev.next;
			prev.next = remove.next;
			this._length--;
		}
	}

	reverse(){
		let current = this._head;
		let prev = undefined;
		let next = undefined;
		while(current){
			next = current.next;
			current.next = prev;
			prev = current;
			current = next;
		}
		this._head = prev;
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
	const ll = new LinkedList([4,5]);
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