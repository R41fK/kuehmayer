#include <thread>
#include <iostream>
#include <chrono>
#include <initializer_list>

#include "philosopher.h"
#include "utils.h"

using namespace std;

void philospher::operator()(){

    println("Philosopher", to_string(this->id),  "is thinking ...");

    this_thread::sleep_for(chrono::seconds(1));

    println("Philosopher", to_string(this->id), "attempts to get left fork");

    if (this->s != nullptr) {
        this->s->acquire();
    }
    this->left_fork.lock();

    println("Philosopher", to_string(this->id), "got get left fork. Now he wants the right one ...");

    this_thread::sleep_for(chrono::seconds(5));

    this->right_fork.lock();

    this_thread::sleep_for(chrono::seconds(2));

    println("Philosopher", to_string(this->id), "finished eating");

    this->left_fork.unlock();
    this->right_fork.unlock();

    if (this->s != nullptr) {
        this->s->release();
    }
}