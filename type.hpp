#ifndef __TYPE_HPP__
#define __TYPE_HPP__

#define INT_TYPE "int"
#define DOUBLE_TYPE "double"
#define STRING_TYPE "string"
#define CLASS_TYPE "class"

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
protected:
	string _id;
};

class IntType : public Type
{
public:
	IntType(string id)
	:Type(id){}
	string getType() const { return INT_TYPE;}
	string getClassName(){ return nullptr;}
};

class DoubleType : public Type
{
public:
	DoubleType(string id)
	:Type(id){}
	string getType() const {return DOUBLE_TYPE;}
	string getClassName(){return nullptr;}
};

class StringType : public Type
{
public:
	StringType(string id)
	:Type(id){}
	string getType() const {return STRING_TYPE;}
	string getClassName(){return nullptr;}
};

class ClassType : public Type
{
public:
	ClassType(string className,string id)
	:Type(id),_className(className){}
	string getType() const;
	string getClassName(){ return _className;}
private:
	string _className;
};

class MethodType : Type
{
public:
	MethodType(string type,string id)
	:Type(id),_type(type){}
	string getClassName(){ return nullptr;}
	string getType(){return _type;}
private:
	string _type;
};

#endif