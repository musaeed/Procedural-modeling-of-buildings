#-------------------------------------------------
#
# Project created by QtCreator 2015-08-26T20:48:07
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProceduralBuidlings
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renderer.cpp \
    helpdialog.cpp \
    dtree.cpp \
    vertexcreator.cpp \
    point3d.cpp \
    shape.cpp \
    textures.cpp \
    parser.cpp \
    rules.cpp \
    modeler.cpp

HEADERS  += mainwindow.h \
    renderer.h \
    helpdialog.h \
    dtree.h \
    vertexcreator.h \
    point3d.h \
    shape.h \
    textures.h \
    parser.h \
    rules.h \
    modeler.h

FORMS    += mainwindow.ui \
    helpdialog.ui

RESOURCES += \
    resources.qrc

LIBS  += -lglut -lGLU

CONFIG += c++11
