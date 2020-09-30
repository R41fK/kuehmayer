#include "../include/Motorcycle.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <iomanip>
#include <sstream>


//Bimota Tesi H2

using namespace std;



void bimota_tesi_h2(double& total_time, int rounds) {
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 10};

    ostringstream buf;
    buf << setprecision(2) << fixed;
    
    for (int cntr{1}; cntr <= rounds; cntr++) {
        double lap_time{dis(gen)};
        total_time += lap_time;

        this_thread::sleep_for(chrono::milliseconds(int(lap_time * 1000)));

        buf << "Bimota Tesi H2 raced " << cntr
            << " Rounds, this Round took: " << lap_time << endl;
        string out{buf.str()};
        buf.str("");

        cout << out << flush;
    }
}

void error(string msg="") {
    if (msg != "") {
        cerr << msg << endl;
    } 

    cerr << "Run with --help for more information" << endl;
}

void help() {
    cout << "Usage: contest [-h | --help | LAPS]" << endl;
}
    

void race(int rounds) {
    string name_ninja_h2{"Kawasaki Ninja H2"};
    Motorcycle ninja_h2(name_ninja_h2);

    double total_time_bimota_tesi{0};

    thread racer_1{bimota_tesi_h2, ref(total_time_bimota_tesi), rounds};
    thread racer_2{ref(ninja_h2), rounds};

    racer_1.join();
    racer_2.join();

    ostringstream buf;
    buf << setprecision(2) << fixed;

    if (total_time_bimota_tesi < ninja_h2.get_total_time()) {
        buf << "Winner is Racer_1: Bimota Tesi H2 took a total time of: " << total_time_bimota_tesi << "s" << endl;
        cout << buf.str();
        buf.str("");
        buf << "Loser is Racer_2: " << name_ninja_h2 << " took a total time of: " << ninja_h2.get_total_time() << "s" << endl;
        cout << buf.str();
    } else {
        buf << "Winner is Racer_2: " << name_ninja_h2 << " took a total time of: " << ninja_h2.get_total_time() << "s" << endl;
        cout << buf.str();
        buf.str("");
        buf << "Loser is Racer_1: Bimota Tesi H2 took a total time of: " << total_time_bimota_tesi << "s" << endl;
        cout << buf.str();
    }
}


int main(int argc, char* argv[]) {
    
    if (argc == 2) {
        string argument{argv[1]};
        if (argument == "-h" || argument == "--help") {
            help();
        } else {
            try{
                size_t pos{};
                int rounds{stoi(argument, &pos)};

                if (pos != argument.size()) {
                    throw exception();
                }

                if (rounds > 0 && rounds < 16) {
                    race(rounds);
                } else {
                    error("Out of range (1 <= LAP'S < 16): " + argument);
                }
            } catch (...) {
                error("Could not convert: " + argument);
            }
        }

    } else if (argc == 1) {
        race(10);
    } else {
        error();
    }
    quick_exit(1);
}
