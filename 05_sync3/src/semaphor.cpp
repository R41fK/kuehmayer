#include <mutex>

#include "../include/semaphor.h"

using namespace std;

void semaphor::acquire(){
    unique_lock ul{this->mtx};
    this->can_lock.wait(ul, [&](){return this->avaible_permits() > 0;});
    this->cntr--;
}

void semaphor::release(){
    lock_guard lg{this->mtx};
    this->cntr++;
}


int semaphor::avaible_permits(){
    lock_guard lg{this->mtx};
    return this->cntr;
}