#include <iostream>
#include "Date.cpp"

int main() {

    Date date;

    cout << "Enter the date: ";
    cin >>  date;

    cout << "You entered the following date:\n" << date;

    cout << "\nDecrementing date: " << --date;
    cout << "\nAgain decrementing: " << --date;
    cout << "\nIncrementing date: " << ++date;
    cout << "\nAgain incrementing: " << ++date << endl;
    return 0;
}