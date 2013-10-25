QT += core gui opengl
QT += widgets

TEMPLATE = app
TARGET = qtgl1
DEPENDPATH += .
INCLUDEPATH += .


# Input
HEADERS += glwidget.h \
    window.h \
    shape.h \
    version.h \
    circle.h \
    matmath.h \
    mat.h \
    vect.h
FORMS += MainWindow.ui
SOURCES += glwidget.cpp \
    main.cpp \
    window.cpp \
    shape.cpp \
    circle.cpp \
    matmath.cpp \
    mat.cpp \
    vect.cpp
