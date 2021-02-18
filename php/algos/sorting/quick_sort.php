<?php
function swap(&$arr, $i,$j){
	[$arr[$i], $arr[$j] ] = [ $arr[$j], $arr[$i]];
}
function part(&$arr, $low, $high): int{
	$pivot = $arr[$high];
	$i = $low -1;
	for($j = $low; $j <= $high-1;$j++){
		if($arr[$j] < $pivot){
			swap($arr,++$i, $j);
		}
	}
	swap($arr, $i+1, $j);
	return $i+1;
}
function _qsort(&$arr,$low,$high){
	if($low < $high){
		$pi = part($arr, $low, $high);
		_qsort($arr, $low, $pi - 1);
		_qsort($arr, $pi+1, $high);
	}
}
function quick_sort(&$arr, $start=0){
	_qsort($arr,$start,count($arr)-1);
}


$arr = [1,4,0,5];
quick_sort($arr);
print_r($arr);