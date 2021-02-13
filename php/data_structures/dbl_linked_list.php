<?php
class DblLinkNode{
    /**
     * @var mixed
     */
    public $value;
    /**
     * @var DblLinkNode | NULL
     */
    public $next;
    public $prev;
    public function __construct($val, $prev=NULL, $nxt=NULL){
        $this->value = $val;
        $this->next = $nxt;
        $this->prev = $prev;
    }
}

class DblLinkedList{
    /**
     * @var DblLinkNode | NULL
     */
    private ?DblLinkNode $head_;
    /**
     * @var DblLinkNode | NULL
     */
    private ?DblLinkNode $tail_;
    /**
     * @var int
     */
    private int $length_;

    public function __construct() {
        $this->head_ = NULL;
        $this->tail_ = NULL;
        $this->length_ = 0;
    }
	public function unshift($value){
		if($this->head_)
			$this->head_ = new DblLinkNode($value,null,$this->head_);
		else{
			$this->head_ = new DblLinkNode($value);
			$this->tail_ = $this->head_;
		}
		$this->length_++;
	}
	public function shift(): ?DblLinkNode {
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
		else if($this->head_ === NULL){
			$this->head_ = new DblLinkNode($value);
			$this->tail_ = $this->head_;
		}
		else{
			$prev = $this->get($index - 1);
			$prev->next = new DblLinkNode($value,$prev,$prev->next);
		}
		$this->length_++;
	}
	public function set($index, $value){
		if($index > 0 && $index < $this->length_){
			$p = $this->get($index);
			$p->value = $value;
		}
	}
    public function get($index): ?DblLinkNode {
        if ($index < 0 or $index > $this->length_){
            return NULL;
        }
        $cur = $this->head_;
        $i = 0;
        if($index <= ($this->length_ >> 1)){
			while ($i != $index){
				$cur = $cur->next;
				$i++;
			}
		}
        else{
        	$cur = $this->tail_;
        	$i = $this->length_-1;
        	while($i != $index){
        		$cur = $cur->prev;
        		$i--;
			}
		}
		return $cur;
	}

	/**
     * @return DblLinkNode|null
     */
    public function pop(): ?DblLinkNode {
        if($this->head_ == NULL){
            return NULL;
        }
		$popped = $this->tail_;
        if($this->length_ == 1){
        	$this->head_ = $this->tail_ = NULL;
		}
        else{
        	$this->tail_ = $popped->prev;
        	$this->tail_->next = NULL;
		}
        $this->length_--;
        return $popped;
    }

    public function push($value){
        if($this->head_ == NULL){
            $this->head_ = new DblLinkNode($value);
            $this->tail_ = $this->head_;
        }
        else{
			$p = new DblLinkNode($value,$this->tail_);
			$this->tail_->next = $p;
			$this->tail_ = $p;
        }
        $this->length_++;
    }

	public function remove($index): ?DblLinkNode {
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

	public function reverse(){
  	 	$this->tail_->next = null;
		$cur = $this->head_;
		$this->head_ = $this->tail_;
		$this->tail_ = $cur;
		$prev = null;
		$next = null;
		while($cur !== null){
			$next = $cur->next;
			$cur->next = $prev;
			$cur->prev = $next;
			$prev = $cur;
			$cur = $next;
		}
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

$ll = new DblLinkedList();
$ll->push(4);
$ll->push(5);
$ll->push(6);
$ll->insert(2, 222);
$ll->push(7);
$ll->push(8);
$ll->push(9);
$ll->push(10);
echo "$ll\n";
$ll->reverse();
$ll->pop();
$ll->set(2, 100);
$ll->insert(5, 555);
$ll->insert(4, 444);
$ll->shift();
$ll->unshift(6);
$ll->remove(5);
echo "$ll\n";