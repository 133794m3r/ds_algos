<?php
require_once "priority_q.php";
require_once "graph.php";
class _wg_edge{
	/**
	 * @var mixed
	 */
	public $node;
	/**
	 * @var numeric
	 */
	public $weight;
	public function __construct($value,$weight){
		$this->node = $value;
		$this->weight = $weight;
	}
}

class WeightedGraph extends Graph{

	public function add_edge($src,$dest,$weight=0){
		if(!array_key_exists($src,$this->adj_lists) || !array_key_exists($dest,$this->adj_lists)){
			return;
		}
		if(!in_array($src,$this->adj_lists[$src])){
			array_push($this->adj_lists[$src],new _wg_edge($dest,$weight));
			array_push($this->adj_lists[$dest],new _wg_edge($src,$weight));
		}
	}
	public function remove_edge($v1,$v2){
		$this->adj_lists[$v1] = array_values(array_filter($this->adj_lists[$v1],function($x) use ($v2) {
			return $x->node !== $v2;
		}));
		$this->adj_lists[$v2] = array_values(array_filter($this->adj_lists[$v2], function($x) use ($v1){
			return $x->node !== $v1;
		}));
	}
	public function remove_vertex($v1){
		while($this->adj_lists[$v1]){
			$v2 = $this->adj_lists[$v1][0]->node;
			$this->remove_edge($v1,$v2);
		}
		unset($this->adj_lists[$v1]);
	}
	public function dfs($start): array{
		$stack = new Stack();
		$visited = array();
		$stack->push($start);
		$visited[$start] = 1;
		$result = [];
		while($stack->size()){
			$current = $stack->pop();
			array_push($result,$current);
			foreach($this->adj_lists[$current] as $neighbor){
				if(!array_key_exists($neighbor->node,$visited)){
					$stack->push($neighbor->node);
					$visited[$neighbor->node] = 1;
				}
			}
		}
		return $result;
	}
	public function shortest_path($start,$finish): array {
		$nodes = new PriorityQueue();
		$distances = array();
		$previous = array();
		$inf = 1<<32;
		$path = array();
		$smallest = null;
		foreach(array_keys($this->adj_lists) as $vertex){
			if($start === $vertex){
				$distances[$vertex] = 0;
				$nodes->enqueue($vertex,0);
			}
			else{
				$distances[$vertex] = $inf;
				$nodes->enqueue($vertex,$inf);
			}
		}
		while($nodes->size()){
			$smallest = $nodes->dequeue()->value;
			if($smallest === $finish){
				while(array_key_exists($smallest,$previous) && $previous[$smallest]){
					array_push($path,$smallest);
					$smallest = $previous[$smallest];
				}
				break;
			}
			else if($smallest || $distances[$smallest] !== $inf){
				foreach($this->adj_lists[$smallest] as $neighbor){
					$candidate = $distances[$smallest] + $neighbor->weight;
					$next_neighbor = $neighbor->node;
					if($candidate < $distances[$next_neighbor]){
						$distances[$next_neighbor] = $candidate;
						$previous[$next_neighbor] = $smallest;
						$nodes->enqueue($next_neighbor, $candidate);
					}
				}
			}
		}
		array_push($path, $smallest);
		return array_reverse($path);
	}

}

if (!count(debug_backtrace(DEBUG_BACKTRACE_IGNORE_ARGS))){
	$g = new WeightedGraph();
	$g->add_vertex('a');
	$g->add_vertex('b');
	$g->add_vertex('c');
	$g->add_vertex('d');
	$g->add_vertex('e');
	$g->add_vertex('f');
	$g->add_edge('a', 'b', 4);
	$g->add_edge('a', 'c', 2);
	$g->add_edge('b', 'd', 3);
	$g->add_edge('c', 'd', 2);
	$g->add_edge('c', 'f', 4);
	$g->add_edge('d', 'e', 3);
	$g->add_edge('d', 'f', 1);
	$g->add_edge('e', 'f', 1);
	print_r($g);
	echo "shortest path PHP_EOL";
	print_r($g->shortest_path('a','f'));
	print_r($g->dfs('a'));
	$g->remove_vertex('b');
	print_r($g);
}


