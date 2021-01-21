#ifndef _LINKEDLIST_HXX
#define _LINKEDLIST_HXX
#include <vector>
#include <iostream>


template<typename T> class LinkedList {
  private:
	struct Node{
		T data;
		Node *next=nullptr;
		explicit Node(T val, Node *n=nullptr){
			data = val;
			next = n;
		}
	};

	Node *head_;
	long long length_;
	Node *tail_;
  public:

	LinkedList(){
		head_= nullptr;
		tail_ = nullptr;
		length_ = 0;
	}

	LinkedList(T *A, size_t n) {
		head_ = new Node(A[0]);
		tail_ = head_;
		length_ = 1;
		Node *tmp, *last=head_;
		for (size_t i = 1; i < n; i++) {
			tmp = new Node(A[i]);
			last->next = tmp;
			last = tmp;
		}
		tail_ = last;
		length_ = n;

	}

	explicit LinkedList(std::vector<T> &A) {

		head_ = new Node(A[0]);
		Node *t, *last=head_;
		length_ = static_cast<long long>(A.size());
		for (long long i = 1; i < length_; i++) {
			t = new Node(A[i]);
			last->next = t;
			last = t;
		}
		tail_ = last;
	}

	Node *get(long long idx){
		if(idx <0 || idx >= length_){
			return nullptr;
		}
		Node *current = head_;
		long long i=0;
		while(i != idx){
			current = current->next;
			i++;
		}
		return current;
	}
	void set(long long idx, T val){
		Node *p = get(idx);
		p->data = val;
	}
	long long find(T key){
		Node *cur = head_;
		for(long long i=0;i<length_;i++){
			if(cur->data == key){
				return i;
			}
			cur = cur->next;
		}
		return -1;
	}
	//to let them get a specific element in a normal way.
	//won't let them set the value here because that's too complex to do.
	T operator[](long long idx){
		Node *tmp = this->get(idx);
		if(tmp != nullptr)
			return tmp->data;
		else
			return 0;
	}

	void insert(long long idx,T val){
		if(idx > length_ || idx < 0){
			return;
		}
		if(head_ == nullptr){
			head_ = new Node(val);
			tail_ = head_;
		}
		else if(idx == 0){
			return unshift(val);
		}
		else if(idx == length_){
			return push(val);
		}
		else{
			Node *prev = get(idx-1);
			auto *p = new Node(val,prev->next);
			prev->next = p;
		}
		length_++;

	}

	void push(T val){
		if(!head_){
			head_ = new Node(val);
			tail_ = head_;
		}
		else{
			Node *p = new Node(val);
			tail_->next=p;
			tail_ = p;
		}
		length_++;
	}

	void shift(){
		if(!head_){
			return;
		}
		Node *cur_head = head_;
		head_ = cur_head->next;
		delete cur_head;
		length_--;
		if(length_ == 0){
			tail_ = nullptr;
		}
	}

	void unshift(T val){
		if(!head_){
			head_ = new Node(val);
			tail_ = head_;
		}
		else{
			head_ = new Node(val, head_);
		}
		length_++;
	}

	void remove(long long idx){
		if(idx <0 || idx > length_){
			return;
		}
		if(idx == length_ - 1){
			pop();
		}
		if(idx == 0){
			shift();
		}
		else{
			Node *prev = get(idx-1);
			Node *remove = nullptr;
			remove = prev->next;
			prev->next = remove->next;
			delete(remove);
		}
		length_--;
	}

	T pop(){
		if(head_ == nullptr){
			return -1;
		}
		Node *prev = get(length_-2);
		T pop_val = tail_->data;
		tail_=prev;
		delete(prev->next);
		tail_->next= nullptr;
		length_--;
		return pop_val;
	}

	void display() const{
		Node *p = head_;
		unsigned int i=1;
		std::cout << "length: " << length_ << " ";
		std::cout << "[";
		while (p) {
			std::cout << p->data;
			if(i++ < length_){
				std::cout << ", ";
			}
			p = p->next;
		}
		std::cout << "]" << std::endl;
	}

	void reverse(){
		Node *prev=nullptr, *next=nullptr, *cur;
		cur = head_;
		head_ = tail_;
		tail_ = cur;

		while(cur != nullptr){
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
	}

	void append(const LinkedList<T> &second_list){
		Node *temp = second_list.head_;
		if(this->head_ == second_list.head_){
			long long max = second_list.length_;
			for(long long i=0;i<max;i++){
				push(temp->data);
				temp=temp->next;
				if(temp == nullptr)
					break;
			}
		}
		else{
			while(temp != nullptr){
				push(temp->data);
				temp=temp->next;
			}
		}
	}
	size_t length(){
		return this->length_;
	}
	LinkedList<T> operator+(const LinkedList<T> &second_list) const{
		LinkedList<T> *ret = this;
		ret->append(second_list);

		return &ret;
	}

	LinkedList<T>& operator+=(const LinkedList<T>& second_list) {
		append(second_list);
		return *this;

	}

	~LinkedList(){
		Node* current = head_;
		Node* next=nullptr;
		while (current != NULL) {
			next = current->next;
			delete(current);
			current = next;
		}
		length_ = 0;
		head_=tail_=nullptr;
	}

};


#endif //_LINKEDLIST_HXX
