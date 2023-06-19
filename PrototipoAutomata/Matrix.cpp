//
// Created by gdo-j on 18-Jun-23.
//

#include "Matrix.hpp"
#define OFFSET 4

Matrix::Matrix(size_t rows, size_t columns) {
    rows > MATRIX_MAX_ROWS ? this->matrixRows = 800 : this->matrixRows = rows;
    columns > MATRIX_MAX_COLUMNS ? this->matrixColumns = 800 : this->matrixColumns = columns;
    this->matrixRows += OFFSET;
    this->matrixColumns += OFFSET;

    this->matrix = new bool* [this->matrixRows + OFFSET];
    this->matrix += OFFSET/2;

    for (size_t index = 0; index < this->matrixRows; index++) {
        this->matrix[index] = new bool[this->matrixColumns + OFFSET] {true};
        this->matrix[index] += OFFSET/2;
    }
}

Matrix::~Matrix() {
    for (size_t index = 0; index < this->matrixRows; index++) {
        this->matrix[index] -= OFFSET/2;
        delete[] this->matrix[index];
    }
    this->matrix -= OFFSET/2;
    delete[] this->matrix;
}


bool **Matrix::getMatrix() const {
    return matrix;
}

void Matrix::setMatrix(bool **matrix) {
    Matrix::matrix = matrix;
}

size_t Matrix::getMatrixRows() const {
    return matrixRows;
}

void Matrix::setMatrixRows(size_t matrixRows) {
    Matrix::matrixRows = matrixRows;
}

size_t Matrix::getMatrixColumns() const {
    return matrixColumns;
}

void Matrix::setMatrixColumns(size_t matrixColumns) {
    Matrix::matrixColumns = matrixColumns;
}
