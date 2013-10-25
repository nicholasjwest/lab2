#include "mat.h"
#include "vect.h"

mat::mat()
{
    vect x = vect();
    x.x = 1.0;
    vect y = vect();
    y.y = 1.0;
    vect z = vect();
    z.z = 1.0;
}
