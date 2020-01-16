/**
 * test addition of two row vectors
 */

#ifndef ADDROWVECTORS_H
#define ADDROWVECTORS_H

#ifndef MYROWVECTOR_H
#include "../headers/myRowVector.hpp"
#endif


void addRowVectors()
{
    std::cout << "Testing addition of two row vectors:\n\n";
    
    myRowVector<double> a;
    for (int i = 1; i <= 10; ++i)
    {
        a << static_cast<double>(i);
    }
    std::cout << "Vector A is:\n";
    a.print();
    
    myRowVector<double> b(a);
    std::cout << "Vector B is:\n";
    b.print();
    
    a += b;
    std::cout << "Result is:\n";
    a.print();
    
    std::cout << "\n(1/11 tests passed!)\n\n";
}

#endif
