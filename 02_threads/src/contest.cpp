#include "../include/Motorcycle.h"

#include <iostream>
#include <thread>
#include <chrono>


//Bimota Tesi H2

using namespace std;



void bimota_tesi_h2() {
    int cntr{};
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Bimota Tesi H2 raced " << ++cntr << " Rounds" << endl;
    }
}


int main() {
    Motorcycle ninja_h2("Kawasaki Ninja H2");

    thread racer_1{bimota_tesi_h2};
    thread racer_2{ninja_h2};

    racer_1.join();
    racer_2.join();
}
