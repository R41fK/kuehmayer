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

void children(string out){
    execl("/mnt/Storage/NVSuebungen/kuehmayer/01_processes/build/charout",
            "charout", out.c_str(), nullptr);
    
    signal(SIGTERM, signal_handler);
    if (errno) {
        cerr << strerror(errno) << endl;
        quick_exit(1);
    }
}

int main(){
    auto pid_a{fork()};

    chrono::milliseconds sleeptime(3000);

    if (pid_a == 0) {
        children("ABA_LETTER_A");
    } else {

        auto pid_b{fork()};
        
        if (pid_b == 0) {
            children("ABA_LETTER_B");
        } else {

            this_thread::sleep_for(sleeptime);

            int status_a{};
            int status_b{};
            kill(pid_a, SIGTERM);
            kill(pid_b, SIGTERM);
            waitpid(pid_a, &status_a, 0);
            waitpid(pid_b, &status_b, 0);
            cout << endl;
        }
    }
}