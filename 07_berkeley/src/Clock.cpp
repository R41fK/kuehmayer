#include <chrono>
#include <thread>
#include <iostream>
#include <tuple>

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

void Clock::set_time(int hours, int minutes, int seconds){
    this->curr_time = ::set_time(this->curr_time, hours, minutes, seconds);
}

tuple<int, int, int> Clock::get_time(){
    return ::get_time(this->curr_time);
}