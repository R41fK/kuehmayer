#include "../include/Motorcycle.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <iomanip>
#include <sstream>


//Bimota Tesi H2

using namespace std;



void bimota_tesi_h2() {
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 10};

    ostringstream buf;
    buf << setprecision(2) << fixed;
    int cntr{};
    while (true) {
        double lap_time{dis(gen)};
        this_thread::sleep_for(chrono::milliseconds(int(lap_time * 1000)));

        buf << "Bimota Tesi H2 raced " << ++cntr
            << " Rounds, this Round took: " << lap_time << endl;
        string out{buf.str()};
        buf.str("");

        cout << out << flush;
    }
}


int main() {
    Motorcycle ninja_h2("Kawasaki Ninja H2");

    thread racer_1{bimota_tesi_h2};
    thread racer_2{ninja_h2};

    racer_1.join();
    racer_2.join();
}
