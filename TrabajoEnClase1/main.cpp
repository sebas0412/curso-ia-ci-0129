#include <iostream>
#include "Puzzle.h"

void deleteMatrix(short** m);

int main() {

    /** Matrices de Prueba */

    auto** m1 = new short*[3];
    m1[0] = new short[3] {1, 4, 0};
    m1[1] = new short[3] {3 , 7 , 2};
    m1[2] = new short[3] {6 , 8 , 5};

    auto** m2 = new short*[3];
    m2[0] = new short[3] {1, 2, 3};
    m2[1] = new short[3] {4, 6, 0};
    m2[2] = new short[3] {7, 5, 8};

    auto** m3 = new short*[3];
    m3[0] = new short[3] {6, 3, 2};
    m3[1] = new short[3] {8, 4, 5};
    m3[2] = new short[3] {1, 7, 0};

    auto** m4 = new short*[3];
    m4[0] = new short[3] {1, 3, 2};
    m4[1] = new short[3] {4, 6, 5};
    m4[2] = new short[3] {7, 8, 0};

    auto** m5 = new short*[3];
    m5[0] = new short[3] {1, 3, 5};
    m5[1] = new short[3] {6, 2, 4};
    m5[2] = new short[3] {0, 8, 7};

    auto** m6 = new short*[3];
    m6[0] = new short[3] {3, 0, 1};
    m6[1] = new short[3] {4, 2, 8};
    m6[2] = new short[3] {7, 5, 6};

    auto** m7 = new short*[3];
    m7[0] = new short[3] {6, 1, 2};
    m7[1] = new short[3] {0, 5, 8};
    m7[2] = new short[3] {7, 3, 4};

    auto** m8 = new short*[3];
    m8[0] = new short[3] {4, 0, 3};
    m8[1] = new short[3] {5, 8, 2};
    m8[2] = new short[3] {7, 1, 6};

    auto** m9 = new short*[3];
    m9[0] = new short[3] {4, 1, 2};
    m9[1] = new short[3] {6, 0, 8};
    m9[2] = new short[3] {3, 5, 7};

    auto** m10 = new short*[3];
    m10[0] = new short[3] {1, 4, 6};
    m10[1] = new short[3] {0, 7, 2};
    m10[2] = new short[3] {8, 3, 5};


    auto* puzzleObject = new Puzzle(nullptr);


    /** IDS */
    puzzleObject->setInitialMatrix(m1);
    puzzleObject->executeIDS(0);
    puzzleObject->setInitialMatrix(m2);
    puzzleObject->executeIDS(0);
    puzzleObject->setInitialMatrix(m3);
    puzzleObject->executeIDS(0);
    puzzleObject->setInitialMatrix(m4);
    puzzleObject->executeIDS(0);
    puzzleObject->setInitialMatrix(m5);
    puzzleObject->executeIDS(0);
    puzzleObject->setInitialMatrix(m6);
    puzzleObject->executeIDS(0);
    puzzleObject->setInitialMatrix(m7);
    puzzleObject->executeIDS(0);
    puzzleObject->setInitialMatrix(m8);
    puzzleObject->executeIDS(0);
    puzzleObject->setInitialMatrix(m9);
    puzzleObject->executeIDS(0);
    puzzleObject->setInitialMatrix(m10);
    puzzleObject->executeIDS(0);

    /** Breadth First */
    puzzleObject->setInitialMatrix(m1);
    puzzleObject->executeBreadthFirst();
    puzzleObject->setInitialMatrix(m2);
    puzzleObject->executeBreadthFirst();
    puzzleObject->setInitialMatrix(m3);
    puzzleObject->executeBreadthFirst();
    puzzleObject->setInitialMatrix(m4);
    puzzleObject->executeBreadthFirst();
    puzzleObject->setInitialMatrix(m5);
    puzzleObject->executeBreadthFirst();
    puzzleObject->setInitialMatrix(m6);
    puzzleObject->executeBreadthFirst();
    puzzleObject->setInitialMatrix(m7);
    puzzleObject->executeBreadthFirst();
    puzzleObject->setInitialMatrix(m8);
    puzzleObject->executeBreadthFirst();
    puzzleObject->setInitialMatrix(m9);
    puzzleObject->executeBreadthFirst();
    puzzleObject->setInitialMatrix(m10);
    puzzleObject->executeBreadthFirst();

    /** A-Star IDS */
    puzzleObject->setInitialMatrix(m1);
    puzzleObject->executeAStarIDS();
    puzzleObject->setInitialMatrix(m2);
    puzzleObject->executeAStarIDS();
    puzzleObject->setInitialMatrix(m3);
    puzzleObject->executeAStarIDS();
    puzzleObject->setInitialMatrix(m4);
    puzzleObject->executeAStarIDS();
    puzzleObject->setInitialMatrix(m5);
    puzzleObject->executeAStarIDS();
    puzzleObject->setInitialMatrix(m6);
    puzzleObject->executeAStarIDS();
    puzzleObject->setInitialMatrix(m7);
    puzzleObject->executeAStarIDS();
    puzzleObject->setInitialMatrix(m8);
    puzzleObject->executeAStarIDS();
    puzzleObject->setInitialMatrix(m9);
    puzzleObject->executeAStarIDS();
    puzzleObject->setInitialMatrix(m10);
    puzzleObject->executeAStarIDS();

    /** Greedy Search */

    delete puzzleObject;

    deleteMatrix(m1);
    deleteMatrix(m2);
    deleteMatrix(m3);
    deleteMatrix(m4);
    deleteMatrix(m5);
    deleteMatrix(m6);
    deleteMatrix(m7);
    deleteMatrix(m8);
    deleteMatrix(m9);
    deleteMatrix(m10);


    return 0;
}


void deleteMatrix(short** m) {
    for (short index = 0; index < MATRIX_SIZE; index++) {
        delete[] m[index];
    }
    delete[] m;
}

