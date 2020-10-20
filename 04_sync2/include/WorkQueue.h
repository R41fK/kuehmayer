#pragma once

#include "./WorkPacket.h"

#include <queue>
#include <mutex>
#include <condition_variable>


class WorkQueue{

    std::queue<WorkPacket> queue{};
    std::size_t max_size{};
    std::mutex mutex_queue{};
    std::condition_variable not_empty{};
    std::condition_variable empty{};

    public:
        WorkQueue(size_t size);
        void push(WorkPacket packet);
        WorkPacket pop();
};