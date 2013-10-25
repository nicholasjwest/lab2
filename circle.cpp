#include <QtCore/qmath.h>
#include <stdio.h>

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
    /*printf("1st\n%f, %f, %f\n", transmat.x.x, transmat.x.y, transmat.x.z);
    printf("%f, %f, %f\n", transmat.y.x, transmat.y.y, transmat.y.z);
    printf("%f, %f, %f\n", transmat.z.x, transmat.z.y, transmat.z.z);
    printf("1st\n%f, %f, %f\n", matrixmath.scalermat(d).x.x, matrixmath.scalermat(d).x.y, matrixmath.scalermat(d).x.z);
    printf("%f, %f, %f\n", matrixmath.scalermat(d).y.x, matrixmath.scalermat(d).y.y, matrixmath.scalermat(d).y.z);
    printf("%f, %f, %f\n", matrixmath.scalermat(d).z.x, matrixmath.scalermat(d).z.y, matrixmath.scalermat(d).z.z);*/
    transmat = matrixmath.matmatmult(transmat, matrixmath.scalermat(d));
    /*printf("2nd\n%f, %f, %f\n", transmat.x.x, transmat.x.y, transmat.x.z);
    printf("%f, %f, %f\n", transmat.y.x, transmat.y.y, transmat.y.z);
    printf("%f, %f, %f\n", transmat.z.x, transmat.z.y, transmat.z.z);*/
    fflush(stdout);
}

void circle::translate(double x, double y) {
    transmat = matrixmath.matmatmult(transmat, matrixmath.translatormat(x,y));
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

bool circle::insideZeroCentredShape(int x, int y)
{
    float distFromCentre = qSqrt(x*x+y*y);

    return (distFromCentre <= mRadius);
}
