#include "queue.hxx"
int main(){
	Queue<char> queue=Queue<char>();
	queue.enqueue('a');
	queue.enqueue('b');
	queue.enqueue('c');
	char v = queue.dequeue();
	std::cout << "removed " << v << std::endl;
	char a[4]="ABC";
	Queue<char> queue2(a,3);;
	std::cout << queue << std::endl;
	std::cout << queue2 << std::endl;
	std::cout << "removed " << queue2.dequeue() << std::endl;
	return 0;
}