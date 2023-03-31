#include <iostream>
#include "AnchoPrimero.h"

int main() {
    int** m = new int*[3];
    m[0] = new int[] {4, 1, 2};
    m[1] = new int[] {3, 0, 5};
    m[2] = new int[] {6, 7, 8};

    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            printf("%d\t", m[row][col]);
        }
        printf("\n");
    }
    printf("\n");

    auto* t = new AnchoPrimero(m);
    t->start();
    return 0;
}


