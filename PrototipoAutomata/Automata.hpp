#ifndef CURSO_IA_CI_0129_AUTOMATA_HPP
#define CURSO_IA_CI_0129_AUTOMATA_HPP


#include <cstddef>
#include "Matrix.hpp"

#define DEFAULT_FILL_PERCENTAGE 0.10

class Automata {
public:
    Automata ();
    ~Automata();

    void start();

private:
    bool useWidthOf2;
    Matrix* currentMatrix;
    Matrix* tempMatrix;

    void initialFillRandom(Matrix* matrixObject);
    void applyRules(size_t row, size_t col, Matrix matrixObject);

    size_t sumOfNeighboursMoore(size_t row, size_t col, Matrix* matrixObject);
    size_t sumOfNeighboursNeumann(size_t row, size_t col, Matrix* matrixObject);

    double bMin();
    double bMax ();
    double dMin();
    double dMax();

};


#endif //CURSO_IA_CI_0129_AUTOMATA_HPP
