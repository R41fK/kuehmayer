#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>


using namespace std;

int main(){
    auto pid{fork()};

    std::chrono::milliseconds sleeptime(500);

    if (pid == 0) {
        while (true) {
            cout << "A" << flush;
            std::this_thread::sleep_for(sleeptime);
        }
    } else {
        while (true) {
            cout << "B" << flush;
            std::this_thread::sleep_for(sleeptime);
        }
    }

}