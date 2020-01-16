/**
 * test multiplication of a matrix with a column vector to produce a column vector
 */

#ifndef MULMATRIXCOLUMNVECTOR_H
#define MULMATRIXCOLUMNVECTOR_H

#ifndef MYCOLUMNVECTOR_H
#include "../headers/myColumnVector.hpp"
#endif

#ifndef MYMATRIX_H
#include "../headers/myMatrix.hpp"
#endif

#ifndef MOREVECTORMATRIXOPS_H
#include "../headers/moreVectorMatrixOps.hpp"
#endif


void mulMatrixColumnVector()
{
    std::cout << "Testing multiplication of matrix and column vector (in this order):\n\n";
    
    myMatrix<float> a(3,4);
    for (int i = 1; i <= 12; ++i)
    {
        a << static_cast<float>(i);
    }
    std::cout << "Matrix is:\n";
    a.print();
    
    myColumnVector<float> b;
    for (int i = 1; i <= 4; ++i)
    {
        b << static_cast<double>(i);
    }
    std::cout << "Vector is:\n";
    b.print();
    
    myColumnVector<float> c = a * b;
    std::cout << "Result is:\n";
    c.print();
    
    std::cout << "\n(10/11 tests passed!)\n\n";
}

#endif
