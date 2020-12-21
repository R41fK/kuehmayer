#pragma once

#include <thread>

#include "Clock.h"
#include "Channel.h"

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

    void set_channel1(Channel* channel);
    void set_channel2(Channel* channel);
    void operator()();
};