#include <iostream>

#include "TimeSlave.h"
#include "Channel.h"

using namespace std;

void TimeSlave::operator()(){
    while (1) {
        this_thread::sleep_for(1s);
    }
}


Channel* TimeSlave::get_channel(){
    return &this->channel;
}