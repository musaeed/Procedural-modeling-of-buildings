#include "dtree.h"

DTree::DTree()
{
}

void DTree::fillTree(){

    //////////////////////****************////////////// window area 2
    struct Node wall_wina2;
    wall_wina2.texture = "WALL";
    wall_wina2.axis = 'X';
    vector<float> size_wall {1};
    wall_wina2.sizes = size_wall;

    struct Node window_wina2;
    window_wina2.axis = 'X';
    window_wina2.texture = "WINDOW";
    vector<float> size_win {3};
    window_wina2.sizes = size_win;

    struct Node winA2;
    winA2.axis = 'X';
    vector<float> size_wina2 {4};
    winA2.sizes = size_wina2;
    vector<struct Node> wina2_childs {window_wina2, wall_wina2};
    winA2.childs = wina2_childs;

    ///////////////////////////*******************//////////////// wall ffloor
    struct Node ffwall;
    ffwall.axis = 'X';
    ffwall.texture = "WALL";
    vector<float> size_ffwal {2};
    ffwall.sizes = size_ffwal;

    ///////////////////////******************///////////////////// window area 1

    struct Node wall_wina1;
    wall_wina1.axis = 'X';
    wall_wina1.texture = "WALL";
    vector<float> size_wall_wina1 {1};
    wall_wina1.sizes = size_wall_wina1;

    struct Node window_wina1;
    window_wina1.axis = 'X';
    window_wina1.texture = "WINDOW";
    vector<float> size_win_wina1 {3};
    window_wina1.sizes = size_win_wina1;

    struct Node winA1;
    winA1.axis = 'X';
    vector<float> size_wina1 {4};
    winA1.sizes = size_wina1;
    vector<struct Node> wina1_childs {wall_wina1, window_wina1};
    winA1.childs = wina1_childs;

    /////////////////////////******************////////////////// first floor

    struct Node ffloor;
    ffloor.axis = 'Y';
    vector<float> size_ffloor{5};
    ffloor.sizes = size_ffloor;
    vector <struct Node> ffloor_childs{winA1, ffwall, winA2};
    ffloor.childs = ffloor_childs;

    /////////////////******************/////////////////// wall_ground

    struct Node wall_ground;
    wall_ground.texture = "WALL";
    wall_ground.axis = 'X';
    vector <float> size_wall_ground {3};
    wall_ground.sizes = size_wall_ground;

    ////////////////////**************//////////////////// door_ground

    struct Node door_ground;
    door_ground.axis = 'X';
    door_ground.texture = "DOOR";
    vector <float> size_door_ground {4};
    door_ground.sizes = size_door_ground;

    /////////////////*****************/////////////////// other_wall_ground


    struct Node other_wall_ground;
    other_wall_ground.texture = "WALL";
    other_wall_ground.axis = 'X';
    vector <float> other_size_wall_ground {3};
    other_wall_ground.sizes = other_size_wall_ground;

    /////////////////////****************////////////// ground floor

    struct Node gfloor;
    gfloor.axis = 'Y';
    vector<float> gfloor_size {5};
    gfloor.sizes = gfloor_size;
    vector<struct Node> gfloor_childs{wall_ground, door_ground, other_wall_ground};
    gfloor.childs = gfloor_childs;

    /////////////////*****************///////////////// front

    struct Node left;
    vector<float> leftsize {10,10,10};
    left.sizes = leftsize;
    left.texture = "WALL";

    struct Node right;
    vector<float> rightsize {10,10,10};
    right.sizes = rightsize;
    right.texture = "WALL";

    struct Node top;
    vector<float> topsize {10,10,10};
    top.sizes = topsize;
    top.texture = "TOP";

    struct Node bottom;
    vector<float> bottomsize {10,10,10};
    bottom.sizes = bottomsize;

    struct Node front;
    vector<float> frontsize {10,10,10};
    front.sizes = frontsize;
    vector<struct Node> front_childs {gfloor, ffloor};
    front.childs = front_childs;

    struct Node back;
    vector<float> backsize {10,10,10};
    back.sizes = backsize;
    back.texture = "WALL";

    ////////////////**************////////////////// root

    vector<float> sizes {10,10,10};
    vector<struct Node> childs {left, right, top, bottom, front, back};
    root = new Node('O', sizes, childs);

}

void DTree::fillTreeNew(){

    struct Node wall;
    wall.axis = 'X';
    vector<float> wall_size {0.4};
    wall.texture = "WALL";
    wall.sizes = wall_size;

    struct Node wall2;
    wall2.axis = 'Y';
    vector<float> wall_size2 {0.4};
    wall2.texture = "WALL";
    wall2.sizes = wall_size2;

    struct Node window;
    window.axis = 'X';
    vector<float> window_size {1.6};
    window.sizes = window_size;
    window.texture = "WINDOW";

    struct Node windowArea;
    windowArea.axis = 'X';
    vector<float> windowAreaSize {2};
    windowArea.sizes = windowAreaSize;
    vector<struct Node> windowAreaChilds {wall, window};
    windowArea.childs = windowAreaChilds;

    struct Node wall1;
    wall1.axis = 'X';
    vector<float> wallsize1 {4.3};
    wall1.sizes = wallsize1;
    wall1.texture = "WALL";

    struct Node door;
    door.axis = 'X';
    vector<float> doorsize {1.4};
    door.sizes = doorsize;
    door.texture = "DOOR";


    struct Node floor1;
    floor1.axis = 'Y';
    vector<float> floorSize1 {2};
    floor1.sizes = floorSize1;
    vector<struct Node> floorchilds1 {wall1, wall1, door,  wall};
    floor1.childs = floorchilds1;

    struct Node floor2;
    floor2.axis = 'Y';
    vector<float> floorSize2 {2};
    floor2.sizes = floorSize2;
    vector<struct Node> floorchilds2 {windowArea, windowArea, windowArea, windowArea, windowArea, wall};
    floor2.childs = floorchilds2;


    struct Node floor3;
    floor3.axis = 'Y';
    vector<float> floorSize3 {2};
    floor3.sizes = floorSize3;
    vector<struct Node> floorchilds3 {windowArea, windowArea, windowArea, windowArea, windowArea, wall};
    floor3.childs = floorchilds3;


    struct Node floor4;
    floor4.axis = 'Y';
    vector<float> floorSize4 {2};
    floor4.sizes = floorSize4;
    vector<struct Node> floorchilds4 {windowArea, windowArea, windowArea, windowArea, windowArea, wall};
    floor4.childs = floorchilds4;


    struct Node floor5;
    floor5.axis = 'Y';
    vector<float> floorSize5 {2};
    floor5.sizes = floorSize5;
    vector<struct Node> floorchilds5 {windowArea, windowArea, windowArea, windowArea, windowArea, wall};
    floor5.childs = floorchilds5;

    struct Node left;
    vector<float> leftsize {10.4,10.4,10.4};
    left.sizes = leftsize;
    vector<struct Node> leftchilds {floor1, floor2,floor3,floor4,floor5,wall2};
    left.childs = leftchilds;

    struct Node right;
    vector<float> rightsize {10.4,10.4,10.4};
    right.sizes = rightsize;
    vector<struct Node> rightchilds {floor1, floor2, floor3,floor4,floor5,wall2};
    right.childs = rightchilds;

    struct Node top;
    vector<float> topsize {10.4,10.4,10.4};
    top.sizes = topsize;
    top.texture = "TOP";

    struct Node bottom;
    vector<float> bottomsize {10.4,10.4,10.4};
    bottom.sizes = bottomsize;

    struct Node front;
    vector<float> frontsize {10.4,10.4,10.4};
    front.sizes = frontsize;
    vector<struct Node> frontchilds {floor1, floor2, floor3,floor4,floor5,wall2};
    front.childs = frontchilds;

    struct Node back;
    vector<float> backsize {10.4,10.4,10.4};
    back.sizes = backsize;
    vector<struct Node> backchilds {floor1, floor2,floor3,floor4,floor5,wall2};
    back.childs = backchilds;

    vector<float> sizes {10.4,10.4,10.4};
    vector<struct Node> childs {left, right, top, bottom,front,back};
    root = new Node('0', sizes, childs);
}

void DTree::fillUniTree(){

    struct Node darkwall1;
    darkwall1.axis = 'X';
    vector<float> darkwallsizes1 {1};
    darkwall1.sizes = darkwallsizes1;
    darkwall1.texture = "DARKWALL";

    struct Node pillar1;
    pillar1.axis = 'X';
    vector<float> pillarsizes1 {1};
    pillar1.sizes = pillarsizes1;
    pillar1.texture = "PILLAR";

    struct Node wall1;
    wall1.axis = 'X';
    vector<float> wallsizes1 {2};
    wall1.sizes = wallsizes1;
    wall1.texture = "WALL";

    struct Node wall3;
    wall3.axis = 'Y';
    vector<float> wallsizes3 {1};
    wall3.sizes = wallsizes3;
    wall3.texture = "WALL";

    struct Node window;
    window.axis = 'Y';
    vector<float> windowsize {3};
    window.sizes = windowsize;
    window.texture = "WINDOW";

    struct Node windowarea;
    windowarea.axis = 'X';
    vector<float> windowareasizes {2};
    windowarea.sizes = windowareasizes;
    vector<struct Node> windowareachilds {wall3, window, wall3};
    windowarea.childs = windowareachilds;

    struct Node wall2;
    wall2.axis = 'X';
    vector<float> wallsizes2 {1};
    wall2.sizes = wallsizes2;
    wall2.texture = "WALL";

    struct Node darkwall2;
    darkwall2.axis = 'X';
    vector<float> darkwallsizes2 {2};
    darkwall2.sizes = darkwallsizes2;
    darkwall2.texture = "DARKWALL";

    struct Node pillar2;
    pillar2.axis = 'X';
    vector<float> pillarsizes2 {2};
    pillar2.sizes = pillarsizes2;
    pillar2.texture = "PILLAR";

    struct Node bigwall;
    bigwall.axis = 'X';
    vector<float> bigwallsizes {20};
    bigwall.sizes = bigwallsizes;
    bigwall.texture = "WALL";

    struct Node logo;
    logo.axis = 'X';
    vector<float> logosizes {6};
    logo.sizes = logosizes;
    logo.texture = "LOGO";

    struct Node lrfloor1;
    lrfloor1.axis = 'Y';
    vector<float> lrfloorsizes1 {5};
    lrfloor1.sizes = lrfloorsizes1;
    vector<Node> lrfloorchilds1 {darkwall1, pillar1,darkwall1, pillar1,darkwall1, pillar1,darkwall1};
    lrfloor1.childs = lrfloorchilds1;

    struct Node lrfloor2;
    lrfloor2.axis = 'Y';
    vector<float> lrfloorsizes2 {5};
    lrfloor2.sizes = lrfloorsizes2;
    vector<Node> lrfloorchilds2 {wall1, windowarea, windowarea, wall2};
    lrfloor2.childs = lrfloorchilds2;

    struct Node lrfloor3;
    lrfloor3.axis = 'Y';
    vector<float> lrfloorsizes3 {5};
    lrfloor3.sizes = lrfloorsizes3;
    vector<Node> lrfloorchilds3 {wall1, windowarea, windowarea, wall2};
    lrfloor3.childs = lrfloorchilds3;

    struct Node fflor1;
    fflor1.axis = 'Y';
    vector<float> fflorsizes1 {5};
    fflor1.sizes = fflorsizes1;
    vector<struct Node> fflorchilds1 {darkwall2, pillar2,darkwall2, pillar2,darkwall2, pillar2,darkwall2, pillar2,darkwall2, pillar2,darkwall2, pillar2,darkwall2};
    fflor1.childs = fflorchilds1;

    struct Node fflor2;
    fflor2.axis = 'Y';
    vector<float> fflorsizes2 {5};
    fflor2.sizes = fflorsizes2;
    vector<struct Node> fflorchilds2 {wall1, wall1, windowarea, windowarea, windowarea, windowarea, windowarea, windowarea,windowarea, windowarea, windowarea, windowarea, wall1};
    fflor2.childs = fflorchilds2;

    struct Node fflor3;
    fflor3.axis = 'Y';
    vector<float> fflorsizes3 {5};
    fflor3.sizes = fflorsizes3;
    fflor3.texture = "WALL";
    vector<struct Node> fflorchilds3 {bigwall, logo};
    //fflor3.childs = fflorchilds3;

    struct Node left;
    vector<float> leftsize {26,15,7};
    left.sizes = leftsize;
    vector<struct Node> leftchilds {lrfloor1, lrfloor2, lrfloor3};
    left.childs = leftchilds;

    struct Node right;
    vector<float> rightsize {26,15,7};
    right.sizes = rightsize;
    vector<struct Node> rightchilds {lrfloor1, lrfloor2, lrfloor3};
    right.childs = rightchilds;

    struct Node top;
    vector<float> topsize {26,15,7};
    top.sizes = topsize;
    top.texture = "TOP";

    struct Node bottom;
    vector<float> bottomsize {26,15,7};
    bottom.sizes = bottomsize;

    struct Node front;
    vector<float> frontsize {26,15,7};
    front.sizes = frontsize;
    vector<struct Node> frontchilds {fflor1, fflor2, fflor3};
    front.childs = frontchilds;

    struct Node back;
    vector<float> backsize {26,15,7};
    back.sizes = backsize;
    back.texture = "WALL";
    //vector<struct Node> backchilds {floor1, floor2,floor3,floor4,floor5,wall2};
    //back.childs = backchilds;

    vector<float> sizes {26,15,7};
    vector<struct Node> childs {left, right, top, bottom,front,back};
    root = new Node('0', sizes, childs);

}

struct Node* DTree::getTree(){
    return this->root;
}


DTree::~DTree(){

    if(root == NULL){

        return;
    }

    delete root;
}
