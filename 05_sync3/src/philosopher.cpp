#include <thread>
#include <iostream>
#include <chrono>
#include <initializer_list>

#include "../include/philosopher.h"

using namespace std;

mutex out_mtx{};

void println(const initializer_list<string>& st){
    out_mtx.lock();
    for(string str : st){
        cout << str << " ";
    }
    cout << endl;
    out_mtx.unlock();
}


void philospher::operator()(){

    println({"Philosopher", to_string(this->id),  "is thinking ..."});

    this_thread::sleep_for(chrono::seconds(1));

    println({"Philosopher", to_string(this->id), "attempts to get left fork"});

    this->left_fork.lock();

    println({"Philosopher", to_string(this->id), "got get left fork. Now he wants the right one ..."});

    this->right_fork.lock();

    this_thread::sleep_for(chrono::seconds(2));

    println({"Philosopher", to_string(this->id), "finished eating"});

    this->left_fork.unlock();
    this->right_fork.unlock();
}