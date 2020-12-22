
#include "pipe.h"
#include "Channel.h"

Pipe<long>& Channel::get_pipe1(){
    return this->Pipe1;
}

Pipe<long>& Channel::get_pipe2(){
    return this->Pipe2;
}

void Channel::set_latency(long latency){
    this->Pipe1.set_latency(latency);
    this->Pipe2.set_latency(latency);
}