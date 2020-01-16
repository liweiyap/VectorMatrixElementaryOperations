/**
 * Definition of derived ColumnVector class.
 */

#ifndef MYCOLUMNVECTOR_H
#define MYCOLUMNVECTOR_H

#ifndef AUXILIARY_H
#include "auxiliary.hpp"
#endif

#ifndef MYVECTOR_H
#include "myVector.hpp"
#endif


template<typename T>
class myColumnVector : public myVector<T>
{
public:
    myColumnVector();
    myColumnVector(const size_t len);
    myColumnVector(const myColumnVector<T>& otherVec);
    myColumnVector(myColumnVector<T>&& otherVec);
    
    myColumnVector<T>& operator= (const myColumnVector<T>& otherVec);
    myColumnVector<T>& operator<< (T val);
    
    template <typename U> friend myColumnVector<U> operator+ (const myColumnVector<U>& otherVec);
    template <typename U> friend myColumnVector<U> operator+ (const myColumnVector<U>& Vec1, const myColumnVector<U>& Vec2);
    myColumnVector<T>& operator+= (const myColumnVector<T>& otherVec);
    
    template <typename U> friend myColumnVector<U> operator- (const myColumnVector<U>& otherVec);
    template <typename U> friend myColumnVector<U> operator- (const myColumnVector<U>& Vec1, const myColumnVector<U>& Vec2);
    myColumnVector<T>& operator-= (const myColumnVector<T>& otherVec);
    
    template <typename U> friend myColumnVector<U> operator* (const myColumnVector<U>& Vec, const U coeff);
    template <typename U> friend myColumnVector<U> operator* (const U coeff, const myColumnVector<U>& Vec);
    myColumnVector<T>& operator*= (const T coeff);
    
    template <typename U> friend myColumnVector<U> operator/ (const myColumnVector<U>& Vec, const U divisor);
    myColumnVector<T>& operator/= (const T divisor);
    
    myColumnVector<T> block(const size_t minIdx, const size_t len) const;
    
    size_t nrows() const;
    size_t ncols() const;
    
    void print() const override;
};

#endif
