#ifndef _GRAPH_HXX
#define _GRAPH_HXX
#include "../linked_list/d_linked_list.hxx"
#include "../stack/stack.hxx"
//#include <deque>
#include <list>
#include <vector>
template <typename T> class Graph {
  private:
	std::vector<std::list<T>*> adj_lists;
	DoublyLinkedList<T> keys;
	size_t num_vertices;
  public:
	Graph(){
		num_vertices = 0;
	}
	explicit Graph(size_t total_vertices){
		for(size_t i=0; i < total_vertices; i++) {
			adj_lists.push_back(new std::list<T>());
		}
		num_vertices = total_vertices;
	}

	Graph(T *vertices,size_t total_vertices){
		for(size_t i=0; i < total_vertices; i++) {
//			adj_lists.push(new DoublyLinkedList<T>());
			adj_lists.push_back(new std::list<T>());
		}
		num_vertices = total_vertices;
	}

	void add_vertex(T vert){
		if(keys.find(vert) == -1){
			adj_lists.push_back(new std::list<T>{});
			keys.push(vert);
			num_vertices++;
		}
	}
	void add_edge(T src, T dest){
		long long idx = keys.find(src);
		std::list<T> tmp;
		if(idx != -1) {
			adj_lists[idx]->push_back(dest);
		}
		else {
			adj_lists.push_back(new std::list<T>());
			keys.push(src);
		}
		idx = keys.find(dest);
		if(idx != -1){

			adj_lists[idx]->push_back(src);
		}
		else{
			adj_lists.push_back(new std::list<T>());
			adj_lists[num_vertices++]->push_back(src);
			keys.push(dest);
		}
	}
	void remove_edge(T v1, T v2){
		long long idx = keys.find(v1);
		long long idx2 = keys.find(v2);
		if(idx == -1 or idx2 == -1) return;
		adj_lists[idx]->remove(v2);
		adj_lists[idx2]->remove(v1);
	}
	void remove_vertex(T vertex){
		long long idx = keys.find(vertex);
		if(idx == -1) return;
		std::list<T> *tmp = adj_lists[idx];

		auto it = tmp->begin();
		while(tmp->size() > 0){
			T v2 = *it;
			std::cout << *it << std::endl;
			it++;
			remove_edge(vertex, v2);
		}
		adj_lists.erase(adj_lists.begin()+idx);
		keys.remove(idx);
		delete(tmp);
		num_vertices--;
	}

	DoublyLinkedList<T> dfs(T start){
		Stack<T> stack{};
		size_t idx = keys.find(start);
		stack.push(idx);
		size_t idx2 = 0;
		std::vector<T> visited(num_vertices);
		size_t current;
		DoublyLinkedList<T> result{};
		visited[idx] = 1;
		while(stack.size() > 0){
			current = stack.pop();
			idx = keys.find(current);
			result.push(keys[idx]);
			for(auto it=adj_lists[idx]->begin();it != adj_lists[idx]->end();it++){
				idx2 = keys.find(*it);
				if(visited[idx2] == 0){
					stack.push(*it);
					visited[idx2] = 1;
				}
			}
		}
		return result;
	}
	void print(){
		for(size_t i=0;i<num_vertices;i++){
			std::cout << keys[i] << "-->";
			std::list<T> *tmp = adj_lists[i];
			size_t j =0;
			for(auto it=tmp->begin();it!=tmp->end();it++){
				std::cout << *it;
				if( j < tmp->size() -1)
					std::cout << ",";
				j++;
			}
			std::cout << std::endl;
		}
	}
	~Graph(){
		for(auto &x:adj_lists){
			delete x;
		}
		adj_lists.clear();
		num_vertices=0;
	}
};


#endif //_GRAPH_HXX
