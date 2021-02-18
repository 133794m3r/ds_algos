<?php
function num_digits($num){
	if($num < 0)
		return floor(log10($num*-1))+1;
	else
		return floor(log10($num))+1;
}

function most_digits($arr,$len): int {
	$max_digits = 0;
	for($i=0;$i<$len;$i++){
		$max_digits = max($max_digits, num_digits($arr[$i]));
	}
	return $max_digits;
}
function count_sort(&$arr,$n,$exp){
	$buckets = array();
	$count = array(0,0,0,0,0,0,0,0,0,0,0);
	for($i=0;$i<$n;$i++){
		$count[($arr[$i]/$exp) % 10]++;
	}
	for($i=1;$i<10;$i++){
		$count[$i] += $count[$i-1];
	}
	for($i=$n-1;$i>=0;$i--){
		$buckets[$count[($arr[$i]/$exp) % 10] -1] = $arr[$i];
		$count[($arr[$i]/$exp) %10]--;
	}
	for($i=0;$i<$n;$i++){
		$arr[$i] = $buckets[$i];
	}
}
function radix_sort(&$arr){
	$len = count($arr);
	$exp = 1;
	$max_digits = most_digits($arr,$len);
	for($i=0;$i<$max_digits;$i++){
		count_sort($arr,$len, $exp);
		$exp*=10;
	}
}

$arr = [1,3,4,7,0,6];
$arr2 = $arr;
radix_sort($arr);
print_r($arr);
