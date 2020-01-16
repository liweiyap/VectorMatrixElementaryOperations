/**
 * list of additional helper functions
 */

#ifndef AUXILIARY_H
#define AUXILIARY_H

#ifndef EXCEPTIONS_H
#include "exceptions.hpp"
#endif

#include <limits>
#include <string>


template <typename T>
T maxOf3(const T n, const T m, const T p);

template <typename T>
void checkOverAndUnderflows_Addition(const T operand1, const T operand2);

template <typename T>
void checkOverAndUnderflows_Subtraction(const T operand1, const T operand2);

template <typename T>
void checkOverAndUnderflows_Multiplication(const T operand1, const T operand2);

template <typename T>
void checkOverAndUnderflows_Division(const T operand1, const T operand2);

template <typename T>
void checkOverAndUnderflows(const T operand1, const T operand2, const std::string mode);

#endif
