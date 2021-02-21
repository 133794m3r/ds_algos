function bubbleSort(arr){
	let swapped = false;
	for(let i=arr.length;i >0;i--){
		for(let j=0;j<i-1;j++){
			if(arr[j] > arr[j+1]){
				let tmp = arr[j];
				arr[j] = arr[j+1]
				arr[j+1] = tmp;
				swapped = true;
			}
		}
		if(!swapped) break;
	}
}

arr = [3,2,1,6,7,9];
bubble_sort(arr);
console.log(arr);