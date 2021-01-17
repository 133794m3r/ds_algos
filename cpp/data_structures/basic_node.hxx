#ifndef PROG_ASSIGNMENT_BASIC_NODE_HXX
#define PROG_ASSIGNMENT_BASIC_NODE_HXX

template <typename T> struct Node{
	T value;
	Node<T> *next;
	explicit Node(T val,Node *nxt=nullptr){
		value = val;
		next = nxt;
	}
};
std::ostream& operator<<(std::ostream &os, const Node<char> &n){
	os << "{ ";
	os << "ref: " << std::addressof(n.next);
	if(! (n.value < 32 || n.value > 126) ){
		os << "value: '" << n.value << "' raw: ";
	}
	else{
		os << "value: ";
	}
	os << static_cast<int>(n.value);
	std::cout << "}" << std::endl;
	return os;
}


template <typename T> std::ostream& operator<<(std::ostream& os, const Node<T> &n){
	os << "{ " ;
	os << "value: " << n.value;
	os << " ref: " <<std::addressof(n.next);
	std::cout << "}" << std::endl;
	return os;
}
#endif //PROG_ASSIGNMENT_BASIC_NODE_HXX
