//-------------------------------------------------------------------------------------------
//  University of Bath Computer Science Department
//	FrameWork for OpenGL application under QT
//  Course title: Introduction Computer Graphics
//-------------------------------------------------------------------------------------------
#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QColorDialog>
#include "ui_MainWindow.h"
#include "glwidget.h"
#include "mat.h"
#include "matmath.h"

class GLWidget;

//Create a window and load the components from generated code ui_MainWindow.h
class Window : public QDialog, public Ui::frmMain
{
    Q_OBJECT;

public:
    //Constructor
    Window(QWidget *parent = 0);
    GLWidget *nGLWidget;
    matmath matrixmath;
    mat id = matrixmath.ident();
    mat matBuild();

private:
    //GLWidget instance---by storing an instance, the widget is automatically created
    //and cleared up when the Window class is instantiated (i.e. no need for new/delete)
    GLWidget mGLWidget;

private slots:
    void aboutBut();
    void pressmebut();

    void on_scaleButton_clicked();


    void on_sidesButton_clicked();

    void colour_valueChanged();

    void on_colourR_valueChanged(int value);

    void on_colourG_valueChanged(int value);

    void on_colourB_valueChanged(int value);

    void on_sColourR_valueChanged(int value);

    void on_sColourG_valueChanged(int value);

    void on_sColourB_valueChanged(int value);

    void on_newShapeButton_clicked();

    void on_radiusButton_clicked();


    void on_removeButton_clicked();

    void on_stackButton_clicked();

    void on_stackinateButton_clicked();


    void on_transButton_clicked();


protected:
    // void  resizeEvent(QResizeEvent * );
};


#endif
