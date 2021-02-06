#include "weighted_graph.hxx"
#include "../../vectors.hxx"
int main(){;
	WeightedGraph<std::string,ull> graph;
	graph.add_vertex("a");
	graph.add_vertex("b");
	graph.add_vertex("c");
	graph.add_vertex("d");
	graph.add_vertex("e");
	graph.add_vertex("f");
	graph.add_edge("a","b", 4);
	graph.add_edge("a","c", 2);
	graph.add_edge("b","e", 3);
	graph.add_edge("c","d", 2);
	graph.add_edge("c","f", 4);
	graph.add_edge("d","e", 3);
	graph.add_edge("d","f", 1);
	graph.add_edge("e","f", 1);
	graph.shortest_path("a","f");
	std::cout << graph.shortest_path("a","f");
	std::cout << graph.dfs("a");
	graph.remove_vertex("a");
}
