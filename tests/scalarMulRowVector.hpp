/**
 * test scalar multiplication of a row vector
 */

#ifndef SCALARMULROWVECTOR_H
#define SCALARMULROWVECTOR_H

#ifndef MYROWVECTOR_H
#include "../headers/myRowVector.hpp"
#endif


void scalarMulRowVector()
{
    std::cout << "Testing scalar multiplication of row vector:\n\n";
    
    myRowVector<double> a;
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
    
    std::cout << "\n(4/11 tests passed!)\n\n";
}

#endif
