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
	private int $size_;
	private ?QueueNode $first_;
	private ?QueueNode $last_;

	public function __construct(){
		$this->first_ = null;
		$this->last_ = null;
		$this->size_ = 0;
	}

	public function enqueue($value){
		if($this->first_ === null){
			$this->first_ = new QueueNode($value);
			$this->last_ = $this->first_;
		}
		else{
			$tmp = new QueueNode($value);
			$this->last_->next = $tmp;
			$this->last_ = $tmp;
		}
		$this->size_++;
	}

	public function dequeue(){
		if(!$this->first_){
			return null;
		}
		if($this->first_ === $this->last_)
			$this->last_ = null;

		$tmp = $this->first_;
		$this->first_ = $this->first_->next;
		$this->size_--;
		return $tmp->value;
	}
	public function __toString(): string {
		$os = '{' . PHP_EOL;
		$tmp = $this->first_;
		while ($tmp) {
			$os .= "| value: $tmp->value |";
			$os .= "\t";
			$tmp = $tmp->next;
		}
		$os .= PHP_EOL.'}'.PHP_EOL;
		return $os;
	}
	public function length(){
		return $this->size_;
	}
}

$q = new Queue();
$q->enqueue(1);
$q->enqueue(2);
$q->enqueue(3);
echo $q.PHP_EOL;
echo $q->dequeue().PHP_EOL;
echo $q.PHP_EOL;
