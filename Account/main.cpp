#include <iostream>
#include "CheckingAccount.cpp"

using namespace std;

int main() {

    double balance, interestRate, transactionFee, transaction;

    cout << "Enter the account balance: ";
    cin >> balance;

    cout << "Enter the interest rate: ";
    cin >> interestRate;

    cout << "Enter the transaction fee: ";
    cin >> transactionFee;

    Account account(balance);
    SavingsAccount savingsAccount(balance, interestRate);
    CheckingAccount checkingAccount(balance, transactionFee);

    ////////////////////////////////////////////////////////////////

    cout << "\n\nDealing with the Account class: \n\n";
    cout << "Current balance: " << account.getBalance();

    cout << "\nEnter debit amount: ";
    cin >> transaction;
    account.debit(transaction);
    cout << "Account balance after debit: " << account.getBalance();

    cout << "\nEnter the credit amount: ";
    cin >> transaction;
    account.credit(transaction);
    cout << "Account balance after credit: " << account.getBalance();

    /////////////////////////////////////////////////////////////////

    cout << "\n\nDealing with the SavingsAccount class:\n\n";
    cout << "Current balance: " << savingsAccount.getBalance();

    cout << "\nInterest: " << savingsAccount.calculateInterest();

    cout << "\nAmount after adding interest: ";
    savingsAccount.setBalance(savingsAccount.getBalance() +
                              savingsAccount.calculateInterest());
    cout << savingsAccount.getBalance();

    /////////////////////////////////////////////////////////////////

    cout << "\n\nDealing with the  CheckingAccount class: \n\n";
    cout << "Current balance: " << checkingAccount.getBalance();

    cout << "\nEnter debit amount: ";
    cin >> transaction;
    checkingAccount.debit(transaction);
    cout << "Account balance after debit: " << checkingAccount.getBalance();

    cout << "\nEnter the credit amount: ";
    cin >> transaction;
    checkingAccount.credit(transaction);
    cout << "Account balance after credit: " << checkingAccount.getBalance();


    return 0;
}