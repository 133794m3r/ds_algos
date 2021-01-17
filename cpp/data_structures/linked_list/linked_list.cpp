#include "d_linked_list.hxx"
#include "linked_list.hxx"
int main(){
	int test[5]={1,2,3,4,5};
	//make
	DoublyLinkedList<int> dbl_list= DoublyLinkedList<int>(test, 5);
	LinkedList<int> list = LinkedList<int>(test,5);
	//lists we're going to append to later.
	int smol[3] = {111,222,333};
	DoublyLinkedList<int> dbl_list2 = DoublyLinkedList<int>(smol,3);
	LinkedList<int> list2 = LinkedList<int>(smol,3);
	//push
	list.push(1);
	dbl_list.push(2);
	//pop
	list.pop();
	dbl_list.pop();
	//insert
	list.insert(5,22);
	list.insert(5,33);
	list.insert(6,44);
	list.insert(1,13);
	list.insert(0,100);
	list.insert(-1,1000);
	//dbl inserts
	dbl_list.insert(5,22);
	dbl_list.insert(6,44);
	dbl_list.insert(1,33);
	dbl_list.insert(0,100);
	dbl_list.insert(-100,1000);
	//set
	list.set(1,33);
	dbl_list.set(1,33);
	//get
	list.get(1);
	dbl_list.get(1);
	//delete
	list.remove(3);
	dbl_list.remove(3);
	//append
	list.append(list2);
	dbl_list.append(dbl_list2);
	//display
	list.display();
	dbl_list.display();
	//reverse
	list.reverse();
	dbl_list.reverse();
	//array syntax
	list[1];
	dbl_list[1];
	//std::vector versions
	std::vector<std::string> vec1 = {"Bill", "Tom", "Something"};
	std::vector<std::string> vec2 = {"Joe", "Frasier", "Colten"};
	DoublyLinkedList<std::string> dbl_list_str(vec1);
	LinkedList<std::string> list_str(vec2);
	//push some values to strings
	list_str.push("John");
	dbl_list_str.push("Bill");
	list.display();
	//check that circular list appending is checked and we don't repeat ourselves.
	dbl_list_str+=dbl_list_str;
	list_str+=list_str;
	list_str.display();

}