#include <thread>
#include <iostream>
#include <chrono>
#include <initializer_list>

#include "../include/philosopher.h"

using namespace std;

recursive_mutex out_mtx;


void println() {
    lock_guard<recursive_mutex> lg{out_mtx};
    cout << endl;
}


template<typename T, typename... Rest>
    void println(const T& word, const Rest&... rest) {
    lock_guard<recursive_mutex> lg{out_mtx};
    cout << word << ' ';
    println(rest...);
}



void philospher::operator()(){

    println("Philosopher", to_string(this->id),  "is thinking ...");

    this_thread::sleep_for(chrono::seconds(1));

    println("Philosopher", to_string(this->id), "attempts to get left fork");

    this->left_fork.lock();

    println("Philosopher", to_string(this->id), "got get left fork. Now he wants the right one ...");

    this_thread::sleep_for(chrono::seconds(5));

    this->right_fork.lock();

    this_thread::sleep_for(chrono::seconds(2));

    println("Philosopher", to_string(this->id), "finished eating");

    this->left_fork.unlock();
    this->right_fork.unlock();
}