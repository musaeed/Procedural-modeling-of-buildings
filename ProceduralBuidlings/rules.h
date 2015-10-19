#ifndef RULES_H
#define RULES_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Rules {

public:

    string rule_name;
    string function;
    vector <string> parameters;
    vector <string> children;
    string probability;

};

#endif // RULES_H
