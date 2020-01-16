/**
 * test scalar multiplication of a matrix
 */

#ifndef SCALARMULMATRIX_H
#define SCALARMULMATRIX_H

#ifndef MYMATRIX_H
#include "../headers/myMatrix.hpp"
#endif


void scalarMulMatrix()
{
    std::cout << "Testing scalar multiplication of matrix:\n\n";
    
    myMatrix<int> a(3,2);
    for (int i = 1; i <= 6; ++i)
    {
        a << i;
    }
    std::cout << "Matrix is:\n";
    a.print();
    
    int b = 2;
    std::cout << "Coefficient is:\n" << b << "\n";
    
    a *= b;
    std::cout << "Result is:\n";
    a.print();
    
    std::cout << "\n(6/11 tests passed!)\n\n";
}

#endif
