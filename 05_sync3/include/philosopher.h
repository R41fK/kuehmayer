#pragma once

#include <mutex>

class philospher
{
    int id;
    std::mutex& left_fork;
    std::mutex& right_fork;

public:
    philospher(int id, std::mutex& left_fork, std::mutex& right_fork): id(id), left_fork(left_fork), right_fork(right_fork) {};

    void operator()();
};