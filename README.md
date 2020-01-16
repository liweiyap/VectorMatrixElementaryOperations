## General Information

This is a simple and small library containing my own implementations of row vectors, column vectors, and matrices. All these three classes are derived from a base vector class, which is designed to be an abstract class. 

The following operations are supported:
* Addition and subtraction of row vectors.
* Addition and subtraction of column vectors.
* Addition and subtraction of matrices.
* Negation of row vectors, column vectors, and matrices.
* Scalar multiplication and division of row vectors.
* Scalar multiplication and division of column vectors.
* Scalar multiplication and division of matrices.
* Multiplication of a row vector with a column vector, yielding a scalar.
* Multiplication of a column vector with a row vector, yielding a matrix.
* Multiplication of a row vector with a matrix, yielding a row vector.
* Multiplication of a matrix with a column vector, yielding a column vector.
* Matrix-matrix multiplication.

Only the following C++ data types are supported thus far:  `int`, `float`, and `double`.

## Compilation

To create a local copy of this repository, simply click 'Download'. Alternatively, clone it by first navigating to the path you want to store the local copy and then executing the following on the command line:
```
git clone https://github.com/liweiyap/VectorMatrixElementaryOperations.git
```

Compilation relies on the [CMake](https://cmake.org/) build system. The code has been tested with recent versions of the [Clang](http://clang.llvm.org/docs/) C++ compiler. To compile and run all tests, execute the following **in the root of the repository**:
```
mkdir build
cd build
cmake ..
make
./main
```
