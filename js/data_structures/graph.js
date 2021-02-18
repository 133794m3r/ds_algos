class Graph{
	constructor(){
		this._adj_lists = {};
		this._vertexes = 0;
	}
	addVertex(vertex){
		if(! this._adj_lists[vertex]){
			this._adj_lists[vertex] = []
			this._vertexes++;
		}
	}
	addEdge(src, dest){
		if(dest in this._adj_lists[src]){
			return;
		}
		this._adj_lists[src].push(dest);
		this._adj_lists[dest].push(src);
	}

	removeEdge(v1, v2){
		this._adj_lists[v1] = this._adj_lists[v1].filter(x => x !== v2);
		this._adj_lists[v2] = this._adj_lists[v2].filter(x => x !== v1);
	}

	removeVertex(v1){
		while(this._adj_lists[v1].length !== 0){
			let v2 = this._adj_lists[v1][0];
			this.removeEdge(v1,v2);
		}
		delete this._adj_lists[v1];
	}

	dfs(start){
		let stack = [start];
		let visited = {start:1};
		let result = [];
		while(stack.length !== 0){
			let current = stack.pop();
			result.push(current);
			for(let i=0; i<this._adj_lists[current].length; i++){
				let neighbor = this._adj_lists[current][i];
				if(! visited[neighbor]){
					stack.push(neighbor);
					visited[neighbor] = 1;
				}
			}
		}
		return result;
	}
}

if (typeof module !== 'undefined' && require.main === module) {
	let g = new Graph();
	g.addVertex('a');
	g.addVertex('b');
	g.addVertex('c');
	g.addVertex('d');
	g.addVertex('e');
	g.addVertex('f');
	g.addEdge('a','b');
	g.addEdge('a','c');
	g.addEdge('b','d');
	g.addEdge('c','e');
	g.addEdge('d','e');
	g.addEdge('d','f');
	g.addEdge('e','f');
	console.log(g);
	g.removeVertex('b');
	console.log(g.dfs('a'));
}
