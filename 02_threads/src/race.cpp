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
    thread t{bimota_tesi_h2};

    t.join();
}
