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
    private ?LinkNode $head;
    /**
     * @var LinkNode | NULL
     */
    private ?LinkNode $tail;
    /**
     * @var int
     */
    private int $length;

    public function __construct() {
        $this->head = NULL;
        $this->tail = NULL;
        $this->length = 0;
    }

    public function get($index): ?LinkNode {
        if ($index < 0 or $index > $this->length){
            return NULL;
        }
        $cur = $this->head;
        $i = 0;
        while ($i != $index){
            $cur = $cur->next;
            $i++;
        }
        return $cur;
    }
	public function unshift($value){
    	if($this->head)
    		$this->head = new LinkNode($value,$this->head);
    	else{
    		$this->head = new LinkNode($value);
    		$this->tail = $this->head;
		}
    	$this->length++;
	}
	public function shift(): ?LinkNode {
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
    	else{
    		$prev = $this->get($index - 1);
    		$prev->next = new LinkNode($value,$prev->next);
		}
    	$this->length++;
	}
	public function set($index, $value){
    	if($index > 0 && $index < $this->length){
    		$p = $this->get($index);
    		$p->value = $value;
		}
	}
    /**
     * @return LinkNode|null
     */
    public function pop(): ?LinkNode {
        if($this->head == NULL){
            return NULL;
        }
        $popped = $this->tail;
        if($this->length > 1) {
			$prev = $this->get($this->length-2);
			$this->tail = $prev;
			$this->tail->next = NULL;
		}
        else
	        $this->tail = NULL;
        $this->length--;
        return $popped;
    }
	public function remove($index): ?LinkNode {
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
    public function push($value){
        if($this->head == NULL){
            $this->head = new LinkNode($value);
            $this->tail = $this->head;
            $this->length++;
        }
        else{
            $cur = $this->head;
            while($cur->next != NULL){
                $cur = $cur->next;
            }
            $cur->next = new LinkNode($value);
            $this->tail = $cur->next;
            $this->length++;
        }
    }

    public function reverse(){
    	$current = $this->head;
    	$prev = NULL;
    	$next = NULL;
    	$this->head = $this->tail;
    	$this->tail = $current;
    	while($current){
    		$next = $current->next;
    		$current->next = $prev;
    		$prev = $current;
    		$current = $next;
		}
		$this->head = $prev;
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

if($argv) {
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