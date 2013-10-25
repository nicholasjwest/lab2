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




