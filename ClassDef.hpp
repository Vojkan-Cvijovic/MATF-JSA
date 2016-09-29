/*! \class ClassDef
    \brief Class for storage classes from java program.
    ClassDef is used for storage classes from java program.
*/
#ifndef __CLASSDEF_HPP__
#define __CLASSDEF_HPP__ 

#include "FieldType.hpp"
#include <iostream>
#include <vector>
class ClassDef
{
public:
        ClassDef(std::string id,std::vector<FieldType*>* bucket)
	:_id(id),_bucket(bucket){}
	~ClassDef();

        void add(FieldType* t);
        FieldType* get(std::string id);
	std::string getId() {return _id;}
private:
    std::vector<FieldType*>* _bucket;
    std::string _id;	
};

#endif
