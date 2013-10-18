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
    square.h \
    version.h \
    circle.h \
    matmath.h
FORMS += MainWindow.ui
SOURCES += glwidget.cpp \
    main.cpp \
    window.cpp \
    shape.cpp \
    square.cpp \
    circle.cpp \
    matmath.cpp
