#include "modeler.h"
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>

using namespace std;

Modeler::Modeler(){

}

Modeler::~Modeler(){

}

void Modeler::S(string ruleName, vector<string> params, vector<string> childNodes){

    vector<float> sizes;
    for(int i=0; i<params.size(); i++){
        std::string::size_type sz;
        double temp = std::stof(params[i],&sz);
        sizes.push_back(temp);
        startSize.push_back(temp);
    }

    vector<Node> children;

    for(int i=0; i<childNodes.size(); i++){
        children.push_back(Node(childNodes[i], sizes));
        children[i].propertiesSet = false; // only node is created but its properties are not set
    }

    root = new Node(ruleName, '0', sizes);
    root->propertiesSet = true;

    childrenQueue.push_back(children);
    root->childs = children;
    queue.push_back(root);

    expandedNodes.push_back(root->nodeName);
}

void Modeler::comp(string ruleName, vector<string> childNodes){
    vector<Node> children;
    for(int i=0; i<childrenQueue.size(); i++){
        for(int j=0; j<childrenQueue[i].size(); j++){
            if( (ruleName.compare(childrenQueue[i][j].getnodeName()) == 0) && (childrenQueue[i][j].propertiesSet != true) ){

                for(int k=0; k<childNodes.size(); k++){
                    children.push_back(Node(childNodes[k], '0', startSize));
                    children[k].propertiesSet = false;
                }
                //childrenQueue[i][j].sizes = startSize;
                childrenQueue[i][j].childs = children;
                childrenQueue[i][j].propertiesSet = true;
                childrenQueue[i][j].setaxis('0');
                queue.push_back(&childrenQueue[i][j]);
                expandedNodes.push_back(childrenQueue[i][j].nodeName);
            }
        }
    }
    //adding new children in the childrenqueue
    childrenQueue.push_back(children);

}

void Modeler::subDiv(string ruleName, vector<string> params, vector<string> childNodes){
    bool check = false;

    vector<Node> children;

    for(int i=0; i<childrenQueue.size(); i++){
        for(int j=0; j<childrenQueue[i].size(); j++){
            if( (ruleName.compare(childrenQueue[i][j].getnodeName()) == 0) && (childrenQueue[i][j].propertiesSet != true) && (check == false)){


                    //setting axis
                    //childrenQueue[i][j].axis = params[0][1];

                    //childrenQueue[i][j].setsizes(tempsizes);
                    //creating children of parent node
                    //cout << "axis of node being expanded: " << childrenQueue[i][j].axis << endl;
                    //cout << "ruleName: " << ruleName << endl;
                    //cout << "axis of children: " << params[0][1] << endl;
                    for(int k=0; k<childNodes.size(); k++){

                        //computing size of each child node
                        std::string::size_type sz;
                        double temp = std::stof(params[k+1],&sz);
                        vector<float> tempsizes;
                        tempsizes.push_back(temp);

                        children.push_back(Node(childNodes[k], params[0][1], tempsizes));
                        children[k].propertiesSet = false;
                    }
                    childrenQueue[i][j].childs = children;
                    childrenQueue[i][j].propertiesSet = true;
                    queue.push_back(&childrenQueue[i][j]);
                    expandedNodes.push_back(childrenQueue[i][j].nodeName);


                    if(!checkExpanded(ruleName)){
                        check = true;
                    }
            }
        }
    }
    //adding new children in the children queue
    childrenQueue.push_back(children);
}

void Modeler::texture(string ruleName, vector<string> params){
    bool check = false;

    for(int i=0; i<childrenQueue.size(); i++){
        for(int j=0; j<childrenQueue[i].size(); j++){
            if( (ruleName.compare(childrenQueue[i][j].getnodeName()) == 0) && (childrenQueue[i][j].propertiesSet != true) && (check == false) ){
                childrenQueue[i][j].texture = params[0];
                //childrenQueue[i][j].axis = '0';
                //cout << "Axis of expanded node: " << childrenQueue[i][j].axis << endl;
                queue.push_back(&childrenQueue[i][j]);
                expandedNodes.push_back(childrenQueue[i][j].nodeName);

                if(!checkExpanded(ruleName)){
                        check = true;
                }
            }
        }
    }

}

void Modeler::Model(map<int, Rules> ruleSet){
    cout << "************** Modeling ************************ " << endl;

    std::map<int,Rules>::iterator iter;

    int nodeCounter = 0;
    for(iter = ruleSet.begin(); iter != ruleSet.end(); ++iter){

        if((iter->second.function.compare("S")) == 0 ){
            //cout << "Rule Head: " << iter->second.rule_name << endl;
            S(iter->second.rule_name, iter->second.parameters, iter->second.children);
            printNode(queue[nodeCounter]);
            nodeCounter++;
            //cout << "A node has been created!" << endl;
            cout << "---------------------------------------------------------------------------" << endl;
        }
        else if((iter->second.function.compare("comp")) == 0){
            //cout << "Rule Head: " << iter->second.rule_name << endl;
            comp(iter->second.rule_name, iter->second.children);
            printNode(queue[nodeCounter]);
            nodeCounter++;
            //cout << "A node has been created!" << endl;
            cout << "---------------------------------------------------------------------------" << endl;
        }
        else if((iter->second.function.compare("subDiv")) == 0){
            //cout << "Rule Head: " << iter->second.rule_name << endl;
            subDiv(iter->second.rule_name, iter->second.parameters, iter->second.children);
            printNode(queue[nodeCounter]);
            nodeCounter++;
            //cout << "A node has been created!" << endl;
            cout << "---------------------------------------------------------------------------" << endl;
        }
        else if((iter->second.function.compare("texture")) == 0){
            //cout << "Rule Head: " << iter->second.rule_name << endl;
            texture(iter->second.rule_name, iter->second.parameters);
            printNode(queue[nodeCounter]);
            nodeCounter++;
            //cout << "Texture has been set!" << endl;
            cout << "---------------------------------------------------------------------------" << endl;
        }
        else{
            cout << "No function call in the grammar file!" << endl;
        }
        //printExpandedNodes(expandedNodes);
        //printChidrenQueue(childrenQueue);
    }
}

void Modeler::printNode(Node *tempNode){
    string nodeName;
    char axis;
    vector<float> tempsizes;
    string texture;
    vector<Node*> children;

    cout << "Node Name: " << tempNode->getnodeName() << endl;
    cout << "Node axis: " << tempNode->getaxis() << endl;
    tempsizes = tempNode->getsizes();

    cout << "Node Size: [";
    for(int i=0; i<tempsizes.size(); i++){
        cout << tempsizes[i] << " ";
    }
    cout << "]" << endl;

    cout << "Node texture: " << tempNode->gettexture() << endl;

    cout << "Children names: [";
    for(int i=0; i<tempNode->childs.size(); i++){
        cout << tempNode->childs[i].getnodeName()<< " ";
    }
    cout << "]" << endl;

}

void Modeler::printChidrenQueue(vector<vector<Node> > childrenQ){
    cout <<"Children queue: [";
    for(int i=0; i< childrenQ.size(); i++){
        for(int j=0; j<childrenQ[i].size(); j++){
            cout << childrenQ[i][j].getnodeName() << " ";
        }
    }
    cout << "]" << endl;
}

void Modeler::printExpandedNodes(vector<string> expandedNodes){
    cout << "Expanded Nodes: [";
    for(int i=0; i<expandedNodes.size(); i++){
        cout << expandedNodes[i] << " ";
    }
    cout << "]" << endl;
}

bool Modeler::checkExpanded(string ruleName){
    for(int i=0; i<expandedNodes.size(); i++){
        if(ruleName.compare(expandedNodes[i]) == 0){
            return true;
        }
        else{
            return false;
        }
    }
}
