#include <QApplication>
#include "window.h"
#include "stdio.h"
#include "matmath.h"
#include "mat.h"
#include "vect.h"

//Main is needed in all win32 applications
int main(int argc, char* argv[])
{

    QApplication app(argc, argv);

    Window appWindow;

    /*matmath matrix;
    mat c = matrix.scalermat(3.0);
    mat b = matrix.translatormat(3.0, 2.0);
    vect a = vect();
    a.x = 2;
    a.y = 3;
    a.z = 1;
    vect d = matrix.vectmatmult(a, b);
    mat e = matrix.matmatmult(b, c);
    printf("%f %f %f \n%f %f %f \n%f %f %f\n", b.x.x, b.x.y, b.x.z, b.y.x, b.y.y, b.y.z, b.z.x, b.z.y, b.z.z);
    printf("%f %f %f \n%f %f %f \n%f %f %f\n", e.x.x, e.x.y, e.x.z, e.y.x, e.y.y, e.y.z, e.z.x, e.z.y, e.z.z);
    printf("%f %f %f", d.x, d.y, d.z);
    fflush(stdout);*/



    appWindow.show();

    app.exec();

    return 0;
}
