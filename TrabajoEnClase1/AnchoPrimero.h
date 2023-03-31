//
// Created by gerardo on 30/03/23.
//

#ifndef HEURISTICAIA_ANCHOPRIMERO_H
#define HEURISTICAIA_ANCHOPRIMERO_H

#include <queue>

#define MATRIX_SIZE 3
#define MAX_DEPTH 4


class AnchoPrimero {

public:
    AnchoPrimero();
    AnchoPrimero(int** matrix);
    ~AnchoPrimero();

    int **getMatrix() const;
    void setMatrix(int **matrix);
    void start();

private:
    bool isSolved(int** matrix);
    void swap(int* a, int* b);
    bool solve(int currentRow, int currentCol, int currentDepth);
    void printState();
    bool withinBoundaries(int currentRow, int currentCol);

    bool canMoveUp(int currentRow, int currentCol);
    bool canMoveDown(int currentRow, int currentCol);
    bool canMoveLeft(int currentRow, int currentCol);
    bool canMoveRight(int currentRow, int currentCol);

    bool stateExists(int** matrix);

    int** matrix;
    int** solutionMatrix;
    std::queue<int*> queue;
    long int totalIterations;
};


#endif //HEURISTICAIA_ANCHOPRIMERO_H
