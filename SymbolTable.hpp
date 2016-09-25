#ifndef __SYMBOLTABLE_HPP__
#define __SYMBOLTABLE_HPP__
#include "Type.hpp"
#include <vector>
using namespace std;

class SymbolTable
{
public:
	void add(Type* t);			// add new type
	Type* get(string id);		// find Type object with id=s 
	void init();				// do this at the start of block
	void deinit();				// do this at the end of block
	SymbolTable(){}
	~SymbolTable(){}
private:
	vector<Type*> bucket;
};


#endif
