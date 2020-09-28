#include <iostream>
#include <thread>
#include <chrono>


using namespace std;

int main(int argc, char** argv) {
    if (argc == 2) {
        const char* env_charout{getenv(argv[1])};

        if (!env_charout) {
            quick_exit(1);
        }

        chrono::milliseconds sleeptime(500);

        while (1) {
            cout << env_charout << flush;
            this_thread::sleep_for(sleeptime);
        }

    }
}
