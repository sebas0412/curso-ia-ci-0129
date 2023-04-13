//
// Created by gerardo on 30/03/23.
//

#include "AnchoPrimero.h"

AnchoPrimero::AnchoPrimero(int **matrix) {
    this->initialMatrix = new int*[MATRIX_SIZE];
    this->solution = new int*[MATRIX_SIZE];
    this->queue = new std::deque<int**>();

    for (int i = 0; i < MATRIX_SIZE; i++) {
        this->initialMatrix[i] = new int[MATRIX_SIZE];
        this->solution[i] = new int [MATRIX_SIZE];
    }

    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            this->solution[row][col] = row + col;
        }
    }
}

AnchoPrimero::~AnchoPrimero() {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        delete[] this->initialMatrix[i];
        delete[] this->solution[i];
    }


    delete this->initialMatrix;
    delete this->solution;
    delete this->queue;
}

bool AnchoPrimero::existsInQueue(int **matrix) {
    int** tempMatrix;

    if (!this->queue->empty()) {
        for (auto & index : *this->queue) {
            tempMatrix = index;

            if (matricesAreEqual(matrix, tempMatrix)) {
                return true;
            }
        }
    }

    return false;
}

bool AnchoPrimero::matricesAreEqual(int **matrixA, int **matrixB) {
    for (int rows = 0; rows < MATRIX_SIZE; rows++) {
        for (int cols = 0; cols < MATRIX_SIZE; cols++) {
            if (matrixA[rows][cols] != matrixB[rows][cols]) {
                return false;
            }
        }
    }

    return true;
}

void AnchoPrimero::execute() {
    this->queue->push_back(this->initialMatrix);
    int** currentState;
    int zeroR, zeroC;

    while (!matricesAreEqual(currentState = this->queue->front(), this->solution)) {
        this->queue->pop_front();
        this->iterationCounter++;

        findZeroLocation(currentState, &zeroR, &zeroC);
        findAllNeighbourStates(currentState, &zeroR, &zeroC);
    }

    printResults(currentState);
}

void AnchoPrimero::findZeroLocation(int **matrix, int *r, int *c) {
    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            if (matrix[row][col] == 0) {
                *r = row;
                *c = col;
                return;
            }
        }
    }
}


void AnchoPrimero::findAllNeighbourStates(int **matrix, int *r, int *c) {
    int** tempMatrix;

    if (canMoveUp(r)) {
        tempMatrix = cloneMatrix(matrix);
        swap(&tempMatrix[*r][*c], &tempMatrix[*r - 1][*c]);
        this->queue->push_back(tempMatrix);
    }

    if (canMoveDown(r)) {
        tempMatrix = cloneMatrix(matrix);
        swap(&tempMatrix[*r][*c], &tempMatrix[*r + 1][*c]);
        this->queue->push_back(tempMatrix);
    }

    if (canMoveLeft(c)) {
        tempMatrix = cloneMatrix(matrix);
        swap(&tempMatrix[*r][*c], &tempMatrix[*r][*c - 1]);
        this->queue->push_back(tempMatrix);
    }

    if (canMoveRight(c)) {
        tempMatrix = cloneMatrix(matrix);
        swap(&tempMatrix[*r][*c], &tempMatrix[*r][*c + 1]);
        this->queue->push_back(tempMatrix);
    }
}

int **AnchoPrimero::cloneMatrix(int **matrix) {
    int** newMatrix = new int*[MATRIX_SIZE];

    for (int index = 0; index < MATRIX_SIZE; index++) {
        newMatrix[index] = new int[MATRIX_SIZE];
    }

    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            newMatrix[row][col] = matrix[row][col];
        }
    }

    return newMatrix;
}

void AnchoPrimero::deleteMatrix(int **matrix) {
    for (int index = 0; index < MATRIX_SIZE; index++) {
        delete matrix[index];
    }
    delete matrix;
}

void AnchoPrimero::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool AnchoPrimero::canMoveUp(const int *row) {
    return *row > 0;
}

bool AnchoPrimero::canMoveDown(const int *row) {
    return *row < MATRIX_SIZE - 1;
}

bool AnchoPrimero::canMoveLeft(const int *col) {
    return *col > 0;
}

bool AnchoPrimero::canMoveRight(const int *col) {
    return *col < MATRIX_SIZE - 1;
}

int AnchoPrimero::printResults(int **matrix) {
    for (int rows = 0; rows < MATRIX_SIZE; ++rows) {
        for (int cols = 0; cols < MATRIX_SIZE; ++cols) {
            printf("%d\t", matrix[rows][cols]);
        }
        printf("\n");
    }
    printf("Iteraciones Totales: %ld", this->iterationCounter);
}

