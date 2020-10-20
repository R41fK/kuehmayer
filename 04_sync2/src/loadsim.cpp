#include "../include/WorkPacket.h"
#include "../include/WorkQueue.h"

#include <iostream>
#include <thread>

using namespace std;

void worker(int id, WorkQueue& queue){
    while (true) {
        string output{"W" + to_string(id) + ": Want work packet\n"};
        cout << output << flush; 
        WorkPacket packet = queue.pop();
        output = "W" + to_string(id) + ": Got work packet " + to_string(packet.getId()) + "\n";
        cout << output << flush; 
        this_thread::sleep_for(chrono::seconds(1));
        output = "W" + to_string(id) + ": Prozessed work packet " + to_string(packet.getId()) + "\n";
        cout << output << flush; 
    }
}



int main() {
    
    WorkQueue queue{};

    thread worker_1{worker, 1, ref(queue)};
    thread worker_2{worker, 2, ref(queue)};

    for (int i=1;; i++) {
        WorkPacket packet{i};
        queue.push(packet);
        string output{"B: Submitted work packet " + to_string(packet.getId()) + "\n"};
        cout << output << flush;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    
    worker_1.join();
    worker_2.join();
}
