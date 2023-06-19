//
// Created by gdo-j on 18-Jun-23.
//

#ifndef CURSO_IA_CI_0129_MATRIX_HPP
#define CURSO_IA_CI_0129_MATRIX_HPP

#include <cstddef>
#include <exception>
#include <iostream>

#define MATRIX_MAX_ROWS 800
#define MATRIX_MAX_COLUMNS 800
#define COUT std::cout
#define ENDL std::endl


class Matrix {
public:
    Matrix (size_t rows, size_t columns);
    ~Matrix();

    bool **getMatrix() const;
    void setMatrix(bool **matrix);

    size_t getMatrixRows() const;
    void setMatrixRows(size_t matrixRows);

    size_t getMatrixColumns() const;
    void setMatrixColumns(size_t matrixColumns);

private:
    bool** matrix;
    size_t matrixRows;
    size_t matrixColumns;
};


#endif //CURSO_IA_CI_0129_MATRIX_HPP
