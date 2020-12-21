#include <thread>

#include "TimeSlave.h"
#include "TimeMaster.h"

using namespace std;

int main() {
    
    TimeSlave s1{"slave1", 0, 0, 0};
    TimeSlave s2{"slave2", 10, 0, 0};
    TimeMaster m1{"master", 30, 0, 0};

    thread t1{ref(s1)};
    thread t2{ref(s2)};
    thread t3{ref(m1)};

    t1.join();
    t2.join();
    t3.join();
}
