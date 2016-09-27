#ifndef __TYPE_HPP__
#define __TYPE_HPP__

#define INT_TOKEN "int"
#define DOUBLE_TOKEN "double"
#define STRING_TOKEN "string"
#define CLASS_TOKEN "class"
#define VOID_TOKEN "void"
#include <iostream>

class Type
{
public:
    Type(std::string id)
	:_id(id){}
	std::string getId(){ return _id;}
	virtual std::string getType() const =0;
    virtual std::string getClassName() =0;
	virtual ~Type(){};
protected:
    std::string _id;
};

class IntType : public Type
{
public:
    IntType(std::string id)
	:Type(id){}
	std::string getType() const { return INT_TOKEN;}
	std::string getClassName(){ return nullptr;}
};

class DoubleType : public Type
{
public:
    DoubleType(std::string id)
	:Type(id){}
	std::string getType() const {return DOUBLE_TOKEN;}
	std::string getClassName(){return nullptr;}
};

class StringType : public Type
{
public:
    StringType(std::string id)
	:Type(id){}
	std::string getType() const {return STRING_TOKEN;}
	std::string getClassName(){return nullptr;}
};

class ClassType : public Type
{
public:
    ClassType(std::string className,std::string id)
	:Type(id),_className(className){}
	std::string getType() const{ return CLASS_TOKEN;}
	std::string getClassName(){ return _className;}
private:
    std::string _className;
};

class VoidType : Type
{
public:
    VoidType(std::string id)
	:Type(id){}
	std::string getClassName(){ return nullptr;}
	std::string getType(){return VOID_TOKEN;}
};

#endif
