#ifndef __FIELDTYPE_HPP__
#define __FIELDTYPE_HPP__ 

#define ATTRIBUTE_TOKEN "attribute"
#define METHOD_TOKEN "method"
#define PUBLIC_TOKEN "public"
#define PRIVATE_TOKEN "private"

#include "Type.hpp"
#include <iostream>


class FieldType
{
public:
	FieldType(Type* t)
	:_type(t){}
	std::string getId(){return _type->getId();}
	virtual std::string getAccess() =0;
    virtual std::string getFieldType() =0;
	virtual ~FieldType() {}
protected:
	Type* _type;
	
};

class PrivateAttributeFieldType : public FieldType
{
public:
	 PrivateAttributeFieldType(Type* t)
	 :FieldType(t){}
	 std::string getFieldType(){return ATTRIBUTE_TOKEN;}
	 std::string getAccess(){return PRIVATE_TOKEN;}
};

class PublicAttributeFieldType : public FieldType
{
public:
	 PublicAttributeFieldType(Type* t)
	 :FieldType(t){}
	 std::string getFieldType(){return ATTRIBUTE_TOKEN;}
	 std::string getAccess(){return PUBLIC_TOKEN;}
};

class PrivateMethodFieldType : public FieldType
{
public:
	 PrivateMethodFieldType(Type* t)
	 :FieldType(t){}
	 std::string getFieldType(){return METHOD_TOKEN;}
	 std::string getAccess(){return PRIVATE_TOKEN;}
};

class PublicMethodFieldType : public FieldType
{
public:
	 PublicMethodFieldType(Type* t)
	 :FieldType(t){}
	 std::string getFieldType(){return METHOD_TOKEN;}
	 std::string getAccess(){return PUBLIC_TOKEN;}
};
#endif
