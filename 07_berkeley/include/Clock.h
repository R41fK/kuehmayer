#pragma once

#include <chrono>
#include <tuple>

#include "timeutils.h"

class Clock
{
private:
    std::string name{};
    std::chrono::time_point<std::chrono::system_clock> curr_time{};
    long right_time{};
    int sleep_time{0};
    bool is_monoton{false};
    bool is_right{true};
public:
    Clock(std::string name): 
    name{name},
    curr_time{std::chrono::system_clock::now()}
    {};

    Clock(std::string name, int hours_, int minutes_, int seconds_, int deviation):
    name{name},
    curr_time{std::chrono::system_clock::now()},
    sleep_time{1000 + deviation}
    {
        curr_time = ::set_time(curr_time, hours_, minutes_, seconds_);
    };

    void set_time(int hours, int minutes, int seconds);
    std::tuple<int, int, int> get_time();
    long to_time();
    void from_time(long time);
    void set_time_monoton(bool set_monoton);

    void operator()();
};