/**
 * test addition of two matrices
 */

#ifndef ADDMATRICES_H
#define ADDMATRICES_H

#ifndef MYMATRIX_H
#include "../headers/myMatrix.hpp"
#endif


void addMatrices()
{
    std::cout << "Testing addition of two matrices:\n\n";
    
    myMatrix<int> a(3,2);
    for (int i = 1; i <= 6; ++i)
    {
        a << i;
    }
    std::cout << "Matrix A is:\n";
    a.print();
    
    myMatrix<int> b(a);
    std::cout << "Matrix B is:\n";
    b.print();
    
    a += b;
    std::cout << "Result is:\n";
    a.print();
    
    std::cout << "\n(3/11 tests passed!)\n\n";
}

#endif
