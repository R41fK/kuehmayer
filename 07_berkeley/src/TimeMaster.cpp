#include <iostream>

#include "TimeMaster.h"


using namespace std;

void TimeMaster::operator()(){
    while (1) {
        this_thread::sleep_for(1s);
    }
}

void TimeMaster::set_channel1(Channel* channel){
    this->channel1 = channel;
}

void TimeMaster::set_channel2(Channel* channel){
    this->channel2 = channel;
}