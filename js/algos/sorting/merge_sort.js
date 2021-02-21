function mergeSort(arr){
	function _merge(v,start,mid,end){
		let i=start;
		let j = mid+1;
		let n = 0;
		let tmp = new Array((end-start)+1);
		while(i <= mid && j <= end){
			if(v[i] <= v[j]){
				tmp[n++] = v[i++];
			}
			else{
				tmp[n++] = v[j++];
			}
		}
		while(i <= mid){
			tmp[n++] = v[i++];
		}
		while(j <= end){
			tmp[n++] = v[j++];
		}
		for(i=start;i<=end;++i){
			v[i] = tmp[i - start];
		}
	}
	function _merge_sort(arr,start,end){
		if(start < end){
			let mid = Math.floor((start+end)/2)
			_merge_sort(arr,start,mid);
			_merge_sort(arr,mid+1,end);
			_merge(arr,start,mid,end);
		}
	}
	_merge_sort(arr,0,arr.length-1);
}
arr = [3,2,1,6,7,9];
mergeSort(arr);
console.log(arr);