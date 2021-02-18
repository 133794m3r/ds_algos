<?php
function bubble_sort(&$arr){
	$len = count($arr);
	$swapped = false;
	for($i=$len;$i > 0;$i--){
		for($j=0;$j<$i-1;$j++){
			if($arr[$j] > $arr[$j+1]){
				$tmp = $arr[$j];
				$arr[$j] = $arr[$j+1];
				$arr[$j+1] = $tmp;
				$swapped = true;
			}
		}
		if(!$swapped) break;
	}
}

$arr = [3,2,1,6,7,9];
bubble_sort($arr);
print_r($arr);