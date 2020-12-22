#include <iostream>
#include <chrono>

#include "TimeSlave.h"
#include "Channel.h"

using namespace std;

void TimeSlave::operator()(){
    long value{};
    ostringstream buf{};

    while (this->channel.get_pipe1() >> value) {
        this->channel.get_pipe2() << this->clock.to_time();
        
        buf << this->name << ": Sent his time: " << this->clock.to_time() << "\n";
        cout << buf.str() << flush;
        buf.str("");

        this->channel.get_pipe1() >> value;
        this->clock.from_time(value);

        buf << this->name << ": Is correcting his time\n";
        cout << buf.str() << flush;
        buf.str("");
    }
}


Channel* TimeSlave::get_channel(){
    return &this->channel;
}

void TimeSlave::set_time_monoton(bool set_monoton){
    this->clock.set_time_monoton(set_monoton);
}