#ifndef _STACK_HXX
#define _STACK_HXX
#include <cstddef>
#include <iostream>
#include "../basic_node.hxx"

template <typename T> class Stack;
template <typename T> std::ostream &operator<<(std::ostream &os, const Stack<T> &s);


template <typename T> class Stack{
  private:
	Node<T> *first_;
	Node<T> *last_;
	unsigned long size_;
  public:
	explicit Stack(){
		first_=nullptr;
		last_=nullptr;
		size_=0;
	}

	Stack(T *values,unsigned long n){
		first_ = new Node<T>(values[0]);
		for(size_t i=1;i<n;i++){
			first_ = new Node<T>(values[i],first_);
		}
		size_ = n;
	}
	unsigned long size(){
		return size_;
	}
	unsigned long push(T value){
		if(first_ == nullptr){
			first_ = new Node<T>(value);
			last_ = first_;
		}
		else{
			first_ = new Node<T>(value,first_);
		}
		return ++size_;
	}

	T pop(){
		if(first_ == nullptr){
			return 0;
		}
		Node<T> *tmp = first_;
		first_ = first_->next;
		size_--;
		if(size_ == 0){
			first_ = last_ = nullptr;
		}
		T val = tmp->value;
		delete(tmp);
		return val;
	}

	friend std::ostream &operator<< <>(std::ostream &os, const Stack<T> &s);

	~Stack(){
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




template <typename T> std::ostream &operator<<(std::ostream &os, const Stack<T> &s) {
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

template <typename T=char> std::ostream &operator<<(std::ostream &os, const Stack<char> &s) {
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



#endif //_STACK_HXX
