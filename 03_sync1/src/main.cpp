#include "../include/Account.h"

#include <iostream>
#include <thread>

using namespace std;

int main() {
    
    Account my_bank_account;

    // Punkt 1
    // my_bank_account.deposit(15);

    // cout << "my new Account balance is: " << my_bank_account.get_balance() << endl;

    // cout << (my_bank_account.withdraw(6) ? "Money was withdrawn" : "Money was not withdrawn") 
    //     << " new Balance is: " << my_bank_account.get_balance() << endl;

    // cout << (my_bank_account.withdraw(10) ? "Money was withdrawn" : "Money was not withdrawn") 
    //     << " new Balance is: " << my_bank_account.get_balance() << endl;

    my_bank_account.deposit(1);

    thread first{[&](){
        my_bank_account.withdraw(1);
    }};

    thread second{[&](){
        my_bank_account.withdraw(1);
    }};

    first.join();
    second.join();

    cout << "new Account balance is: " << my_bank_account.get_balance() << endl;
}
