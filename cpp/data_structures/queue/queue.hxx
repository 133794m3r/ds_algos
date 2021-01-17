#ifndef PROG_ASSIGNMENT_QUEUE_HXX
#define PROG_ASSIGNMENT_QUEUE_HXX
#include <cstddef>
#include <iostream>
#include "../basic_node.hxx"

template <typename T> class Queue;
template <typename T> std::ostream &operator<<(std::ostream &, const Queue<T> &);


template <typename T> class Queue{
  private:
	Node<T> *first_;
	Node<T> *last_;
	unsigned long size_;
  public:
	explicit Queue(){
		first_=nullptr;
		last_=nullptr;
		size_=0;
	}

	Queue(T *values,unsigned long n){
		first_ = new Node<T>(values[0]);
		last_ = first_;
		Node<T> *tmp;
		for(size_t i = 1;i<n;i++){
			tmp = new Node<T>(values[i]);
			last_->next = tmp;
			last_=tmp;
		}
		size_ = n;
	}

	unsigned long enqueue(T value){
		if(!first_){
			first_ = new Node<T>(value);
			last_ = first_;
		}
		else{
			Node <T> *tmp= new Node<T>(value);
			last_->next = tmp;
			last_=tmp;
		}
		return ++size_;
	}

	T dequeue(){
		if(!first_){
			return 0;
		}
		if(first_ == last_){
			last_ = nullptr;
		}
		Node<T> *tmp = first_;
		first_ = first_->next;
		size_--;
		T val = tmp->value;
		delete(tmp);
		return val;
	}

	friend std::ostream &operator<<(std::ostream &, const Queue<T> &);

	~Queue(){
		Node<T> *nxt = first_;
		Node<T> *cur = first_;
		while(cur != nullptr){
			nxt = cur->next;
			delete(cur);
			cur=nxt;
		}
		size_ = 0;
		first_ = last_ = nullptr;
	}
};




template <typename T> std::ostream &operator<<(std::ostream &os, const Queue<T> &s) {
	std::cout << "{" << std::endl;
	Node<T> *tmp = s.first_;
	for(size_t i=0;i<s.size_;i++){
		std::cout << "| ";
		std::cout << "value: " << tmp->value;
		std::cout << ", addr: " << std::addressof(tmp->next);
		std::cout << " |" << std::endl;
		tmp=tmp->next;
	}
	std::cout << "}" << std::endl;
	return os;
}

std::ostream &operator<<(std::ostream &os, const Queue<char> &s) {
	std::cout << "{" << std::endl;
	Node<char> *tmp = s.first_;
	for(size_t i=0;i<s.size_;i++){
		std::cout << "| ";
		std::cout << "value: " << static_cast<int>(tmp->value);
		std::cout << " addr: " << std::addressof(tmp->next);
		std::cout << " |" << std::endl;
		tmp=tmp->next;
	}
	std::cout << "}" << std::endl;
	return os;
}

#endif //PROG_ASSIGNMENT_QUEUE_HXX
