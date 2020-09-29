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
        cout << this->brand_and_model << " raced " << ++cntr << " Rounds" << endl;
    }
}