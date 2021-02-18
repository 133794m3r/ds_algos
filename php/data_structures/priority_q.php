<?php

class PQNode{
	public ?int $priority;
	public $value;
	public function __construct($value, $priority=null){
		$this->value = $value;
		$this->priority = $priority;
	}
	public function __toString(): string{
		return "{ value: $this->value, priority:$this->priority }";
	}
}

class PriorityQueue {
	private $values;
	private $len;
	public function __construct(){
		$this->values = array();
		$this->len = 0;
	}
	private function shift_up(){
		$index = $this->len - 1;
		while($index > 0){
			$parent_index = ($index -1) >> 1;
			if($this->values[$index] >= $this->values[$parent_index]) break;
			$tmp = $this->values[$parent_index];
			$this->values[$parent_index] = $this->values[$index];
			$this->values[$index] = $tmp;
			$index = $parent_index;
		}
	}
	private function shift_down(){
		$index = 0;
		while(true){
			$swap_id = $index;
			$left = ($index << 1) + 1;
			$right = $left + 1;
			if($left < $this->len && $this->values[$left] > $this->values[$index])
				$swap_id = $left;
			if($right < $this->len && $this->values[$right] < $this->values[$swap_id])
				$swap_id = $right;

			if($swap_id === $index) break;
			$tmp = $this->values[$index];
			$this->values[$index] = $this->values[$swap_id];
			$this->values[$swap_id] = $tmp;
			$index = $swap_id;
		}
	}

	public function enqueue($value, $priority){
		array_push($this->values, new PQNode($value, $priority));
		$this->len++;
		$this->shift_up();
	}

	public function dequeue(){
		$highest = null;
		if($this->len > 0){
			$highest = $this->values[0];
			$this->values[0] = array_pop($this->values);
			$this->len--;
			$this->shift_down();
		}
		return $highest;
	}

	public function __toString(): string{
		$os = '';
		$i = 0;
		while($i < $this->len){
			$os .= (string)$this->values[$i++];
			if($i <= $this->len - 1)
				$os .= ',';
		}
		return $os;
	}
	public function size(): int{
		return $this->len;
	}
}

if (!count(debug_backtrace(DEBUG_BACKTRACE_IGNORE_ARGS))){
	$pq = new PriorityQueue();
	$inf = 1 << 31;
	$pq->enqueue("a", 0);
	$pq->enqueue("b", $inf);
	$pq->enqueue("c", $inf);
	$pq->enqueue("d", $inf);
	$pq->enqueue("e", $inf);
	$pq->enqueue("f", $inf);
	$pq->dequeue();
	$pq->enqueue("b", 4);
	$pq->enqueue("c", 2);
	echo $pq . PHP_EOL;
	$pq->dequeue();
	$pq->enqueue("d", 4);
	echo $pq->size() . PHP_EOL;
	echo (string)$pq;
}