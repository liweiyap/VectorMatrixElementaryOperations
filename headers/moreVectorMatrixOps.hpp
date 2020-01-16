/**
 * list of more operations involving vectors and matrices.
 */

#ifndef MOREVECTORMATRIXOPS_H
#define MOREVECTORMATRIXOPS_H

#ifndef MYCOLUMNVECTOR_H
#include "myColumnVector.hpp"
#endif

#ifndef MYMATRIX_H
#include "myMatrix.hpp"
#endif

#ifndef MYROWVECTOR_H
#include "myRowVector.hpp"
#endif

#ifndef AUXILIARY_H
#include "auxiliary.hpp"
#endif


template <typename T>
T operator* (const myRowVector<T>& Vec1, const myColumnVector<T>& Vec2);

template <typename T>
myMatrix<T> operator* (const myColumnVector<T>& Vec1, const myRowVector<T>& Vec2);

template <typename T>
myColumnVector<T> operator* (const myMatrix<T>& Mat, const myColumnVector<T>& Vec);

#endif
