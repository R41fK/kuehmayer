#include <iostream>
#include <thread>
#include <chrono>


using namespace std;

int main(int argc, char** argv) {
    if (argc == 2) {
        char charout = argv[1][0];

        std::chrono::milliseconds sleeptime(500);

        while (1) {
            cout << charout << flush;
            std::this_thread::sleep_for(sleeptime);
        }

    }
}
