//
// Created by macarthur on 1/19/21.
//

#include "graph.hxx"
int main(){
	Graph<int> graph{};
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.add_vertex(5);
	graph.add_edge(0,1);
	graph.add_edge(0,2);
	graph.add_edge(1,3);
	graph.add_edge(2,4);
	graph.add_edge(3,4);
	graph.add_edge(3,5);
	graph.add_edge(4,5);
	graph.print();
	graph.remove_vertex(1);
	std::cout << std::endl;
	graph.print();
	DoublyLinkedList<int> res = graph.dfs(0);
	res.display();
	return 0;
}