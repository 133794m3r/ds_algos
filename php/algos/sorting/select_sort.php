<?php
function select_sort(&$arr){
	$len = count($arr);
	for($i=0;$i<$len;$i++){
		$lowest = $i;
		for($j=$i+1;$j<$len;$j++){
			if($arr[$j] < $arr[$lowest])
				$lowest = $j;
		}
		if($i !== $lowest){
			$tmp = $arr[$i];
			$arr[$i] = $arr[$lowest];
			$arr[$lowest] = $tmp;
		}
	}
}

$arr = [10,9,8,5,3,2,1,0];
select_sort($arr);
print_r($arr);