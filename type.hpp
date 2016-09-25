#ifndef __TYPE_HPP__
#define __TYPE_HPP__

#define INT_TOKEN "int"
#define DOUBLE_TOKEN "double"
#define STRING_TOKEN "string"
#define CLASS_TOKEN "class"
#define VOID_TOKEN "void"

#include <string>

using namespace std;

class Type
{
public:
	Type(string id)
	:_id(id){}
	string getId(){ return _id;}
	virtual string getType() const =0;
	virtual string getClassName() =0;
	virtual ~Type(){};
protected:
	string _id;
};

class IntType : public Type
{
public:
	IntType(string id)
	:Type(id){}
	string getType() const { return INT_TOKEN;}
	string getClassName(){ return nullptr;}
};

class DoubleType : public Type
{
public:
	DoubleType(string id)
	:Type(id){}
	string getType() const {return DOUBLE_TOKEN;}
	string getClassName(){return nullptr;}
};

class StringType : public Type
{
public:
	StringType(string id)
	:Type(id){}
	string getType() const {return STRING_TOKEN;}
	string getClassName(){return nullptr;}
};

class ClassType : public Type
{
public:
	ClassType(string className,string id)
	:Type(id),_className(className){}
	string getType() const{ return CLASS_TOKEN;}
	string getClassName(){ return _className;}
private:
	string _className;
};

class VoidType : Type
{
public:
	VoidType(string id)
	:Type(id){}
	string getClassName(){ return nullptr;}
	string getType(){return VOID_TOKEN;}
};

#endif