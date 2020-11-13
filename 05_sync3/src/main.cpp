#include <thread>
#include <iostream>
#include <mutex>

#include "philosopher.h"
#include "semaphor.h"
#include "CLI11.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    CLI::App app("Dining philosophers simulation");
    
    bool no_deadlock{};
    bool livelock{};

    app.add_flag("-n, --nodeadlock", no_deadlock, "Prevent a deadlock at all");
    app.add_flag("-l, --livelock", livelock, "Simulate a lifelock");

    CLI11_PARSE(app, argc, argv);
    
    mutex fork1{};
    mutex fork2{};
    mutex fork3{};
    mutex fork4{};
    mutex fork5{};

    semaphor sem{4};
    semaphor* s{};

    if (no_deadlock){
       s = &sem;
    }
    
    philospher p1{1, fork1, fork2, s};
    philospher p2{2, fork2, fork3, s};
    philospher p3{3, fork3, fork4, s};
    philospher p4{4, fork4, fork5, s};
    philospher p5{5, fork5, fork1, s};

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
