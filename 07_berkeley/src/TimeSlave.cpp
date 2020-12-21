#include <iostream>

#include "TimeSlave.h"


using namespace std;

void TimeSlave::operator()(){
    while (1) {
        this_thread::sleep_for(1s);
    }
}