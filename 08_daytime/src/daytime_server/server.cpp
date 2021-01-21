#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/bundled/color.h"
#include "asio.hpp"
#include "CLI11.hpp"
#include "timeutils.h"

using namespace asio;
using namespace std;

int main(int argc, char** argv) {
    
    // spdlog::info(fmt::format(
    //             fg(fmt::color::magenta), 
    //             "Hello world in magenta."));

    short unsigned int port{1113};

    CLI::App app("client");

    app.add_option("-p", port, "server port", true);

    CLI11_PARSE(app, argc, argv);

    asio::io_context ctx;
    ip::tcp::endpoint ep{ip::tcp::v4(), port};
    ip::tcp::acceptor acceptor{ctx, ep};

    try {
        while (1) {
            acceptor.listen();
            
            ip::tcp::iostream strm{acceptor.accept()};

            strm << asio::chrono::system_clock::now();
            
            strm.close();
        }
    } catch (asio::system_error& e) {
        spdlog::error(fmt::format(fg(fmt::color::red), e.what())); 
    }
}
