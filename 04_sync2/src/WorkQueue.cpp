#include "../include/WorkQueue.h"

using namespace std;

WorkPacket WorkQueue::pop(){
    unique_lock<mutex> u_lock{this->mutex_queue};
    not_empty.wait(u_lock, [this]{ return this->queue.size();});
    WorkPacket return_value = this->queue.front();
    this->queue.pop();
    return return_value;
}

void WorkQueue::push(WorkPacket packet){
    lock_guard<mutex> guard{this->mutex_queue};
    this->queue.push(packet);
    this->not_empty.notify_one();
}