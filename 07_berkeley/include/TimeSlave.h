#pragma once

#include <thread>

#include "Clock.h"
#include "Channel.h"

class TimeSlave
{
private:
    Clock clock;
    std::thread t_clock;
    Channel channel;
    std::string name;
public:
    TimeSlave(std::string name, int hours_, int minutes_, int seconds_, int deviation):
    clock{Clock(name, hours_, minutes_, seconds_, deviation)},
    t_clock(std::ref(this->clock)),
    name{name}
    {};

    ~TimeSlave(){
        t_clock.join();
    };

    void operator()();
    Channel* get_channel();
    void set_time_monoton(bool set_monoton);
};