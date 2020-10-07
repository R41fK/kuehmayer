#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <mutex>

class Account{

    int balance{};
    std::mutex m{};

    public:
        int get_balance();
        void deposit(int amount);
        bool withdraw(int amount);

};


class Depositor{

    Account& bank_account;
    int deposites{};

    public:
        Depositor(Account& bank_account, int deposites):
            bank_account(bank_account), 
            deposites(deposites)
            {}
        ;

        void operator()(){
            for(int i=0; i < 5; i++) {
                this->bank_account.deposit(1);
            }
        };
};

#endif //ACCOUNT_H