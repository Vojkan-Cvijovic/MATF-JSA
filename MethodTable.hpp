#ifndef __METHODTABLE_HPP__
#define __METHODTABLE_HPP__
#include "Type.hpp"
#include <vector>
using namespace std;

class MethodTable
{
public:
	void add(Type* t);			// add new type of method
	Type* get(string id);		// find method Type with id 
	void init();				// do this at the start of block
	void deinit();				// do this at the end of block
	MethodTable(){}
	~MethodTable(){}
private:
	vector<Type*> bucket;
};


#endif