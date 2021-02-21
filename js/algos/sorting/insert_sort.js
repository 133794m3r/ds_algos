function insertSort(arr){
	let j;
	for(let i=1;i<arr.length;i++){
		let cur = arr[i];
		for(j=i-1;j>=0 && arr[j] > cur; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = cur;
	}
}
arr = [3,2,1,6,7,9];
insertSort(arr);
console.log(arr);