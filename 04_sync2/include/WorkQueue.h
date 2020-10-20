#pragma once

#include "./WorkPacket.h"

#include <queue>
#include <mutex>
#include <condition_variable>


class WorkQueue{

    std::queue<WorkPacket> queue{};
    std::mutex mutex_queue{};
    std::condition_variable not_empty{};

    public:
        void push(WorkPacket packet);
        WorkPacket pop();
};