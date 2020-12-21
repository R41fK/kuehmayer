#pragma once

#include "pipe.h"

class Chanell
{
private:
    Pipe<long> Pipe1{};
    Pipe<long> Pipe2{};
public:
    Pipe<long>& get_pipe1();
    Pipe<long>& get_pipe2();
};