<?php

class MaxBinaryHeap{
	private array $values;
	private int $size;


	public function __construct(){
		$this->values = [];
		$this->size = 0;
	}

	public function shift_up(){
		$index = $this->size-1;
		$item = $this->values[$index];
		while($index > 0){
			$parent_index = ($index -1) >> 1;
			$parent = $this->values[$parent_index];
			if($item <= $parent) break;
			$this->values[$parent_index] = $item;
			$this->values[$index] = $parent;
			$index = $parent_index;
		}
	}

	public function shift_down(){
		$el = $this->values[0];
		$index = 0;
		while($index < $this->size){
			$swap_id = $index;
			$left = ($index << 1)+1;
			$right = $left+1;
			if($left < $this->size && $this->values[$left] < $el )
				$swap_id = $left;
			if($right < $this->size && $this->values[$swap_id] < $this->values[$right])
				$swap_id = $right;
			if($swap_id === $index) break;
			$this->values[$index] = $this->values[$swap_id];
			$this->values[$swap_id] = $el;
			$index = $swap_id;
		}
	}

	public function insert($element){
		array_push($this->values,$element);
		$this->size++;
		$this->shift_up();
	}
	public function extract_max(){
		$removed = null;
		if($this->size > 0){
			$removed = $this->values[0];
			$end = array_pop($this->values);
			$this->values[0] = $end;
			$this->size--;
			$this->shift_down();
		}
		return $removed;
	}
	public function get_max(){
		if($this->size > 0)
			return $this->values[0];
		else
			return null;
	}
}

$heap = new MaxBinaryHeap();
$heap->insert(41);
$heap->insert(39);
$heap->insert(33);
$heap->insert(18);
$heap->insert(27);
$heap->insert(12);
$heap->insert(55);
echo $heap->extract_max().PHP_EOL;
echo $heap->get_max().PHP_EOL;