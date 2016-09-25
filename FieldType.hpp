#ifndef __FIELDTYPE_HPP__
#define __FIELDTYPE_HPP__ 

#define ATTRIBUTE_TOKEN "attribute"
#define METHOD_TOKEN "method"
#define PUBLIC_TOKEN "public"
#define PRIVATE_TOKEN "private"

#include "Type.hpp"
using namespace std;

class FieldType
{
public:
	FieldType(Type* t)
	:_type(t){}
	string getId(){return _type->getId();}
	virtual string getAccess() =0;
	virtual string getFieldType() =0;
	virtual ~FieldType() {}
protected:
	Type* _type;
	
};

class PrivateAttributeFieldType : public FieldType
{
public:
	 PrivateAttributeFieldType(Type* t)
	 :FieldType(t){}
	 string getFieldType(){return ATTRIBUTE_TOKEN;}
	 string getAccess(){return PRIVATE_TOKEN;}
};

class PublicAttributeFieldType : public FieldType
{
public:
	 PublicAttributeFieldType(Type* t)
	 :FieldType(t){}
	 string getFieldType(){return ATTRIBUTE_TOKEN;}
	 string getAccess(){return PUBLIC_TOKEN;}
};

class PrivateMethodFieldType : public FieldType
{
public:
	 PrivateMethodFieldType(Type* t)
	 :FieldType(t){}
	 string getFieldType(){return METHOD_TOKEN;}
	 string getAccess(){return PRIVATE_TOKEN;}
};

class PublicMethodFieldType : public FieldType
{
public:
	 PublicMethodFieldType(Type* t)
	 :FieldType(t){}
	 string getFieldType(){return METHOD_TOKEN;}
	 string getAccess(){return PUBLIC_TOKEN;}
};
#endif