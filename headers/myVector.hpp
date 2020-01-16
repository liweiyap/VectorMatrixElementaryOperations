/**
 * Definition of base Vector class, from which RowVector, ColumnVector and Matrix classes are derived.
 */

#ifndef MYVECTOR_H
#define MYVECTOR_H

#ifndef EXCEPTIONS_H
#include "exceptions.hpp"
#endif

#include <stddef.h>
#include <iostream>


/**
 * Definition of base Vector class. Note: this is an abstract class!
 */
template <typename T>
class myVector
{
public:
    myVector();
    myVector(const size_t len);
    
    void push_back(const T val);
    void pop_back();
    
    T& operator[](const size_t idx) const;
    void setValue(const size_t idx, const T val);
    
    T* begin() const;
    T* end() const;
    T& back() const;
    
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    
    virtual void print() const = 0;
    
    void clear();
    ~myVector();
    
protected:
    T* myBuffer = nullptr;
    size_t mySize = 0;
    size_t myCapacity = 0;
    
    void reserve(size_t newCapacity);
};

#endif
