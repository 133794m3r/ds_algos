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
			this.first = new Queue.Node(values[0]);
			this.last = this.first;
			let tmp = undefined;
			this.length = values.length;
			for(let i=1;i<values.length;i++){
				tmp = new Queue.Node(values[1]);
				this.last.next = tmp;
				this.last = tmp;
			}
		}
		else{
			this.first = null;
			this.last = null;
			this.length = 0;
		}
	}

	enqueue(value){
		if(!this.first){
			this.first = new Queue.Node(value);
			this.last = this.first;
		}
		else{
			let tmp = new Queue.Node(value);
			this.last.next = tmp;
			this.last = tmp;
		}
		this.length++;
	};

	dequeue() {
		if (!this.first) {
			return undefined;
		}
		if (this.first === this.last) {
			this.last = null;
		}
		let tmp = this.first;
		this.first = this.first.next;
		this.length--;
		return tmp;
	};
	toString(){
		let tmp  = this.first;
		let output = '[';
		for(let i=0; i<this.length; i++){
			//output += `| value:${tmp.value}, nxt:${tmp.next} |\r\n`;
			output += tmp.value;
			tmp = tmp.next;
			if(i < this.length -1)
				output += ',';
		}
		return output+']';
	}
	size(){
		return this.length;
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