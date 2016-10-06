#include "Parser/parser.h"
#include "iostream"
#include "regex"
#include "qdebug.h"
#include "QString"
#include <boost/algorithm/string.hpp>
#include <unistd.h>
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



vector<string> parser::pars(string s){

    vector<string> result;
    regex tag_regex("\<(/?[^\>]+)\>");
    regex words_regex("(/?[^\>]+)\<");
    bool tag = true;
    int j = 0;
    boost::trim(s);
    while(!s.empty()){
        boost::trim(s);
        if(s.at(0) == '<')
        {
            tag = true;
        }
        else
        {
            tag = false;
        }
    if(tag){
        auto tags_begin =  sregex_iterator(s.begin(), s.end(), tag_regex);
        auto tags_end = sregex_iterator();
        sregex_iterator i = tags_begin;
        if(i != tags_end){
                smatch match = *i;
                string match_str = match.str();
                result.push_back(match_str);
                s.erase(0,match_str.size());
                ++i;
        }

    }else{
        auto words_begin =  sregex_iterator(s.begin(), s.end(), words_regex);
        auto words_end = sregex_iterator();
        sregex_iterator k = words_begin;
        if(k != words_end){
                smatch match = *k;
                string match_str = match.str();
                match_str.erase(match_str.size()-1,1);
                result.push_back(match_str);
                s.erase(0,match_str.size());
                ++k;
    }

}


    }
    return result;
}


