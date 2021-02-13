class PriorityQueue{
	static Node = class{
		constructor(value,priority=null){
			this.value = value;
			this.priority = priority;
		}
		toString(){
			return `{ value:${this.value} next:${this.priority} }`;
		}
	}
	constructor(){
		this._values = [];
		this._len= 0;
	}

	shiftUp(){
		let idx = this._len - 1;
		while(idx > 0){
			let parentIdx = (idx -1)>>>1;
			if(this._values[idx].priority >= this._values[parentIdx].priority) break;
			let tmp = this._values[parentIdx];
			this._values[parentIdx] = this._values[idx];
			this._values[idx] = tmp;
			idx = parentIdx;
		}
	}
	enqueue(value,priority){
		this._values.push(new PriorityQueue.Node(value,priority));
		this._len++;
		this.shiftUp();
	};

	shiftDown(){
		let idx = 0;
		while(true){
			let swap_id = idx;
			let left = (idx << 1)+1;
			let right = left+1;
			if(left < this._len){
				if(this._values[left].priority < this._values[idx].priority)
					swap_id = left;
			}
			if(right < this._len && this._values[swap_id].priority > this._values[right].priority){
				swap_id = right;
			}
			if(swap_id === idx) break;
			let tmp = this._values[idx];
			this._values[idx] = this._values[swap_id];
			this._values[swap_id] = tmp;
			idx = swap_id;
		}
	}
	dequeue(){
		let highest = null;
		if(this._len > 0){
			highest = this._values[0];
			this._values[0] = this._values.pop();
			this._len--;
			this.shiftDown();
		}
		return highest;
	};
	toString(){
		let os = ''
		for(let i=0; i<this._len; i++){
			os += this[i].toString();
			if(i < this._len -1)
				os+=','
		}
	}
	size(){
		return this._len;
	}
}
if(typeof module !== 'undefined') {
	module.exports = PriorityQueue;
	if (require.main === module) {
		let inf = 1<<31-1;
		pq = new PriorityQueue();
		pq.enqueue("a",0);
		pq.enqueue("b",inf);
		pq.enqueue("c",inf);
		pq.enqueue("d",inf);
		pq.enqueue("e",inf);
		pq.enqueue("f",inf);
		pq.dequeue();
		pq.enqueue("b",4);
		pq.enqueue("c",2);
		console.log(pq);
		pq.dequeue();
		pq.enqueue("d",4);
		console.log(pq.size());
		console.log(pq);
	}
}