
#include <iostream>
#include <boost/asio.hpp>
#include <string>
#include <network.h>
#include <vector>

using namespace boost::asio;
using namespace std;

int main()
{
   std::string site = "http://localhost/dsad";
   vector<string> res;
   vector<string> header;
   vector<string> main;
   res=geth(site);
   int i = 0;
   int k = 0;
    while(res[i] != "\r" && res[i+1] != "\r"){
        i++;
        header.push_back(res[k]);
        k++;
    }
    while(k != res.size()-1){
        main.push_back(res[k]);
        k++;
    }
  for(i = 0;i<header.size();i++)
        cout<<header[i]<<endl;
  for(i = 0;i<main.size();i++)
        cout<<main[i]<<endl;
    return 0;
}

