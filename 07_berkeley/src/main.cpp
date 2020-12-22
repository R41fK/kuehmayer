#include <thread>

#include "CLI11.hpp"
#include "TimeSlave.h"
#include "TimeMaster.h"

using namespace std;

int main(int argc, char** argv) {
    bool set_monoton{false};
    unsigned long latency1{0};
    unsigned long latency2{0};
    int deviation1{0};
    int deviation2{0};
    int deviationm{0};
    
    CLI::App app("berkeley");

    app.add_flag("--monotone", set_monoton, "set monotone mode");

    app.add_option("--latency1", latency1, "latency to channel 1 (both directions)");
    app.add_option("--latency2", latency2, "latency to channel 2 (both directions)");

    app.add_option("--deviation1", deviation1, "deviation of clock of slave 1");
    app.add_option("--deviation2", deviation2, "deviation of clock of slave 2");
    app.add_option("--deviationm", deviationm, "deviation of clock of master");

    CLI11_PARSE(app, argc, argv);

    TimeSlave s1{"slave1", 0, 0, 0, deviation1};
    TimeSlave s2{"slave2", 0, 5, 0, deviation2};
    TimeMaster m1{"master", 0, -6, 0, deviationm};

    s1.get_channel()->set_latency(latency1);
    s2.get_channel()->set_latency(latency2);

    s1.set_time_monoton(set_monoton);
    s2.set_time_monoton(set_monoton);
    m1.set_time_monoton(set_monoton);

    m1.set_channel1(s1.get_channel());
    m1.set_channel2(s2.get_channel());

    thread t1{ref(s1)};
    thread t2{ref(s2)};
    thread t3{ref(m1)};

    t1.join();
    t2.join();
    t3.join();
}
