#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <vector>


using namespace std;

class parser
{
public:

    struct Attr{
        string name;
        string value;
    };

    struct Tag{
        string name;
        Attr* attr;
        Tag* tag;
    };

    struct Node{
        Tag* tag;
        string* text;
    };
    vector<string> pars(string s);
    string del_spaces(string s);
};

#endif // PARSER_H
