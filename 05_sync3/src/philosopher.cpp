#include <thread>
#include <iostream>
#include <chrono>
#include <vector>

#include "../include/philosopher.h"

using namespace std;

mutex out_mtx{};

void println(const vector<string>& st){
    out_mtx.lock();
    for(string str : st){
        cout << str << " ";
    }
    cout << endl;
    out_mtx.unlock();
}


void philospher::operator()(){
    vector<string> output{"Philosopher", to_string(this->id),  "is thinking ..."};

    println(output);

    this_thread::sleep_for(chrono::seconds(1));

    output = {"Philosopher", to_string(this->id), "attempts to get left fork"};
    println(output);

    this->left_fork.lock();

    output = {"Philosopher", to_string(this->id), "got get left fork. Now he wants the right one ..."};
    println(output);

    this->right_fork.lock();

    this_thread::sleep_for(chrono::seconds(2));

    output = {"Philosopher", to_string(this->id), "finished eating"};
    println(output);

    this->left_fork.unlock();
    this->right_fork.unlock();
}