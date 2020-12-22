#include <thread>
#include <chrono>
#include <iostream>

#include "TimeMaster.h"
#include "pipe.h"


using namespace std;

void TimeMaster::operator()(){
    long val1{0};
    long val2{0};
    long diff{0};
    ostringstream buf{};

    while (this->channel1->get_pipe1() && this->channel1->get_pipe2() &&
           this->channel2->get_pipe1() && this->channel2->get_pipe2()) {
        
        this_thread::sleep_for(chrono::seconds(10));

        buf << this->name << ": Has initiated the time sync\n";
        cout << buf.str() << flush;
        buf.str("");

        this->channel1->get_pipe1() << 0;
        this->channel2->get_pipe1() << 0;

        this->channel1->get_pipe2() >> val1;
        this->channel2->get_pipe2() >> val2;

        diff = (val1 + val2 + this->clock.to_time()) / 3;

        this->clock.from_time(diff);

        buf << this->name << ": Calculated avg: " << diff << ", sent it to the slaves and is correcting its time\n";
        cout << buf.str() << flush;
        buf.str("");

        this->channel1->get_pipe1() << diff;
        this->channel2->get_pipe1() << diff;
    }
    this_thread::sleep_for(chrono::milliseconds(500));
}

void TimeMaster::set_channel1(Channel* channel){
    this->channel1 = channel;
}

void TimeMaster::set_channel2(Channel* channel){
    this->channel2 = channel;
}

void TimeMaster::set_time_monoton(bool set_monoton){
    this->clock.set_time_monoton(set_monoton);
}