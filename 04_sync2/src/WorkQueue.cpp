#include "../include/WorkQueue.h"

using namespace std;

WorkQueue::WorkQueue(size_t size): max_size{size} {}

WorkPacket WorkQueue::pop(){
    unique_lock<mutex> u_lock{this->mutex_queue};
    not_empty.wait(u_lock, [this]{ return this->queue.size();});
    WorkPacket return_value = this->queue.front();
    this->queue.pop();
    empty.notify_one();
    return return_value;
}

void WorkQueue::push(WorkPacket packet){
    unique_lock<mutex> u_lock{this->mutex_queue};
    empty.wait(u_lock, [this]{ return this->queue.size() < this->max_size;});
    this->queue.push(packet);
    this->not_empty.notify_one();
}