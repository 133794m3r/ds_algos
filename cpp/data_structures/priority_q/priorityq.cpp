#include <string>
#include "priorityq.hxx"
int main(){
	PriorityQueue<std::string, size_t>pq;
	ull inf = (1<<64)-1;
	pq.enqueue("a",0);
	pq.enqueue("b",inf);
	pq.enqueue("c",inf);
	pq.enqueue("d",inf);
	pq.enqueue("e",inf);
	pq.enqueue("f",inf);
	pq.dequeue();
	pq.enqueue("b",4);
	pq.enqueue("c",2);
	pq.dequeue();
	pq.enqueue("d",4);
	pq.display();
	std::cout << pq.dequeue() <<std::endl;
	std::cout << pq.dequeue()<<std::endl;
	std::cout << pq.dequeue()<<std::endl;
	std::cout << pq.dequeue()<<std::endl;
	std::cout << pq.dequeue()<<std::endl;
	std::cout << pq.dequeue()<<std::endl;
	std::cout << pq.dequeue()<<std::endl;
	std::cout << pq.dequeue()<<std::endl;
	std::cout << pq.dequeue()<<std::endl;
}