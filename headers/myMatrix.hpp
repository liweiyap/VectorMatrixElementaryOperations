/**
 * Definition of derived Matrix class.
 */

#ifndef MYMATRIX_H
#define MYMATRIX_H

#ifndef AUXILIARY_H
#include "auxiliary.hpp"
#endif

#ifndef MYVECTOR_H
#include "myVector.hpp"
#endif

#include <cassert>


template<typename T>
class myMatrix : public myVector<T>
{
public:
    myMatrix(const size_t rows, const size_t cols);
    myMatrix(const myMatrix<T>& otherMat);
    myMatrix(myMatrix<T>&& otherMat);
    
    myMatrix<T>& operator= (const myMatrix<T>& otherMat);
    myMatrix<T>& operator<< (T val);
    
    template <typename U> friend myMatrix<U> operator+ (const myMatrix<U>& otherMat);
    template <typename U> friend myMatrix<U> operator+ (const myMatrix<U>& Mat1, const myMatrix<U>& Mat2);
    myMatrix<T>& operator+= (const myMatrix<T>& otherMat);
    
    template <typename U> friend myMatrix<U> operator- (const myMatrix<U>& otherMat);
    template <typename U> friend myMatrix<U> operator- (const myMatrix<U>& Mat1, const myMatrix<U>& Mat2);
    myMatrix<T>& operator-= (const myMatrix<T>& otherMat);
    
    template <typename U> friend myMatrix<U> operator* (const myMatrix<U>& Mat, const U coeff);
    template <typename U> friend myMatrix<U> operator* (const U coeff, const myMatrix<U>& Mat);
    myMatrix<T>& operator*= (const T coeff);
    template <typename U> friend myMatrix<U> operator* (const myMatrix<U>& Mat1, const myMatrix<U>& Mat2);
    myMatrix<T>& operator*= (const myMatrix<T>& otherMat);
    
    template <typename U> friend myMatrix<U> operator/ (const myMatrix<U>& Mat, const U divisor);
    myMatrix<T>& operator/= (const T divisor);
    
    myMatrix<T> block(const size_t minRowIdx, const size_t minColIdx,
                      const size_t rows, const size_t cols) const;
    
    myMatrix<T> concatenateVert(const myMatrix<T>& Mat1, const myMatrix<T>& Mat2);
    myMatrix<T>& concatenateVert(const myMatrix<T>& otherMat);
    
    myMatrix<T> concatenateHoriz(const myMatrix<T>& Mat1, const myMatrix<T>& Mat2);
    myMatrix<T>& concatenateHoriz(const myMatrix<T>& otherMat);
    
    T getValue(const size_t rowIdx, const size_t colIdx);
    void setValue(const size_t rowIdx, const size_t colIdx, const T val);
    
    size_t nrows() const;
    size_t ncols() const;
    
    void print() const override;
    
private:
    size_t myRows = 0;
    size_t myCols = 0;
};

#endif
