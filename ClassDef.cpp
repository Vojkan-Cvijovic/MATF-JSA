#include "ClassDef.hpp"

using namespace std;

void ClassDef::add(FieldType* t){
	bucket.push_back(t);
}
FieldType* ClassDef::get(string id){
	
	for(auto iterator = _bucket.begin(); iterator != _bucket.end(); ++iterator){
		if(!id.compare((*iterator)->getId()))
			return *iterator;
	}
	cout << "Error: Variable "<< id << " is not defined in class "<< _id << endl;
	return nullptr;
}

