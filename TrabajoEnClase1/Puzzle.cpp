//
// Created by gerardo on 30/03/23.
//

#include <string>
#include "Puzzle.h"

Puzzle::Puzzle(short **matrix) {
    this->initialMatrix = matrix;
    this->queue = new std::deque<short**>();

    this->solution = new short*[MATRIX_SIZE];
    this->solution[0] = new short[3] {0, 1, 2};
    this->solution[1] = new short[3] {3 ,4 ,5};
    this->solution[2] = new short[3] {6 ,7 ,8};
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

void Puzzle::executeIDS(unsigned long int startingDepth = 0) {
    this->searchDepth = startingDepth;
    this->idsIterations = 0;
    short r, c;
    short** tempMatrix = cloneMatrix(this->initialMatrix);
    findZeroLocation(tempMatrix, &r, &c);
    std::string idsType = startingDepth == 0 ? "IDS" : "A-Star IDS";

    for (short index = 0; index < MAX_DEPTH; ++index) {
        if (IDS(tempMatrix, 0, r, c)) {
            printf("%s: Se encontro la solucion en %ld iteraciones y en una profundidad de %ld\n\n\n", idsType.c_str(), this->idsIterations, this->idsFinalDepth);
            return;
        } else {
            printf("%s: No se encontro la solucion en la profundidad de %ld\n", idsType.c_str(), this->searchDepth);
            this->searchDepth++;
        }
    }
    deleteMatrix(tempMatrix);
}

bool Puzzle::IDS(short **matrix, short currentDepth, short zeroR, short zeroC) {
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
        bool solved;

        if (canMoveUp(&zeroR)) {
            swap(&matrix[zeroR][zeroC], &matrix[zeroR - 1][zeroC]);
            solved = IDS(matrix, currentDepth + 1, zeroR - 1, zeroC);
            if (solved) {
                return true;
            }
            swap(&matrix[zeroR][zeroC], &matrix[zeroR - 1][zeroC]);
        }

        if (canMoveDown(&zeroR)) {
            swap(&matrix[zeroR][zeroC], &matrix[zeroR + 1][zeroC]);
            solved = IDS(matrix, currentDepth + 1, zeroR + 1, zeroC);
            if (solved) {
                return true;
            }
            swap(&matrix[zeroR][zeroC], &matrix[zeroR + 1][zeroC]);
        }

        if (canMoveLeft(&zeroC)) {
            swap(&matrix[zeroR][zeroC], &matrix[zeroR][zeroC - 1]);
            solved = IDS(matrix, currentDepth + 1, zeroR, zeroC - 1);
            if (solved) {
                return true;
            }
            swap(&matrix[zeroR][zeroC], &matrix[zeroR][zeroC - 1]);
        }

        if (canMoveRight(&zeroC)) {
            swap(&matrix[zeroR][zeroC], &matrix[zeroR][zeroC + 1]);
            solved = IDS(matrix, currentDepth + 1, zeroR, zeroC + 1);
            if (solved) {
                return true;
            }
            swap(&matrix[zeroR][zeroC], &matrix[zeroR][zeroC + 1]);
        }
    }
    return false;
}

short Puzzle::countTilesOutOfPlace(short **matrix) {
    short count = 0;

    for (int rows = 0; rows < MATRIX_SIZE; ++rows) {
        for (int cols = 0; cols < MATRIX_SIZE; ++cols) {
            if (matrix[rows][cols] != this->solution[rows][cols]) {
                count++;
            }
        }
    }
    return count;
}

short Puzzle::getSumOfAllDistances(short **matrix) {
    short count = 0;

    for (short rows = 0; rows < MATRIX_SIZE; ++rows) {
        short rowDiff, colDiff;

        for (short cols = 0; cols < MATRIX_SIZE; ++cols) {
            rowDiff = abs(matrix[rows][cols] / MATRIX_SIZE - rows);
            colDiff = abs(matrix[rows][cols] % MATRIX_SIZE - cols);
            count += rowDiff + colDiff;
        }
    }

    return count;
}

void Puzzle::executeAStarIDS() {
    executeIDS(getSumOfAllDistances(this->initialMatrix));
}

void Puzzle::executeGreedySearch() {
    this->breadthIterations = 0;
    this->queue->push_back(cloneMatrix(this->initialMatrix));
    short** currentState;
    short zeroR, zeroC;
    auto* costs = new short[4] {10, 10, 10, 10};
    short min;


    while (!matricesAreEqual(currentState = this->queue->front(), this->solution)) {
        this->queue->pop_front();
        this->breadthIterations++;


        findZeroLocation(currentState, &zeroR, &zeroC);
        evaluateAllNeighbourStates(currentState, &zeroR, &zeroC, costs);

        min = costs[0];
        for (int index = 1; index < 4; ++index) {
            if (costs[index] < min) {
                min = costs[index];
            }
        }

        deleteMatrix(currentState);
    }
}

void Puzzle::evaluateAllNeighbourStates(short **matrix, short *r, short *c, short *costs) {
    if (canMoveUp(r)) {
        swap(&matrix[*r][*c], &matrix[*r - 1][*c]);
        costs[0] = countTilesOutOfPlace(matrix);
        swap(&matrix[*r][*c], &matrix[*r - 1][*c]);
    }

    if (canMoveDown(r)) {
        swap(&matrix[*r][*c], &matrix[*r + 1][*c]);
        costs[1] = countTilesOutOfPlace(matrix);
        swap(&matrix[*r][*c], &matrix[*r + 1][*c]);
    }

    if (canMoveLeft(c)) {
        swap(&matrix[*r][*c], &matrix[*r][*c - 1]);
        costs[2] = countTilesOutOfPlace(matrix);
        swap(&matrix[*r][*c], &matrix[*r][*c - 1]);
    }

    if (canMoveRight(c)) {
        swap(&matrix[*r][*c], &matrix[*r][*c + 1]);
        costs[2] = countTilesOutOfPlace(matrix);
        swap(&matrix[*r][*c], &matrix[*r][*c + 1]);
    }
}

