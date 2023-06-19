//
// Created by gdo-j on 18-Jun-23.
//

#include "Automata.hpp"

size_t Automata::sumOfNeighboursMoore(size_t row, size_t col, Matrix *matrixObject) {
    bool** matrix = matrixObject->getMatrix();

    if (this->useWidthOf2) {
        return (matrix[row - 1][col] +
                matrix[row - 2][col] +

                matrix[row + 1][col] +
                matrix[row + 2][col] +

                matrix[row][col - 1] +
                matrix[row][col - 2] +

                matrix[row][col + 1] +
                matrix[row][col - 2]
        );
    } else {
        return (matrix[row - 1][col] +
                matrix[row + 1][col] +

                matrix[row][col - 1] +
                matrix[row][col + 1]
        );
    }
}

size_t Automata::sumOfNeighboursNeumann(size_t row, size_t col, Matrix *matrixObject) {
    bool ** matrix = matrixObject->getMatrix();

    if (this->useWidthOf2) {
        return sumOfNeighboursMoore(row, col, matrixObject) + (
                matrix[row + 1][col + 1] +
                matrix[row + 2][col + 2] +
                matrix[row - 1][col - 1] +
                matrix[row - 2][col - 2] +

                matrix[row - 1][col + 1] +
                matrix[row - 2][col + 2] +
                matrix[row + 1][col - 1] +
                matrix[row + 2][col - 2]
        );
    } else {
        return sumOfNeighboursMoore(row, col, matrixObject) + (
                matrix[row + 1][col + 1] +
                matrix[row - 1][col - 1] +

                matrix[row - 1][col + 1] +
                matrix[row + 1][col - 1]
        );
    }
}

void Automata::initialFillRandom(Matrix *matrixObject) {
    srand(time(nullptr));

    size_t iterations = (size_t)( (double) (matrixObject->getMatrixRows() * matrixObject->getMatrixColumns()) * DEFAULT_FILL_PERCENTAGE);
    bool** matrix = matrixObject->getMatrix();

    for (size_t index = 0; index < iterations; index++) {
        size_t randomRow = rand() % matrixObject->getMatrixRows();
        size_t randomCol = rand() % matrixObject->getMatrixColumns();

        matrix[randomRow][randomCol] = true;
    }
}
