#include <iostream>

#include "TimeSlave.h"
#include "Chanell.h"

using namespace std;

void TimeSlave::operator()(){
    while (1) {
        this_thread::sleep_for(1s);
    }
}


Chanell* TimeSlave::get_chanell(){
    return &this->chanell;
}