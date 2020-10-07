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

#endif //ACCOUNT_H