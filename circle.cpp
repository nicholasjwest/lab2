#include <QtCore/qmath.h>
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288419717
#endif

#include "circle.h"
#include "matmath.h"
#include "mat.h"
#include "vect.h"

circle::circle(int XCentre, int YCentre, QColor& colour,
               QColor& selectedColour, unsigned int radius) :
    shape(XCentre, YCentre, colour, selectedColour),
    mRadius(radius)
{
    sides = 5;
    transmat = matrixmath.ident();
}

void circle::scale(double d) {
    mat matter = matrixmath.matmatmult(transmat, matrixmath.scalermat(d));
    transmat = matter;
}

void circle::translate(double x, double y) {
    mat matter = matrixmath.matmatmult(transmat, matrixmath.translatormat(x,y));
    transmat = matter;
}

void circle::changeRadius(int r)
{
    mRadius = r;
    this->draw(1);
}

void circle::changeColour(QColor color, QColor selectedcolor)
{
    mNormalColour = color;
    mSelectedColour = selectedcolor;
    this->draw(1);
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
        a.x = X;
        a.y = Y;
        a.z = 1;

        vect b = vect();
        b = matrixmath.vectmatmult(a, transmat);
        a = b;
        X = a.x;
        Y = a.y;
        glVertex2i(X, Y);
    }

}

void circle::setSides(int i)
{
    sides = i;
    this->draw(1);
}

void circle::matricise(mat matrix)
{
    mat matter = matrixmath.matmatmult(transmat, matrix);
    transmat = matter;
}

bool circle::insideZeroCentredShape(int x, int y)
{
    float distFromCentre = qSqrt(x*x+y*y);

    vect a = vect();
    a.x = a.y = mRadius;
    a.z = 1;
    vect b = matrixmath.vectmatmult(a, transmat);
    a.x = x;
    a.y = y;
    fflush(stdout);

    return ((abs(a.x)<abs(b.x)) && (abs(a.y)<abs(b.y)));
}
