#include <iostream>
#include "bst.hxx"
int main(){
	BinarySearchTree<int> bst1 = BinarySearchTree<int>();
	bst1.insert(10);
	bst1.insert(6);
	bst1.insert(15);
	bst1.insert(3);
	bst1.insert(8);
	bst1.insert(20);
	std::vector<int> tmp = bst1.bfs();
	auto sz = tmp.size();
	std::cout << "[";
	for(unsigned long i=0;i<sz;++i){
		std::cout << tmp[i];
		if(i < sz-1){
			std::cout << ", ";
		}
	}
	std::cout << "]" << std::endl;
	std::vector<int> dfs = bst1.pre_order();
	std::cout << "[";
	for(unsigned long i=0;i<sz;++i){
		std::cout << dfs[i];
		if(i < sz-1){
			std::cout << ", ";
		}
	}
	std::cout << "]" << std::endl;
	int val = bst1.remove(8);
	std::cout << val << std::endl;
	dfs = bst1.pre_order();
	std::cout << "[";
	for(unsigned long i=0;i<dfs.size();++i){
		std::cout << dfs[i];
		if(i < dfs.size()-1){
			std::cout << ", ";
		}
	}
	std::cout << "]" << std::endl;
	return 0;
}