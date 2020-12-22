#pragma once

#include <thread>

#include "Clock.h"
#include "Channel.h"

class TimeMaster
{
private:
    Clock clock;
    std::thread t_clock;
    Channel* channel1;
    Channel* channel2;
public:
    TimeMaster(std::string name, int hours_, int minutes_, int seconds_):
    clock{Clock(name, hours_, minutes_, seconds_)},
    t_clock(std::ref(this->clock))
    {};

    ~TimeMaster(){
        t_clock.join();
    };

    void set_channel1(Channel* channel);
    void set_channel2(Channel* channel);
    void operator()();
};