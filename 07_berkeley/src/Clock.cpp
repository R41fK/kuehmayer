#include <chrono>
#include <thread>
#include <iostream>
#include <tuple>

#include "timeutils.h"
#include "Clock.h"

using namespace std;


void Clock::operator()(){
    ostringstream buf{};
    while (1) {
        buf << this->name + ": " << this->curr_time << endl;
        cout << buf.str() << flush;
        this_thread::sleep_for(chrono::seconds(1));
        this->curr_time += 1s;
        buf.str("");
    }
}

void Clock::set_time(int hours, int minutes, int seconds){
    this->curr_time = ::set_time(this->curr_time, hours, minutes, seconds);
}

tuple<int, int, int> Clock::get_time(){
    return ::get_time(this->curr_time);
}

long Clock::to_time(){
    return chrono::system_clock::to_time_t(this->curr_time);
}

void Clock::from_time(long time){
    this->curr_time = chrono::system_clock::from_time_t(time);
}