#include <iostream>

#include "TimeMaster.h"


using namespace std;

void TimeMaster::operator()(){
    while (1) {
        this_thread::sleep_for(1s);
    }
}