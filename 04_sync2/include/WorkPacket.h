#pragma once

#include <mutex>

class WorkPacket{
    const int id{};

    public:
        WorkPacket(int id): id{id} {};

        int getId() const {
            return id;
        }

};