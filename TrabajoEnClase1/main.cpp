#include <iostream>
#include "Puzzle.h"

int main() {

    /** Matrices de Prueba */

    int** m1 = new int*[3];
    m1[0] = new int[3] {1, 4, 0};
    m1[1] = new int[3] {3 , 7 , 2};
    m1[2] = new int[3] {6 , 8 , 5};

    int** m2 = new int*[3];
    m2[0] = new int[3] {6, 5, 2};
    m2[1] = new int[3] {7, 4, 3};
    m2[2] = new int[3] {1, 8, 0};

    int** m3 = new int*[3];
    m3[0] = new int[3] {6, 3, 2};
    m3[1] = new int[3] {8, 4, 5};
    m3[2] = new int[3] {1, 7, 0};

    int** m4 = new int*[3];
    m4[0] = new int[3] {1, 3, 2};
    m4[1] = new int[3] {0, 4, 6};
    m4[2] = new int[3] {7, 8, 5};

    int** m5 = new int*[3];
    m5[0] = new int[3] {8, 1, 5};
    m5[1] = new int[3] {3, 0, 2};
    m5[2] = new int[3] {7, 6, 4};

    int** m6 = new int*[3];
    m6[0] = new int[3] {3, 0, 1};
    m6[1] = new int[3] {4, 2, 8};
    m6[2] = new int[3] {7, 5, 6};

    int** m7 = new int*[3];
    m7[0] = new int[3] {6, 1, 2};
    m7[1] = new int[3] {0, 5, 8};
    m7[2] = new int[3] {7, 3, 4};

    int** m8 = new int*[3];
    m8[0] = new int[3] {4, 0, 3};
    m8[1] = new int[3] {5, 8, 2};
    m8[2] = new int[3] {7, 1, 6};

    int** m9 = new int*[3];
    m9[0] = new int[3] {8, 6, 1};
    m9[1] = new int[3] {4, 5, 2};
    m9[2] = new int[3] {3, 7, 0};

    int** m10 = new int*[3];
    m10[0] = new int[3] {1, 4, 6};
    m10[1] = new int[3] {0, 7, 2};
    m10[2] = new int[3] {8, 3, 5};



    /** IDS */

    auto* a1 = new Puzzle(m1);
    auto* a2 = new Puzzle(m2);
    auto* a3 = new Puzzle(m3);
    auto* a4 = new Puzzle(m4);
    auto* a5 = new Puzzle(m5);
    auto* a6 = new Puzzle(m6);
    auto* a7 = new Puzzle(m7);
    auto* a8 = new Puzzle(m8);
    auto* a9 = new Puzzle(m9);
    auto* a10 = new Puzzle(m10);

    a1->executeIDS();
    a2->executeIDS();
    a3->executeIDS();
    a4->executeIDS();
    a5->executeIDS();
    a6->executeIDS();
    a7->executeIDS();
    a8->executeIDS();
    a9->executeIDS();
    a10->executeIDS();

    char a;
    std::cin >> a;

    delete a1;
    delete a2;
    delete a3;
    delete a4;
    delete a5;
    delete a6;
    delete a7;
    delete a8;
    delete a9;
    delete a10;


    /** Ancho Primero */

    a1 = new Puzzle(m1);
    a2 = new Puzzle(m2);
    a3 = new Puzzle(m3);
    a4 = new Puzzle(m4);
    a5 = new Puzzle(m5);
    a6 = new Puzzle(m6);
    a7 = new Puzzle(m7);
    a8 = new Puzzle(m8);
    a9 = new Puzzle(m9);
    a10 = new Puzzle(m10);

    a1->executeBreadthFirst();
    a2->executeBreadthFirst();
    a3->executeBreadthFirst();
    a4->executeBreadthFirst();
    a5->executeBreadthFirst();
    a6->executeBreadthFirst();
    a7->executeBreadthFirst();
    a8->executeBreadthFirst();
    a9->executeBreadthFirst();
    a10->executeBreadthFirst();

    char b;
    std::cin >> b;

    delete a1;
    delete a2;
    delete a3;
    delete a4;
    delete a5;
    delete a6;
    delete a7;
    delete a8;
    delete a9;
    delete a10;


    return 0;
}


