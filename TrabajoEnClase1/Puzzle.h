//
// Created by gerardo on 30/03/23.
//

#include <cstdio>
#ifndef HEURISTICAIA_ANCHOPRIMERO_H
#define HEURISTICAIA_ANCHOPRIMERO_H
#define MATRIX_SIZE 3
#define MAX_DEPTH 25

#include <queue>

class Puzzle{
public:
    Puzzle(int** matrix);
    ~Puzzle();
    void executeBreadthFirst();
    void executeIDS();


private:
    bool existsInQueue(int** matrix);
    bool matricesAreEqual(int** matrixA, int** matrixB);
    void findZeroLocation(int** matrix, int* r, int* c);
    void findAllNeighbourStates(int** matrix, int* r, int* c);

    static bool canMoveUp(const int* row);
    static bool canMoveDown(const int* row);
    static bool canMoveLeft(const int* col);
    static bool canMoveRight(const int* col);


    static int** cloneMatrix(int** matrix);
    static void deleteMatrix(int** matrix);
    static void swap(int* a, int* b);
    void printMatrix(int** matrix);
    bool IDS(int** matrix, int currentDepth);


    int** initialMatrix;
public:
    int **getInitialMatrix() const;
    void setInitialMatrix(int **initialMatrix);

private:
    int** solution;
    unsigned long int breadthIterations;
    unsigned long int idsIterations;
    unsigned long int idsFinalDepth;
    unsigned long int searchDepth;
    std::deque<int**>* queue;
};

#endif //HEURISTICAIA_ANCHOPRIMERO_H
