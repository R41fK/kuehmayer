#include <chrono>
#include <thread>
#include <iostream>

#include "timeutils.h"
#include "Clock.h"

using namespace std;


void Clock::operator()(){
    while (1) {

        cout << this->curr_time << endl;
        this_thread::sleep_for(chrono::seconds(1));
        this->curr_time += 1s;
    }
}
