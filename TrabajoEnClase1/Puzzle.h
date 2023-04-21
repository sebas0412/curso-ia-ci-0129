//
// Created by gerardo on 30/03/23.
//

#include <cstdio>
#ifndef HEURISTICAIA_ANCHOPRIMERO_H
#define HEURISTICAIA_ANCHOPRIMERO_H
#define MATRIX_SIZE 3
#define MAX_DEPTH 24

#include <queue>
#include <cstdlib>

class Puzzle{
public:
    Puzzle(short** matrix);
    ~Puzzle();
    void executeBreadthFirst();
    void executeIDS(unsigned long int startingDepth);
    void executeAStarIDS();
    void executeGreedySearch();

    short **getInitialMatrix() const;
    void setInitialMatrix(short **initialMatrix);


private:
    bool existsInQueue(short** matrix);
    bool matricesAreEqual(short** matrixA, short** matrixB);
    void findZeroLocation(short** matrix, short* r, short* c);
    void findAllNeighbourStates(short** matrix, short* r, short* c);
    void evaluateAllNeighbourStates(short **matrix, short *r, short *c, short *costs);

    bool canMoveUp(const short* row);
    bool canMoveDown(const short* row);
    bool canMoveLeft(const short* col);
    bool canMoveRight(const short* col);

    short** cloneMatrix(short** matrix);
    void deleteMatrix(short** matrix);
    void swap(short* a, short* b);
    void printMatrix(short** matrix);
    bool IDS(short **matrix, short currentDepth, short zeroR, short zeroC);

    short countTilesOutOfPlace(short** matrix);
    short getSumOfAllDistances(short** matrix);
    void executeMostOptimalState(short state, short **matrix, short *zeroR, short *zeroC);


    short** initialMatrix;

private:
    short** solution;
    unsigned long int iterations;
    unsigned long int idsFinalDepth;
    unsigned long int searchDepth;
    std::deque<short**>* queue;
    unsigned long int created;
    unsigned long int deleted;
};

#endif //HEURISTICAIA_ANCHOPRIMERO_H
