#ifndef __CLASSDEF_HPP__
#define __CLASSDEF_HPP__ 

#include "FieldType.hpp"
#include <iostream>
#include <vector>
class ClassDef
{
public:
	void add(FieldType* t);
    FieldType* get(std::string id);
    ClassDef(std::string id,std::vector<FieldType*>* bucket)
	:_id(id),_bucket(bucket){}
	std::string getId() {return _id;}
	~ClassDef();
private:
    std::vector<FieldType*>* _bucket;
    std::string _id;	
};

#endif
