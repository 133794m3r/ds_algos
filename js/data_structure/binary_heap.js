class MaxBinaryHeap{
	constructor(){
		this._values = [];
		this._size = 0;
	}
	shiftUp(){
		let idx = this._size -1;
		let item = this._values[idx];
		let parentIdx = 0;
		let parent;
		while(idx > 0){
			parentIdx = (idx-1) >> 1;
			parent = this._values[parentIdx];
			if (item <= parent) break
			this._values[parentIdx] = item;
			this._values[idx] = parent;
			idx = parentIdx;
		}
	}

	shiftDown(){
		let el = this._values[0];
		let idx = 0;
		const heapSize = this._size;
		while (idx < heapSize){
			let swapIdx = idx;
			let left = (idx << 1) + 1;
			let right = left+1;
			if(left < heapSize && this._values[left] < el)
				swapIdx = left;

			if(right < heapSize && this._values[swapIdx] < this._values[right])
				swapIdx = right;

			if (swapIdx === idx) break;
			this._values[idx] = this._values[swapIdx];
			this._values[swapIdx] = el;
			idx = swapIdx;
		}
	}

	insert(element){
		this._values.push(element);
		this._size++;
		this.shiftUp();
	}

	extractMax(){
		let removed = undefined;
		if (this._size > 0){
			removed = this._values[0];
			this._values[0] = this._values.pop();
			this._size--;
			this.shiftDown();
		}
		return removed;
	}

	getMax(){
		if (this._size >0){
			return this._values[0];
		}
		else{
			return undefined;
		}
	}
}

const heap = new MaxBinaryHeap();
heap.insert(41);
heap.insert(39);
heap.insert(33);
heap.insert(18);
heap.insert(27);
heap.insert(12);
heap.insert(55);
heap.getMax();
heap.extractMax();
console.log(heap)