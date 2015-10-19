#ifndef POINT3D_H
#define POINT3D_H
#include <GL/gl.h>
#include <cmath>
#include <iostream>

class Point3D
{
public:
    // Coordinates of the point

    float x;
    float y;
    float z;

    // Geometric functions

    void scale(float);
    Point3D minus(Point3D point);
    Point3D plus(Point3D);
    Point3D cross(Point3D point);
    float distance(Point3D);
    void normalize();

    // Drawing functions

    void draw();
    void drawNormal();

    // Constructor and debugging functions

    Point3D();
    Point3D(float, float, float);
    void print();
};

#endif // POINT3D_H
