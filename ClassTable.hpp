#ifndef __CLASSTABLE_HPP__
#define __CLASSTABLE_HPP__
#include "ClassDef.hpp"
#include <iostream>
#include <vector>
class ClassTable
{
public:
    ClassTable(std::vector<ClassDef*> bucket)
	:_bucket(bucket){}
	~ClassTable();
	void add(ClassDef* cd);
    ClassDef* get(std::string className);
private:
    std::vector<ClassDef*> _bucket;
};



#endif
