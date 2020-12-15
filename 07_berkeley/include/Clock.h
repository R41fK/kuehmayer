#pragma once

#include <chrono>

#include "timeutils.h"

class Clock
{
private:
    std::string name{};
    std::chrono::time_point<std::chrono::system_clock> curr_time{};

public:
    Clock(std::string name): 
    name{name},
    curr_time{std::chrono::system_clock::now()}
    {};

    Clock(std::string name, int hours_, int minutes_, int seconds_):
    name{name},
    curr_time{set_time(curr_time, hours_, minutes_, seconds_)}
    {};

   
   void operator()();
};