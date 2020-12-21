#pragma once

#include <thread>

#include "Clock.h"

class TimeMaster
{
private:
    Clock clock;
    std::thread t_clock;
public:
    TimeMaster(std::string name, int hours_, int minutes_, int seconds_):
    clock{Clock(name, hours_, minutes_, seconds_)},
    t_clock(this->clock)
    {};

    ~TimeMaster(){
        t_clock.join();
    };

    void operator()();
};