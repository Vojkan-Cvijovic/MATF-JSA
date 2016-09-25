#include "SymbolTable.hpp"
using namespace std;

void SymbolTable::add(Type* t){
	bucket.push_back(t);
}
Type* SymbolTable::get(string id){
	for(auto iterator = bucket.rbegin(); *iterator != nullptr; ++iterator){
		if(!id.compare((*iterator)->getId()))
			return *iterator;
	}
	return nullptr;
}
void SymbolTable::init(){
	bucket.push_back(nullptr);
}
void SymbolTable::deinit(){
	for(auto iterator = bucket.rbegin(); *iterator != nullptr; ++iterator){
		// traversing from back of the vector until we get to nulptr
		bucket.pop_back();
	}
	// removing nullptr
	bucket.pop_back();
}


