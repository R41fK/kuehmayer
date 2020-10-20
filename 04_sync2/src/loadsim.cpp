#include "../include/WorkPacket.h"
#include "../include/WorkQueue.h"

#include <iostream>
#include <thread>


using namespace std;

int main() {
    
    WorkQueue queue{};

    for (int i=0;; i++) {
        WorkPacket packet{i};
        queue.push(packet);
        cout << "B: Submitted work packet " << packet.getId() << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    

}
