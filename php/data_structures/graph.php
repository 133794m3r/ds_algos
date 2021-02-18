<?php
require_once "stack.php";
class Graph {
	protected array $adj_lists;
	private int $vertexes;
	public function __construct(){
		$this->adj_lists = array();
		$this->vertexes = 0;
	}

	public function add_vertex($vertex){
		if(!array_key_exists($vertex,$this->adj_lists)){
			$this->adj_lists[$vertex] = array();
			$this->vertexes++;
		}
	}

	public function add_edge($src, $dest){
		if(in_array($dest,$this->adj_lists[$src])){
			return;
		}
		array_push($this->adj_lists[$src],$dest);
		array_push($this->adj_lists[$dest],$src);
	}

	public function remove_edge($v1,$v2){
		$this->adj_lists[$v1] = array_values(array_filter($this->adj_lists[$v1],function($x) use ($v2) {
			return $x !== $v2;
		}));
		$this->adj_lists[$v2] = array_values(array_filter($this->adj_lists[$v2], function($x) use ($v1){
			return $x !== $v1;
		}));
	}

	public function remove_vertex($v1){
		while($this->adj_lists[$v1]){
			$v2 = $this->adj_lists[$v1][0];
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
				if(!array_key_exists($neighbor,$visited)){
					$stack->push($neighbor);
					$visited[$neighbor] = 1;
				}
			}
		}
		return $result;
	}

}

if (!count(debug_backtrace(DEBUG_BACKTRACE_IGNORE_ARGS))){
	$g = new Graph();
	$g->add_vertex('a');
	$g->add_vertex('b');
	$g->add_vertex('c');
	$g->add_vertex('d');
	$g->add_vertex('e');
	$g->add_vertex('f');
	$g->add_edge('a','b');
	$g->add_edge('a','c');
	$g->add_edge('b','d');
	$g->add_edge('c','e');
	$g->add_edge('d','e');
	$g->add_edge('d','f');
	$g->add_edge('e','f');
	var_dump($g);
	$g->remove_vertex('b');
	var_dump($g);
	var_dump($g->dfs('a'));
}