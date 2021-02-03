#ifndef _PRIORITYQ_HXX
#define _PRIORITYQ_HXX
#include <vector>
#include <iostream>
typedef unsigned long long ull;
template <typename T, typename U> class PriorityQueue {
  private:
	struct Node{
		T value;
		U priority;
		Node(T val, U weight){
			value = val;
			priority = weight;
		}

		bool operator >(const Node &rhs){
			return this->priority > rhs.priority;
		}

		bool operator <(const Node &rhs){
			return this->priority < rhs.priority;
		}

		bool operator ==(const Node &rhs){
			return this->priority == rhs.priority;
		}

		bool operator <=(const Node &rhs){
			return this->priority <= rhs.priority;
		}

		bool operator >=(const Node &rhs){
			return this->priority >= rhs.priority;
		}
	};
	std::vector<Node*>values_;
	ull size_;

  public:
	PriorityQueue(){
		size_ = 0;
	};

	ull length(){
		return size_;
	};

	void shift_up(){
		ull idx = size_-1;
		ull parent;
		while(idx > 0){
			parent = (idx-1)>>1;
			if( *values_[idx] >= *values_[parent]) break;
			std::swap(values_[parent],values_[idx]);
			idx = parent;
		}
	};

	void enqueue(T value, U priority) {
		Node *tmp = new Node(value, priority);
		values_.push_back(tmp);
		size_++;
		shift_up();
	};

	void shift_down(){
		ull idx = 0;
		while(true){
			ull swap_id = idx;
			ull left = (idx << 1)+1;
			ull right = left+1;
			if(left < size_) {
				if ( *values_[left] < *values_[idx])
					swap_id = left;
			}
			if(right < size_ && *values_[swap_id] > *values_[right])
				swap_id = right;

			if(swap_id == idx) break;
			std::swap(values_[idx],values_[swap_id]);
			idx = swap_id;
		}
	};



	~PriorityQueue(){
		while(size_ > 0){
			Node *tmp = values_[--size_];
			values_.pop_back();
			delete tmp;
		}
	};

	void display(){
		for(ull i=0;i<size_;i++){
			std::cout << "{" << values_[i]->value << ", " << values_[i]->priority << "}" << std::endl;
		}
	};
	T dequeue() {
		if(this->size_ > 0){
			Node *highest = values_[0];
			Node *end = values_[size_-1];
			values_.pop_back();
			values_[0] = end;
			size_--;
			shift_down();
			T value = highest->value;
			delete highest;
			return value;
		}
		else{
			return T();
		}
	}
};

#endif //_PRIORITYQ_HXX
