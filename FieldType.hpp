/*! \class FiledType
    \brief Abstract class for field information, wether it is atribute or method.
*/
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
	Type* getType(){return _type;}
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
	 ~PrivateAttributeFieldType(){delete _type;}
};

class PublicAttributeFieldType : public FieldType
{
public:
	 PublicAttributeFieldType(Type* t)
	 :FieldType(t){}
	 std::string getFieldType(){return ATTRIBUTE_TOKEN;}
	 std::string getAccess(){return PUBLIC_TOKEN;}
        ~PublicAttributeFieldType(){delete _type;}
    
};

class PrivateMethodFieldType : public FieldType
{
public:
	 PrivateMethodFieldType(Type* t)
	 :FieldType(t){}
	 std::string getFieldType(){return METHOD_TOKEN;}
	 std::string getAccess(){return PRIVATE_TOKEN;}
        ~PrivateMethodFieldType(){delete _type;}
    
};

class PublicMethodFieldType : public FieldType
{
public:
	 PublicMethodFieldType(Type* t)
	 :FieldType(t){}
	 std::string getFieldType(){return METHOD_TOKEN;}
	 std::string getAccess(){return PUBLIC_TOKEN;}
        ~PublicMethodFieldType(){delete _type;}
};
#endif
