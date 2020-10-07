#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{

    int balance{};

    public:
        int get_balance();
        void deposit(int amount);
        bool withdraw(int amount);

};

#endif //ACCOUNT_H