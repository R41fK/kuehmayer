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
        cerr << "starting charout failed: " << strerror(errno) << endl;
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

            cout << "waiting for 3 seconds" << endl;
            this_thread::sleep_for(sleeptime);

            int status_a{};
            int status_b{};
            cout << endl << "killing both subprocesses with pids " << pid_a << " and " << pid_b << endl;

            kill(pid_a, SIGTERM);
            kill(pid_b, SIGTERM);

            cout << "waiting for both subprocesses to be dead" << endl;
            waitpid(pid_a, &status_a, 0);
            waitpid(pid_b, &status_b, 0);
            cout << "subprocess " << pid_a << " exited with " << WEXITSTATUS(status_a) << endl;
            cout << "subprocess " << pid_b << " exited with " << WEXITSTATUS(status_a) << endl;
        }
    }
}