#include <thread>
#include <iostream>
#include <chrono>

#include "../include/philosopher.h"

using namespace std;

void philospher::operator()(){
    string output{"Philosopher " +  to_string(this->id) + " is thinking ...\n"};

    cout << output << flush;

    this_thread::sleep_for(chrono::seconds(1));

    output = "Philosopher " + to_string(this->id) + " attempts to get left fork\n";
    cout << output << flush;

    this->left_fork.lock();

    output = "Philosopher " + to_string(this->id) + " got get left fork. Now he wants the right one ...\n";
    cout << output << flush;

    this->right_fork.lock();

    this_thread::sleep_for(chrono::seconds(2));

    output = "Philosopher " + to_string(this->id) + " finished eating\n";
    cout << output << flush;
}