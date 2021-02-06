#ifndef _DIJKSTRA_HXX
#define _DIJKSTRA_HXX
#include "../priority_q/priorityq.hxx"
//not using my own hashtable as the std::unordered_map is faster.
#include <unordered_map>
#include <algorithm>
/* std::stack or my own stack would work for this instance. As I'm not using
 * any iterators for the code. Modify all instances of Stack<T> for std::stack below to use std::stack
 * and uncomment next line and comment out mine.
 */
//#include <stack>
#include "../stack/stack.hxx"
template <typename T, typename U> class WeightedGraph {
  private:
	struct Edge{
		T node;
		U weight;
		Edge(T node_, U weight_){
			this->node = node_;
			this->weight = weight_;
		}
	};
  public:
	std::unordered_map<T,std::vector<Edge>> adj_lists;
	ull vertexes;
	WeightedGraph(){
		vertexes = 0;
	}
	bool add_vertex(T vertex){
		if(adj_lists.count(vertex) > 0)
			return false;
		adj_lists[vertex] = std::vector<Edge>();
		return true;
	}

	bool add_edge(T src, T dest, U weight){
		for(Edge edge: this->adj_lists[src]){
			if(edge.node == dest){
				return false;
			}
		}
		adj_lists[src].push_back(Edge(dest,weight));
		adj_lists[dest].push_back(Edge(src,weight));
		return true;
	}
	void remove_edge(T v1, T v2){
		for(ull i =0;i<adj_lists[v1].length;i++){
			if(adj_lists[v1][i].node == v2) {
				adj_lists[v1].erase(adj_lists[v1].begin() + i);
				break;
			}
		}
		for(ull i =0;i<adj_lists[v2].length;i++){
			if(adj_lists[v2][i].node == v1) {
				adj_lists[v2].erase(adj_lists[v2].begin() + i);
				break;
			}
		}
	}
	bool remove_vertex(T v1){
		if(adj_lists.count(v1) > 0){
			while(adj_lists[v1].size()){
				Edge tmp = adj_lists[v1][0];
				remove_edge(v1,tmp.node);
			}
			adj_lists.erase(v1);
			vertexes--;
			return true;
		}
		else{
			return false;
		}
	}

	std::vector<T> dfs(T start){
		Stack stack(start);
		std::unordered_map<T,bool> visited{};
		visited.reserve(vertexes);
		visited[start] = true;
		std::vector<T> result;
		result.reserve(vertexes);
		while(stack){
			T current = stack.pop();
			result.push_back(current);
			for(Edge neighbor: adj_lists[current]){
				if(visited.count(neighbor.node) == 0){
					stack.push(neighbor);
					visited[neighbor] = true;
				}
			}
		}
		return result;
	}
	std::vector<T> shortest_path(T start, T finish){
		std::unordered_map<T, ull> distances;
		std::unordered_map<T, T> previous;
		ull inf = (1 << 64) -1;
		std::vector<T> path;
		T smallest;
		PriorityQueue<T, ull> nodes;
		for(auto pair:adj_lists){
			if (pair.first == start){
				distances[pair.first] = 0;
				nodes.enqueue(pair.first,0);
			}
			else{
				distances[pair.first] = inf;
				nodes.enqueue(pair.first,inf);
			}
			previous[pair.first] =T();
		}
		while(nodes.length()){
			smallest = nodes.dequeue();
			if(smallest == finish){
				while (previous[smallest] != T()){
					path.push_back(smallest);
					smallest = previous[smallest];
				}
				break;
			}
				for(Edge neighbor: adj_lists[smallest]){
					U candidate = distances[smallest] + neighbor.weight;
					T next_neighbor = neighbor.node;
					if(candidate < distances[next_neighbor]){
						distances[next_neighbor] = candidate;
						previous[next_neighbor] = smallest;
						nodes.enqueue(next_neighbor,candidate);
					}
				}
		}

		path.push_back(smallest);
		std::reverse(path.begin(), path.end());
		return path;
	}
};


#endif //_DIJKSTRA_HXX
