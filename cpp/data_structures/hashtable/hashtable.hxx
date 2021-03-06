#ifndef _HASHTABLE_HXX
#define _HASHTABLE_HXX
//Not going to bother using my own linked list here.
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

template <typename T> class HashTable{
  private:
	size_t num_buckets;
	struct Node{
		std::string key;
		T value;
		Node(std::string k, T v){
			key = std::move(k);
			value = v;
		}
	};
	std::vector<std::vector<Node*>> buckets_;
	[[nodiscard]] size_t hash_func(const std::string &s) const{
		size_t prime = 1000000007;
		size_t multiplier = 263;
		size_t hash = 0;
		for(int i = static_cast<int>(s.size())-1;i >= 0; --i)
			hash = (hash * multiplier + s[i]) % prime;
		return hash % num_buckets;
	}
  public:
	explicit HashTable(size_t bucket_count=269){
		//make sure that the number of buckets is at least somewhat prime to reduce collisions.
		if(!(bucket_count & 1))
			num_buckets += 1;
		num_buckets = bucket_count;
		buckets_.resize(num_buckets);
	}
	
	void set(const std::string &key, T value){
		size_t idx = hash_func(key);
		for(Node *node:buckets_[idx]){
			if(node->key == key) {
				node->value = value;
				return;
			}
		}
		buckets_[idx].push_back(new Node(key, value));
	}
	
	T get(const std::string &key){
		size_t idx = hash_func(key);
		if(buckets_[idx].size() == 0){
			return -1;
		}
		else{
			for(Node *node:buckets_[idx]){
				if(node->key == key)
					return node->value;
			}
		}
		return -1;

	}

	T operator[](const std::string &k){
		return get(k);
	}

	std::vector<std::string> keys(){
		std::vector<std::string> res;
		res.reserve(num_buckets);
		for(std::vector<Node*> bucket:buckets_){
			if(bucket.size() != 0) {
				for (Node* item:bucket) {
					res.push_back(item->key);
				}
			}
		}
		return res;
	}
	void remove(const std::string &key){
		size_t idx = hash_func(key);
		for(size_t i=0;i<buckets_[idx].size();i++){
			if(buckets_[idx][i]->key == key){
				Node *tmp = buckets_[idx][i];
				buckets_[idx].erase(buckets_[idx].begin()+i);
				delete tmp;
			}
		}

	}
	std::vector<T> values(){
		std::vector<T> res;
		res.reserve(num_buckets);
		for(std::vector<Node*> bucket:buckets_){
			if(bucket.size() != 0) {
				for (Node* item:bucket) {
					res.push_back(item->value);
				}
			}
		}
		return res;
	}
	~HashTable(){
		for(size_t i=0;i<num_buckets;i++){
			for(size_t j=0;j<buckets_[i].size();j++){
				delete buckets_[i][j];
			}
			buckets_[i].clear();
		}
		buckets_.clear();
	}
	
};
#endif //_HASHTABLE_HXX

