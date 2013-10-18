#include "matmath.h"

matmath::matmath()
{
}

vect vectmatmult(vect a, mat b){
    vect ans;
    ans.x = b.x.x*a.x + b.y.x*a.y + b.z.x*a.y;
    ans.y = b.x.y*a.x + b.y.y*a.y + b.z.y*a.y;
    ans.z = b.x.z*a.x + b.y.z*a.y + b.z.z*a.y;
    return ans;
}

mat matmatmult(mat a, mat b){
    mat ans;
    ans.x.x = a.x.x*b.x.x + a.y.x*b.x.y + a.z.x*b.x.z;
    ans.x.y = a.x.y*b.x.x + a.y.y*b.x.y + a.z.y*b.x.z;
    ans.x.z = a.x.z*b.x.x + a.y.z*b.x.y + a.z.z*b.x.z;
    ans.y.x = a.x.x*b.y.x + a.y.x*b.y.y + a.z.x*b.y.z;
    ans.y.y = a.x.y*b.y.x + a.y.y*b.y.y + a.z.y*b.y.z;
    ans.y.z = a.x.z*b.y.x + a.y.z*b.y.y + a.z.z*b.y.z;
    ans.z.x = a.x.x*b.z.x + a.y.x*b.z.y + a.z.x*b.z.z;
    ans.z.y = a.x.y*b.z.x + a.y.y*b.z.y + a.z.y*b.z.z;
    ans.z.z = a.x.z*b.z.x + a.y.z*b.z.y + a.z.z*b.z.z;
    return ans;
}

mat scalermat(double b) {
    mat ans;
    ans.x.x = b;
    ans.x.y = 0;
    ans.x.z = 0;
    ans.y.x = 0;
    ans.y.y = b;
    ans.y.z = 0;
    ans.z.x = 0;
    ans.z.y = 0;
    ans.z.z = b;
    return ans;
}

mat translatermat(double x, double y) {
    mat ans;
    ans.x.x = 0;
    ans.x.y = 0;
    ans.x.z = x;
    ans.y.x = 0;
    ans.y.y = 0;
    ans.y.z = y;
    ans.z.x = 0;
    ans.z.y = 0;
    ans.z.z = 0;
    return ans;
}




