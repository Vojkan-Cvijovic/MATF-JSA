#include "ClassTable.hpp"
#include <string>
using namespace std;

void ClassTable::add(ClassDef* cd){
	bucket.push_back(cd);
}
ClassDef* ClassTable::get(string className){
	for(auto iterator = _bucket.begin(); iterator != _bucket.end(); ++iterator){
		if(!className.compare((*iterator)->getId()))
			return *iterator;
	}
	cout << "Error: Class "<< className << " is not defined" << endl;
	return nullptr;
}
