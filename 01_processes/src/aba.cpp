#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <csignal>


using namespace std;

int main(){
    auto pid{fork()};

    std::chrono::milliseconds sleeptime(500);

    int cntr{};

    if (pid == 0) {
        while (true) {
            cout << "A" << flush;
            std::this_thread::sleep_for(sleeptime);
        }
    } else {
        while (cntr < 6) {
            cout << "B" << flush;
            std::this_thread::sleep_for(sleeptime);
            cntr++;
        }
        kill(pid, SIGKILL);
        cout << endl;
    }

}