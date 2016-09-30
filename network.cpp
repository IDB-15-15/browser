#include <network.h>
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/error.hpp>
using namespace boost::asio;
using namespace std;
std::string geth(std::string site){

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

    std::string line1;
    std::getline(stream,line1);

            std::stringstream response_stream(line1);
                    std::string http_version;
                    response_stream >> http_version;
                    unsigned int status_code;
                    response_stream >> status_code;
                    std::string status_message;
                    std::getline(response_stream,status_message);
                    if ((status_code>=300&&status_code<=303)||status_code==305){
                        for (int i=0; i<=4;i++){
                            std::getline(stream,line1);

                        }
                       string redirect;
                       std::getline(stream,redirect);


                      cout<<redirect;
                    }


    std::ostringstream ss;
    string res;
    ss << stream.rdbuf();
    res=ss.str();
    return res;

};
