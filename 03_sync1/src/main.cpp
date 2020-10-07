#include "../include/Account.h"
#include "../include/CLI11.hpp"

#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char* argv[]) {
    
    Account my_bank_account;

    // Punkt 1
    // my_bank_account.deposit(15);

    // cout << "my new Account balance is: " << my_bank_account.get_balance() << endl;

    // cout << (my_bank_account.withdraw(6) ? "Money was withdrawn" : "Money was not withdrawn") 
    //     << " new Balance is: " << my_bank_account.get_balance() << endl;

    // cout << (my_bank_account.withdraw(10) ? "Money was withdrawn" : "Money was not withdrawn") 
    //     << " new Balance is: " << my_bank_account.get_balance() << endl;

    // Punkt 5
    // my_bank_account.deposit(1);

    // thread first{[&](){
    //     my_bank_account.withdraw(1);
    // }};

    // thread second{[&](){
    //     my_bank_account.withdraw(1);
    // }};

    // first.join();
    // second.join();

    // cout << "new Account balance is: " << my_bank_account.get_balance() << endl;


    CLI::App app("Account app");
    
    int balance{0};
    app.add_option("balance", balance, "Initial balance")->required();
    
    int deposits{5};
    app.add_option("-d,--deposits", deposits, "Number of deposits", true);


    CLI11_PARSE(app, argc, argv);

    my_bank_account.deposit(balance);

    Depositor depositor_1(ref(my_bank_account), deposits);
    Depositor depositor_2(ref(my_bank_account), deposits);

    thread first{depositor_1};
    thread second{depositor_2};

    first.join();
    second.join();

    cout << "new Account balance is: " << my_bank_account.get_balance() << endl;
}
