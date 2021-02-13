<?php
class QueueNode{
	/**
	 * @var mixed
	 */
	public $value;
	public $next;
	public function __construct($value,$next=null){
		$this->value = $value;
		$this->next = $next;
	}
}
class Queue {
	public int $size;
	public ?QueueNode $first;
	public ?QueueNode $last;

	public function __construct(){
		$this->first = null;
		$this->last = null;
		$this->size = 0;
	}

	public function enqueue($value){
		if($this->first === null){
			$this->first = new QueueNode($value);
			$this->last = $this->first;
		}
		else{
			$tmp = new QueueNode($value);
			$this->last->next = $tmp;
			$this->last = $tmp;
		}
		$this->size++;
	}

	public function dequeue(){
		if(!$this->first){
			return null;
		}
		if($this->first === $this->last)
			$this->last = null;

		$tmp = $this->first;
		$this->first = $this->first->next;
		$this->size--;
		return $tmp->value;
	}
	public function __toString(): string {
		$os = '{' . PHP_EOL;
		$tmp = $this->first;
		while ($tmp) {
			$os .= "| value: $tmp->value |";
			$os .= "\t";
			$tmp = $tmp->next;
		}
		$os .= PHP_EOL.'}'.PHP_EOL;
		return $os;
	}
	public function length(){
		return $this->size;
	}
}

$q = new Queue();
$q->enqueue(1);
$q->enqueue(2);
$q->enqueue(3);
echo $q.PHP_EOL;
echo $q->dequeue().PHP_EOL;
echo $q.PHP_EOL;
