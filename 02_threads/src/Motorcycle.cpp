#include "../include/Motorcycle.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <random>

using namespace std;


Motorcycle::Motorcycle(string brand_and_model){
    this->brand_and_model = brand_and_model;
}

void Motorcycle::operator()(){
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 10};

    int cntr{};
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(int(dis(gen) * 1000)));
        string out{this->brand_and_model + " raced " + to_string(++cntr) + " Rounds\n"};
        cout << out << flush;
    }
}