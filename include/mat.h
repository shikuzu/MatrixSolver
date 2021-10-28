/**
 * @file mat.h
 * @author shikuzu (*)
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <iomanip>

#pragma once

namespace mat
{
    /**
     * @brief Matix class
     * 
     * WARNING: INDEX starts a '0'
     */
    class Matrix
    {
    public:
        Matrix(double _rows, double _cols);

        ~Matrix();

        float *operator()(uint16_t row, uint16_t col);

        //Check if two matrices are equal
        bool operator==(mat::Matrix mat2);


        //multiply two matrices
        Matrix operator*(mat::Matrix mat2);

        //add two matrices
        Matrix operator+(mat::Matrix mat2);


        //Display the matrix in the console
        void display();

        //swap two rows of the matrix
        void SwapRows(uint16_t a, uint16_t b);

        uint16_t getRows();
        uint16_t getCols();

    private:
        uint16_t rows;
        uint16_t cols;

        std::vector<float> MatData;
    };

    /**
     * @brief 
     * brings a matrix to it's row echelon form using the gauss Elimination algorithm
     * @param orig: pointer to a matrix
     * @return row echelon form of the orig Matrix 
     */
    Matrix gaussElm(Matrix *orig);

} // namespace  mat
