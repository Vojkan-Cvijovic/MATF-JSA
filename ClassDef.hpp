#ifndef __CLASSDEF_HPP
#define __CLASSDEF_HPP 
#include "FieldType.hpp"

using namespace std;

class ClassDef
{
public:
	void add(FieldType* t);
	FieldType* get(string id);
	ClassDef(string id,vector<FieldType*>* bucket)
	:_id(id),_bucket(bucket){}
	string getId() {return _id;}
	~ClassDef();
private:
	vector<FieldType*>* _bucket;
	string _id;	
};

#endif