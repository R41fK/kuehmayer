#include <thread>

#include "Clock.h"

using namespace std;

int main() {
    
    Clock clock{"TestClock"};
    thread t{clock};

    t.join();
}
