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
    private ?DblLinkNode $head;
    /**
     * @var DblLinkNode | NULL
     */
    private ?DblLinkNode $tail;
    /**
     * @var int
     */
    private int $length;

    public function __construct() {
        $this->head = NULL;
        $this->tail = NULL;
        $this->length = 0;
    }
	public function unshift($value){
		if($this->head)
			$this->head = new DblLinkNode($value,null,$this->head);
		else{
			$this->head = new DblLinkNode($value);
			$this->tail = $this->head;
		}
		$this->length++;
	}
	public function shift(): ?DblLinkNode {
		if($this->head){
			$tmp = $this->head;
			$this->head = $tmp->next;
			$this->length--;
			if($this->length === 0){
				$this->tail = NULL;
			}
			return $tmp;
		}
		return NULL;
	}

	public function insert($index,$value){
		if($index > $this->length || $index < 0)
			return NULL;
		else if($index == 0)
			$this->unshift($value);
		else if($this->head === NULL){
			$this->head = new DblLinkNode($value);
			$this->tail = $this->head;
		}
		else{
			$prev = $this->get($index - 1);
			$prev->next = new DblLinkNode($value,$prev,$prev->next);
		}
		$this->length++;
	}
	public function set($index, $value){
		if($index > 0 && $index < $this->length){
			$p = $this->get($index);
			$p->value = $value;
		}
	}
    public function get($index): ?DblLinkNode {
        if ($index < 0 or $index > $this->length){
            return NULL;
        }
        $cur = $this->head;
        $i = 0;
        if($index <= ($this->length >> 1)){
			while ($i != $index){
				$cur = $cur->next;
				$i++;
			}
		}
        else{
        	$cur = $this->tail;
        	$i = $this->length-1;
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
        if($this->head == NULL){
            return NULL;
        }
		$popped = $this->tail;
        if($this->length == 1){
        	$this->head = $this->tail = NULL;
		}
        else{
        	$this->tail = $popped->prev;
        	$this->tail->next = NULL;
		}
        $this->length--;
        return $popped;
    }

    public function push($value){
        if($this->head == NULL){
            $this->head = new DblLinkNode($value);
            $this->tail = $this->head;
        }
        else{
			$p = new DblLinkNode($value,$this->tail);
			$this->tail->next = $p;
			$this->tail = $p;
        }
        $this->length++;
    }
	public function remove($index): ?DblLinkNode {
		if($index < 0 || $index > $this->length)
			return NULL;
		if($index === $this->length - 1)
			return $this->pop();
		else if($index === 0)
			return $this->shift();
		else{
			$prev = $this->get($index-1);
			$removed = $prev->next;
			$prev->next = $removed->next;
			$this->length--;
			return $removed;
		}
	}
	public function reverse(){
//    	$cur = $this->head;
////    	$this->head = $this->tail;
//    	$this->tail = $cur;
//    	$prev = NULL;
//    	$next = NULL;
//    	$tmp = null;
//    	while($cur !== NULL){
//			$tmp = $cur->prev;
//			$cur->prev = $cur->next;
//			$cur->next = $tmp;
//			$cur = $cur->prev;
//		}
//		if($tmp !== null)
//			$this->head = $tmp;
//    	$this->tail->next = null;
		$cur = $this->head;
		$this->head = $this->tail;
		$this->tail = $cur;
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
        $cur = $this->head;
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