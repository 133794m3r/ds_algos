#include "hashtable.hxx"
#include <iostream>
#include "../../vectors.hxx"
int main() {
	HashTable<int> hashtable(5);
	hashtable.set("a",1);
	hashtable.set("b",2);
	hashtable.set("c",3);
	std::cout << hashtable.get("a") << std::endl;
	std::cout << hashtable["c"] << std::endl;
	std::cout << hashtable.keys();
	std::cout << hashtable.values();
	hashtable.set("b",100);
	std::cout << hashtable.values();
	hashtable.remove("a");
	std::cout << hashtable.values();
}

