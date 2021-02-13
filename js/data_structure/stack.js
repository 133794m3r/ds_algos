class Stack{
	static Node = class{
		constructor(value,next=null){
			this.value = value;
			this.next = next;
		}
	}
	constructor(){
		this._first = null;
		this._last = null;
		this._size = null;
	}

	push(value){
		if(this._first)
			this._first = new Stack.Node(value,this._first);
		else{
			this._first = new Stack.Node(value);
			this._last = this._first;
		}
		this._size++;
	}

	pop(){
		if(this._first === null)
			return null;
		if(this._first === this._last)
			this._last = null

		let tmp = this._first.value;
		this._first = this._first.next;
		this._size--;
		return tmp;
	}
}

if(typeof module !== 'undefined' && require.main === module){
	let stack = new Stack();
	stack.push('a');
	stack.push('b');
	stack.push('c');
	console.log(stack.pop());
	console.log(stack);
}