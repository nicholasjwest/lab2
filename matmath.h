#ifndef MATMATH_H
#define MATMATH_H

#include "mat.h"
#include "vect.h"


class matmath
{
public:
    matmath();
    vect vectmatmult(vect a, mat b);
    mat matmatmult(mat a, mat b);
    mat scalermat(double b);
    mat translatormat(double x, double y);
    mat ident();
};

#endif // MATMATH_H
