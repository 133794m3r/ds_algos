//
// Created by macarthur on 1/3/21.
//

#ifndef _SORT_ALGOS_HXX
#define _SORT_ALGOS_HXX

#include <memory>
#include <complex>

template <class T,class Allocator> std::ostream& operator<<(std::ostream& os, const std::vector<T,Allocator> &m){
	size_t m_size=m.size();
	os << "[";
	for(size_t i=0; i < m.size(); i++) {
		os << m[i]  <<(i == m_size - 1 ? "" : ",");
	}
	os << "]" << std::endl;
	return os;
}
template <class T,class Allocator> std::istream& operator>>(std::istream& is, std::vector<T,Allocator> &m){
	size_t n=m.size();
	for(size_t i=0;i<n;i++){
		is >> m[i];
	}
	return is;
}

template <typename T> unsigned int num_digits(T num){
	if(num <0){
		return static_cast<T>(floor(std::log10(num*-1))+1);
	}
	else{
		return static_cast<T>(floor(std::log10(num))+1);
	}
}

template <typename T> unsigned int most_digits(T *arr,size_t len){
	unsigned int max_digits =0;
	for(size_t i=0;i<len;i++){
		max_digits = std::max(max_digits, num_digits(arr[i]));
	}
	return max_digits;
}

template <typename T> char get_digit(T num, unsigned int i){
	return static_cast<T>(std::floor(std::abs(num)/std::pow(10,i)) % 10);
}

template <typename T> void count_sort(T *arr, long long n,unsigned int exp){
	T *buckets = new T[n];
	long long i,count[10]={0};
	for(i=0;i < n;i++){
		count[(arr[i] / exp) % 10]++;
	}
	for(i=1;i<10;i++){
		count[i] += count[i-1];
	}

	for(i=n-1;i>=0;i--){
		buckets[count[(arr[i]/exp) %10] -1] = arr[i];
		count[(arr[i]/exp) % 10]--;
	}
	for(i=0;i<n;i++){
		arr[i] = buckets[i];
	}
}
template<typename T> void radix_sort(T *arr, size_t len){
	unsigned int max_digits = most_digits(arr,len);
	unsigned int exp =1;
	for(unsigned int i=0;i<max_digits;i++){
		count_sort(arr,len,exp);
		exp*=10;
	}
}

template <typename T> void bubble_sort(T *arr, size_t len){
	bool swapped;
	for(size_t i=len;i  > 0; i--){
		for(size_t j=0;j<i-1;j++){
			if(arr[j] > arr[j+1]){
				std::swap(arr[j],arr[j+1]);
				swapped = true;
			}
		}
		if(!swapped) break;
	}
}

template <typename T> void insert_sort(T &arr, size_t len){
	T cur;
	size_t j=0;
	for(size_t i=1;i < len;i++){
		cur = arr[i];
		for(j=i-1;j>=0 && arr[j] > cur; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = cur;
	}
}
template <typename T> void select_sort(T &arr, size_t len){
	for(size_t i=0;i<len;i++){
		size_t lowest = i;
		for(size_t j=i+1;j<len; j++){
			if(arr[j] < arr[lowest]){
				lowest = j;
			}
		}
		if(i!=lowest){
			std::swap(arr[i],arr[lowest]);
		}
	}
}

template <typename T> void merge_(T *v, const size_t start, const size_t mid, const size_t end){
	size_t i = start;
	size_t j = mid+1;
	size_t n = 0;
	std::unique_ptr<T[]> tmp(new T[(end-start)+1]());

	while(i <= mid && j <= end){
		if(v[i] <= v[j]){
			tmp[n++]=v[i];
			i++;
		}
		else{
			tmp[n++]=v[j];
			j++;
		}
	}

	while (i <= mid){
		tmp[n++]=v[i];
		i++;
	}

	while( j <= end){
		tmp[n++]=v[j];
		j++;
	}

	for(i=start; i<= end; i++){
		v[i] = tmp[i-start];
	}
}

template <typename T> void _merge_sort(T *arr,size_t start, size_t end){
	if(start < end){
		size_t mid = (start+end)/2;
		_merge_sort(arr,start,mid);
		_merge_sort(arr,mid+1,end);
		merge_(arr,start,mid,end);
	}
}

template <typename T> void merge_sort(T *arr, size_t len){
	_merge_sort(arr, 0, len-1);
}

//vector templates
template <typename T> void bubble_sort( std::vector<T> &arr){
	bool swapped;
	for(size_t i=arr.size();i >0; i--){
		for(size_t j=0;j<i-1;j++){
			if(arr[j] > arr[j+1]){
				std::swap(arr[j],arr[j+1]);
				swapped = true;
			}
		}
		if(!swapped) break;
	}
}

template <typename T> void insert_sort(std::vector<T> &arr){
	T cur;
	size_t j=0;
	for(size_t i=1;i < arr.size();i++){
		cur = arr[i];
		for(j= i -1;j>=0 && arr[j] > cur; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = cur;
	}
}

template <typename T> void select_sort(std::vector<T> &arr){
	size_t len = arr.size();
	for(size_t i=0;i < len;i++){
		size_t lowest = i;
		for(size_t j= i+1;j<len; j++){
			if(arr[j] < arr[lowest]){
				lowest = j;
			}
		}
		if(i != lowest){
			std::swap(arr[i],arr[lowest]);
		}
	}
}

template <typename T> void merge_(std::vector<T> &v, size_t start, size_t mid, size_t end){
	size_t i = start;
	size_t j = mid+1;
	std::vector<T> tmp;
	tmp.reserve((end-start)+1);
	while(i <= mid && j <= end){

		if(v[i] <= v[j]){
			tmp.push_back(v[i]);
			i++;
		}
		else{
			tmp.push_back(v[j]);
			j++;
		}
	}
	while (i <= mid){
		tmp.push_back(v[i]);
		i++;
	}
	while( j <= end){
		tmp.push_back(v[j]);
		j++;
	}
	for(i=start; i<= end; ++i){
		v[i] = tmp[i-start];
	}
}

template <typename T> void _merge_sort(std::vector<T> &arr,size_t start, size_t end){
	if(start < end){
		size_t mid = (start+end)/2;
		_merge_sort(arr,start,mid);
		_merge_sort(arr,mid+1,end);
		merge_(arr,start,mid,end);
	}
}

template <typename T> void merge_sort(std::vector<T> &arr){
	_merge_sort(arr, 0, arr.size()-1);
}


template <typename T, typename N> N part(T *arr, N low, N high){
	N pivot = arr[high];// pivot
	N i = (low - 1);  // Index of smaller element
	N j;
	//iterate over the entire thing.
	for(j = low; j <= high- 1; j++){
		//if the current value is less than the pivot value we saw before
		if (arr[j] < pivot){
			//it means we need to swap them to get them sorted.
			//pass by value of the pointer.
			swap(&arr[++i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	//return the index value of i plus 1.
	return (i + 1);
}

//here's the real quicksort implementation.
template <typename T, typename N >void qsrt(T *arr, N low, N high){
	//if the lower point is less than our high time to keep going.
	if (low < high){
		//get the partition index so that we can sort it in replace.
		int pi = part(arr, low, high);
		//quick sort the items before the middle of the partition.
		qsrt(arr, low, pi - 1);
		//quick sort the items after the partition index.
		qsrt(arr, pi + 1, high);
	}
}

//normally quick sort requires the person to pass to it a end point that's one less
//than the length. This way they can just pass the length to us.
template <typename T, typename N> void quick_sort(T *arr, N start, N length){
	qsrt(arr,start,length-1);
}
#endif //_SORT_ALGOS_HXX
