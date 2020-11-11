#include <thread>
#include <iostream>
#include <mutex>

#include "../include/philosopher.h"

using namespace std;

int main() {
    
    mutex fork1{};
    mutex fork2{};
    mutex fork3{};
    mutex fork4{};
    mutex fork5{};

    philospher p1{1, fork1, fork2};
    philospher p2{2, fork2, fork3};
    philospher p3{3, fork3, fork4};
    philospher p4{4, fork4, fork5};
    philospher p5{5, fork5, fork1};

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
