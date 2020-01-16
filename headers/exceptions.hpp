/**
 * list of exceptions that can be thrown in case of run-time errors
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


class MyException{};
class IncompatibleDims: public MyException{};
class IndexOutOfRange: public MyException{};
class Overflow: public MyException{};
class Underflow: public MyException{};
class DivisionByZero: public MyException{};
class InvalidMode: public MyException{};

#endif
