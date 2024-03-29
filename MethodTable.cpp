#include "MethodTable.hpp"
#include <string>
#include <vector>

using namespace std;

void MethodTable::add(Type* t){
	bucket.push_back(t);
}
Type* MethodTable::get(std::string id){

	for(auto iterator = bucket.rbegin(); iterator != bucket.rend(); ++iterator){
		if(*iterator == nullptr){
			cerr << "iterator in MethodTable is null " << endl;
		}
		if(!id.compare((*iterator)->getId()))
			return *iterator;
	}
	return nullptr;
}
void MethodTable::init(){
	bucket.push_back(nullptr);
}
void MethodTable::deinit(){
	for(auto iterator = bucket.rbegin(); *iterator != nullptr; ++iterator){
		// traversing from back of the vector until we get to nulptr
		bucket.pop_back();
	}
	// removing nullptr
	bucket.pop_back();
}
MethodTable::~MethodTable(){
    if(*bucket.begin() != nullptr)
        bucket.erase(bucket.begin(), bucket.end());
}
