#ifndef __TRASH_HPP__
#define __TRASH_HPP__
#include "Type.hpp"
#include <iostream>
#include <vector>

class Trash{
public:
    Trash(){}
    ~Trash(){
        if(*_bucket.begin() != nullptr)
            _bucket.erase(_bucket.begin(),_bucket.end());
    }
    void add(Type* t){
        _bucket.push_back(t);
    }
private:
    std::vector<Type*> _bucket;
};


#endif
