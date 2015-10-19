#ifndef RENDERER_H
#define RENDERER_H

#include <QApplication>
#include <QGLWidget>
#include <iostream>
#include <QTimer>
#include <QMouseEvent>
#include <QKeyEvent>
#include <vertexcreator.h>
#include <QDebug>
#include <cmath>
#include "textures.h"
#include "dtree.h"

class Renderer : public QGLWidget
{
    Q_OBJECT
public:
    explicit Renderer(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);
    void keyPressEvent(QEvent* event);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void drawFloor();
    void openNewGrammar(struct Node*);

    ~Renderer();

private:

    VertexCreator* creator;
    DTree tree;
    QPoint mousePosition;
    bool render;

};

#endif // RENDERER_H
