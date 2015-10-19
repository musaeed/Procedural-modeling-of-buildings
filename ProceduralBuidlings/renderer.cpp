#include "renderer.h"
#include <GL/glut.h>

using namespace std;

Renderer::Renderer(QWidget *parent) :
    QGLWidget(parent)
{
    render = true;
}

void Renderer::initializeGL(){

    creator = new VertexCreator();
    this->tree.fillTreeNew();
    creator->createVertices(tree.getTree());

   Textures::getInstance()->loadTextures();



    glClearColor(0.196078, 0.6, 0.8, 1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);



    GLfloat material_ambient_coefficient[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat material_diffuse_coefficient[] = {0.3, 0.5, 0.4, 1.0};
    GLfloat material_specular_coefficient[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat material_shininess_coefficient[] = {40.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient_coefficient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse_coefficient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular_coefficient);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess_coefficient);


    GLfloat light_ambient_coefficient[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse_coefficient[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular_coefficient[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

    GLfloat light_position1[] = {1.0,1.0,-3.0,0.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient_coefficient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse_coefficient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular_coefficient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse_coefficient);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
    glLightModelf(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Renderer::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glTranslatef(-0.5,-0.5,-0.5);
    drawFloor();
    if(render) creator->drawTerminals();
    glTranslatef(0.5,0.5,0.5);
}

void Renderer::resizeGL(int w, int h){

    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0.0,2.5, 0.0,0.0,0.0, 0,1,0);
}

void Renderer::drawFloor(){




    Shape floor;

    floor.p1.x = -8;
    floor.p1.y = 0;
    floor.p1.z = 8;

    floor.p2.x = 8;
    floor.p2.y = 0;
    floor.p2.z = 8;

    floor.p3.x = 8;
    floor.p3.y = 0;
    floor.p3.z = -8;

    floor.p4.x = -8;
    floor.p4.y = 0;
    floor.p4.z = -8;
    floor.texture.x = FLOOR;
    floor.makeTextureAvailable(true);
    floor.draw();
}

void Renderer::mouseMoveEvent(QMouseEvent *event){

    QPoint currentPos = event->pos();

    float x = -mousePosition.x() + currentPos.x();
    float y = -mousePosition.y() + currentPos.y();

    if(event->buttons() == Qt::LeftButton){


        if(x > 0){

            glRotatef(0.9, 0, 1, 0);

        }
        else{

            glRotatef(-0.9, 0, 1, 0);
        }
    }
    if(event->buttons() == Qt::RightButton){
        if(y > 0){

            glRotatef(0.9, 1, 0, 0);
        }
        else{

            glRotatef(-0.9, 1, 0, 0);
        }
    }
    mousePosition = currentPos;
    updateGL();
}

void Renderer::mousePressEvent(QMouseEvent * event){

    mousePosition = event->pos();
    QApplication::setOverrideCursor(QCursor(Qt::ClosedHandCursor));
}

void Renderer::mouseReleaseEvent(QMouseEvent * event){
    QApplication::restoreOverrideCursor();
}


void Renderer::wheelEvent(QWheelEvent *event){

    /*if(event->delta() > 0){
        glTranslatef(0,0,1);
    }

    else{

        glTranslatef(0,0,-1);
    }

    updateGL();
*/
}

void Renderer::keyPressEvent(QEvent *event){
    qDebug() << event << "\n";
    cout << "Salam" << endl;
}

void Renderer::openNewGrammar(struct Node* root){

    render = false;

    creator->releaseTerminals();
    creator->createVertices(root);

    render = true;
}


Renderer::~Renderer(){
    delete creator;
}
