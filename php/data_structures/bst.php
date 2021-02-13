<?php
require_once 'queue.php';
class BSTNode{
	/**
	 * @var mixed
	 */
	public  $value;
	public $left;
	public $right;

	public function __construct($value,$left=null,$right=null){
		$this->value = $value;
		$this->left = $left;
		$this->right = $right;
	}
}
class BinarySearchTree {

	private ?BSTNode $root;
	public function __construct(){
		$this->root = null;
	}

	public function find($value): ?BSTNode{
		if($this->root === null)
			return null;

		$cur = $this->root;
		$found = false;
		while(! $found){
			if($cur->value > $value)
				$cur = $cur->left;
			else if($cur->value < $value)
				$cur = $cur->right;
			else
				return $cur;
		}
		return null;
	}

	public function contains($value): bool {
		$cur = $this->root;
		while($cur){
			if($cur->value > $value)
				$cur = $cur->left;
			else if($cur->value < $value)
				$cur = $cur->right;
			else
				return true;
		}
		return false;
	}

	public function insert($value){
		if($this->root === null){
			$this->root = new BSTNode($value);
		}
		else{
			$cur = $this->root;
			while($cur !== null){
				if($cur->value > $value) {
					if($cur->left)
						$cur = $cur->left;
					else{
						$cur->left = new BSTNode($value);
						break;
					}
				}
				else if($cur->value < $value) {
					if($cur->right)
						$cur = $cur->right;
					else{
						$cur->right = new BSTNode($value);
						break;
					}
				}
				else
					break;
			}
		}
	}
	public function _height($node): int{
		if($node === null)
			return 0;
		else{
			$x = $this->_height($node->left);
			$y = $this->_height($node->right);
			return $x>$y?$x+1:$y+1;
		}
	}

	public function get_height($node=null): int{
		if($node === null)
			$node = $this->root;

		return $this->_height($node);
	}

	public function _remove($node, $key){
		if($node === null)
			return null;
		if(! ($node->left && $node->right)){
			if($node->left === $node->right){
				if($node === $this->root)
					$this->root = null;
				return null;
			}
		}
		if($key < $node->value)
			$node->left = $this->_remove($node->left, $key);
		else if($key > $node->value)
			$node->right = $this->_remove($node->right, $key);
		else{
			if($this->_height($node->left) > $this->_height($node->right)){
				$q = $node->left;
				while($q && ($node->right !== null)){
					$q = $q->right;
				}
				$node->value = $q->value;
				$node->left = $this->_remove($node->left,$q->value);
			}
			else {
				$q = $node->right;
				while ($q && ($node->left !== null)) {
					$q = $q->left;
				}
				$node->value = $q->value;
				$node->right = $this->_remove($node->right, $q->value);
			}
		}
		return $node;
	}
	public function remove($key){
		return $this->_remove($this->root, $key);
	}
	public function bfs(): array{
		$q = new Queue();
		$data = [];
		$q->enqueue($this->root);
		while($q->size){
			$cur = $q->dequeue();
			array_push($data,$cur->value);
			if($cur->left) $q->enqueue($cur->left);
			if($cur->right) $q->enqueue($cur->right);
		}
		return $data;
	}

	private function pre_traverse(&$data, $node){
		array_push($data, $node->value);
		if($node->left) $this->pre_traverse($data, $node->left);
		if($node->right) $this->pre_traverse($data, $node->right);
	}

	private function in_traverse(&$data,$node){
		if($node->left) $this->pre_traverse($data, $node->left);
		array_push($data, $node->value);
		if($node->right) $this->pre_traverse($data, $node->right);
	}

	private function post_traverse(&$data,$node){
		if($node->left) $this->pre_traverse($data, $node->left);
		if($node->right) $this->pre_traverse($data, $node->right);
		array_push($data, $node->value);
	}

	public function pre_order(): array{
		$cur = $this->root;
		$data = [];
		$this->pre_traverse($data,$cur);
		return $data;
	}

	public function in_order(): array{
		$cur = $this->root;
		$data = [];
		$this->in_traverse($data,$cur);
		return $data;
	}

	public function post_order(): array{
		$cur = $this->root;
		$data = [];
		$this->post_traverse($data, $cur);
		return $data;
	}

}

//comment out all of this if you don't need it as it is used when running via cli.
if($argc) {
	$bst = new BinarySearchTree();
	$bst->insert(10);
	$bst->insert(6);
	$bst->insert(15);
	$bst->insert(3);
	$bst->insert(8);
	$bst->insert(20);

	$bfs = $bst->bfs();
	var_dump($bfs);
	$tmp = $bst->pre_order();
	var_dump($tmp);
	$tmp = $bst->in_order();
	echo "IO\n";
	var_dump($tmp);
	echo $bst->get_height() . "\n";
	echo $bst->remove(3)->value . "\n";
	var_dump($bst->in_order());
	var_dump($bst->post_order());
	echo $bst->find(6)->value.PHP_EOL;
	echo $bst->contains(8).PHP_EOL;
}