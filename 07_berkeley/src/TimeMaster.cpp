#include <iostream>
#include <thread>
#include <chrono>

#include "TimeMaster.h"
#include "pipe.h"


using namespace std;

void TimeMaster::operator()(){
    for (int i=0; i < 3; i++){
        this->channel1->get_pipe1() << 10*i;
        this->channel2->get_pipe1() << 20*i;
    }
    this_thread::sleep_for(chrono::milliseconds(500));
}

void TimeMaster::set_channel1(Channel* channel){
    this->channel1 = channel;
}

void TimeMaster::set_channel2(Channel* channel){
    this->channel2 = channel;
}