<?php
class StackNode{
	public $value;
	public ?StackNode $next;
	public function __construct($value, $next=null) {
		$this->value=$value;
		$this->next=$next;
	}
	public function __toString(): string {
		return (string) $this->value;
	}
}

class Stack {
	private ?StackNode $first;
	private ?StackNode $last;
	private int $size;
	public function __construct(){
		$this->first = null;
		$this->last = null;
		$this->size = 0;
	}
	public function push($value){
		if($this->first)
			$this->first = new StackNode($value,$this->first);
		else{
			$this->first = new StackNode($value);
			$this->last = $this->first;
		}
		$this->size++;
	}

	public function pop(){
		if($this->first === null)
			return null;
		if($this->first === $this->last)
			$this->last = null;
		$tmp = $this->first->value;
		$this->first = $this->first->next;
		$this->size--;
		return $tmp;
	}
}

if($argc == 1){
	$stack = new Stack();
	$stack->push('a');
	$stack->push('b');
	$stack->push('c');
	echo $stack->pop().PHP_EOL;

}