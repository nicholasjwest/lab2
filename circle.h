#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "matmath.h"
#include "mat.h"
#include "vect.h"

class circle : public shape
{
public:
    circle (int XCentre, int YCentre, QColor& colour,
            QColor& selectedColour, unsigned int radius);
    void setSides(int i);
    int sides;
    matmath matrixmath;
    mat matrix;
    mat transmat;
    void scale(double d);
    void translate(double x, double y);
    void changeColour(QColor col, QColor selcol);
    void changeRadius(int);

private:
    //Implemented functions for drawing and checking if inside the shape, specified by the base class, shape
    virtual void drawShape();
    virtual bool insideZeroCentredShape(int x, int y);

    unsigned int mRadius;

};

#endif // CIRCLE_H
