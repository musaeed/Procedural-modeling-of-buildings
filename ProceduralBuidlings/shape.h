#ifndef SHAPE_H
#define SHAPE_H
#include "point3d.h"
#include <GL/gl.h>
#include <QTime>
#include <cstdlib>
#include <iostream>
#include "textures.h"

class Shape
{
public:

    // Shape coordinates

    Point3D p1;
    Point3D p2;
    Point3D p3;
    Point3D p4;

    // Shape normals
    Point3D n1;
    Point3D n2;
    Point3D n3;
    Point3D n4;

    // Shape texture and color
    Point3D texture;
    Point3D color;
    bool colorAvailable;
    bool textureAvailable;


    // Constructor and helping functions
    Shape();
    void draw();
    void calculateNormals();
    void print();
    void setColor(float,float,float);
    void makeTextureAvailable(bool);

};

#endif // SHAPE_H
