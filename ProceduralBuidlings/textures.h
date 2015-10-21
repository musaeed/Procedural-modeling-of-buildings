#ifndef TEXTURES_H
#define TEXTURES_H
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <QCoreApplication>
#include <QMessageBox>

using namespace std;

// Pre-defininition of texture names

#define FLOOR 0
#define DOOR 1
#define WALL 2
#define WINDOW 3
#define TOP 4
#define LOGO 5
#define PILLAR 6
#define DARKWALL 7

class Textures
{

private:

    // Holds the IDs of loaded textures
    vector <GLuint> textures;

    Textures();
    static Textures *instance;

public:


    static Textures* getInstance();

    // Functions for loading textures into texture memory
    GLuint LoadTexture(const char*, int, int);
    void loadTextures();

    vector<unsigned int> getTextures();
};



#endif // TEXTURES_H
