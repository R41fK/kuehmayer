#pragma once

#include <mutex>

#include "semaphor.h"

class philospher
{
    int id;
    std::mutex& left_fork;
    std::mutex& right_fork;
    semaphor* s;

public:
    philospher(int id, std::mutex& left_fork, std::mutex& right_fork, semaphor* s): id(id), left_fork(left_fork), right_fork(right_fork), s{s} {};

    void operator()();
};