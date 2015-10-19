#include "parser.h"
#include "rules.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

Parser::Parser(QString filename)
{
    this->filename = filename;
}
Parser::~Parser()
{

}

//helper function to substract between two delimiters
string Parser::find_between(string &string_to_search_into, string delimiter1, string delimiter2)
{
    //get everything between paranthesis
    size_t pos_start = string_to_search_into.find_first_of(delimiter1);
    size_t pos_end = string_to_search_into.find_first_of(delimiter2);

    if (pos_start != string::npos && pos_end != string::npos)
    {
        string in_between = string_to_search_into.substr(pos_start + 1, pos_end - pos_start - 1);
        return in_between;
    }
    else
    {
        cout << "Invalid request to retrieve substring!" << endl;
        return "";
    }
}

//everything after a character
string Parser::find_after(string &string_to_search_into, string delimiter)
{
    //get everything between paranthesis
    size_t pos_start = string_to_search_into.find_first_of(delimiter);
    size_t pos_end = string_to_search_into.length();

    if (pos_start != string::npos && pos_end != string::npos)
    {
        string after = string_to_search_into.substr(pos_start + 1, pos_end - pos_start - 1);
        return after;
    }
    else
        return "";
}

map<int,Rules> Parser::extract_rules()
{
    //define file name of the grammar we are reading
    //E:\graphics\project\Parser
    string file_name = filename.toStdString();


    //create the instance of ifstream for the grammar file we are reading
    ifstream grammar_file(file_name.c_str());
    string returned_file_contents = read_file(grammar_file);


    if (returned_file_contents.length() > 0)
    {
        //1) extract rules
        vector<string> rules;

        //one element of the vector is one rule - but can we do better?
        construct_array(returned_file_contents, rules, "\n");
        int count = 0;
        std::map<int, Rules> parser_results;

        //Initial rules
        for (string &rule : rules) //here rules is a vector (as defined above), so iterate over it
        {
            if (!rule.empty() )
            {
                //rule head
                string head_rule = extract_rule_head(rule);

                //get everything between > and ( => FUNCTION NAME
                string function = find_between(rule, ">", "(");

                //get everything between paranthesis => PARAMETERS
                vector<string> params = extract_rule_individual_item(find_between(rule, "(", ")"), ",");

                //get everything between {} => CHILDREN
                vector<string> children = extract_rule_individual_item(find_between(rule, "{", "}"), "|");

                //get everything after {} => PROBABILITY
                string probability = find_after(rule, ":");

                //construct a rule
                Rules r;
                r.rule_name = head_rule;
                r.function = function;
                r.parameters = params;
                r.children = children;
                r.probability = probability;

                //insert the rule in the result
                parser_results.emplace(count,r);

                count++;
            }

        }
        return parser_results;
    }
    else
    {
        cout << "The grammar has no rules!" << endl;
    }
}

string Parser::extract_rule_head(string &rule)
{
    vector<string> rule_head;
    construct_array(rule, rule_head, "->");
    //rule_head[0] start
    //rule_head[1] S(10,10,10){box}
    cout << "Rule head =  " << rule_head[0] << " " << endl;

    //after observing the rule head
    if (rule.size() > 0)
        return rule_head[0];
    else
        return "";
}

vector<string> Parser::extract_rule_individual_item(string rule, string delimiter)
{
    vector<string> params;
    construct_array(rule, params, delimiter);
    return params;
}


void Parser::process_grammar(const string& long_string, const string& separator, string::size_type& start, string::size_type& end)
{
    //Find absence of character in string
    //Searches the string for the first character that does not match any of the characters specified in its arguments.

    start = long_string.find_first_not_of(separator, 0);

    // Find character in string
    //Searches the string for the first character that matches any of the characters specified in its arguments.
    //When end is specified, the search only includes characters at or after position end, ignoring any possible occurrences before end.
    end = long_string.find_first_of(separator, start);
}

void Parser::construct_array(const string& long_string, vector<string>& words, const string& separator)
{
    if (long_string != "")
    {
        string::size_type start;
        string::size_type end;

        process_grammar(long_string, separator, start, end);

        do
        {
            words.push_back(long_string.substr(start, end - start));
            start = long_string.find_first_not_of(separator, end);
            end = long_string.find_first_of(separator, start);
        } while (end != string::npos || start != string::npos);
    }
    else
        return;
}

//returns a string of all the rules in the file
string Parser::read_file(ifstream &in)
{
    if (!in.bad())
    {
        string temp_string, line_chars;
        while (!in.eof())
        {
            //read each line
            getline(in, line_chars);
            //cout << line_chars << endl;
            temp_string.append(line_chars);
            temp_string.append("\n");
        }
        cout << "Finsihed reading file into string ... " <<  endl;
        return temp_string;
    }
    else
    {
        cout << "Grammar file could not be read! " << endl;
        exit(0);
    }
}

void Parser::print(map<int, Rules> result){

    for ( std::map< int, Rules >::const_iterator iter = result.begin();iter != result.end(); ++iter ){
        cout << iter->first << '\t' << iter->second.rule_name << '\n';
    }
}
