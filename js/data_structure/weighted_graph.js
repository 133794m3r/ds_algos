const PriorityQueue = require('./priority_queue');
class WeightedGraph{
	static Edge = class{
		constructor(value,weight){
			this.value = value;
			this.weight = weight;
		}
		toString(){
			return `{ value:${this.value} next:${this.weight} }`;
		}
	}

	constructor(){
		this.adj_lists = {};
		this.vertexes = 0;
	}

	addVertex(vertex){
		if(! this.adj_lists[vertex]){
			this.adj_lists[vertex] = []
			this.vertexes++;
		}
	}

	addEdge(src, dest, weight){
		if(dest in this.adj_lists[src]){
			return;
		}
		this.adj_lists[src].push(new WeightedGraph.Edge(dest,weight));
		this.adj_lists[dest].push(new WeightedGraph.Edge(src,weight));
	}

	removeEdge(v1, v2){
		this.adj_lists[v1] = this.adj_lists[v1].filter(
			x => x.value !== v2);
		this.adj_lists[v2] = this.adj_lists[v2].filter(
			x => x.value !== v1);
	}

	removeVertex(v1){
		while(this.adj_lists[v1].length !== 0){
			let v2 = this.adj_lists[v1][0].value;
			this.removeEdge(v1,v2);
		}
		delete this.adj_lists[v1];
	}

	dfs(start){
		let stack = [start];
		let visited = {start:1};
		let result = [];
		while(stack.length > 0){
			let current = stack.pop();
			result.push(current);
			for(let i=0;i<this.adj_lists[current].length;i++){
				let neighbor = this.adj_lists[current][i];
				if(! visited[neighbor]){
					stack.push(neighbor.value);
					visited[neighbor] = 1;
				}
			}
		}
		return result;
	}

	shortestPath(start,finish){
		let nodes = new PriorityQueue();
		let distances = {};
		let previous = {};
		let inf = Infinity;
		let path = [];
		let smallest = null;
		for(let vertex in this.adj_lists){
			if(vertex === start){
				distances[vertex] = 0;
				nodes.enqueue(vertex,0);
			}
			else{
				distances[vertex] = inf;
				nodes.enqueue(vertex,inf);
			}
		}
		while(nodes.len !== 0){
			smallest = nodes.dequeue().value;
			if(smallest === finish){
				while(previous[smallest]){
					path.push(smallest);
					smallest = previous[smallest];
				}
				break;
			}
			else if(smallest || distances[smallest] !== inf){
				for(let i=0;i<this.adj_lists[smallest].length;i++){
					let neighbor = this.adj_lists[smallest][i];
					let candidate = distances[smallest] + neighbor.weight;
					let next_neighbor = neighbor.value;
					if(candidate < distances[next_neighbor]){
						distances[next_neighbor] = candidate;
						previous[next_neighbor] = smallest;
						nodes.enqueue(next_neighbor,candidate);
					}
				}
			}
		}
		path.push(smallest);
		return path.reverse();
	}
}

if (typeof module !== 'undefined' && require.main === module) {
	let graph = new WeightedGraph();
	graph.addVertex('a');
	graph.addVertex('b');
	graph.addVertex('c');
	graph.addVertex('d');
	graph.addVertex('e');
	graph.addVertex('f');
	graph.addEdge("a","b", 4);
	graph.addEdge("a","c", 2);
	graph.addEdge("b","e", 3);
	graph.addEdge("c","d", 2);
	graph.addEdge("c","f", 4);
	graph.addEdge("d","e", 3);
	graph.addEdge("d","f", 1);
	graph.addEdge("e","f", 1);
	console.log(graph);
	graph.removeVertex('b');
	console.log(graph.dfs('a'));
	console.log(graph.shortestPath('a','f'));
}