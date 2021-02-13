class HashTable{
	static Node = class{
		constructor(key,value){
			this.key = key;
			this.value = value;
		}
		toString(){
			return `{${this.key}:${this.value}}`;
		}
	}
	constructor(num_buckets = 263){
		this._num_buckets = num_buckets;
		this._buckets = new Array(num_buckets);
	}
	_hash(key){
		let prime = 1000000007;
		let multiplier = 263;
		let hash = 0;
		for(let x in key){
			hash = (hash * multiplier + x.charCodeAt(0)) % prime;
		}
		return hash % this._num_buckets;
	}

	set(key,value){
		if(typeof key !== "string")
			key = key.toString();
		let index = this._hash(key);
		if(this._buckets[index] === undefined){
			this._buckets[index] = [new HashTable.Node(key,value)];
			return;
		}
		for(let i = 0;i< this._num_buckets[index];i++){
			let node = this._buckets[i];
			if(node.key === key){
				this._buckets[i].value = value;
				return;
			}
		}
		this._buckets[index].push(new HashTable.Node(key,value));
	}
	get(key){
		if(typeof key !== "string")
			key = key.toString();

		let index = this._hash(key)
		if(!this._buckets[index])
			return null;
		else{
			for(let i=0;i<this._num_buckets;i++){
				let node = this._buckets[i];
				if(node.key === key)
					return node.value;
			}
			return null;
		}
	}
	toString(){
		let os = '{';
		for(let i = 0;i<this._num_buckets;i++){
			if(this._buckets[i] === undefined)
				continue;
			for(let j = 0; j<this._buckets[i].length;j++){
				let node = this._buckets[i][j];
				os+= `${node.key}:${node.value}`;
				if(j < this._buckets[i].length - 1){
					os+= ', ';
				}
			}
		}
		os+='}';
		return os;
	}
}

if(typeof module !== 'undefined' && require.main === module){
	let ht = new HashTable();
	ht.set('a',3);
	ht.set('b',4);
	ht.set('c',5);
	ht.set('d',6);
	ht.set('e',7);
	console.log(ht.toString());
}