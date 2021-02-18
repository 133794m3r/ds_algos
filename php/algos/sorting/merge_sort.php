<?php
function _merge_(&$v, $start, $mid, $end){
	$i = $start;
	$j = $mid+1;
	$n = 0;
	$tmp = array_fill(0,($end-$start)+1,0);
	while($i <= $mid && $j <= $end){
		if($v[$i] <= $v[$j]){
			$tmp[$n++] = $v[$i++];
		}
		else{
			$tmp[$n++] = $v[$j++];
		}
	}

	while($i <= $mid){
		$tmp[$n++] = $v[$i++];
	}
	while($j <= $end){
		$tmp[$n++] = $v[$j++];
	}
	for($i=$start;$i<=$end;++$i){
		$v[$i] = $tmp[$i - $start];
	}
}
function _merge_sort(&$arr, $start, $end){
	if($start < $end){
		$mid = (int)(($start+$end)/2);
		_merge_sort($arr,$start,$mid);
		_merge_sort($arr, $mid+1,$end);
		_merge_($arr, $start, $mid, $end);
	}
}
function merge_sort(&$arr){
	_merge_sort($arr, 0, count($arr)-1);
}

$arr = [4,5,1,3,2];
merge_sort($arr);
print_r($arr);