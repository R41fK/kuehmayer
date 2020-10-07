#include "../include/Account.h"

#include <thread>
#include <mutex>

using namespace std;


void Account::deposit(int amount) {
    unique_lock u_lock{this->m};
    this->balance += amount;
}

bool Account::withdraw(int amount) {
    lock_guard guard{this->m};
    if (this->balance - amount >= 0) {
        this_thread::yield();
        this->balance -= amount;
        return true;
    }
    return false;
}

int Account::get_balance() {
    return this->balance;
}
