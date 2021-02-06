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
	std::unordered_map<T,std::vector<Edge>> adj_lists_;
	ull vertexes_;
  public:
	WeightedGraph(){
		vertexes_ = 0;
	}
	bool add_vertex(T vertex){
		if(adj_lists_.count(vertex) > 0)
			return false;
		adj_lists_[vertex] = std::vector<Edge>();
		return true;
	}

	bool add_edge(T src, T dest, U weight){
		for(Edge edge: this->adj_lists_[src]){
			if(edge.node == dest){
				return false;
			}
		}
		adj_lists_[src].push_back(Edge(dest, weight));
		adj_lists_[dest].push_back(Edge(src, weight));
		return true;
	}
	void remove_edge(T v1, T v2){
		for(ull i =0; i < adj_lists_[v1].size(); i++){
			if(adj_lists_[v1][i].node == v2) {
				adj_lists_[v1].erase(adj_lists_[v1].begin() + i);
				break;
			}
		}
		for(ull i =0; i < adj_lists_[v2].size(); i++){
			if(adj_lists_[v2][i].node == v1) {
				adj_lists_[v2].erase(adj_lists_[v2].begin() + i);
				break;
			}
		}
	}
	bool remove_vertex(T v1){
		if(adj_lists_.count(v1) > 0){
			while(adj_lists_[v1].size()){
				Edge tmp = adj_lists_[v1][0];
				remove_edge(v1,tmp.node);
			}
			adj_lists_.erase(v1);
			vertexes_--;
			return true;
		}
		else{
			return false;
		}
	}

	std::vector<T> dfs(T start){
		Stack<T> stack(start);
		std::unordered_map<T,bool> visited{};
		visited.reserve(vertexes_);
		visited[start] = true;
		std::vector<T> result;
		result.reserve(vertexes_);
		while(stack.size()){
			T current = stack.pop();
			result.push_back(current);
			for(Edge neighbor: adj_lists_[current]){
				if(visited.count(neighbor.node) == 0){
					stack.push(neighbor.node);
					visited[neighbor.node] = true;
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
		for(auto pair:adj_lists_){
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
				for(Edge neighbor: adj_lists_[smallest]){
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
