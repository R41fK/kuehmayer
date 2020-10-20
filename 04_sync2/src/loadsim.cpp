#include "../include/WorkPacket.h"
#include "../include/WorkQueue.h"

#include <iostream>
#include <thread>
#include <random>
#include <sstream>
#include <iomanip>

using namespace std;

void worker(int id, WorkQueue& queue){
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 10};

    ostringstream buf;
    buf << setprecision(2) << fixed;

    while (true) {
        double work_time{dis(gen)};

        string output{"W" + to_string(id) + ": Want work packet\n"};
        cout << output << flush; 
        WorkPacket packet = queue.pop();
        
        output = "W" + to_string(id) + ": Got work packet " + to_string(packet.getId()) + "\n";
        cout << output << flush; 

        this_thread::sleep_for(chrono::milliseconds(int(work_time * 1000)));
        buf << "W" << id << ": Prozessed work packet " << packet.getId() << " (" << work_time << "s)\n";
        output = buf.str();
        cout << output << flush; 
        buf.str("");
    }
}



int main() {
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{0, 1};
    
    WorkQueue queue{};

    thread worker_1{worker, 1, ref(queue)};
    thread worker_2{worker, 2, ref(queue)};
    thread worker_3{worker, 3, ref(queue)};

    ostringstream buf;
    buf << setprecision(2) << fixed;

    for (int i=1;; i++) {
        double work_time{dis(gen)};

        WorkPacket packet{i};
        string output{"B: Waiting to submit work packet " + to_string(packet.getId()) + "\n"};
        cout << output << flush;

        this_thread::sleep_for(chrono::milliseconds(int(work_time * 1000)));
        queue.push(packet);
        buf << "B: Submitted work packet " << packet.getId() << " (" << work_time << "s)\n";
        output = buf.str();
        cout << output << flush;
        buf.str("");
    }
    
    worker_1.join();
    worker_2.join();
    worker_3.join();
}
