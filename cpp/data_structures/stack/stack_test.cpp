#include "stack.hxx"
int main(){
	Stack<char> stack=Stack<char>();
	stack.push('a');
	stack.push('b');
	stack.push('c');
	char popped = stack.pop();
	char a[4]="ABC";
	Stack<char> stack2(a,3);
	std::cout << "popped " << popped << std::endl;
	std::cout << stack << std::endl;
	std::cout << stack2 << std::endl;
	return 0;
}