
#include "pipe.h"
#include "Channel.h"

Pipe<long>& Channel::get_pipe1(){
    return this->Pipe1;
}

Pipe<long>& Channel::get_pipe2(){
    return this->Pipe2;
}