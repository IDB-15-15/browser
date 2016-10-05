#include "parser.h"
#include "iostream"
#include "regex"

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
vector<string> parser::pars( string s,int mode){

    vector<string> result;
    regex tag_regex("\<(/?[^\>]+)\>");
    regex words_regex("\>(/?[^\>^\<]+)\<");
    regex m_regex;
    if(mode == 1)
        m_regex = tag_regex;
    if(mode == 2)
        m_regex = words_regex;
    auto words_begin =  sregex_iterator(s.begin(), s.end(), m_regex);
    auto words_end = sregex_iterator();
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
            smatch match = *i;
            string match_str = match.str();
            result.push_back(match_str);
                 }
    return result;
}
