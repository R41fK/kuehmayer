#include "../include/Motorcycle.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <iomanip>
#include <sstream>

using namespace std;


Motorcycle::Motorcycle(string brand_and_model){
    this->brand_and_model = brand_and_model;
}

double Motorcycle::get_total_time(){
    return this->totale_time;
}

void Motorcycle::operator()(int rounds){
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 10};

    ostringstream buf;
    buf << setprecision(2) << fixed;
    for (int cntr{1}; cntr <= rounds; cntr++) {
        double lap_time{dis(gen)};
        this_thread::sleep_for(chrono::milliseconds(int(lap_time * 1000)));

        buf << this->brand_and_model << " raced " << cntr
            << " Rounds, this Round took: " << lap_time << endl;
        string out{buf.str()};
        buf.str("");
        cout << out << flush;

        this->totale_time += lap_time;
    }
}