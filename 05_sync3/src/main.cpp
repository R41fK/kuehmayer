#include <thread>
#include <iostream>
#include <mutex>

#include "philosopher.h"
#include "semaphor.h"
#include "CLI11.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    CLI::App app("Dining philosophers simulation");
    
    bool no_deadlock{false};
    bool livelock{false};

    app.add_flag("-n, --nodeadlock", no_deadlock, "Prevent a deadlock at all");
    app.add_flag("-l, --livelock", livelock, "Simulate a lifelock");

    CLI11_PARSE(app, argc, argv);
    
    timed_mutex fork1{};
    timed_mutex fork2{};
    timed_mutex fork3{};
    timed_mutex fork4{};
    timed_mutex fork5{};

    semaphor sem{4};
    semaphor* s{nullptr};

    if (no_deadlock){
       s = &sem;
    }
    
    philospher p1{1, fork1, fork2, s, livelock};
    philospher p2{2, fork2, fork3, s, livelock};
    philospher p3{3, fork3, fork4, s, livelock};
    philospher p4{4, fork4, fork5, s, livelock};
    philospher p5{5, fork5, fork1, s, livelock};

    thread t1{p1};
    thread t2{p2};
    thread t3{p3};
    thread t4{p4};
    thread t5{p5};

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}
