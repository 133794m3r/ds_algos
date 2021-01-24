// noinspection JSValidateTypes
class LinkedList {
	constructor(head=null,tail=null,length=0){
		this.head=head;
		this.tail=tail;
		this.length=length;
	}
	Node = class {
		value = null;
		next = null;
		constructor(val=null,next=null){
			this.value=val;
			this.next=next;
		}
	}
	push(value){
		if(!this.head){
			this.head = new this.Node(value);
			this.tail = this.head;
		}
		else{
			let p = new this.Node(value);
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
		for(let i=0;i<idx;i++){
			current = current.next;
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
		// return prev;
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
			// this.head = new this.Node(value,this.head);
			this.unshift(value);
		}
		else if(idx === this.length){
			this.push(value);
		}
		else{
			let prev = this.get(idx - 1);
			prev.next = new this.Node(value, prev.next);
		}
		this.length++;
	}
	set(idx,value){
		if (!(this.length > idx || idx < 0)) {
			let p = self.get(idx);
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
			this.head = new this.Node(value,this.head);
		}
		else{
			this.head = new this.Node(value);
			this.tail = this.head;
		}
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
	display(){
		let current = this.head;
		let output = '['
		for(let i=0;i<this.length;i++){
			output += current.value.toString();
			if(i < this.length - 1){
				output += ',';
			}
			current = current.next;
		}
		output += ']';
		console.log(output);
		return output;
	}
}

const a = new LinkedList();
a.push(4);
a.push(5);
a.push(6);
a.push(7);
a.push(8);
a.push(9);
a.push(10);
a.display();
console.log(a);
a.reverse();
console.log(a.pop())
a.set(2,100);
a.insert(5,555);
a.shift();
a.unshift(6);
a.display();
a.remove(5);
a.display();
console.log(a);