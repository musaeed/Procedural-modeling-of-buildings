#include "vertexcreator.h"

using namespace std;

VertexCreator::VertexCreator()
{
    xScale = 0.f;
    yScale = 0.f;
    zScale = 0.f;

}

void VertexCreator::createVertices(struct Node* root){

    vector<float> scales = root->sizes;

    xScale = scales[0];
    yScale = scales[1];
    zScale = scales[2];

    maxScale = max(xScale, max(yScale, zScale));
    //maxScale = 10.f;

//    cout << root->childs[0].childs.size() << endl;



    Shape left = createInitialVerticesLeft(root->childs[0].sizes[0], root->childs[0].sizes[1], root->childs[0].sizes[2]);
    Shape right = createInitialVerticesRight(root->childs[1].sizes[0], root->childs[1].sizes[1], root->childs[1].sizes[2]);
    Shape top = createInitialVerticesTop(root->childs[2].sizes[0], root->childs[2].sizes[1], root->childs[2].sizes[2]);
    //Shape bottom = createInitialVerticesDown(root->childs[3].sizes[0], root->childs[3].sizes[1], root->childs[3].sizes[2]);
    Shape front = createInitialVerticesFront(root->childs[4].sizes[0], root->childs[4].sizes[1], root->childs[4].sizes[2]);
    Shape back = createInitialVerticesBack(root->childs[5].sizes[0], root->childs[5].sizes[1], root->childs[5].sizes[2]);

    recursiveCalculateTree(root->childs[0], left, zScale, yScale);
    recursiveCalculateTree(root->childs[1], right, zScale, yScale);
    recursiveCalculateTree(root->childs[2], top, xScale, yScale);
    recursiveCalculateTree(root->childs[4], front, xScale, yScale);
    recursiveCalculateTree(root->childs[5], back, xScale, yScale);
}

void VertexCreator::recursiveCalculateTree(struct Node node, Shape pCoordinates, float xSize, float YSize){

    vector<struct Node> childs = node.childs;

    Shape parent;
    parent.p1 = pCoordinates.p1;
    parent.p2 = pCoordinates.p2;
    parent.p3 = pCoordinates.p3;
    parent.p4 = pCoordinates.p4;

    if(childs.size() == 0){

        if(node.texture.compare("") != 0){

            pCoordinates.texture.x = getTextureID(QString::fromStdString(node.texture));
            pCoordinates.makeTextureAvailable(true);
        }

        terminalShapes.push_back(pCoordinates);

        return;

    }


    vector<Shape> shapes;
    vector<float> xSizes;
    vector<float> ySizes;


    for(unsigned int i = 0 ; i < node.childs.size() ; i++){



        Shape shape;

        if(node.childs[i].axis == 'Y'){

            float nsize;

/*            if(node.sizes.size() == 1){
                nsize = (float)node.sizes[1];
            }
            else{
                nsize = (float)node.sizes[0];
            }*/

            //cout << ySize << endl;
            //cout << (float)node.childs[i].sizes[0] << endl;
            //cout << (float)node.sizes[1] << endl << endl;

            //float ratio = (float)node.childs[i].sizes[0] / (float)node.sizes[1];
            float ratio = (float)node.childs[i].sizes[0] / YSize;

            //cout << ratio << endl;
            Point3D newP2 = getNewCoordinate(pCoordinates.p2, pCoordinates.p1, parent.p1 ,ratio);
            Point3D newP3 = getNewCoordinate(pCoordinates.p3, pCoordinates.p4, parent.p4 ,ratio);

            shape.p1 = pCoordinates.p1;
            shape.p2 = newP2;
            shape.p3 = newP3;
            shape.p4 = pCoordinates.p4;

            pCoordinates.p1 = newP2;
            pCoordinates.p4 = newP3;

            xSizes.push_back(xSize);
            ySizes.push_back((float)node.childs[i].sizes[0]);
           // cout <<(float)node.childs[i].sizes[0] << endl;

        }

        else if(node.childs[i].axis == 'X'){

            float ratio = (float)node.childs[i].sizes[0] / xSize;
            Point3D newP3 = getNewCoordinate(pCoordinates.p3, pCoordinates.p2, parent.p2, ratio);
            Point3D newP4 = getNewCoordinate(pCoordinates.p4, pCoordinates.p1, parent.p1, ratio);

            shape.p1 = pCoordinates.p1;
            shape.p2 = pCoordinates.p2;
            shape.p3 = newP3;
            shape.p4 = newP4;

            pCoordinates.p1 = newP4;
            pCoordinates.p2 = newP3;
            //cout << YSize << endl;
            xSizes.push_back((float)node.childs[i].sizes[0]);
            ySizes.push_back(YSize);
        }

        shapes.push_back(shape);
    }



    for(unsigned int i = 0; i < node.childs.size() ; i++){
       // cout << ySizes[i] << endl;
        recursiveCalculateTree(node.childs[i], shapes[i], xSizes[i], ySizes[i]);

    }
}

Point3D VertexCreator::getNewCoordinate(Point3D p1, Point3D p2, Point3D reference, float ratio){



    Point3D dir = p2.minus(p1);
    dir.normalize();
    dir.scale(-1.f);
    float dist = reference.distance(p1);
    float newDis = dist * ratio;

    dir.scale(newDis);

    return p2.plus(dir);
}

Shape VertexCreator::createInitialVerticesLeft(float Xsize, float Ysize, float Zsize){

    Shape shape;

    float Xmax = Xsize / maxScale;
    float Ymax = Ysize / maxScale;
    float Zmax = Zsize / maxScale;

    shape.p1.x = 0.f;
    shape.p1.y = 0.f;
    shape.p1.z = 0.f;

    shape.p2.x = 0.f;
    shape.p2.y = Ymax;
    shape.p2.z = 0.f;

    shape.p3.x = 0.f;
    shape.p3.y = Ymax;
    shape.p3.z = Zmax;

    shape.p4.x = 0.f;
    shape.p4.y = 0.f;
    shape.p4.z = Zmax;

    return shape;
}

Shape VertexCreator::createInitialVerticesRight(float Xsize, float Ysize, float Zsize){

    Shape shape;
    float Xmax = Xsize / maxScale;
    float Ymax = Ysize / maxScale;
    float Zmax = Zsize / maxScale;

    shape.p1.x = Xmax;
    shape.p1.y = 0.f;
    shape.p1.z = 0.f;

    shape.p2.x = Xmax;
    shape.p2.y = Ymax;
    shape.p2.z = 0.f;

    shape.p3.x = Xmax;
    shape.p3.y = Ymax;
    shape.p3.z = Zmax;

    shape.p4.x = Xmax;
    shape.p4.y = 0.f;
    shape.p4.z = Zmax;
    return shape;
}



Shape VertexCreator::createInitialVerticesTop(float Xsize, float Ysize, float Zsize){

    Shape shape;
    float Xmax = Xsize / maxScale;
    float Ymax = Ysize / maxScale;
    float Zmax = Zsize / maxScale;

    shape.p1.x = 0.f;
    shape.p1.y = Ymax;
    shape.p1.z = 0.f;

    shape.p2.x = Xmax;
    shape.p2.y = Ymax;
    shape.p2.z = 0.f;

    shape.p3.x = Xmax;
    shape.p3.y = Ymax;
    shape.p3.z = Zmax;

    shape.p4.x = 0.f;
    shape.p4.y = Ymax;
    shape.p4.z = Zmax;


    return shape;
}

Shape VertexCreator::createInitialVerticesDown(float Xsize, float Ysize, float Zsize){

    Shape shape;
    float Xmax = Xsize / maxScale;
    float Ymax = Ysize / maxScale;
    float Zmax = Zsize / maxScale;

    shape.p1.x = 0.f;
    shape.p1.y = 0.f;
    shape.p1.z = 0.f;

    shape.p2.x = Xmax;
    shape.p2.y = 0.f;
    shape.p2.z = 0.f;

    shape.p3.x = Xmax;
    shape.p3.y = 0.f;
    shape.p3.z = Zmax;

    shape.p4.x = 0.f;
    shape.p4.y = 0.f;
    shape.p4.z = Zmax;

    return shape;
}

Shape VertexCreator::createInitialVerticesFront(float Xsize, float Ysize, float Zsize){

    Shape shape;
    float Xmax = Xsize / maxScale;
    float Ymax = Ysize / maxScale;
    float Zmax = Zsize / maxScale;

    shape.p1.x = 0.f;
    shape.p1.y = 0.f;
    shape.p1.z = Zmax;

    shape.p2.x = 0.f;
    shape.p2.y = Ymax;
    shape.p2.z = Zmax;

    shape.p3.x = Xmax;
    shape.p3.y = Ymax;
    shape.p3.z = Zmax;

    shape.p4.x = Xmax;
    shape.p4.y = 0.f;
    shape.p4.z = Zmax;

    return shape;
}

Shape VertexCreator::createInitialVerticesBack(float Xsize, float Ysize, float Zsize){

    Shape shape;
    float Xmax = Xsize / maxScale;
    float Ymax = Ysize / maxScale;
    float Zmax = Zsize / maxScale;

    shape.p1.x = 0.f;
    shape.p1.y = 0.f;
    shape.p1.z = 0.f;

    shape.p2.x = 0.f;
    shape.p2.y = Ymax;
    shape.p2.z = 0.f;

    shape.p3.x = Xmax;
    shape.p3.y = Ymax;
    shape.p3.z = 0.f;

    shape.p4.x = Xmax;
    shape.p4.y = 0.f;
    shape.p4.z = 0.f;


    return shape;
}


void VertexCreator::drawTerminals(){

    for(unsigned int i = 0 ; i < terminalShapes.size() ; i++){

        terminalShapes[i].draw();
    }
}


float VertexCreator::getTextureID(QString name){

    if(name.compare(name, "DOOR") == 0){
        return DOOR;
    }

    if(name.compare(name, "WALL") == 0){
        return WALL;
    }

    if(name.compare(name, "WINDOW") == 0){
        return WINDOW;
    }

    if(name.compare(name, "TOP") == 0){
        return TOP;
    }

    if(name.compare(name, "TOP") == 0){
        return TOP;
    }

    if(name.compare(name, "LOGO") == 0){
        return LOGO;
    }

    if(name.compare(name, "PILLAR") == 0){
        return PILLAR;
    }

    if(name.compare(name, "DARKWALL") == 0){
        return DARKWALL;
    }

    return -1;
}

void VertexCreator::releaseTerminals(){

    terminalShapes.clear();
}
