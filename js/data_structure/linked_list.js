class LinkedList {
	constructor(values){
		if(arguments.length === 0){
			this.head=null;
			this.tail=null;
			this.length=0;
		}
		else{
			this.length = values.length;
			this.head = new LinkedList.Node(values[0]);
			let current = this.head;
			for(let i=1;i<this.length;i++) {
				current.next = new LinkedList.Node(values[i]);
				current = current.next;
			}
			this.tail = current;

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
		if(!this.head){
			this.head = new LinkedList.Node(value);
			this.tail = this.head;
		}
		else{
			let p = new LinkedList.Node(value);
			this.tail.next = p;
			this.tail = p;
		}
		this.length++;
	}
	get(idx){
		if (idx < 0 || idx> this.length){
			return undefined;
		}
		let current = this.head;
		let i = 0;
		while(i !== idx){
			current = current.next;
			i++;
		}
		return current;
	}
	pop(){
		if(!this.head){
			return undefined;
		}
		let popped = this.tail.value;
		if(this.length > 1) {
			this.tail = this.get(this.length - 2);
			this.tail.next = undefined;
		}
		else{
			this.head = undefined;
			this.tail = this.head;
		}
		this.length--;
		return popped;
	}

	/**
	 *
	 * @param idx Number
	 * @param value mixed
	 * @returns
	 */
	insert(idx,value){
		if(idx > this.length || idx < 0)
			return undefined;
		else if(idx === 0){
			this.unshift(value);
		}
		else if(idx === this.length){
			this.push(value);
		}
		else{
			let prev = this.get(idx - 1);
			prev.next = new LinkedList.Node(value, prev.next);
		}
		this.length++;
	}
	set(idx,value){
		if( idx > 0 && idx < this.length){
			let p = this.get(idx);
			p.value = value;
		}
	}
	shift(){
		if(this.head){
			let tmp = this.head;
			this.head = tmp.next;
			this.length--;
			if(this.length === 0){
				this.tail = undefined;
			}
			return tmp;
		}
	}
	unshift(value){
		if(this.head){
			this.head = new LinkedList.Node(value,this.head);
		}
		else{
			this.head = new LinkedList.Node(value);
			this.tail = this.head;
		}
		this.length++;
	}
	remove(idx){
		if(idx < 0 || idx > this.length){
			return undefined;
		}
		else if(idx === this.length - 1){
			this.pop();
		}
		else{
			let prev = this.get(idx-1);
			let remove = prev.next;
			prev.next = remove.next;
			this.length--;
		}
	}

	reverse(){
		let current = this.head;
		let prev = undefined;
		let next = undefined;
		while(current){
			next = current.next;
			current.next = prev;
			prev = current;
			current = next;
		}
		this.head = prev;
	}
	toString(){
		let current = this.head;
		let output = '['
		for(let i=0;i<this.length;i++){
			output += current.value.toString();
			if(i < this.length - 1){
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