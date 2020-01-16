/**
 * list of additional helper functions
 */

#ifndef AUXILIARY_H
#include "auxiliary.hpp"
#endif

#ifndef EXCEPTIONS_H
#include "exceptions.hpp"
#endif


template <typename T>
T maxOf3(const T n, const T m, const T p)
{
    T max = (n > m) ? n : m;
    max = (max > p) ? max : p;
    return max;
}

template <typename T>
void checkOverAndUnderflows_Addition(const T operand1, const T operand2)
{
    if (operand2 > 0 && operand1 > std::numeric_limits<int>::max() - operand2)
    {
        throw Overflow();
    }
    if (operand2 < 0 && operand1 < std::numeric_limits<int>::min() - operand2)
    {
        throw Underflow();
    }
}

template <typename T>
void checkOverAndUnderflows_Subtraction(const T operand1, const T operand2)
{
    if (operand2 < 0 && operand1 > std::numeric_limits<int>::max() + operand2)
    {
        throw Overflow();
    }
    if (operand2 > 0 && operand1 < std::numeric_limits<int>::min() + operand2)
    {
        throw Underflow();
    }
}

template <typename T>
void checkOverAndUnderflows_Multiplication(const T operand1, const T operand2)
{
    if (operand1 == -1 && operand2 == std::numeric_limits<int>::min())
    {
        throw Overflow();
    }
    if (operand2 == -1 && operand1 == std::numeric_limits<int>::min())
    {
        throw Overflow();
    }
    if (operand2 != 0 && operand1 > std::numeric_limits<int>::max() / operand2)
    {
        throw Overflow();
    }
    if (operand2 != 0 && operand1 < std::numeric_limits<int>::min() / operand2)
    {
        throw Underflow();
    }
}

template <typename T>
void checkOverAndUnderflows_Division(const T operand1, const T operand2)
{
    if (operand2 == -1 && operand1 == std::numeric_limits<int>::min())
    {
        throw Overflow();
    }
}

template <typename T>
void checkOverAndUnderflows(const T operand1, const T operand2, const std::string mode)
{
    if (mode == "add")
    {
        checkOverAndUnderflows_Addition(operand1, operand2);
    }
    else if (mode == "sub")
    {
        checkOverAndUnderflows_Subtraction(operand1, operand2);
    }
    else if (mode == "mul")
    {
        checkOverAndUnderflows_Multiplication(operand1, operand2);
    }
    else if (mode == "div")
    {
        checkOverAndUnderflows_Division(operand1, operand2);
    }
    else
    {
        throw InvalidMode();
    }
}

// explicit template instantiations
template size_t maxOf3<size_t>(const size_t, const size_t, const size_t);
template int maxOf3<int>(const int, const int, const int);
template float maxOf3<float>(const float, const float, const float);
template double maxOf3<double>(const double, const double, const double);

template void checkOverAndUnderflows<int>(const int, const int, const std::string);
template void checkOverAndUnderflows<float>(const float, const float, const std::string);
template void checkOverAndUnderflows<double>(const double, const double, const std::string);
