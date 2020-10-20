#pragma once

#include "./WorkPacket.h"

#include <queue>
#include <mutex>

class WorkQueue{

    std::queue<WorkPacket> queue{};
    std::mutex mutex_queue{};

    public:
        void push(WorkPacket packet);
        WorkPacket pop();
};