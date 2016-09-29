#include "ClassTable.hpp"
#include <string>
#include <vector>
using namespace std;

void ClassTable::add(ClassDef* cd){
	_bucket.push_back(cd);
}
ClassDef* ClassTable::get(std::string className){
	for(auto iterator = _bucket.begin(); iterator != _bucket.end(); ++iterator){
		if(!className.compare((*iterator)->getId()))
			return *iterator;
	}
	return nullptr;
}
ClassTable::~ClassTable(){
    if(*_bucket.begin() != nullptr){
        _bucket.erase(_bucket.begin(), _bucket.end());
    }        
}
