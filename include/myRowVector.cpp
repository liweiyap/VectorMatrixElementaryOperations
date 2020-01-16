/**
 * Definition of derived RowVector class.
 */

#ifndef MYROWVECTOR_H
#include "myRowVector.hpp"
#endif


template<typename T>
myRowVector<T>::myRowVector() : myVector<T>(){}

template<typename T>
myRowVector<T>::myRowVector(const size_t len) : myVector<T>(len){}

template<typename T>
myRowVector<T>::myRowVector(const myRowVector<T>& otherVec) : myVector<T>()
{
    *this = otherVec;
}

template<typename T>
myRowVector<T>::myRowVector(myRowVector<T>&& otherVec)
{
    this->myBuffer = otherVec.begin();
    this->mySize = otherVec.size();
    this->myCapacity = otherVec.capacity();
    
    otherVec.myBuffer = nullptr;
    otherVec.mySize = 0;
    otherVec.myCapacity = 0;
}

template<typename T>
myRowVector<T>& myRowVector<T>::operator= (const myRowVector<T>& otherVec)
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

template<typename T>
myRowVector<T>& myRowVector<T>::operator<< (T val)
{
    myRowVector<T>& result = *this;
    result.push_back(val);
    return *this;
}

template<typename T>
myRowVector<T> operator+ (const myRowVector<T>& otherVec)
{
    return otherVec;
}

template<typename T>
myRowVector<T> operator+ (const myRowVector<T>& Vec1, const myRowVector<T>& Vec2)
{
    myRowVector<T> result = Vec1;
    result += Vec2;
    return result;
}

template<typename T>
myRowVector<T>& myRowVector<T>::operator+= (const myRowVector<T>& otherVec)
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

template<typename T>
myRowVector<T> operator- (const myRowVector<T>& otherVec)
{
    myRowVector<T> result = otherVec;
    result *= (-1);
    return result;
}

template<typename T>
myRowVector<T> operator- (const myRowVector<T>& Vec1, const myRowVector<T>& Vec2)
{
    myRowVector<T> result = Vec1;
    result -= Vec2;
    return result;
}

template<typename T>
myRowVector<T>& myRowVector<T>::operator-= (const myRowVector<T>& otherVec)
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

template<typename T>
myRowVector<T> operator* (const myRowVector<T>& Vec, const T coeff)
{
    myRowVector<T> result = Vec;
    result *= coeff;
    return result;
}

template<typename T>
myRowVector<T> operator* (const T coeff, const myRowVector<T>& Vec)
{
    myRowVector<T> result = Vec;
    result *= coeff;
    return result;
}

template<typename T>
myRowVector<T> operator* (const myRowVector<T>& Vec, const myMatrix<T>& Mat)
{
    myRowVector<T> result = Vec;
    result *= Mat;
    return result;
}

template<typename T>
myRowVector<T>& myRowVector<T>::operator*= (const T coeff)
{
    for (size_t idx = 0; idx < this->mySize; ++idx)
    {
        checkOverAndUnderflows(this->myBuffer[idx], coeff, "mul");
        this->myBuffer[idx] *= coeff;
    }
    
    return *this;
}

template<typename T>
myRowVector<T>& myRowVector<T>::operator*= (const myMatrix<T>& Mat)
{
    if(this->mySize != Mat.nrows())
    {
        throw IncompatibleDims();
    }
    
    T* newBuffer = new T[Mat.ncols()];
    size_t counter = 0;
    
    for (size_t newColIdx = 0; newColIdx < Mat.ncols(); ++newColIdx)
    {
        T sum = 0;
        for (size_t oldColIdx = 0; oldColIdx < this->mySize; ++oldColIdx)
        {
            checkOverAndUnderflows(this->myBuffer[oldColIdx], Mat[oldColIdx * Mat.ncols() + newColIdx], "mul");
            T increment = this->myBuffer[oldColIdx] * Mat[oldColIdx * Mat.ncols() + newColIdx];
            checkOverAndUnderflows(sum, increment, "add");
            sum += increment;
        }
        newBuffer[counter++] = sum;
    }
    
    this->mySize = Mat.ncols();
    this->myCapacity = this->mySize;

    delete[] this->myBuffer;
    this->myBuffer = newBuffer;
    
    return *this;
}

template<typename T>
myRowVector<T> operator/ (const myRowVector<T>& Vec, const T divisor)
{
    myRowVector<T> result = Vec;
    result /= divisor;
    return result;
}

template<typename T>
myRowVector<T>& myRowVector<T>::operator/= (const T divisor)
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

template<typename T>
myRowVector<T> myRowVector<T>::block(const size_t minIdx, const size_t len) const
{
    if (minIdx + len > this->mySize)
    {
        throw IndexOutOfRange();
    }
    
    myRowVector<T> result(len);
    
    for (size_t idx = minIdx; idx < minIdx + len; ++idx)
    {
        result.push_back(this->myBuffer[idx]);
    }
    
    return result;
}

template<typename T>
size_t myRowVector<T>::nrows() const
{
    return 1;
}

template<typename T>
size_t myRowVector<T>::ncols() const
{
    return this->mySize;
}

template<typename T>
void myRowVector<T>::print() const
{
    for (T val : *this)
    {
        std::cout << val << "\t";
    }
    std::cout << "\n";
}

// explicit template instantiations
template class myRowVector<int>;
template class myRowVector<float>;
template class myRowVector<double>;

template myRowVector<int> operator+ (const myRowVector<int>&);
template myRowVector<int> operator+ (const myRowVector<int>&, const myRowVector<int>&);
template myRowVector<int> operator- (const myRowVector<int>&);
template myRowVector<int> operator- (const myRowVector<int>&, const myRowVector<int>&);
template myRowVector<int> operator* (const myRowVector<int>&, const int coeff);
template myRowVector<int> operator* (const int, const myRowVector<int>&);
template myRowVector<int> operator* (const myRowVector<int>&, const myMatrix<int>&);
template myRowVector<int> operator/ (const myRowVector<int>&, const int);

template myRowVector<float> operator+ (const myRowVector<float>&);
template myRowVector<float> operator+ (const myRowVector<float>&, const myRowVector<float>&);
template myRowVector<float> operator- (const myRowVector<float>&);
template myRowVector<float> operator- (const myRowVector<float>&, const myRowVector<float>&);
template myRowVector<float> operator* (const myRowVector<float>&, const float coeff);
template myRowVector<float> operator* (const float, const myRowVector<float>&);
template myRowVector<float> operator* (const myRowVector<float>&, const myMatrix<float>&);
template myRowVector<float> operator/ (const myRowVector<float>&, const float);

template myRowVector<double> operator+ (const myRowVector<double>&);
template myRowVector<double> operator+ (const myRowVector<double>&, const myRowVector<double>&);
template myRowVector<double> operator- (const myRowVector<double>&);
template myRowVector<double> operator- (const myRowVector<double>&, const myRowVector<double>&);
template myRowVector<double> operator* (const myRowVector<double>&, const double coeff);
template myRowVector<double> operator* (const double, const myRowVector<double>&);
template myRowVector<double> operator* (const myRowVector<double>&, const myMatrix<double>&);
template myRowVector<double> operator/ (const myRowVector<double>&, const double);
