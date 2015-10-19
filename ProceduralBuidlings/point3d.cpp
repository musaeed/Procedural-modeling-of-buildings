#include "point3d.h"

using namespace std;

Point3D::Point3D()
{
}

Point3D::Point3D(float x, float y, float z){

    this->x = x;
    this->y = y;
    this->z = z;
}

void Point3D::scale(float sc){

    this->x *= sc;
    this->y *= sc;
    this->z *= sc;

}

Point3D Point3D::minus(Point3D point){

    float xn = x - point.x;
    float yn = y - point.y;
    float zn = z - point.z;

    return Point3D(xn, yn, zn);
}

Point3D Point3D::plus(Point3D point){

    float xn = x + point.x;
    float yn = y + point.y;
    float zn = z + point.z;

    return Point3D(xn, yn, zn);
}

float Point3D::distance(Point3D point){

    float xn = pow(x-point.x, 2);
    float yn = pow(y-point.y, 2);
    float zn = pow(z-point.z, 2);

    return sqrt(xn+yn+zn);
}


Point3D Point3D::cross(Point3D val){

    double x1 = y * val.z - val.y * z;
    double y1 = z * val.x - val.z * x;
    double z1 = x * val.y - val.x * y;

    Point3D result(x1,y1,z1);

    return result;
}

void Point3D::normalize(){

    float dis = x*x + y*y + z*z;
    scale(1.f/sqrt(dis));
}


void Point3D::draw(){

    glVertex3f(x,y,z);
}

void Point3D::drawNormal(){

    glNormal3f(x,y,z);
}

void Point3D::print(){

    cout <<"x: " << x << "\t\n";
    cout <<"y: " << y << "\t\n";
    cout <<"z: " << z << "\t\n";

}
