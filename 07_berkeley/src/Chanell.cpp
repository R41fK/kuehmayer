
#include "pipe.h"
#include "Chanell.h"

Pipe<long>& Chanell::get_pipe1(){
    return this->Pipe1;
}

Pipe<long>& Chanell::get_pipe2(){
    return this->Pipe2;
}