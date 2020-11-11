#include <thread>
#include <iostream>

#include "../include/philospher.h"

using namespace std;

void philospher::operator()(){

    cout << "Philospher " << this->id << " is thinking ...\n" << flush;

    this_thread.sleep(1s);

    cout << "Philospher " << this->id << " attempts to get left fork\n" << flush;

    this->left_fork.lock();

    cout << "Philospher " << this->id << " got get left fork. Now he wants the right one ...\n" << flush;

    this->right_fork.lock();

    this_thread.sleep(2s);

    cout << "Philospher " << this->id << "  finished eating\n" << flush;
}