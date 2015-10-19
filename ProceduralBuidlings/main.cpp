#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <GL/glut.h>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();

    glutInit(&argc, argv);

    return a.exec();
}
