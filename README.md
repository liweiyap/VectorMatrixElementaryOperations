## General Information

This is a simple and small library containing my own hard-coded implementations of row vectors, column vectors, and matrices. All these three classes are derived from a base vector class, which is designed to be an abstract class. 

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
