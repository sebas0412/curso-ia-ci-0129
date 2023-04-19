//
// Created by gerardo on 30/03/23.
//

#include "Puzzle.h"

Puzzle::Puzzle(short **matrix) {
    this->initialMatrix = matrix;
    this->queue = new std::deque<short**>();

    this->solution = new short*[MATRIX_SIZE];
    this->solution[0] = new short[3] {0, 1, 2};
    this->solution[1] = new short[3] {3 ,4 ,5};
    this->solution[2] = new short[3] {6 ,7 ,8};
    this->created = 0;
    this->deleted = 0;
}

Puzzle::~Puzzle() {
    deleteMatrix(this->solution);
    delete this->queue;
}

bool Puzzle::existsInQueue(short **matrix) {
    short** tempMatrix;

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

bool Puzzle::matricesAreEqual(short **matrixA, short **matrixB) {
    for (short rows = 0; rows < MATRIX_SIZE; rows++) {
        for (short cols = 0; cols < MATRIX_SIZE; cols++) {
            if (matrixA[rows][cols] != matrixB[rows][cols]) {
                return false;
            }
        }
    }

    return true;
}

void Puzzle::executeBreadthFirst() {
    this->breadthIterations = 0;
    this->queue->push_back(cloneMatrix(this->initialMatrix));
    short** currentState;
    short zeroR, zeroC;


    while (!matricesAreEqual(currentState = this->queue->front(), this->solution)) {
        this->queue->pop_front();
        this->breadthIterations++;

        findZeroLocation(currentState, &zeroR, &zeroC);
        findAllNeighbourStates(currentState, &zeroR, &zeroC);
        deleteMatrix(currentState);
    }

    printMatrix(currentState);
    printf("Ancho Primero: Total de Iteraciones necesitadas: %ld\n", this->breadthIterations);
    while (!this->queue->empty()) {
        short** temp = this->queue->front();
        this->queue->pop_front();
        deleteMatrix(temp);
    }
}

void Puzzle::findZeroLocation(short **matrix, short *r, short *c) {
    for (short row = 0; row < MATRIX_SIZE; row++) {
        for (short col = 0; col < MATRIX_SIZE; col++) {
            if (matrix[row][col] == 0) {
                *r = row;
                *c = col;
                return;
            }
        }
    }
}


void Puzzle::findAllNeighbourStates(short **matrix, short *r, short *c) {
    short** tempMatrix;

    if (canMoveUp(r)) {
        tempMatrix = cloneMatrix(matrix);
        swap(&tempMatrix[*r][*c], &tempMatrix[*r - 1][*c]);
        if (!existsInQueue(tempMatrix)) {
            this->queue->push_back(tempMatrix);
        } else {
            deleteMatrix(tempMatrix);
        }
    }

    if (canMoveDown(r)) {
        tempMatrix = cloneMatrix(matrix);
        swap(&tempMatrix[*r][*c], &tempMatrix[*r + 1][*c]);
        if (!existsInQueue(tempMatrix)) {
            this->queue->push_back(tempMatrix);
        } else {
            deleteMatrix(tempMatrix);
        }
    }

    if (canMoveLeft(c)) {
        tempMatrix = cloneMatrix(matrix);
        swap(&tempMatrix[*r][*c], &tempMatrix[*r][*c - 1]);
        if (!existsInQueue(tempMatrix)) {
            this->queue->push_back(tempMatrix);
        } else {
            deleteMatrix(tempMatrix);
        }
    }

    if (canMoveRight(c)) {
        tempMatrix = cloneMatrix(matrix);
        swap(&tempMatrix[*r][*c], &tempMatrix[*r][*c + 1]);
        if (!existsInQueue(tempMatrix)) {
            this->queue->push_back(tempMatrix);
        } else {
            deleteMatrix(tempMatrix);
        }
    }
}

short **Puzzle::cloneMatrix(short **matrix) {
    short** newMatrix = new short*[MATRIX_SIZE];
    this->created++;

    for (short index = 0; index < MATRIX_SIZE; index++) {
        newMatrix[index] = new short[MATRIX_SIZE];
    }

    for (short row = 0; row < MATRIX_SIZE; row++) {
        for (short col = 0; col < MATRIX_SIZE; col++) {
            newMatrix[row][col] = matrix[row][col];
        }
    }

    return newMatrix;
}

void Puzzle::deleteMatrix(short **matrix) {
    this->deleted++;
    for (short index = 0; index < MATRIX_SIZE; index++) {
        delete[] matrix[index];
    }
    delete[] matrix;
}

void Puzzle::swap(short *a, short *b) {
    short temp = *a;
    *a = *b;
    *b = temp;
}

bool Puzzle::canMoveUp(const short *row) {
    return *row > 0;
}

bool Puzzle::canMoveDown(const short *row) {
    return *row < MATRIX_SIZE - 1;
}

bool Puzzle::canMoveLeft(const short *col) {
    return *col > 0;
}

bool Puzzle::canMoveRight(const short *col) {
    return *col < MATRIX_SIZE - 1;
}

void Puzzle::printMatrix(short **matrix) {
    for (short rows = 0; rows < MATRIX_SIZE; ++rows) {
        for (short cols = 0; cols < MATRIX_SIZE; ++cols) {
            printf("%d\t", matrix[rows][cols]);
        }
        printf("\n");
    }
    printf("\n");
}

short **Puzzle::getInitialMatrix() const {
    return initialMatrix;
}

void Puzzle::setInitialMatrix(short **initialMatrix) {
    Puzzle::initialMatrix = initialMatrix;
}

void Puzzle::executeIDS() {
    this->searchDepth = 0;
    this->idsIterations = 0;

    for (short index = 0; index < MAX_DEPTH; ++index) {
        if (IDS(this->initialMatrix, 0)) {
            printf("IDS: Se encontro la solucion en %ld iteraciones y en una profundidad de %ld\n\n\n", this->idsIterations, this->idsFinalDepth);
            return;
        } else {
            printf("IDS: No se encontro la solucion en la profundidad de %ld\n", this->searchDepth);
            this->searchDepth++;
        }
    }
}

bool Puzzle::IDS(short **matrix, short currentDepth) {
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
        short r, c;
        findZeroLocation(matrix, &r, &c);
        short** tempMatrix;
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

