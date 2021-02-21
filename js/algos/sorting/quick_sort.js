function quickSort(arr,start=0){
	function swap(arr,i,j){
		return [ arr[i], arr[j] ] = [ arr[j], arr[i]];
	}
	function part(arr,low,high){
		let pivot = arr[high];
		let i = low-1;
		let j;
		for(j = low; j<= high - 1;j++){
			if(arr[j] < pivot){
				swap(arr,++i,j);
			}
		}
		swap(arr,i+1,j);
		return i+1;
	}
	function _qsort(arr,low,high){
		if(low < high){
			let pi = part(arr,low,high);
			_qsort(arr,low,pi-1);
			_qsort(arr,pi+1,high);
		}
	}
	_qsort(arr,start,arr.length-1);
}
arr = [3,2,1,6,7,9];
quickSort(arr);
console.log(arr);