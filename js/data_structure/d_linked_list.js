class DoublyLinkedList {
	constructor(values){
		if(arguments.length > 0) {
			this.length = values.length;
			this.head = new DoublyLinkedList.Node(values[0]);
			let current = this.head;
			for (let i = 1; i < this.length; i++) {
				current.next = new DoublyLinkedList.Node(values[i],current);
				current = current.next;
			}
			this.tail = current;
		}
		else{
			this.length = 0;
			this.head = null;
			this.tail = null;
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
		if(!this.head){
			this.head = new DoublyLinkedList.Node(value);
			this.tail = this.head;
		}
		else{
			let p = new DoublyLinkedList.Node(value,this.tail);
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
		if(idx <= (this.length >>> 1) ){
			let i = 0;
			while(i !== idx){
				current = current.next;
				i++;
			}
		}
		else{
			let i = this.length - 1;
			current = this.tail;
			while (i !== idx){
				current = current.prev;
				i--;
			}
		}

		return current;
	}

	pop(){
		if(!this.head){
			return undefined;
		}
		let tmp = this.tail;
		if(this.length === 1){
			this.head=this.tail=null;
		}
		else{
			this.tail = tmp.prev;
			this.tail.next = null;
		}
		this.length--;
		return tmp.value;
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
			let afterNode = this.get(idx);
			let beforeNode = afterNode.prev;
			let newNode = new DoublyLinkedList.Node(value, beforeNode, afterNode);
			beforeNode.next = newNode;
			afterNode.prev = newNode;
			this.length++;
		}
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
			this.head = new DoublyLinkedList.Node(value,null,this.head);
		}
		else{
			this.head = new DoublyLinkedList.Node(value);
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
		else if(idx === 0){
			this.shift();
		}
		else{
			let prev = this.get(idx-1);
			let remove = prev.next;
			prev.next = remove.next;
			this.length--;
		}
	}

	reverse(){
		let current = this.head
		this.head = this.tail
		this.tail = current

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
