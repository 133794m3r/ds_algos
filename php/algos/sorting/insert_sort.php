<?php
function insert_sort(&$arr){
	$len = count($arr);
	for($i=1;$i<$len;$i++){
		$cur = $arr[$i];
		for($j=$i-1;$j>=0 && $arr[$j] > $cur;$j--){
			$arr[$j+1] = $arr[$j];
		}
		$arr[$j+1] = $cur;
	}
}
$arr = [3,2,1,6,9,7];
insert_sort($arr);
print_r($arr);

