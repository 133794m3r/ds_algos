#ifndef PROG_ASSIGNMENT_DBLY_LINKEDLIST_HXX
#define PROG_ASSIGNMENT_DBLY_LINKEDLIST_HXX
#include <vector>
#include <iostream>


template<typename T> class DoublyLinkedList {
  private:
	struct Node{
		T data;
		Node *next=nullptr;
		Node *prev=nullptr;
		explicit Node(T val,Node *p=nullptr , Node *n=nullptr){
			data = val;
			next = n;
			prev = p;
		}
	};

	Node *head_;
	Node *tail_;
	long long length_;
  public:

	DoublyLinkedList(){
		head_= nullptr;
		tail_ = nullptr;
		length_ = 0;
	}

	DoublyLinkedList(T *A, unsigned long long n) {
		head_ = new Node(A[0]);
		tail_ = head_;
		length_ = 1;
		Node *tmp, *last=head_;
		for (unsigned long long i = 1; i < n; i++) {
			tmp = new Node(A[i],last);
			last->next = tmp;
			last = tmp;
		}
		tail_ = last;
		length_ = n;

	}

	DoublyLinkedList(std::vector<T> &A) {

		head_ = new Node(A[0]);
		Node *t, *last=head_;
		length_ = static_cast<long long>(A.size());
		for (long long i = 1; i < length_; i++) {
			t = new Node(A[i],last);
			last->next = t;
			last = t;
		}
		tail_ = last;
	}

	Node *get(long long int idx){
		if(idx <0 || idx >= length_){
			return nullptr;
		}
		Node *current = head_;
		if(idx <= (length_ / 2)){
			long long i=0;

			while(i != idx){
				current = current->next;
				i++;
			}
		}
		else{
			long long i = length_ -1;
			current = tail_;
			while(i != idx){
				current = current->prev;
				i--;
			}
		}
		return current;
	}

	void set(long long idx, T val){
		Node *p = get(idx);
		p->data = val;
	}

	//to let them get a specific element in a normal way.
	//won't let them set the value here because that's too complex to do.
	T operator[](long long idx){
		Node *tmp =  get(idx);
		//default to returning 0 if they are out of range.
		if(tmp == nullptr){
			return 0;
		}
		else {
			return tmp->data;
		}
	}

	void insert(long long idx,T val){
		if(idx > length_ || idx < 0){
			return;
		}
		if(head_ == nullptr){
			head_ = new Node(val);
			tail_ = head_;
			length_ = 1;
		}
		else if(idx == 0){
			return unshift(val);
		}
		else if(idx == length_){
			return push(val);
		}
		else{
			Node *prev = get(idx-1);
			auto *p = new Node(val, prev,prev->next);
			prev->next = p;
			length_++;
		}

	}

	void push(T val){
		if(head_ == nullptr){
			head_ = new Node(val);
			tail_ = head_;
		}
		else{
			Node *p = new Node(val,tail_);
			tail_->next=p;
			tail_ = p;
		}
		length_++;
	}

	void shift(){
		if(head_ == nullptr){
			return;
		}
		Node *cur_head = head_;
		head_ = cur_head->next;
		head_->prev = nullptr;
		delete(cur_head);
		length_--;
		if(length_ == 0){
			tail_ = nullptr;
		}
	}

	void unshift(T val){
		if(head_ == nullptr){
			head_ = new Node(val);
			tail_ = head_;
		}
		else{
			Node *tmp = new Node(val, nullptr, head_);
			head_ = tmp;
		}
		length_++;
	}

	void remove(long long idx){
		if(idx <0 || idx > length_) return;
		if(idx == length_ - 1){
			pop();
			return;
		}
		if(idx == 0){
			shift();
			return;
		}

		Node *prev = get(idx-1);
		Node *remove = nullptr;
		remove = prev->next;
		prev->next = remove->next;
		delete(remove);

		length_--;
	}

	T pop(){
		if(head_ == nullptr){
			return static_cast<T>(NULL);
		}

		Node *tmp = tail_->prev;
		if(length_ == 1){
			head_=tail_=nullptr;
		}
		else {
			delete (tail_->next);
			tail_=tmp;
			tail_->next = nullptr;
		}
		length_--;
		return tmp->data;
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
		Node *curr = head_;
		tail_ = head_;
		Node * prev = nullptr;
		Node * next = nullptr;
		while(curr != nullptr){
			next = curr->next;
			curr->next = prev;
			curr->prev = next;
			prev = curr;
			curr = next;
		}
		head_ = prev;
		tail_->next = nullptr;
	}

	void append(const DoublyLinkedList<T> &_list){
		Node *temp = _list.head_;
		if(this->head_ == _list.head_){
			long long max = _list.length_;
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
	size_t length(){
		return this->length_;
	}
	DoublyLinkedList<T> operator+(const DoublyLinkedList<T> &second_list) const{
		DoublyLinkedList<T> *ret = this;
		ret->append(second_list);
		return &ret;
	}

	DoublyLinkedList<T>& operator+=(const DoublyLinkedList<T> &_list) {
		append(_list);
		return *this;
	}

	~DoublyLinkedList(){
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


#endif //PROG_ASSIGNMENT_DBLY_LINKEDLIST_HXX
