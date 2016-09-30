#include <iostream>
#include <boost/asio.hpp>
#include <string>
#include <network.h>

using namespace boost::asio;

int main(int argc, char *argv[])
{
   std::string site = "http://ukranews.com/";
   std::string res;
   std::cout<<site;
   res=geth(site);
   //std::cout<<res;

}

