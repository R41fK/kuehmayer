#include <iostream>
#include <chrono>

#include "TimeSlave.h"
#include "Channel.h"

using namespace std;

void TimeSlave::operator()(){
    long value{};
    while (this->channel.get_pipe1() >> value) {
        
        this->channel.get_pipe2() << 0;
    }
}


Channel* TimeSlave::get_channel(){
    return &this->channel;
}