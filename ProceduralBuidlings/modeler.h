#ifndef MODELER_H
#define MODELER_H

#include <iostream>
#include <vector>
#include <string>
#include "rules.h"
#include "dtree.h"
#include "parser.h"

class Modeler{
    private:
        struct Node* root;

    public:
        vector<Node*> queue;
        vector< vector<Node> > childrenQueue;
        vector<string> expandedNodes;
        vector<float> startSize;
        Modeler();
        ~Modeler();

        void Model(map<int, Rules> ruleSet); //uses the rules obtained from Parser class
        void S(string ruleName, vector<string> params, vector<string> childNodes);
        void printNode(Node *tempNode);

        void comp(string ruleName, vector<string> childNodes);
        void subDiv(string ruleName, vector<string> params, vector<string> childNodes);
        void texture(string ruleName, vector<string> params);

        Node* returnRoot(){
            return this->root;
        }

        void printChidrenQueue(vector<vector<Node> > childrenQ);
        void printExpandedNodes(vector<string> expandedNodes);
        bool checkExpanded(string ruleName);
};

#endif
