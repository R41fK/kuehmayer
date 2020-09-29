#include "../include/Motorcycle.h"

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


Motorcycle::Motorcycle(string brand_and_model){
    this->brand_and_model = brand_and_model;
}

void Motorcycle::operator()(){
    int cntr{};
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cntr++;
        string out{this->brand_and_model + " raced " + to_string(cntr) + " Rounds\n"};
        cout << out << flush;
    }
}