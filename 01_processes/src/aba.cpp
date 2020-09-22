#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <csignal>
#include <sys/wait.h>


using namespace std;

void signal_handler(int){
    quick_exit(EXIT_SUCCESS);
}

void children(std::chrono::milliseconds sleeptime){
    while (true) {
        cout << "A" << flush;
        std::this_thread::sleep_for(sleeptime);
        signal(SIGTERM, signal_handler);
    }
}

int main(){
    auto pid{fork()};

    std::chrono::milliseconds sleeptime(500);

    int cntr{};

    if (pid == 0) {
        children(sleeptime);
    } else {
        while (cntr < 6) {
            cout << "B" << flush;
            std::this_thread::sleep_for(sleeptime);
            cntr++;
        }
        int status{};
        kill(pid, SIGTERM);
        waitpid(pid, &status, 0);
        cout << endl;
    }
    sleep(10);

}