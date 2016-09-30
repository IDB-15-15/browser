<<<<<<< HEAD
int main(){
	
	return 0;
}
=======
#include <iostream>
#include <boost/asio.hpp>
#include <string>
#include <network.h>
#include <vector>

using namespace boost::asio;

int main(int argc, char *argv[])
{
   std::string site = "http://ukrnews.com/";
   std::vector<std::string> res;
   //std::cout<<site;
   res=geth(site);
   //std::cout<<res;
     for (int i= 0; i!=res.size(); i++){
         std::cout<<res[i]<<std::endl;
     }
}

>>>>>>> dcdf3736686ad1f24101157f0b4eec28d38588d9
