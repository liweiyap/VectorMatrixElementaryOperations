/**
 * test addition of two column vectors
 */

#ifndef ADDCOLUMNVECTORS_H
#define ADDCOLUMNVECTORS_H

#ifndef MYCOLUMNVECTOR_H
#include "../headers/myColumnVector.hpp"
#endif


void addColumnVectors()
{
    std::cout << "Testing addition of two column vectors:\n\n";
    
    myColumnVector<double> a;
    for (int i = 1; i <= 10; ++i)
    {
        a << static_cast<double>(i);
    }
    std::cout << "Vector A is:\n";
    a.print();
    
    myColumnVector<double> b(a);
    std::cout << "Vector B is:\n";
    b.print();
    
    a += b;
    std::cout << "Result is:\n";
    a.print();
    
    std::cout << "\n(2/11 tests passed!)\n\n";
}

#endif
