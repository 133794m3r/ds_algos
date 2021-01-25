class MaxBinaryHeap{
	constructor(){
		this.values = [];
		this.size = 0;
	}
	shiftUp(){
		let idx = this.size -1;
		let item = this.values[idx];
		let parentIdx = 0;
		let parent;
		while(idx > 0){
			parentIdx = (idx-1) >> 1;
			parent = this.values[parentIdx];
			if (item <= parent) break
			this.values[parentIdx] = item;
			this.values[idx] = parent;
			idx = parentIdx;
		}
	}

	shiftDown(){
		let el = this.values[0];
		let idx = 0;
		const heapSize = this.size;
		while (idx < heapSize){
			let swapIdx = idx;
			let left = (idx << 1) + 1;
			let right = left+1;
			if(left < heapSize && this.values[left] < el)
				swapIdx = left;

			if(right < heapSize && this.values[swapIdx] < this.values[right])
				swapIdx = right;

			if (swapIdx === idx) break;
			this.values[idx] = this.values[swapIdx];
			this.values[swapIdx] = el;
			idx = swapIdx;
		}
	}

	insert(element){
		this.values.push(element);
		this.size++;
		this.shiftUp();
	}

	extractMax(){
		let removed = undefined;
		if (this.size > 0){
			removed = this.values[0];
			this.values[0] = this.values.pop();
			this.size--;
			this.shiftDown();
		}
		return removed;
	}

	getMax(){
		if (this.size >0){
			return this.values[0];
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