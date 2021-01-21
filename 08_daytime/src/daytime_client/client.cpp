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

    unsigned int port{1113};

    CLI::App app("client");

    app.add_option("-p", port, "port to connect to", true);

    CLI11_PARSE(app, argc, argv);

    spdlog::set_pattern("[%^%l%$] %v");

    ip::tcp::iostream strm{"localhost", to_string(port)};

    strm.expires_after(10s);

    try {
        if (strm) { 
            string data;
            getline(strm, data);
            
            if (strm) {
                cout << data << endl;
            } else {
            spdlog::error(fmt::format(fg(fmt::color::red), strm.error().message()));
            }

            strm.close();
        } else { 
            cerr << "Could not connect to server!" << endl;
            spdlog::error(fmt::format(fg(fmt::color::red), strm.error().message()));
        } 
    } catch (asio::system_error& e) {
        spdlog::error(fmt::format(fg(fmt::color::red), e.what())); 
    }
}
