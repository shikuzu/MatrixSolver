/**
 * @file mat.cpp
 * @author shikuzu (*)
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "mat.h"

mat::Matrix::Matrix(double _rows, double _cols)
{
    rows = _rows;
    cols = _cols;
    MatData.resize(rows * cols);
}

mat::Matrix::~Matrix()
{
}

/**
 * @brief Operator for acessing an element of the matrix 
 * 
 * @param row 
 * @param col 
 * @return float* a pointer to the m,n Index of the Matrix
 */
float *mat::Matrix::operator()(uint16_t row, uint16_t col)
{
    return &MatData[row * cols + col];
}

//multiply two matrices
mat::Matrix mat::Matrix::operator*(mat::Matrix mat2)
{
    if (mat2.getRows() != this->cols)
    {
        std::cerr << "For matrix multiplication the rows of the first matrix"
                     "have to match the columns of the second matrix" << std::endl;
        mat::Matrix empty(0, 0);
        return empty;
    }

    mat::Matrix res(this->cols, mat2.getRows());

    for(uint16_t i = 0; i <this->cols; i++)
    {
    
    }

    return res;
}

/**
 * @brief Construct a new std::vector<uint16 t>::operator* object
 * Perform the dot Product of two vectors
 * 
 * this is not yet tested!!
 * 
 * @param vec2 second vector 
 */
/*
std::vector<uint16_t>::operator*(std::vector<uint16_t> vec2)
{
    if(this->size != vec2.size)
    {
        std::cerr << "Error while performing vector" 
        "dot product: vector size doesn't match" << std::endl;
        std::vector<uint16_t> empty;
        return empty;
    }

    uint16_t dotProd = 0;
    for(uint i=0; i<this->size; i++)
    {
        dotProd += this[i]*vec2[i];
    }
    return dotProd;
}
*/

/**
 * @brief Add two matrices
 * 
 * @param mat2 
 * @return mat::Matrix 
 */
/*mat::Matrix operator+(mat::Matrix mat2)
{
}
*/

uint16_t mat::Matrix::getRows() { return this->rows; }

uint16_t mat::Matrix::getCols() { return this->cols; }

/**
 * @brief swap two rows of the matrix
 * 
 * |a,b,c,d| a
 * |e,f,g,h| b
 * |i,j,k,l|
 * 
 * ->
 * 
 * |e,f,g,h| b
 * |a,b,c,d| a
 * |i,j,k,l|
 * 
 * @param a row a 
 * @param b row b
 */
void mat::Matrix::SwapRows(uint16_t a, uint16_t b)
{
    std::vector<float> buf;
    buf.resize(this->rows);

    //copy row a into the buf (this is probably not the best
    //solution and could be done better with some pointer or something
    for (uint16_t i = 0; i < this->rows; i++)
    {
        buf[i] = *(*this)(a, i);
    }

    //row a = row b
    for (uint16_t i = 0; i < this->rows; i++)
    {
        *(*this)(a, i) = *(*this)(b, i);
    }

    //row b = buf
    for (uint16_t i = 0; i < this->rows; i++)
    {
        *(*this)(b, i) = buf[i];
    }
}

void mat::Matrix::display()
{
    std::cout << "\n";
    for (uint16_t i = 0; i < rows; i++)
    {
        std::cout << "|\t";
        for (uint16_t j = 0; j < cols; j++)
        {
            std::cout << std::setprecision(3) << *(*this)(i, j) << "\t";
        }
        std::cout << "|\n";
    }
}

/**
* @brief 
* brings a matrix to it's row echelon form using the gauss Elimination algorithm
* @param orig: pointer to a matrix
* @return row echelon form of the orig Matrix 
*/
mat::Matrix mat::gaussElm(mat::Matrix *orig)
{
    mat::Matrix rowEch = *orig;

    uint16_t ind;
    uint16_t n = 0;
    for (uint16_t m = 0; m < rowEch.getCols(); m++)
    {
        //First search for the first row where it's index 0 isn't '0'
        ind = n;
        while ((*rowEch(ind, m) == 0) && (ind < rowEch.getRows()))
        {
            ind++;
        }

        //Only do this if the column isn't already all zeros
        if (ind < rowEch.getRows())
        {
            rowEch.SwapRows(n, ind);

            float k;
            //make all values in the column 0 to '0'
            for (uint16_t i = n + 1; i < rowEch.getRows(); i++)
            {
                //calculate lamda
                k = -1 * (*rowEch(i, m)) / (*rowEch(n, m));

                for (uint16_t j = m; j < rowEch.getCols(); j++)
                {
                    *rowEch(i, j) += k * (*rowEch(n, j));
                }
            }

            //If Index m+1 of row m+1 isn't '0' -> divide by Index m+1,m+1
            //this will make the first nonzero index of every row '1'
            if (*rowEch(n + 1, m + 1))
            {
                k = *rowEch(n + 1, m + 1);
                for (uint16_t i = m + 1; i < rowEch.getCols(); i++)
                {
                    *rowEch(n + 1, i) /= k;
                }
            }
            //Increment counter
            n++;
        }
    }

    return rowEch;
}
