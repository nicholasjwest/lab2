#include <iostream>
#include <QtGui>
#include <QtOpenGL>
#include "version.h"
#include "window.h"
#include "circle.h"
#include <stdio.h>
//#include "dfuncs.h"

//------------------------------------------------------------------------------------
// Creates and initializes the main window for application
//------------------------------------------------------------------------------------
Window::Window(QWidget *parent):QDialog(parent)
{
	//Setup application interface. Creates all the required components and sliders.
	setupUi(this);

    //We need to attach our m_glWidget to glWidgetArea
    //All our drawings will be on glWidgetArea
   //glWidgetArea->setWidget(&mGLWidget);
}

//void Window::resizeEvent( QResizeEvent * )
//{
//  cerr << "new size "<< width() SEP height() NL;
//  //m_glWidget->resizeGL(width(), height());
// // qttsnk->setGeometry(width()-320,  110, 100,  100);
//}


void Window::aboutBut()
{
    QString title="QtOpenGl-2 ";
    QString mess = "QtOpenGl-basic by Brian Wyvill Release Version: " + QString::number(MY_VERSION);
    QMessageBox::information( this, title, mess, QMessageBox::Ok );
}

//bool Window::checkData(QString tempStr, double *num)
//{
//    bool validate;
////no error message
//    *num = tempStr.toDouble(&validate);
//    if (validate == false) *num =0.0;
//    return validate;
//}

//void Window::txt0()
//{
//    double a;
//    if ( checkData(mat[0], &a) ) cerr << "data ok  ";
//    cerr << "a="<<a NL;
//}

//void Window::txt0(QString a)
//{
//    mat[0]=a;
//}

//void Window::txt9(QString a)
//{
//    mat[9]=a;
//    cerr << "Input string\n";
//}

//void Window::txt99()
//{
//    double a;
//    if ( checkData(mat[9], &a) ) cerr << "9data ok  ";
//    cerr << "a="<<a NL;
//     QMessageBox::information( this, "QtGl: ", mat[9], QMessageBox::Ok );
//}

//void Window::txt1()
//{
//    double a;
//    if ( checkData(mat[1], &a) ) cerr << "data ok  ";
//        cerr << "a="<<a NL;
//}

//void Window::txt1(QString a)
//{
//    mat[1]=a;
//}

void Window::pressmebut()
{
    std::cerr << "Don't press me!";
}

void Window::on_scaleButton_clicked()
{
    if(widget->nSelectedShape.isNull())
    {
        return;
    }
    widget->nSelectedShape->scale(this->scaleSpinBox->value());
    widget->updateGL();
}



void Window::on_sidesButton_clicked()
{
    if(widget->nSelectedShape.isNull())
    {
        return;
    }
    widget->nSelectedShape->setSides(this->sidesBox->value());
    widget->updateGL();
}

void Window::colour_valueChanged()
{
    QColor color = QColor(colourR->value(), colourG->value(), colourB->value());
    QColor selectedcolor = QColor(sColourR->value(), sColourG->value(), sColourB->value());
    widget->nSelectedShape->changeColour(color, selectedcolor);
    widget->updateGL();
}

void Window::on_colourR_valueChanged(int value)
{
    colour_valueChanged();
}

void Window::on_colourG_valueChanged(int value)
{
    colour_valueChanged();
}

void Window::on_colourB_valueChanged(int value)
{
    colour_valueChanged();
}

void Window::on_sColourR_valueChanged(int value)
{
    colour_valueChanged();
}

void Window::on_sColourG_valueChanged(int value)
{
    colour_valueChanged();
}

void Window::on_sColourB_valueChanged(int value)
{
    colour_valueChanged();
}

void Window::on_newShapeButton_clicked()
{
    widget->newCircle(this->sidesBox->value(), this->radiusBox->value());
}

void Window::on_radiusButton_clicked()
{
    widget->nSelectedShape->changeRadius(this->radiusBox->value());
    widget->updateGL();
}

void Window::on_removeButton_clicked()
{
    widget->removeShape();
    widget->updateGL();
}

mat Window::matBuild()
{
    mat matrix = matrixmath.ident();
    matrix.x.x = this->XX->value();
    matrix.y.x = this->XY->value();
    matrix.z.x = this->XZ->value();
    matrix.x.y = this->YX->value();
    matrix.y.y = this->YY->value();
    matrix.z.y = this->YZ->value();
    matrix.x.z = this->ZX->value();
    matrix.y.z = this->ZY->value();
    matrix.z.z = this->ZZ->value();
    printf("matBuild\n%f, %f, %f\n", matrix.x.x, matrix.x.y, matrix.x.z);
    printf("%f, %f, %f\n", matrix.y.x, matrix.y.y, matrix.y.z);
    printf("%f, %f, %f\n", matrix.z.x, matrix.z.y, matrix.z.z);
    return matrix;
}

void Window::on_stackButton_clicked()
{
    mat matrix = matBuild();
    printf("Stack button clicked, matrix\n%f, %f, %f\n", matrix.x.x, matrix.x.y, matrix.x.z);
    printf("%f, %f, %f\n", matrix.y.x, matrix.y.y, matrix.y.z);
    printf("%f, %f, %f\n", matrix.z.x, matrix.z.y, matrix.z.z);
    printf("Stack button clicked, id 1\n%f, %f, %f\n", id.x.x, id.x.y, id.x.z);
    printf("%f, %f, %f\n", id.y.x, id.y.y, id.y.z);
    printf("%f, %f, %f\n", id.z.x, id.z.y, id.z.z);
    id = matrixmath.matmatmult(id, matrix);
    printf("Stack button clicked, id 2\n%f, %f, %f\n", id.x.x, id.x.y, id.x.z);
    printf("%f, %f, %f\n", id.y.x, id.y.y, id.y.z);
    printf("%f, %f, %f\n", id.z.x, id.z.y, id.z.z);
}

void Window::on_stackinateButton_clicked()
{
    if (widget->nSelectedShape.isNull())
    {
        return;
    }
    widget->nSelectedShape->matricise(id);
    id = matrixmath.ident();
    widget->updateGL();
}


void Window::on_transButton_clicked()
{
    if (widget->nSelectedShape.isNull())
    {
        return;
    }
    widget->nSelectedShape->translate(this->xSpinBox->value(), this->ySpinBox->value());
    widget->updateGL();
}
