#include <network.h>
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/error.hpp>
#include <vector>

using namespace boost::asio;
using namespace std;

vector<string> httpg(std::string site){ //GET запрос для http (работает)
    ip::tcp::iostream stream;
    stream.expires_from_now(boost::posix_time::seconds(10));
    site.erase(0,7);

    std::string::size_type sl = site.find('/');
    int pl = (int)sl;
    string page(site.substr(sl));
    site.erase(pl,site.length());
    stream.connect(site, "http");
//Ethernet check
    if (!stream){
        std::cout << "Error: " << stream.error().message() << std::endl;
    }

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
        return tochtonado;
    }
}

vector<string> httpsg(std::string site){  //GET запрос для https (будем думать)
    vector<string> res;
    res.push_back("blablabla");
    res.push_back("/r/n");
    res.push_back("dadada");
    return res;
}

vector<string> geth(std::string site){

    string http="http://";
    string https="https://";

    bool right=true;
    for (int i=8; i<site.length(); i++){
        if (site[i]=='/') right=false;       //Здесь проходит проверка на то,
    }                                        //есть ли символ '/' в адресе.
    if (right){
        site.push_back('/');                 //Если нет, то добавляется насильно. Ибо нефиг.
    }

    vector<string> res;
    res.push_back("blablabla");
    res.push_back("\r\n");
    res.push_back("dadadad");
    /*if (site.find(http)!=site.npos) */
    return httpg(site);//return httpg(site); //Узнаем протокол для "общения".
    //else if (site.find(https)!=site.npos) return httpsg(site); //http или https или ничего.
    //else              //Вот тут надо будет что-то сделать. Вызывается если перед строкой
                        //не указан "http://" или "https://" (в большинстве случаев тоесть)
}
