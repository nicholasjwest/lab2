#include <QtCore/qmath.h>
#include <stdio.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288419717
#endif

#include "circle.h"
#include "matmath.h"
#include "mat.h"
#include "vect.h"

circle::circle(int XCentre, int YCentre, const QColor& colour,
               const QColor& selectedColour, unsigned int radius) :
    shape(XCentre, YCentre, colour, selectedColour),
    mRadius(radius)
{
    sides = 5;
}

void circle::drawShape()
{
    int numCoords = sides;

    //Draw 1000 coordinates of the circle
    for(int i = 0;
        i < numCoords;
        i++)
    {
        int X = mRadius*qCos(2.0*i*M_PI/(double)numCoords)+0.5;
        int Y = mRadius*qSin(2.0*i*M_PI/(double)numCoords)+0.5;
        vect a = vect();
        transmat = matrixmath.scalermat(4.0);
        a.x = X;
        a.y = Y;
        a.z = 1;
        //printf("X1: %f, Y1: %f", X, Y);
        vect b = vect();
        b = matrixmath.vectmatmult(a, transmat);
        a = b;
        X = a.x;
        Y = a.y;
        //printf("X2: %f, Y2: %f", X, Y);
        glVertex2i(X, Y);
    }

}

void circle::setSides(int i)
{
    sides = i;
    this->draw(1);
}

bool circle::insideZeroCentredShape(int x, int y)
{
    float distFromCentre = qSqrt(x*x+y*y);

    return (distFromCentre <= mRadius);
}
