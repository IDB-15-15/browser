#include <network.h>
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/error.hpp>
#include <vector>


using namespace boost::asio;
using namespace std;

vector<string> geth(std::string site){

    ip::tcp::iostream stream;
    stream.expires_from_now(boost::posix_time::seconds(60));
    site.erase(0,7);

    std::string::size_type sl = site.find('/');
    int pl = (int)sl;
    string page(site.substr(sl));
    site.erase(pl,site.length());
    stream.connect(site, "http");
    stream << "GET ";
    stream << page;
    stream << " HTTP/1.0\r\n";
    stream << "Host: ";
    stream << site;
    stream << "\r\n";
    stream << "Accept: */*\r\n";
    stream << "Connection: close\r\n\r\n";

    stream.flush();


                        vector<string> tochtonado;
                        std::string blabla="";

                            while(stream){
                            getline(stream, blabla);
                            tochtonado.push_back(blabla);
                            }
                            stringstream some(tochtonado[0]);
                            some>>tochtonado[0];
                            some>>tochtonado[0];
                            if (tochtonado[0]=="301"||tochtonado[0]=="302"||tochtonado[0]=="300"||
                                    tochtonado[0]=="303"||tochtonado[0]=="305"||tochtonado[0]=="307"){

                            stringstream _some(tochtonado[6]);
                            _some>>tochtonado[6];
                            _some>>tochtonado[6];
                            return geth(tochtonado[6]);
                            }

                         else{


                          return tochtonado;}

}
