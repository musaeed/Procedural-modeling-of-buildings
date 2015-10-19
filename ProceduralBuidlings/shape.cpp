#include "shape.h"

using namespace std;

Shape::Shape()
{
    colorAvailable = false;
    textureAvailable = false;

}

void Shape::draw(){

    calculateNormals();





    glPushMatrix();
    if(textureAvailable) glEnable(GL_TEXTURE_2D);

    if(textureAvailable) glBindTexture(GL_TEXTURE_2D, Textures::getInstance()->getTextures()[(int)texture.x]);

    if(colorAvailable){

        //glColor3f(color.x, color.y, color.z);
    }

    glBegin(GL_QUADS);



    if(textureAvailable){

        if(texture.x == PILLAR){
            glTexCoord2f(0.4,0.0);
        }
        else
            glTexCoord2f(0.09,0.0);
    }
    n1.drawNormal();
    p1.draw();

    if(textureAvailable){
        if(texture.x == PILLAR){
            glTexCoord2f(0.4,1.f);
        }
        else
            glTexCoord2f(0.09,1.f);
    }
    n2.drawNormal();
    p2.draw();

    if(textureAvailable){
        if(texture.x == PILLAR){
            glTexCoord2f(1.0f,1.f);
        }
        glTexCoord2f(1.1f,1.f);
    }
    n3.drawNormal();
    p3.draw();

    if(textureAvailable){
        if(texture.x == PILLAR){
            glTexCoord2f(1.0f,0.f);
        }
        glTexCoord2f(1.1f,0.f);
    }
    n4.drawNormal();
    p4.draw();

    glEnd();
    if(textureAvailable) glBindTexture(GL_TEXTURE_2D, 0);
    if(textureAvailable) glDisable(GL_TEXTURE_2D);

    glPopMatrix();

}


void Shape::calculateNormals(){

    Point3D e1 = p1.minus(p2);
    Point3D e2 = p2.minus(p3);
    Point3D e3 = p3.minus(p4);
    Point3D e4 = p4.minus(p1);

    n1 = e4.cross(e1);
    n2 = e1.cross(e2);
    n3 = e2.cross(e3);
    n4 = e3.cross(e4);

    n1.normalize();
    n2.normalize();
    n3.normalize();
    n4.normalize();
}

void Shape::setColor(float x, float y, float z){
    colorAvailable = true;
    color.x = x;
    color.y = y;
    color.z = z;
}

void Shape::print(){

    cout << "P1\t";
    p1.print();

    cout << "P2\t";
    p2.print();

    cout << "P3\t";
    p3.print();

    cout << "P4\t";
    p4.print();

}

void Shape::makeTextureAvailable(bool b){

    textureAvailable = b;
}
