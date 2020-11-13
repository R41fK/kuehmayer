#pragma once

#include <mutex>

#include "semaphor.h"

class philospher
{
    int id;
    std::timed_mutex& left_fork;
    std::timed_mutex& right_fork;
    semaphor* s;
    bool& livelock;

public:
    philospher(int id, std::timed_mutex& left_fork, std::timed_mutex& right_fork, semaphor* s, bool& livelock): 
        id(id), 
        left_fork(left_fork), 
        right_fork(right_fork), 
        s{s},
        livelock{livelock} 
        {};

    void operator()();
};