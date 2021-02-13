class Queue{
	static Node = class{
		constructor(value,nxt=null){
			this.value = value;
			this.next = nxt;
		}
		toString(){
			return `{ value:${this.value} next:${this.next} }`;
		}
	}
	constructor(values){
		if(arguments.length > 0){
			this._first = new Queue.Node(values[0]);
			this._last = this._first;
			let tmp = undefined;
			this._length = values.length;
			for(let i=1;i<values.length;i++){
				tmp = new Queue.Node(values[1]);
				this._last.next = tmp;
				this._last = tmp;
			}
		}
		else{
			this._first = null;
			this._last = null;
			this._length = 0;
		}
	}

	enqueue(value){
		if(!this._first){
			this._first = new Queue.Node(value);
			this._last = this._first;
		}
		else{
			let tmp = new Queue.Node(value);
			this._last.next = tmp;
			this._last = tmp;
		}
		this._length++;
	};

	dequeue() {
		if (!this._first) {
			return undefined;
		}
		if (this._first === this._last) {
			this._last = null;
		}
		let tmp = this._first;
		this._first = this._first.next;
		this._length--;
		return tmp;
	};
	toString(){
		let tmp  = this._first;
		let output = '[';
		for(let i=0; i<this._length; i++){
			//output += `| value:${tmp.value}, nxt:${tmp.next} |\r\n`;
			output += tmp.value;
			tmp = tmp.next;
			if(i < this._length -1)
				output += ',';
		}
		return output+']';
	}
	size(){
		return this._length;
	}
}
if(typeof module !== 'undefined') {
	module.exports = Queue;
	if (require.main === module) {
		q = new Queue();
		q.enqueue(1);
		q.enqueue(2);
		q.enqueue(3);
		q.dequeue();
		console.log(q.toString());
	}
}