#ifndef MATMATH_H
#define MATMATH_H

class matmath
{
public:
    matmath();
    struct vect {double x, y, z;};
    struct mat {vect x, y, z;};
    mat vectmatmult(vect a, mat b);
};

#endif // MATMATH_H
