#include "ClassDef.hpp"

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
	cout << "Error: Variable "<< id << " is not defined in class "<< _id << endl;
	return nullptr;
}

