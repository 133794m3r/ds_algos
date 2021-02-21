function radixSort(arr){
	function num_digits(num){
		if(num <0)
			num *= -1;
		return Math.floor(Math.log10(num))+1;
	}
	function most_digits(arr,len){
		let max_digits = 0;
		for(let i=0;i<len;i++){
			max_digits = Math.max(max_digits, num_digits(arr[i]));
		}
		return max_digits;
	}
	function count_sort(arr,n,exp){
		let buckets = [];
		let count = new Array(10).fill(0);
		let i;
		for(i=0;i<n;i++){
			count[(arr[i]/exp) % 10]++;
		}
		for(i=1;i<10;i++){
			count[i] += count[i-1];
		}
		for(i=n-1;i>=0;i--){
			buckets[count[(arr[i]/exp) % 10]-1] = arr[i];
			count[(arr[i]/exp) % 10]--;
		}
		for(i=0;i<n;i++){
			arr[i] = buckets[i];
		}
	}
	let len = arr.length;
	let exp = 1;
	let max_digits = most_digits(arr,len);
	for(let i=0;i<max_digits;i++){
		count_sort(arr,len,exp);
		exp*=10;
	}
}
arr = [3,2,1,6,7,9];
radixSort(arr);
console.log(arr);