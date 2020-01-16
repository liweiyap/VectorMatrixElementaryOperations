/**
 * Definition of derived RowVector class.
 */

#ifndef MYROWVECTOR_H
#define MYROWVECTOR_H

#ifndef AUXILIARY_H
#include "auxiliary.hpp"
#endif

#ifndef MYVECTOR_H
#include "myVector.hpp"
#endif

#ifndef MYMATRIX_H
#include "myMatrix.hpp"
#endif


template<typename T>
class myRowVector : public myVector<T>
{
public:
    myRowVector();
    myRowVector(const size_t len);
    myRowVector(const myRowVector<T>& otherVec);
    myRowVector(myRowVector<T>&& otherVec);
    
    myRowVector<T>& operator= (const myRowVector<T>& otherVec);
    myRowVector<T>& operator<< (T val);
    
    template <typename U> friend myRowVector<U> operator+ (const myRowVector<U>& otherVec);
    template <typename U> friend myRowVector<U> operator+ (const myRowVector<U>& Vec1, const myRowVector<U>& Vec2);
    myRowVector<T>& operator+= (const myRowVector<T>& otherVec);
    
    template <typename U> friend myRowVector<U> operator- (const myRowVector<U>& otherVec);
    template <typename U> friend myRowVector<U> operator- (const myRowVector<U>& Vec1, const myRowVector<U>& Vec2);
    myRowVector<T>& operator-= (const myRowVector<T>& otherVec);
    
    template <typename U> friend myRowVector<U> operator* (const myRowVector<U>& Vec, const U coeff);
    template <typename U> friend myRowVector<U> operator* (const U coeff, const myRowVector<U>& Vec);
    template <typename U> friend myRowVector<U> operator* (const myRowVector<U>& Vec, const myMatrix<U>& Mat);
    myRowVector<T>& operator*= (const T coeff);
    myRowVector<T>& operator*= (const myMatrix<T>& Mat);
    
    template <typename U> friend myRowVector<U> operator/ (const myRowVector<U>& Vec, const U divisor);
    myRowVector<T>& operator/= (const T divisor);
    
    myRowVector<T> block(const size_t minIdx, const size_t len) const;
    
    size_t nrows() const;
    size_t ncols() const;
    
    void print() const override;
};

#endif
