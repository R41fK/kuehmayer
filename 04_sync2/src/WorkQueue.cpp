#include "../include/WorkQueue.h"

using namespace std;

WorkPacket WorkQueue::pop(){
    lock_guard<mutex> guard{this->mutex_queue};
    WorkPacket return_value = this->queue.front();
    this->queue.pop();
    return return_value;
}

void WorkQueue::push(WorkPacket packet){
    lock_guard<mutex> guard{this->mutex_queue};
    this->queue.push(packet);
}