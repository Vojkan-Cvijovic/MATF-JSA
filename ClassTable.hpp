#ifndef __CLASSTABLE_HPP__
#define __CLASSTABLE_HPP__
#include "ClassDef.hpp"

using namespace std;
#include <vector>

class ClassTable
{
public:
	ClassTable()
	:_bucket(bucket){}
	~ClassTable();
	void add(ClassDef* cd);
	ClassDef* get(string className);
private:
	vector<ClassDef*> _bucket;
};



#endif