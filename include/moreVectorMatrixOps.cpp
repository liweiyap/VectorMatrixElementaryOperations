/**
 * list of more operations involving vectors and matrices.
 */

#ifndef MOREVECTORMATRIXOPS_H
#include "moreVectorMatrixOps.hpp"
#endif


template <typename T>
T operator* (const myRowVector<T>& Vec1, const myColumnVector<T>& Vec2)
{
    if(Vec1.size() != Vec2.size())
    {
        throw IncompatibleDims();
    }

    T result = 0;
    for (size_t idx = 0; idx < Vec1.size(); ++idx)
    {
        checkOverAndUnderflows(Vec1[idx], Vec2[idx], "mul");
        T increment = Vec1[idx] * Vec2[idx];
        checkOverAndUnderflows(result, increment, "add");
        result += increment;
    }
    return result;
}

template <typename T>
myMatrix<T> operator* (const myColumnVector<T>& Vec1, const myRowVector<T>& Vec2)
{
    if(Vec1.size() != Vec2.size())
    {
        throw IncompatibleDims();
    }
    
    myMatrix<T> result(Vec1.size(), Vec2.size());
    for (size_t rowIdx = 0; rowIdx < result.nrows(); ++rowIdx)
    {
        for (size_t colIdx = 0; colIdx < result.ncols(); ++colIdx)
        {
            checkOverAndUnderflows(Vec1[rowIdx], Vec2[colIdx], "mul");
            result.push_back(Vec1[rowIdx] * Vec2[colIdx]);
        }
    }
    return result;
}

template <typename T>
myColumnVector<T> operator* (const myMatrix<T>& Mat, const myColumnVector<T>& Vec)
{
    if(Mat.ncols() != Vec.size())
    {
        throw IncompatibleDims();
    }
    
    myColumnVector<T> result;
    for (size_t rowIdx = 0; rowIdx < Mat.nrows(); ++rowIdx)
    {
        T sum = 0;
        for (size_t colIdx = 0; colIdx < Mat.ncols(); ++colIdx)
        {
            checkOverAndUnderflows(Mat[rowIdx * Mat.ncols() + colIdx], Vec[colIdx], "mul");
            T increment = Mat[rowIdx * Mat.ncols() + colIdx] * Vec[colIdx];
            checkOverAndUnderflows(sum, increment, "add");
            sum += increment;
        }
        result.push_back(sum);
    }
    return result;
}

// explicit template instantiations
template int operator* (const myRowVector<int>&, const myColumnVector<int>&);
template myMatrix<int> operator* (const myColumnVector<int>&, const myRowVector<int>&);
template myColumnVector<int> operator* (const myMatrix<int>&, const myColumnVector<int>&);

template float operator* (const myRowVector<float>&, const myColumnVector<float>&);
template myMatrix<float> operator* (const myColumnVector<float>&, const myRowVector<float>&);
template myColumnVector<float> operator* (const myMatrix<float>&, const myColumnVector<float>&);

template double operator* (const myRowVector<double>&, const myColumnVector<double>&);
template myMatrix<double> operator* (const myColumnVector<double>&, const myRowVector<double>&);
template myColumnVector<double> operator* (const myMatrix<double>&, const myColumnVector<double>&);
