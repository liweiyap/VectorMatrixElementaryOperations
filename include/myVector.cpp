/**
 * Definition of base Vector class, from which RowVector, ColumnVector and Matrix classes are derived.
 */

#ifndef MYVECTOR_H
#include "myVector.hpp"
#endif


template <typename T>
myVector<T>::myVector(){}

template <typename T>
myVector<T>::myVector(const size_t len) : mySize(len){}

template <typename T>
void myVector<T>::push_back(const T val)
{
    if (mySize >= myCapacity)
    {
        size_t newCapacity = (myCapacity==0) ? 1:myCapacity*2;
        reserve(newCapacity);
    }
    
    myBuffer[mySize++] = val;
}

template <typename T>
void myVector<T>::pop_back()
{
    --mySize;
    if (mySize <= myCapacity/4)
    {
        reserve(myCapacity/2);
    }
}

template <typename T>
T& myVector<T>::operator[](const size_t idx) const
{
    if(idx >= mySize)
    {
        throw IndexOutOfRange();
    }
    
    return myBuffer[idx];
}

template <typename T>
void myVector<T>::setValue(const size_t idx, const T val)
{
    if(idx >= mySize)
    {
        throw IndexOutOfRange();
    }
    
    myBuffer[idx] = val;
}

template <typename T>
T* myVector<T>::begin() const
{
    return myBuffer;
}

template <typename T>
T* myVector<T>::end() const
{
    return myBuffer + mySize;
}

template <typename T>
T& myVector<T>::back() const
{
    return myBuffer[mySize-1];
}

template <typename T>
size_t myVector<T>::size() const
{
    return mySize;
}

template <typename T>
size_t myVector<T>::capacity() const
{
    return myCapacity;
}

template <typename T>
bool myVector<T>::empty() const
{
    return !myBuffer;
}

template <typename T>
void myVector<T>::clear()
{
    myBuffer = nullptr;
    mySize = 0;
    myCapacity = 0;
}

template <typename T>
myVector<T>::~myVector()
{
    delete[] myBuffer;
}

// no need to reallocate with every call of push_back
template <typename T>
void myVector<T>::reserve(size_t newCapacity)
{
    if (!myBuffer)
    {
        mySize = 0;
        myCapacity = 0;
    }
    
    T* newBuffer = new T[newCapacity];
    
    size_t sizeFilled = (myCapacity < mySize) ? myCapacity : mySize;
    
    for (size_t idx = 0; idx < sizeFilled; ++idx)
    {
        newBuffer[idx] = myBuffer[idx];
    }
    
    delete[] myBuffer;
    myBuffer = newBuffer;
    
    myCapacity = newCapacity;
}

// explicit template instantiations
template class myVector<int>;
template class myVector<float>;
template class myVector<double>;
