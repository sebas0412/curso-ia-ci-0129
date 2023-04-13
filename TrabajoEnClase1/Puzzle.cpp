//
// Created by gerardo on 30/03/23.
//

#include "Puzzle.h"

Puzzle::Puzzle(int **matrix) {
    this->initialMatrix = matrix;
    this->queue = new std::deque<int**>();

    this->solution = new int*[MATRIX_SIZE];
    this->solution[0] = new int[3] {0, 1, 2};
    this->solution[1] = new int[3] {3 ,4 ,5};
    this->solution[2] = new int[3] {6 ,7 ,8};
}

Puzzle::~Puzzle() {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        delete[] this->initialMatrix[i];
        delete[] this->solution[i];
    }


    while (!this->queue->empty()) {
        int** temp = this->queue->front();
        this->queue->pop_front();
        deleteMatrix(temp);
    }

    delete[] this->initialMatrix;
    delete[] this->solution;
    delete this->queue;
}

bool Puzzle::existsInQueue(int **matrix) {
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

bool Puzzle::matricesAreEqual(int **matrixA, int **matrixB) {
    for (int rows = 0; rows < MATRIX_SIZE; rows++) {
        for (int cols = 0; cols < MATRIX_SIZE; cols++) {
            if (matrixA[rows][cols] != matrixB[rows][cols]) {
                return false;
            }
        }
    }

    return true;
}

void Puzzle::executeBreadthFirst() {
    this->breadthIterations = 0;
    this->queue->push_back(this->initialMatrix);
    int** currentState;
    int zeroR, zeroC;


    while (!matricesAreEqual(currentState = this->queue->front(), this->solution)) {
        this->queue->pop_front();
        this->breadthIterations++;

        findZeroLocation(currentState, &zeroR, &zeroC);
        findAllNeighbourStates(currentState, &zeroR, &zeroC);
        deleteMatrix(currentState);
    }

    printMatrix(currentState);
    printf("Ancho Primero: Total de Iteraciones necesitadas: %ld\n", this->breadthIterations);
}

void Puzzle::findZeroLocation(int **matrix, int *r, int *c) {
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


void Puzzle::findAllNeighbourStates(int **matrix, int *r, int *c) {
    int** tempMatrix;

    if (canMoveUp(r)) {
        tempMatrix = cloneMatrix(matrix);
        swap(&tempMatrix[*r][*c], &tempMatrix[*r - 1][*c]);
        if (!existsInQueue(tempMatrix)) {
            this->queue->push_back(tempMatrix);
        }
    }

    if (canMoveDown(r)) {
        tempMatrix = cloneMatrix(matrix);
        swap(&tempMatrix[*r][*c], &tempMatrix[*r + 1][*c]);
        if (!existsInQueue(tempMatrix)) {
            this->queue->push_back(tempMatrix);
        }
    }

    if (canMoveLeft(c)) {
        tempMatrix = cloneMatrix(matrix);
        swap(&tempMatrix[*r][*c], &tempMatrix[*r][*c - 1]);
        if (!existsInQueue(tempMatrix)) {
            this->queue->push_back(tempMatrix);
        }
    }

    if (canMoveRight(c)) {
        tempMatrix = cloneMatrix(matrix);
        swap(&tempMatrix[*r][*c], &tempMatrix[*r][*c + 1]);
        if (!existsInQueue(tempMatrix)) {
            this->queue->push_back(tempMatrix);
        }
    }
}

int **Puzzle::cloneMatrix(int **matrix) {
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

void Puzzle::deleteMatrix(int **matrix) {
    for (int index = 0; index < MATRIX_SIZE; index++) {
        delete[] matrix[index];
    }
    delete[] matrix;
}

void Puzzle::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool Puzzle::canMoveUp(const int *row) {
    return *row > 0;
}

bool Puzzle::canMoveDown(const int *row) {
    return *row < MATRIX_SIZE - 1;
}

bool Puzzle::canMoveLeft(const int *col) {
    return *col > 0;
}

bool Puzzle::canMoveRight(const int *col) {
    return *col < MATRIX_SIZE - 1;
}

void Puzzle::printMatrix(int **matrix) {
    for (int rows = 0; rows < MATRIX_SIZE; ++rows) {
        for (int cols = 0; cols < MATRIX_SIZE; ++cols) {
            printf("%d\t", matrix[rows][cols]);
        }
        printf("\n");
    }
    printf("\n");
}

int **Puzzle::getInitialMatrix() const {
    return initialMatrix;
}

void Puzzle::setInitialMatrix(int **initialMatrix) {
    Puzzle::initialMatrix = initialMatrix;
}

void Puzzle::executeIDS() {
    this->searchDepth = 0;
    this->idsIterations = 0;

    for (int index = 0; index < MAX_DEPTH; ++index) {
        if (IDS(this->initialMatrix, 0)) {
            printf("IDS: Se encontro la solucion en %ld iteraciones y en una profundidad de %ld\n", this->idsIterations, this->idsFinalDepth);
            return;
        } else {
            printf("IDS: No se encontro la solucion en la profundidad de %ld\n", this->searchDepth);
            this->searchDepth++;
        }
    }
}

bool Puzzle::IDS(int **matrix, int currentDepth) {
    if (currentDepth == this->searchDepth) {
        this->idsIterations++;

        if (matricesAreEqual(matrix, this->solution)) {
            printMatrix(matrix);
            this->idsFinalDepth = currentDepth;
            return true;
        } else {
            return false;
        }
    } else {
        int r, c;
        findZeroLocation(matrix, &r, &c);
        int** tempMatrix;
        bool solved;

        if (canMoveUp(&r)) {
            tempMatrix = cloneMatrix(matrix);
            swap(&tempMatrix[r][c], &tempMatrix[r - 1][c]);
            solved = IDS(tempMatrix, currentDepth + 1);
            deleteMatrix(tempMatrix);
            if (solved) {
                return true;
            }
        }

        if (canMoveDown(&r)) {
            tempMatrix = cloneMatrix(matrix);
            swap(&tempMatrix[r][c], &tempMatrix[r + 1][c]);
            solved = IDS(tempMatrix, currentDepth + 1);
            deleteMatrix(tempMatrix);
            if (solved) {
                return true;
            }
        }

        if (canMoveLeft(&c)) {
            tempMatrix = cloneMatrix(matrix);
            swap(&tempMatrix[r][c], &tempMatrix[r][c - 1]);
            solved = IDS(tempMatrix, currentDepth + 1);
            deleteMatrix(tempMatrix);
            if (solved) {
                return true;
            }
        }

        if (canMoveRight(&c)) {
            tempMatrix = cloneMatrix(matrix);
            swap(&tempMatrix[r][c], &tempMatrix[r][c + 1]);
            solved = IDS(tempMatrix, currentDepth + 1);
            deleteMatrix(tempMatrix);
            if (solved) {
                return true;
            }
        }
    }
    return false;
}

