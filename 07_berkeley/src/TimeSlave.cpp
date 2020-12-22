#include <iostream>
#include <chrono>

#include "TimeSlave.h"
#include "Channel.h"

using namespace std;

void TimeSlave::operator()(){
    long value{};
    while (this->channel.get_pipe1() >> value) {
        this->channel.get_pipe2() << this->clock.to_time();
        this->channel.get_pipe1() >> value;
        this->clock.from_time(value);
    }
}


Channel* TimeSlave::get_channel(){
    return &this->channel;
}