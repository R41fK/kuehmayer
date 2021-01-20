#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/bundled/color.h"
#include "asio.hpp"
#include "CLI11.hpp"
#include "timeutils.h"

using namespace asio;
using namespace std;

int main() {
    
    // spdlog::info(fmt::format(
    //             fg(fmt::color::magenta), 
    //             "Hello world in magenta."));

    asio::io_context ctx;
    ip::tcp::endpoint ep{ip::tcp::v4(), 1113};
    ip::tcp::acceptor acceptor{ctx, ep}; 
    while (1) {
        acceptor.listen();
        
        ip::tcp::iostream strm{acceptor.accept()};

        string data;

        strm << asio::chrono::system_clock::now();    
        strm.close();
    }
}
