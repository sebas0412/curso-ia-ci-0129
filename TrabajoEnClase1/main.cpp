#include <iostream>
#include "AnchoPrimero.h"

int main() {
    int** matrix = new int*[3];
    matrix[0] = new int[3] {1, 4, 0};
    matrix[1] = new int[3] {3 ,7 ,2};
    matrix[2] = new int[3] {6 ,8 ,5};

    auto* a = new AnchoPrimero(matrix);
    a->execute();
    return 0;
}


