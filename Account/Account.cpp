//
// Created by devansh on 22/10/18.
//

#include <iostream>

using namespace std;

class Account {

    double balance;

public:

    Account(double accountBalance) : balance(accountBalance) {}

    virtual void credit(double amount) {
        balance += amount;
    }

    virtual void debit(double amount) {
        if ((balance - amount) < 0)
            cout << "Debit amount exceeded account balance\n";
        else
            balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

    void setBalance(double balance) {
        this->balance = balance;
    }
};