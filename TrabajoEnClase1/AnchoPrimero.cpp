//
// Created by gerardo on 30/03/23.
//

#include <cstdio>
#include "AnchoPrimero.h"

AnchoPrimero::AnchoPrimero() {
    this->solutionMatrix = new int*[MATRIX_SIZE];
    this->matrix = new int*[MATRIX_SIZE];
    this->totalIterations = 0;

    for (int i = 0; i < MATRIX_SIZE; i++) {
        this->solutionMatrix[i] = new int[MATRIX_SIZE];
        this->matrix[i] = new int [MATRIX_SIZE];
    }

    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int column = 0; column < MATRIX_SIZE; column++) {
            this->solutionMatrix[row][column] = (row * MATRIX_SIZE) + column;
            this->matrix[row][column] = (row * MATRIX_SIZE) + column;
        }
    }
}

AnchoPrimero::AnchoPrimero(int **matrix) {
    this->solutionMatrix = new int*[MATRIX_SIZE];
    this->matrix = matrix;
    this->totalIterations = 0;

    for (int i = 0; i < MATRIX_SIZE; i++) {
        this->solutionMatrix[i] = new int[MATRIX_SIZE];
    }

    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int column = 0; column < MATRIX_SIZE; column++) {
            this->solutionMatrix[row][column] = (row * MATRIX_SIZE) + column;
        }
    }
}

AnchoPrimero::~AnchoPrimero() {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        delete[] this->matrix[i];
        delete[] this->solutionMatrix[i];
    }
    delete this->matrix;
    delete this->solutionMatrix;
}

int **AnchoPrimero::getMatrix() const {
    return matrix;
}

void AnchoPrimero::setMatrix(int **matrix) {
    AnchoPrimero::matrix = matrix;
}

bool AnchoPrimero::isSolved(int **matrix) {
    bool isSolved = true;

    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            if (this->matrix[row][col] != this->solutionMatrix[row][col]) {
                isSolved = false;
                return isSolved;
            }
        }
    }
    return isSolved;
}

void AnchoPrimero::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool AnchoPrimero::solve(int currentRow, int currentCol, int currentDepth) {
    this->totalIterations++;
    printState();

    if (isSolved(this->matrix)) {
        return true;
    } else if (currentDepth > MAX_DEPTH){
        return false;
    } else {
        if (canMoveLeft(currentRow, currentCol)) {
            if (solve(currentRow, currentCol - 1, currentDepth + 1)) {
                return true;
            } else {
                canMoveRight(currentRow, currentCol);
            }
        }

        if (canMoveUp(currentRow, currentCol)) {
            if (solve(currentRow - 1, currentCol, currentDepth + 1)) {
                return true;
            } else {
                canMoveDown(currentRow, currentCol);
            }
        }

        if (canMoveRight(currentRow, currentCol)) {
            if (solve(currentRow, currentCol + 1, currentDepth + 1)) {
                return true;
            } else {
                canMoveLeft(currentRow, currentCol);
            }
        }

        if (canMoveDown(currentRow, currentCol)) {
            if (solve(currentRow + 1, currentCol, currentDepth + 1)) {
                return true;
            } else {
                canMoveUp(currentRow, currentCol);
            }
        }
    }

    return false;
}

void AnchoPrimero::printState() {
    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            printf("%d\t", this->matrix[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void AnchoPrimero::start() {
    int location = 0;
    int rowLocation;
    int colLocation;

    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            if (this->matrix[row][col] == 0) {
                goto cycleExit;
            } else {
                location++;
            }
        }
    }

    cycleExit:
    rowLocation = location / MATRIX_SIZE;
    colLocation = location % MATRIX_SIZE;

    solve(rowLocation, colLocation, 0);
    printf("Iteraciones Totales: %ld", this->totalIterations);
}

bool AnchoPrimero::withinBoundaries(int currentRow, int currentCol) {
    return (currentRow >= 0 && currentRow < MATRIX_SIZE && currentCol >= 0 && currentCol < MATRIX_SIZE);
}

bool AnchoPrimero::canMoveUp(int currentRow, int currentCol) {
    if (withinBoundaries(currentRow - 1, currentCol)) {
        swap(&matrix[currentRow][currentCol], &matrix[currentRow - 1][currentCol]);
        return true;
    } else {
        return false;
    }
}

bool AnchoPrimero::canMoveDown(int currentRow, int currentCol) {
    if (withinBoundaries(currentRow + 1, currentCol)) {
        swap(&matrix[currentRow][currentCol], &matrix[currentRow + 1][currentCol]);
        return true;
    } else {
        return false;
    }
}

bool AnchoPrimero::canMoveLeft(int currentRow, int currentCol) {
    if (withinBoundaries(currentRow, currentCol - 1)) {
        swap(&matrix[currentRow][currentCol], &matrix[currentRow][currentCol - 1]);
        return true;
    } else {
        return false;
    }
}

bool AnchoPrimero::canMoveRight(int currentRow, int currentCol) {
    if (withinBoundaries(currentRow, currentCol + 1)) {
        swap(&matrix[currentRow][currentCol], &matrix[currentRow][currentCol + 1]);
        return true;
    } else {
        return false;
    }
}
