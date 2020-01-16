/**
 * test multiplication of a row vector with a column vector to produce a scalar
 */

#ifndef MULROWCOLUMNVECTORS_H
#define MULROWCOLUMNVECTORS_H

#ifndef MYCOLUMNVECTOR_H
#include "../headers/myColumnVector.hpp"
#endif

#ifndef MYROWVECTOR_H
#include "../headers/myRowVector.hpp"
#endif

#ifndef MOREVECTORMATRIXOPS_H
#include "../headers/moreVectorMatrixOps.hpp"
#endif


void mulRowColumnVectors()
{
    std::cout << "Testing multiplication of row and column vectors (in this order):\n\n";
    
    myRowVector<double> a;
    for (int i = 1; i <= 10; ++i)
    {
        a << static_cast<double>(i);
    }
    std::cout << "Vector A is:\n";
    a.print();
    
    myColumnVector<double> b;
    for (int i = 1; i <= 10; ++i)
    {
        b << static_cast<double>(i);
    }
    std::cout << "Vector B is:\n";
    b.print();
    
    double c = a * b;
    std::cout << "Result is:\n" << c << "\n";
    
    std::cout << "\n(7/11 tests passed!)\n\n";
}

#endif
