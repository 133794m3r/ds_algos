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

    /**
     * @return LinkNode|null
     */
    public function pop(): ?LinkNode {
        if($this->head == NULL){
            return NULL;
        }
        $prev = $this->get($this->length-2);
        $popped = $this->tail->value;
        $this->tail = $prev;
        $this->tail = NULL;
        $this->length--;
        return $popped;
    }

    public function push($value){
        if($this->head == NULL){
            $this->head = new LinkNode($value);
            $this->tail = $this->head;
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

$ll = new LinkedList();
$ll->push(1);
$ll->push(4);
$ll->push(5);
print($ll);