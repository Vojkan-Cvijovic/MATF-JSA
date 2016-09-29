#ifndef __SYMBOLTABLE_HPP__
#define __SYMBOLTABLE_HPP__
#include "Type.hpp"
#include <iostream>
#include <vector>
class SymbolTable
{
public:
	void add(Type* t);			// add new type
        Type* get(std::string id);		// find Type object with id=s 
	void init();				// do this at the start of block
	void deinit();				// do this at the end of block
	SymbolTable(){}
	~SymbolTable();
private:
    std::vector<Type*> bucket;
};


#endif
