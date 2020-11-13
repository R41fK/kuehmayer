#pragma once

#include <mutex>
#include <condition_variable>

class semaphor
{
    std::mutex mtx{};
    std::condition_variable can_lock{};
    int cntr{};

public:
    void acquire();
    void release();
    int avaible_permits();

    semaphor(int cntr): cntr{cntr} {};
    semaphor(): cntr{0} {};
};