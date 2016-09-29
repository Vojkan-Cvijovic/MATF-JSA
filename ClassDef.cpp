#include "ClassDef.hpp"
#include <string>
#include <vector>
using namespace std;

void ClassDef::add(FieldType* t){
	_bucket->push_back(t);
}
FieldType* ClassDef::get(string id){
	if(_bucket == nullptr){
		cerr << "_bucket is nullptr" << endl;
		return nullptr;
	}
	for(auto iterator = _bucket->begin(); iterator != _bucket->end(); ++iterator){
		if(!id.compare((*iterator)->getId()))
			return *iterator;
	}
	return nullptr;
}
ClassDef::~ClassDef(){
    if(*_bucket->begin() != nullptr){
        _bucket->erase(_bucket->begin(), _bucket->end());
    }
}

