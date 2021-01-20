#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/bundled/color.h"
#include "asio.hpp"
#include "CLI11.hpp"

using namespace asio;
using namespace std;

int main(int argc, char** argv) {
    
    // spdlog::info(fmt::format(
    //             fg(fmt::color::linen), 
    //             "Hello world in linen."));

    CLI::App app("client");

    CLI11_PARSE(app, argc, argv);

    ip::tcp::iostream strm{"localhost", "1113"};

    if (strm) { 
        string data;
        getline(strm, data);
        cout << data << endl;
        strm.close();
    } else { 
        cout << "no connection" << endl; 
    } 


}
