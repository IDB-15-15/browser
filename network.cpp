#include <network.h>
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/error.hpp>
#include <vector>


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

//    vector<string> head;
//    std::string blabla="rrr";
//    getline(stream, blabla);
//    while(blabla[0]!='<'){
//    //for(int i=0; i<=4; i++){
//    head.push_back(blabla);
//    blabla="";
//    getline(stream, blabla);}
//    for(int i=0; i<=4; i++){
//       cout<<head[i]<<endl;
//    }
//    cout<<"\n\n\n\n\n";


//    std::string line1;
//    std::getline(stream,line1);

//            std::stringstream response_stream(line1);
//                    std::string http_version;
//                    response_stream >> http_version;
//                    unsigned int status_code;
//                    response_stream >> status_code;
//                    std::string status_message;
//                    std::getline(response_stream,status_message);
//                    if ((status_code>=300&&status_code<=303)||status_code==305){
//                        for (int i=0; i<=4;i++){
//                            std::getline(stream,line1);

//                           }
//                        string redirect;
//                        std::getline(stream,redirect);
//                        std::stringstream res_stream(redirect);
//                        res_stream>>redirect;
//                        res_stream>>redirect;
//                       // cout<<redirect;
//                        return geth(redirect);
//                    }

//                    else{
//                        std::ostringstream ss;
//                        string res;
//                        ss << stream.rdbuf();
//                        res=ss.str();
                        vector<string> tochtonado;
                        std::string blabla="";

                            while(stream){
                            getline(stream, blabla);
                            tochtonado.push_back(blabla);
                            //blabla="";
                            }
                            //cout<<tochtonado[0]<<endl;
//                            for(int i=0; i<15; i++){
//                                cout<<tochtonado[i]<<endl;
//                            }

                            size_t some=tochtonado[0].find(' ');
                            //cout<<(int)some;
                            tochtonado[0].erase(0, (int)some) ;
                            some=tochtonado[0].find(" ");
                            cout<<tochtonado[0];
                            //cout<<(int)some;
//                            tochtonado[0]=tochtonado[0].erase(some-1, tochtonado[0].npos);
//                            cout<<tochtonado[0];


                          string res="adasdsad";
                          return res;

}
