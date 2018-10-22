//
// Created by devansh on 22/10/18.
//

#include "Account.cpp"

class SavingsAccount : public Account {

    double interestRate;

public:

    SavingsAccount(double balance, double interestRate) : Account(balance) {
        this->interestRate = interestRate;
    }

    double calculateInterest() {
        return interestRate*getBalance()/100;
    }
};
