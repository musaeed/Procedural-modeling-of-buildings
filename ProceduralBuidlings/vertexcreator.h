#ifndef VERTEXCREATOR_H
#define VERTEXCREATOR_H
#include "dtree.h"
#include "shape.h"
#include <iostream>
#include <random>
#include <QDebug>
#include "textures.h"

class VertexCreator
{
public:
    VertexCreator();
    void createVertices(struct Node* root);
    Shape createInitialVerticesLeft(float, float, float);
    Shape createInitialVerticesRight(float, float, float);
    Shape createInitialVerticesTop(float,float, float);
    Shape createInitialVerticesDown(float,float, float);
    Shape createInitialVerticesFront(float, float, float);
    Shape createInitialVerticesBack(float, float, float);
    void drawTerminals();
    void recursiveCalculateTree(struct Node, Shape, float, float);
    Point3D getNewCoordinate(Point3D, Point3D, Point3D,float);
    float getTextureID(QString);
    void releaseTerminals();

private:

    float xScale;
    float yScale;
    float zScale;
    float maxScale;
    vector<Shape> terminalShapes;

};

#endif // VERTEXCREATOR_H
