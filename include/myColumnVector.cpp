/**
 * Definition of derived ColumnVector class.
 */

#ifndef MYCOLUMNVECTOR_H
#include "myColumnVector.hpp"
#endif

template <typename T>
myColumnVector<T>::myColumnVector() : myVector<T>(){}

template <typename T>
myColumnVector<T>::myColumnVector(const size_t len) : myVector<T>(len){}

template <typename T>
myColumnVector<T>::myColumnVector(const myColumnVector<T>& otherVec) : myVector<T>()
{
    *this = otherVec;
}

template <typename T>
myColumnVector<T>::myColumnVector(myColumnVector<T>&& otherVec)
{
    this->myBuffer = otherVec.begin();
    this->mySize = otherVec.size();
    this->myCapacity = otherVec.capacity();
    
    otherVec.myBuffer = nullptr;
    otherVec.mySize = 0;
    otherVec.myCapacity = 0;
}

template <typename T>
myColumnVector<T>& myColumnVector<T>::operator= (const myColumnVector<T>& otherVec)
{
    this->mySize = otherVec.size();
    this->myCapacity = otherVec.capacity();
    
    delete[] this->myBuffer;
    this->myBuffer = new T[this->myCapacity];
    for (size_t idx = 0; idx < this->mySize; ++idx)
    {
        this->myBuffer[idx] = otherVec[idx];
    }
    
    return *this;
}

template <typename T>
myColumnVector<T>& myColumnVector<T>::operator<< (T val)
{
    myColumnVector<T>& result = *this;
    result.push_back(val);
    return *this;
}

template <typename T>
myColumnVector<T> operator+ (const myColumnVector<T>& otherVec)
{
    return otherVec;
}

template <typename T>
myColumnVector<T> operator+ (const myColumnVector<T>& Vec1, const myColumnVector<T>& Vec2)
{
    myColumnVector<T> result = Vec1;
    result += Vec2;
    return result;
}

template <typename T>
myColumnVector<T>& myColumnVector<T>::operator+= (const myColumnVector<T>& otherVec)
{
    if(this->mySize != otherVec.size())
    {
        throw IncompatibleDims();
    }
    
    for (size_t idx = 0; idx < this->mySize; ++idx)
    {
        checkOverAndUnderflows(this->myBuffer[idx], otherVec[idx], "add");
        this->myBuffer[idx] += otherVec[idx];
    }
    
    return *this;
}

template <typename T>
myColumnVector<T> operator- (const myColumnVector<T>& otherVec)
{
    myColumnVector<T> result = otherVec;
    result *= (-1);
    return result;
}

template <typename T>
myColumnVector<T> operator- (const myColumnVector<T>& Vec1, const myColumnVector<T>& Vec2)
{
    myColumnVector<T> result = Vec1;
    result -= Vec2;
    return result;
}

template <typename T>
myColumnVector<T>& myColumnVector<T>::operator-= (const myColumnVector<T>& otherVec)
{
    if(this->mySize != otherVec.size())
    {
        throw IncompatibleDims();
    }
    
    for (size_t idx = 0; idx < this->mySize; ++idx)
    {
        checkOverAndUnderflows(this->myBuffer[idx], otherVec[idx], "sub");
        this->myBuffer[idx] -= otherVec[idx];
    }
    
    return *this;
}

template <typename T>
myColumnVector<T> operator* (const myColumnVector<T>& Vec, const T coeff)
{
    myColumnVector<T> result = Vec;
    result *= coeff;
    return result;
}

template <typename T>
myColumnVector<T> operator* (const T coeff, const myColumnVector<T>& Vec)
{
    myColumnVector<T> result = Vec;
    result *= coeff;
    return result;
}

template <typename T>
myColumnVector<T>& myColumnVector<T>::operator*= (const T coeff)
{
    for (size_t idx = 0; idx < this->mySize; ++idx)
    {
        checkOverAndUnderflows(this->myBuffer[idx], coeff, "mul");
        this->myBuffer[idx] *= coeff;
    }
    
    return *this;
}

template <typename T>
myColumnVector<T> operator/ (const myColumnVector<T>& Vec, const T divisor)
{
    myColumnVector<T> result = Vec;
    result /= divisor;
    return result;
}

template <typename T>
myColumnVector<T>& myColumnVector<T>::operator/= (const T divisor)
{
    if (divisor == 0)
    {
        throw DivisionByZero();
    }
    
    for (size_t idx = 0; idx < this->mySize; ++idx)
    {
        checkOverAndUnderflows(this->myBuffer[idx], divisor, "div");
        this->myBuffer[idx] /= divisor;
    }
    
    return *this;
}

template <typename T>
myColumnVector<T> myColumnVector<T>::block(const size_t minIdx, const size_t len) const
{
    if (minIdx + len > this->mySize)
    {
        throw IndexOutOfRange();
    }
    
    myColumnVector<T> result(len);
    
    for (size_t idx = minIdx; idx < minIdx + len; ++idx)
    {
        result.push_back(this->myBuffer[idx]);
    }
    
    return result;
}

template <typename T>
size_t myColumnVector<T>::nrows() const
{
    return this->mySize;
}

template <typename T>
size_t myColumnVector<T>::ncols() const
{
    return 1;
}

template <typename T>
void myColumnVector<T>::print() const
{
    for (T val : *this)
    {
        std::cout << val << "\n";
    }
}


// explicit template instantiations
template class myColumnVector<int>;
template class myColumnVector<float>;
template class myColumnVector<double>;

template myColumnVector<int> operator+ (const myColumnVector<int>&);
template myColumnVector<int> operator+ (const myColumnVector<int>&, const myColumnVector<int>&);
template myColumnVector<int> operator- (const myColumnVector<int>&);
template myColumnVector<int> operator- (const myColumnVector<int>&, const myColumnVector<int>&);
template myColumnVector<int> operator* (const myColumnVector<int>&, const int coeff);
template myColumnVector<int> operator* (const int, const myColumnVector<int>&);
template myColumnVector<int> operator/ (const myColumnVector<int>&, const int);

template myColumnVector<float> operator+ (const myColumnVector<float>&);
template myColumnVector<float> operator+ (const myColumnVector<float>&, const myColumnVector<float>&);
template myColumnVector<float> operator- (const myColumnVector<float>&);
template myColumnVector<float> operator- (const myColumnVector<float>&, const myColumnVector<float>&);
template myColumnVector<float> operator* (const myColumnVector<float>&, const float coeff);
template myColumnVector<float> operator* (const float, const myColumnVector<float>&);
template myColumnVector<float> operator/ (const myColumnVector<float>&, const float);

template myColumnVector<double> operator+ (const myColumnVector<double>&);
template myColumnVector<double> operator+ (const myColumnVector<double>&, const myColumnVector<double>&);
template myColumnVector<double> operator- (const myColumnVector<double>&);
template myColumnVector<double> operator- (const myColumnVector<double>&, const myColumnVector<double>&);
template myColumnVector<double> operator* (const myColumnVector<double>&, const double coeff);
template myColumnVector<double> operator* (const double, const myColumnVector<double>&);
template myColumnVector<double> operator/ (const myColumnVector<double>&, const double);
