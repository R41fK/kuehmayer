#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <csignal>
#include <sys/wait.h>
#include <cerrno>
#include <cstring>


using namespace std;

void signal_handler(int){
    quick_exit(EXIT_SUCCESS);
}

void children(){
    execl("/mnt/Storage/NVSuebungen/kuehmayer/01_processes/build/charout",
            "charout", "r", nullptr);
    
    signal(SIGTERM, signal_handler);
    if (!errno) {
        cerr << strerror(errno) << endl;
        quick_exit(1);
    }
}

int main(){
    auto pid{fork()};

    std::chrono::milliseconds sleeptime(500);

    int cntr{};

    if (pid == 0) {
        children();
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
}