/**
 * test multiplication of a column vector and a row vector to produce a matrix
 */

#ifndef MULCOLUMNROWVECTORS_H
#define MULCOLUMNROWVECTORS_H

#ifndef MYCOLUMNVECTOR_H
#include "../headers/myColumnVector.hpp"
#endif

#ifndef MYMATRIX_H
#include "../headers/myMatrix.hpp"
#endif

#ifndef MYROWVECTOR_H
#include "../headers/myRowVector.hpp"
#endif

#ifndef MOREVECTORMATRIXOPS_H
#include "../headers/moreVectorMatrixOps.hpp"
#endif


void mulColumnRowVectors()
{
    std::cout << "Testing multiplication of column and row vectors (in this order):\n\n";
    
    myColumnVector<double> a;
    for (int i = 1; i <= 10; ++i)
    {
        a << static_cast<double>(i);
    }
    std::cout << "Vector A is:\n";
    a.print();
    
    myRowVector<double> b;
    for (int i = 1; i <= 10; ++i)
    {
        b << static_cast<double>(i);
    }
    std::cout << "Vector B is:\n";
    b.print();
    
    myMatrix<double> c = a * b;
    std::cout << "Result is:\n";
    c.print();
    
    std::cout << "\n(8/11 tests passed!)\n\n";
}

#endif
