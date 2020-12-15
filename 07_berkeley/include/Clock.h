#pragma once

#include <chrono>

class Clock
{
private:
    std::string name{};
    std::chrono::time_point<std::chrono::system_clock> curr_time{};

public:
    Clock(std::string name): 
    name{name},
    curr_time{std::chrono::system_clock::now()}
    {}
    ;
   
   void operator()();
};