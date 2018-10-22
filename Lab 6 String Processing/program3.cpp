#include <iostream>
#include <string>
#include "StringProcess.cpp"

using namespace std;

#define TOTAL_CHAR 26

int main() {

    string str;

    cout << "Enter the date (m[m]/d[d]/yyyy): ";
    cin >> str;
    cout << "Formatted date: " << StringProcess::dateFormat(str) << endl;

    return 0;
}