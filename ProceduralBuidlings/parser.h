#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <fstream>
#include <istream>
#include <map>
#include <QString>
#include "rules.h"

using namespace std;

class Parser {

private:
    //map<int, vector<Rules>> parsed_grammar_rules;
    QString filename;

public:
    Parser(QString);
    ~Parser();

    /*--------- Methods ---------*/

    //-- Input
    string read_file(ifstream &);
    //void extract_rules();
    map<int,Rules> extract_rules();

    //-- Grammar
    void process_grammar(const string& long_string, const string& separator, string::size_type& start, string::size_type& end);
    void construct_array(const string& long_string, vector<string>& words, const string& separator);


    //-- Rules
    string extract_rule_head(string& rule);
    vector<string> extract_rule_individual_item(string rule, string delimiter);

    //--Helpers
    string find_between(string &string_to_search_into, string delimiter1, string delimiter2);
    string find_after(string &string_to_search_into, string delimiter);
    void print(map<int, Rules>);
};

#endif // PARSER_H
