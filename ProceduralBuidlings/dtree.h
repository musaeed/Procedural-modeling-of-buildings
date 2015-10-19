#ifndef DTREE_H
#define DTREE_H
#include <vector>
#include <QString>

using namespace std;

struct Node {

    string nodeName;
    char axis;
    vector <float> sizes;
    string texture;


    vector<struct Node> childs;
    bool propertiesSet;


    Node(){
        this->texture = "";

    }

    Node(string nodeName, vector<float> nodeSize){
        this->nodeName = nodeName;
        this->sizes = nodeSize;
        this->texture = "";

    }

    Node(string nodeName, char axis, vector<float> sizes/*, vector<Node> childs*/){
        this->nodeName = nodeName;
        this->axis = axis;
        this->sizes = sizes;
        //this->childs = childs;
        this->texture = "";
    }

    Node(char axis, vector<float> sizes, vector<Node> childs){
        this->nodeName = "nodeName";
        this->axis = axis;
        this->sizes = sizes;
        this->childs = childs;
        this->texture = "";
    }

    void setnodeName(string nodeName){
        this->nodeName = nodeName;
    }

    string getnodeName(){
        return nodeName;
    }

    void setaxis(char axis){
        this->axis = axis;
    }
    char getaxis(){
        return axis;
    }

    void setsizes(vector<float> sizes){
        this->sizes = sizes;
    }

    vector<float> getsizes(){
        return sizes;
    }

    void settexture(string texture){
        this->texture = texture;
    }

    string gettexture(){
        return texture;
    }

};

class DTree
{

private:

    struct Node* root;

public:

    DTree();
    void fillTree();
    void fillTreeNew();
    void fillUniTree();
    struct Node* getTree();
    ~DTree();

};

#endif // DTREE_H
