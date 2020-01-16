/**
 * test scalar multiplication of a column vector
 */

#ifndef SCALARMULCOLUMNVECTOR_H
#define SCALARMULCOLUMNVECTOR_H

#ifndef MYCOLUMNVECTOR_H
#include "../headers/myColumnVector.hpp"
#endif


void scalarMulColumnVector()
{
    std::cout << "Testing scalar multiplication of column vector:\n\n";
    
    myColumnVector<double> a;
    for (int i = 1; i <= 10; ++i)
    {
        a << static_cast<double>(i);
    }
    std::cout << "Vector is:\n";
    a.print();
    
    double b = 2.0;
    std::cout << "Coefficient is:\n" << b << "\n";
    
    a *= b;
    std::cout << "Result is:\n";
    a.print();
    
    std::cout << "\n(5/11 tests passed!)\n\n";
}

#endif
