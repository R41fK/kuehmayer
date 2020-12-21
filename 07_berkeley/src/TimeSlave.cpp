#include <iostream>

#include "TimeSlave.h"
#include "Channel.h"

using namespace std;

void TimeSlave::operator()(){
    long value{};
    while (this->channel.get_pipe1() >> value) {
        cout << value << endl;
    }
}


Channel* TimeSlave::get_channel(){
    return &this->channel;
}