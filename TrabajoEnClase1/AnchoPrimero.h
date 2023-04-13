//
// Created by gerardo on 30/03/23.
//

#include <cstdio>
#ifndef HEURISTICAIA_ANCHOPRIMERO_H
#define HEURISTICAIA_ANCHOPRIMERO_H
#define MATRIX_SIZE 3

#include <queue>

class AnchoPrimero{


public:
    AnchoPrimero(int** matrix);
    ~AnchoPrimero();
    void execute();


private:
    bool existsInQueue(int** matrix);
    bool matricesAreEqual(int** matrixA, int** matrixB);

    static bool canMoveUp(const int* row);
    static bool canMoveDown(const int* row);
    static bool canMoveLeft(const int* col);
    static bool canMoveRight(const int* col);
    void findZeroLocation(int** matrix, int* r, int* c);
    void findAllNeighbourStates(int** matrix, int* r, int* c);
    static int** cloneMatrix(int** matrix);
    static void deleteMatrix(int** matrix);
    static void swap(int* a, int* b);
    printResults(int** matrix);


    int** initialMatrix;
    int** solution;
    unsigned long int iterationCounter;
    std::deque<int**>* queue;
};

#endif //HEURISTICAIA_ANCHOPRIMERO_H
