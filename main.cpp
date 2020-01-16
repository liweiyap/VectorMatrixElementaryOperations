/**
 * run all tests
 */

#ifndef ADDROWVECTORS_H
#include "tests/addRowVectors.hpp"
#endif

#ifndef ADDCOLUMNVECTORS_H
#include "tests/addColumnVectors.hpp"
#endif

#ifndef ADDMATRICES_H
#include "tests/addMatrices.hpp"
#endif

#ifndef SCALARMULROWVECTOR_H
#include "tests/scalarMulRowVector.hpp"
#endif

#ifndef SCALARMULCOLUMNVECTOR_H
#include "tests/scalarMulColumnVector.hpp"
#endif

#ifndef SCALARMULMATRIX_H
#include "tests/scalarMulMatrix.hpp"
#endif

#ifndef MULROWCOLUMNVECTORS_H
#include "tests/mulRowColumnVectors.hpp"
#endif

#ifndef MULCOLUMNROWVECTORS_H
#include "tests/mulColumnRowVectors.hpp"
#endif

#ifndef MULROWVECTORMATRIX_H
#include "tests/mulRowVectorMatrix.hpp"
#endif

#ifndef MULMATRIXCOLUMNVECTOR_H
#include "tests/mulMatrixColumnVector.hpp"
#endif

#ifndef MULMATRICES_H
#include "tests/mulMatrices.hpp"
#endif


int main()
{
    try
    {
        addRowVectors();
        addColumnVectors();
        addMatrices();
        scalarMulRowVector();
        scalarMulColumnVector();
        scalarMulMatrix();
        mulRowColumnVectors();
        mulColumnRowVectors();
        mulRowVectorMatrix();
        mulMatrixColumnVector();
        mulMatrices();
    }
    catch (IncompatibleDims& error)
    {
        std::cerr << "Error: Check dimensions of operands.\n";
    }
    catch (IndexOutOfRange& error)
    {
        std::cerr << "Error: Check index.\n";
    }
    catch (Overflow& error)
    {
        std::cerr << "Error: Result of computation is greater than maximum value that can be stored.\n";
    }
    catch (Underflow& error)
    {
        std::cerr << "Error: Result of computation is smaller than minimum value that can be stored.\n";
    }
    catch (DivisionByZero& error)
    {
        std::cerr << "Error: Division by zero produces undefined value.\n";
    }
    catch (InvalidMode& error)
    {
        std::cerr << "Error: Name of mode must be one of the following: add, sub, mul, or div.\n";
    }
}
