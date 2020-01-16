/**
 * Definition of derived Matrix class.
 */

#ifndef MYMATRIX_H
#include "myMatrix.hpp"
#endif


template <typename T>
myMatrix<T>::myMatrix(const size_t rows, const size_t cols) : myVector<T>(rows * cols), myRows(rows), myCols(cols){}

template <typename T>
myMatrix<T>::myMatrix(const myMatrix<T>& otherMat) : myVector<T>()
{
    *this = otherMat;
}

template <typename T>
myMatrix<T>::myMatrix(myMatrix<T>&& otherMat)
{
    this->myBuffer = otherMat.begin();
    this->mySize = otherMat.size();
    this->myCapacity = otherMat.capacity();
    this->myRows = otherMat.nrows();
    this->myCols = otherMat.ncols();
    
    otherMat.myBuffer = nullptr;
    otherMat.mySize = 0;
    otherMat.myCapacity = 0;
    otherMat.myRows = 0;
    otherMat.myCols = 0;
}

template <typename T>
myMatrix<T>& myMatrix<T>::operator= (const myMatrix<T>& otherMat)
{
    this->mySize = otherMat.size();
    this->myCapacity = otherMat.capacity();
    this->myRows = otherMat.nrows();
    this->myCols = otherMat.ncols();
    
    delete[] this->myBuffer;
    this->myBuffer = new T[this->myCapacity];
    for (size_t idx = 0; idx < this->mySize; ++idx)
    {
        this->myBuffer[idx] = otherMat.myBuffer[idx];
    }
    
    return *this;
}

template <typename T>
myMatrix<T>& myMatrix<T>::operator<< (T val)
{
    myMatrix<T>& result = *this;
    result.push_back(val);
    return *this;
}

template <typename T>
myMatrix<T> operator+ (const myMatrix<T>& otherMat)
{
    return otherMat;
}

template <typename T>
myMatrix<T> operator+ (const myMatrix<T>& Mat1, const myMatrix<T>& Mat2)
{
    myMatrix<T> result = Mat1;
    result += Mat2;
    return result;
}

template <typename T>
myMatrix<T>& myMatrix<T>::operator+= (const myMatrix<T>& otherMat)
{
    if( this->myRows != otherMat.nrows() &&
        this->myCols != otherMat.ncols() )
    {
        throw IncompatibleDims();
    }
    
    for (size_t idx = 0; idx < this->mySize; ++idx)
    {
        checkOverAndUnderflows(this->myBuffer[idx], otherMat.myBuffer[idx], "add");
        this->myBuffer[idx] += otherMat.myBuffer[idx];
    }
    
    return *this;
}

template <typename T>
myMatrix<T> operator- (const myMatrix<T>& otherMat)
{
    myMatrix<T> result = otherMat;
    result *= (-1);
    return result;
}

template <typename T>
myMatrix<T> operator- (const myMatrix<T>& Mat1, const myMatrix<T>& Mat2)
{
    myMatrix<T> result = Mat1;
    result -= Mat2;
    return result;
}

template <typename T>
myMatrix<T>& myMatrix<T>::operator-= (const myMatrix<T>& otherMat)
{
    if( this->myRows != otherMat.nrows() &&
        this->myCols != otherMat.ncols() )
    {
        throw IncompatibleDims();
    }
    
    for (size_t idx = 0; idx < this->mySize; ++idx)
    {
        checkOverAndUnderflows(this->myBuffer[idx], otherMat.myBuffer[idx], "sub");
        this->myBuffer[idx] -= otherMat.myBuffer[idx];
    }
    
    return *this;
}

template <typename T>
myMatrix<T> operator* (const myMatrix<T>& Mat, const T coeff)
{
    myMatrix<T> result = Mat;
    result *= coeff;
    return result;
}

template <typename T>
myMatrix<T> operator* (const T coeff, const myMatrix<T>& Mat)
{
    myMatrix<T> result = Mat;
    result *= coeff;
    return result;
}

template <typename T>
myMatrix<T>& myMatrix<T>::operator*= (const T coeff)
{
    for (size_t idx = 0; idx < this->mySize; ++idx)
    {
        checkOverAndUnderflows(this->myBuffer[idx], coeff, "mul");
        this->myBuffer[idx] *= coeff;
    }
    
    return *this;
}

template <typename T>
myMatrix<T> operator* (const myMatrix<T>& Mat1, const myMatrix<T>& Mat2)
{
    if(Mat1.ncols() != Mat2.nrows())
    {
        throw IncompatibleDims();
    }
    
    size_t max = maxOf3<size_t>(Mat1.nrows(), Mat1.ncols(), Mat2.ncols());
    myMatrix<T> A1(Mat1.nrows(), Mat2.ncols());
    
    if (max <= 2)  // breaks recursion
    {
        for (size_t rowIdx = 0; rowIdx < Mat1.nrows(); ++rowIdx)
        {
            for (size_t newColIdx = 0; newColIdx < Mat2.ncols(); ++newColIdx)
            {
                T sum = 0;
                for (size_t colIdx = 0; colIdx < Mat1.ncols(); ++colIdx)
                {
                    checkOverAndUnderflows(Mat1[rowIdx * Mat1.ncols() + colIdx], Mat2[colIdx * Mat2.ncols() + newColIdx], "mul");
                    T increment = Mat1[rowIdx * Mat1.ncols() + colIdx] * Mat2[colIdx * Mat2.ncols() + newColIdx];
                    checkOverAndUnderflows(sum, increment, "add");
                    sum += increment;
                }
                A1.push_back(sum);
            }
        }
        return A1;
    }
    
    // following algorithm taken from Wikipedia for optimisation (https://en.wikipedia.org/wiki/Matrix_multiplication_algorithm#Non-square_matrices)
    if (max == Mat1.nrows())
    {
        A1 = Mat1.block(0, 0, Mat1.nrows()/2, Mat1.ncols());
        myMatrix<T> A2 = Mat1.block(Mat1.nrows()/2, 0, Mat1.nrows() - Mat1.nrows()/2, Mat1.ncols());
        
        A1 = A1 * Mat2;
        A2 = A2 * Mat2;
        
        A1.concatenateVert(A2);
    }
    else if (max == Mat2.ncols())
    {
        myMatrix<T> A = Mat1;
        myMatrix<T> B1 = Mat2.block(0, 0, Mat2.nrows(), Mat2.ncols()/2);
        myMatrix<T> B2 = Mat2.block(0, Mat2.ncols()/2, Mat2.nrows(), Mat2.ncols() - Mat2.ncols()/2);
        
        A1 = A * B1;
        myMatrix<T> A2 = A * B2;
        A1.concatenateHoriz(A2);
    }
    else
    {
        assert(max == Mat1.ncols());
        
        A1 = Mat1.block(0, 0, Mat1.nrows(), Mat1.ncols()/2);
        myMatrix<T> A2 = Mat1.block(0, Mat1.ncols()/2, Mat1.nrows(), Mat1.ncols() - Mat1.ncols()/2);
        myMatrix<T> B1 = Mat2.block(0, 0, Mat2.nrows()/2, Mat2.ncols());
        myMatrix<T> B2 = Mat2.block(Mat2.nrows()/2, 0, Mat2.nrows() - Mat2.nrows()/2, Mat2.ncols());
        
        A1 = A1 * B1;
        A2 = A2 * B2;
        A1 += A2;
    }
    
    return A1;
}

template <typename T>
myMatrix<T>& myMatrix<T>::operator*= (const myMatrix<T>& otherMat)
{
    myMatrix<T>& result = *this;
    result = result * otherMat;
    return *this;
}

template <typename T>
myMatrix<T> operator/ (const myMatrix<T>& Mat, const T divisor)
{
    myMatrix<T> result = Mat;
    result /= divisor;
    return result;
}

template <typename T>
myMatrix<T>& myMatrix<T>::operator/= (const T divisor)
{
    if (divisor == 0)
    {
        throw DivisionByZero();
    }
    
    for (size_t idx = 0; idx < this->mySize; ++idx)
    {
        checkOverAndUnderflows(this->myBuffer[idx], divisor, "div");
        this->myBuffer[idx] /= divisor;
    }
    
    return *this;
}

template <typename T>
myMatrix<T> myMatrix<T>::block(const size_t minRowIdx, const size_t minColIdx,
                  const size_t rows, const size_t cols) const
{
    if (minRowIdx + rows > myRows || minColIdx + cols > myCols)
    {
        throw IndexOutOfRange();
    }
    
    myMatrix<T> result(rows, cols);
    
    for (size_t rowIdx = minRowIdx; rowIdx < minRowIdx + rows; ++rowIdx)
    {
        for (size_t colIdx = minColIdx; colIdx < minColIdx + cols; ++colIdx)
        {
            result.push_back(this->myBuffer[rowIdx * myCols + colIdx]);
        }
    }
    
    return result;
}

template <typename T>
myMatrix<T> myMatrix<T>::concatenateVert(const myMatrix<T>& Mat1, const myMatrix<T>& Mat2)
{
    myMatrix<T> result = Mat1;
    result.concatenateVert(Mat2);
    return result;
}

template <typename T>
myMatrix<T>& myMatrix<T>::concatenateVert(const myMatrix<T>& otherMat)
{
    if(myCols != otherMat.ncols())
    {
        throw IncompatibleDims();
    }
    
    for (size_t idx = 0; idx < otherMat.size(); ++idx)
    {
        this->push_back(*(otherMat.begin() + idx));
    }
    
    myRows += otherMat.nrows();
    
    return *this;
}

template <typename T>
myMatrix<T> myMatrix<T>::concatenateHoriz(const myMatrix<T>& Mat1, const myMatrix<T>& Mat2)
{
    myMatrix<T> result = Mat1;
    result.concatenateHoriz(Mat2);
    return result;
}

template <typename T>
myMatrix<T>& myMatrix<T>::concatenateHoriz(const myMatrix<T>& otherMat)
{
    if(myRows != otherMat.nrows())
    {
        throw IncompatibleDims();
    }
    
    T* newBuffer = new T[this->mySize + otherMat.size()];
    size_t counter = 0;
    size_t myIterator = 0;
    size_t otherIterator = 0;
    
    while (counter < this->mySize + otherMat.size())
    {
        if (counter % (myCols + otherMat.ncols()) < myCols)
        {
            newBuffer[counter++] = this->myBuffer[myIterator++];
        }
        else
        {
            newBuffer[counter++] = otherMat.myBuffer[otherIterator++];
        }
    }
    
    myCols += otherMat.ncols();
    
    this->mySize = myRows * myCols;
    this->myCapacity = this->mySize;

    delete[] this->myBuffer;
    this->myBuffer = newBuffer;
    
    return *this;
}

template <typename T>
T myMatrix<T>::getValue(const size_t rowIdx, const size_t colIdx)
{
    if(rowIdx >= myRows || colIdx >= myCols)
    {
        throw IndexOutOfRange();
    }
    
    return this->myBuffer[rowIdx * myCols + colIdx];
}

template <typename T>
void myMatrix<T>::setValue(const size_t rowIdx, const size_t colIdx, const T val)
{
    if(rowIdx >= myRows || colIdx >= myCols)
    {
        throw IndexOutOfRange();
    }
    
    this->myBuffer[rowIdx * myCols + colIdx] = val;
}

template <typename T>
size_t myMatrix<T>::nrows() const
{
    return myRows;
}

template <typename T>
size_t myMatrix<T>::ncols() const
{
    return myCols;
}

template <typename T>
void myMatrix<T>::print() const
{
    for (size_t rowIdx = 0; rowIdx < myRows; ++rowIdx)
    {
        for (size_t colIdx = 0; colIdx < myCols; ++colIdx)
        {
            std::cout << this->myBuffer[rowIdx * myCols + colIdx] << "\t";
        }
        std::cout << "\n";
    }
}

// explicit template instantiations
template class myMatrix<int>;
template class myMatrix<float>;
template class myMatrix<double>;

template myMatrix<int> operator+ (const myMatrix<int>&);
template myMatrix<int> operator+ (const myMatrix<int>&, const myMatrix<int>&);
template myMatrix<int> operator- (const myMatrix<int>&);
template myMatrix<int> operator- (const myMatrix<int>&, const myMatrix<int>&);
template myMatrix<int> operator* (const myMatrix<int>&, const int coeff);
template myMatrix<int> operator* (const int, const myMatrix<int>&);
template myMatrix<int> operator* (const myMatrix<int>&, const myMatrix<int>&);
template myMatrix<int> operator/ (const myMatrix<int>&, const int);

template myMatrix<float> operator+ (const myMatrix<float>&);
template myMatrix<float> operator+ (const myMatrix<float>&, const myMatrix<float>&);
template myMatrix<float> operator- (const myMatrix<float>&);
template myMatrix<float> operator- (const myMatrix<float>&, const myMatrix<float>&);
template myMatrix<float> operator* (const myMatrix<float>&, const float coeff);
template myMatrix<float> operator* (const float, const myMatrix<float>&);
template myMatrix<float> operator* (const myMatrix<float>&, const myMatrix<float>&);
template myMatrix<float> operator/ (const myMatrix<float>&, const float);

template myMatrix<double> operator+ (const myMatrix<double>&);
template myMatrix<double> operator+ (const myMatrix<double>&, const myMatrix<double>&);
template myMatrix<double> operator- (const myMatrix<double>&);
template myMatrix<double> operator- (const myMatrix<double>&, const myMatrix<double>&);
template myMatrix<double> operator* (const myMatrix<double>&, const double coeff);
template myMatrix<double> operator* (const double, const myMatrix<double>&);
template myMatrix<double> operator* (const myMatrix<double>&, const myMatrix<double>&);
template myMatrix<double> operator/ (const myMatrix<double>&, const double);
