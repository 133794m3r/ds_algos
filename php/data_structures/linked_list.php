<?php
class LinkNode{
    /**
     * @var mixed
     */
    public $value;
    /**
     * @var LinkNode | NULL
     */
    public $next;
    public function __construct($val, $nxt=NULL){
        $this->value = $val;
        $this->next = $nxt;
    }
}
class LinkedList{
    /**
     * @var LinkNode | NULL
     */
    private ?LinkNode $head_;
    /**
     * @var LinkNode | NULL
     */
    private ?LinkNode $tail_;
    /**
     * @var int
     */
    private int $length_;

    public function __construct() {
        $this->head_ = NULL;
        $this->tail_ = NULL;
        $this->length_ = 0;
    }

    public function get($index): ?LinkNode {
        if ($index < 0 or $index > $this->length_){
            return NULL;
        }
        $cur = $this->head_;
        $i = 0;
        while ($i != $index){
            $cur = $cur->next;
            $i++;
        }
        return $cur;
    }
	public function unshift($value){
    	if($this->head_)
    		$this->head_ = new LinkNode($value,$this->head_);
    	else{
    		$this->head_ = new LinkNode($value);
    		$this->tail_ = $this->head_;
		}
    	$this->length_++;
	}
	public function shift(): ?LinkNode {
    	if($this->head_){
    		$tmp = $this->head_;
    		$this->head_ = $tmp->next;
    		$this->length_--;
    		if($this->length_ === 0){
    			$this->tail_ = NULL;
			}
    		return $tmp;
		}
    	return NULL;
	}

    public function insert($index,$value){
    	if($index > $this->length_ || $index < 0)
    		return NULL;
    	else if($index == 0)
    		$this->unshift($value);
    	else if($this->head_ === null) {
			$this->head_ = new LinkNode($value);
			$this->tail_ = $this->head_;
		}
    	else{
    		$prev = $this->get($index - 1);
    		$prev->next = new LinkNode($value,$prev->next);
		}
    	$this->length_++;
	}
	public function set($index, $value){
    	if($index > 0 && $index < $this->length_){
    		$p = $this->get($index);
    		$p->value = $value;
		}
	}
    /**
     * @return LinkNode|null
     */
    public function pop(): ?LinkNode {
        if($this->head_ == NULL){
            return NULL;
        }
        $popped = $this->tail_;
        if($this->length_ > 1) {
			$prev = $this->get($this->length_-2);
			$this->tail_ = $prev;
			$this->tail_->next = NULL;
		}
        else
	        $this->tail_ = NULL;
        $this->length_--;
        return $popped;
    }
	public function remove($index): ?LinkNode {
		if($index < 0 || $index > $this->length_)
			return NULL;

		if($index === $this->length_ - 1)
			return $this->pop();
		else if($index === 0)
			return $this->shift();
		else{
			$prev = $this->get($index-1);
			$removed = $prev->next;
			$prev->next = $removed->next;
			$this->length_--;
			return $removed;
		}
	}
    public function push($value){
        if($this->head_ == NULL){
            $this->head_ = new LinkNode($value);
            $this->tail_ = $this->head_;
            $this->length_++;
        }
        else{
            $cur = $this->head_;
            while($cur->next != NULL){
                $cur = $cur->next;
            }
            $cur->next = new LinkNode($value);
            $this->tail_ = $cur->next;
            $this->length_++;
        }
    }

    public function reverse(){
    	$current = $this->head_;
    	$prev = NULL;
    	$next = NULL;
    	$this->head_ = $this->tail_;
    	$this->tail_ = $current;
    	while($current){
    		$next = $current->next;
    		$current->next = $prev;
    		$prev = $current;
    		$current = $next;
		}
		$this->head_ = $prev;
	}
    public function __toString(): string {
        $cur = $this->head_;
        $res = "[";
        while($cur->next != NULL){
            $res.="$cur->value, ";
            $cur = $cur->next;
        }
        $res .= "$cur->value]";
        return $res;
    }

}

if (!count(debug_backtrace(DEBUG_BACKTRACE_IGNORE_ARGS))){
	$ll = new LinkedList();
	$ll->push(4);
	$ll->push(5);
	$ll->push(6);
	$ll->insert(2, 222);
	$ll->push(7);
	$ll->push(8);
	$ll->push(9);
	$ll->push(10);
	$ll->reverse();
	$ll->pop();
	$ll->set(2, 100);
	$ll->insert(5, 555);
	$ll->insert(4, 444);
	$ll->shift();
	$ll->unshift(6);
	$ll->remove(5);
	$expected = '[6, 9, 100, 7, 444, 555, 222, 5]';
	if((string)$ll === $expected)
		echo "All's Clear\n";
	else
		echo "Error\n$ll\n";
}