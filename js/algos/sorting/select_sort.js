function selectSort(arr){
	// If I was just letting them do numbers I could use the XOR trick.
	function swap(arr,i,j){
		return [ arr[i], arr[j] ] = [ arr[j], arr[i]];
	}
	let len = arr.length;
	for(let i = 0; i<len;i++){
		let lowest = i;
		for(let j=i+1;j<len;j++){
			if(arr[j] < arr[lowest]){
				lowest = j;
			}
		}
		if(i !== lowest){
			swap(arr,i,lowest);
		}
	}
}

arr = [3,2,1,6,7,9];
selectSort(arr);
console.log(arr);