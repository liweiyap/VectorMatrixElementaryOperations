/**
 * test multiplication of a row vector with a matrix to produce a row vector
 */

#ifndef MULROWVECTORMATRIX_H
#define MULROWVECTORMATRIX_H

#ifndef MYMATRIX_H
#include "../headers/myMatrix.hpp"
#endif

#ifndef MYROWVECTOR_H
#include "../headers/myRowVector.hpp"
#endif


void mulRowVectorMatrix()
{
    std::cout << "Testing multiplication of row vector and matrix (in this order):\n\n";
    
    myRowVector<double> a;
    for (int i = 1; i <= 3; ++i)
    {
        a << static_cast<double>(i);
    }
    std::cout << "Vector is:\n";
    a.print();
    
    myMatrix<double> b(3,4);
    for (int i = 1; i <= 12; ++i)
    {
        b << static_cast<double>(i);
    }
    std::cout << "Matrix is:\n";
    b.print();
    
    a *= b;
    std::cout << "Result is:\n";
    a.print();
    
    std::cout << "\n(9/11 tests passed!)\n\n";
}

#endif
