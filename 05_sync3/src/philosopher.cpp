#include <thread>
#include <iostream>
#include <chrono>
#include <initializer_list>

#include "philosopher.h"
#include "utils.h"

using namespace std;

void philospher::operator()(){
    while (1){
        println("Philosopher", to_string(this->id),  "is thinking ...");

        this_thread::sleep_for(chrono::seconds(1));

        bool got_right_fork{false};

        do {
            println("Philosopher", to_string(this->id), "attempts to get left fork");

            if (this->s) {
                this->s->acquire();
            }
            this->left_fork.lock();

            if (this->s) {
                println("curently", to_string(this->s->avaible_permits()), "left forks available");
            }

            println("Philosopher", to_string(this->id), "got left fork. Now he wants the right one ...");

            this_thread::sleep_for(chrono::seconds(5));

            if (livelock) {
                got_right_fork = this->right_fork.try_lock_for(chrono::seconds(3));

                if (!got_right_fork) {
                    this_thread::sleep_for(chrono::milliseconds(100));

                    this->left_fork.unlock();

                    println("Philosopher", to_string(this->id), "released left fork due to timeout getting the right one!");

                    if (this->s) {
                        this->s->release();
                    }

                    this_thread::sleep_for(chrono::seconds(3));
                }
            } else {
                this->right_fork.lock();
            }
        } while (livelock && !got_right_fork);
        
        this_thread::sleep_for(chrono::seconds(2));

        println("Philosopher", to_string(this->id), "finished eating");

        this->left_fork.unlock();

        println("Philosopher", to_string(this->id), "released left fork");

        this->right_fork.unlock();

        println("Philosopher", to_string(this->id), "released right fork");

        if (this->s) {
            this->s->release();
        }
    }
}