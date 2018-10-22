//
// Created by devansh on 22/10/18.
//

#include "SavingsAccount.cpp"

class CheckingAccount : public Account {

    double feePerTransaction;

public:

    CheckingAccount(double accountBalance, double feePerTransaction)
                    : Account(accountBalance), feePerTransaction(feePerTransaction) {}


    void credit(double amount) override {
        Account::credit(amount);
        setBalance(getBalance() - feePerTransaction);
    }

    void debit(double amount) override {
        double balance = getBalance();
        Account::debit(amount);

        //Charge transaction fee if money has actually been withdrawn
        if (balance != getBalance())
            setBalance(getBalance() - feePerTransaction);
    }
};
