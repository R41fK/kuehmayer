#include <thread>
#include <chrono>

#include "TimeMaster.h"
#include "pipe.h"


using namespace std;

void TimeMaster::operator()(){
    while (this->channel1->get_pipe1() && this->channel1->get_pipe2() &&
           this->channel2->get_pipe1() && this->channel2->get_pipe2()) {
        
        this_thread::sleep_for(chrono::seconds(10));

        this->channel1->get_pipe1() << 0;
        this->channel2->get_pipe1() << 0;
        
    }
    this_thread::sleep_for(chrono::milliseconds(500));
}

void TimeMaster::set_channel1(Channel* channel){
    this->channel1 = channel;
}

void TimeMaster::set_channel2(Channel* channel){
    this->channel2 = channel;
}