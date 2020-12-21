#pragma once

#include <thread>

#include "Clock.h"

class TimeSlave
{
private:
    Clock clock;
    std::thread t_clock;
public:
    TimeSlave(std::string name, int hours_, int minutes_, int seconds_):
    clock{Clock(name, hours_, minutes_, seconds_)},
    t_clock(this->clock)
    {};

    ~TimeSlave(){
        t_clock.join();
    };

    void operator()();
};