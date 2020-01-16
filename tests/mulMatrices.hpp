/**
 * test multiplication of two matrices
 */

#ifndef MULMATRICES_H
#define MULMATRICES_H

#ifndef MYMATRIX_H
#include "../headers/myMatrix.hpp"
#endif


void mulMatrices()
{
    std::cout << "Testing multiplication of two matrices:\n\n";
    
    myMatrix<int> a(3,4);
    for (int i = 1; i <= 12; ++i)
    {
        a << i;
    }
    std::cout << "Matrix is:\n";
    a.print();
    
    myMatrix<int> b(4,5);
    for (int i = 1; i <= 20; ++i)
    {
        b << i;
    }
    std::cout << "Matrix is:\n";
    b.print();
    
    a *= b;
    std::cout << "Result is:\n";
    a.print();
    
    std::cout << "\n(11/11 tests passed!)\n\n";
}

#endif
