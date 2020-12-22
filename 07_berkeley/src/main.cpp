#include <thread>

#include "TimeSlave.h"
#include "TimeMaster.h"

using namespace std;

int main() {
    
    TimeSlave s1{"slave1", 0, 0, 0};
    TimeSlave s2{"slave2", 30, 0, 0};
    TimeMaster m1{"master", 10, 0, 0};

    m1.set_channel1(s1.get_channel());
    m1.set_channel2(s2.get_channel());

    thread t1{ref(s1)};
    thread t2{ref(s2)};
    thread t3{ref(m1)};

    t1.join();
    t2.join();
    t3.join();
}
