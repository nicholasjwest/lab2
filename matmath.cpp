#include "matmath.h"
#include "mat.h"
#include "vect.h"

matmath::matmath()
{
}

vect matmath::vectmatmult(vect a, mat b){
    vect ans = vect();
    ans.x = b.x.x*a.x + b.x.y*a.y + b.x.z*a.z;
    ans.y = b.y.x*a.x + b.y.y*a.y + b.y.z*a.z;
    ans.z = b.z.x*a.x + b.z.y*a.y + b.z.z*a.z;
    return ans;
}

mat matmath::matmatmult(mat a, mat b){
    mat ans = mat();
    ans.x.x = a.x.x*b.x.x + a.x.y*b.y.x + a.x.z*b.z.x;
    ans.x.y = a.x.x*b.x.y + a.x.y*b.y.y + a.x.z*b.z.y;
    ans.x.z = a.x.x*b.x.z + a.x.y*b.y.z + a.x.z*b.z.z;
    ans.y.x = a.y.x*b.x.x + a.y.y*b.y.x + a.y.z*b.z.x;
    ans.y.y = a.y.x*b.x.y + a.y.y*b.y.y + a.y.z*b.z.y;
    ans.y.z = a.y.x*b.x.z + a.y.y*b.y.z + a.y.z*b.z.z;
    ans.z.x = a.z.x*b.x.x + a.z.y*b.y.x + a.z.z*b.z.x;
    ans.z.y = a.z.x*b.x.y + a.z.y*b.y.y + a.z.z*b.z.y;
    ans.z.z = a.z.x*b.x.z + a.z.y*b.y.z + a.z.z*b.z.z;
    return ans;
}

mat matmath::scalermat(double b) {
    mat ans = mat();
    ans.x.x = b;
    ans.y.y = b;
    ans.z.z = 1;
    return ans;
}

mat matmath::translatormat(double x, double y) {
    mat ans = mat();
    ans.x.z = x;
    ans.y.z = y;
    ans.x.x = ans.y.y = 1.0;
    ans.z.z = 0.0;
    return ans;
}
mat matmath::ident() {
    mat ans = mat();
    ans.x.x = 1;
    ans.x.y = 0;
    ans.x.z = 0;
    ans.y.x = 0;
    ans.y.y = 1;
    ans.y.z = 0;
    ans.z.x = 0;
    ans.z.y = 0;
    ans.z.z = 1;
    return ans;
}




