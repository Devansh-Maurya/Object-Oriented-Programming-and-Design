#include <iostream>
#include <cstdio>
#include "StringProcess.cpp"

using namespace std;

int main() {

    string str;
    int maxLength;

    cout << "Enter the maximum word length upto which you want to count: ";
    cin >> maxLength;
    getchar();

    //Create an array by allocating memory dynamically
    int *wordLengths = new int[maxLength + 1];
    for (int i = 0; i <= maxLength; ++i) {
        wordLengths[i] = 0;
    }

    cout << "Enter your text (Enter '$' on a new line to stop):" << endl;

    while (true) {
        //Take a new line as input
        getline(cin, str);

        //While entered string is not equal to '$', keep on reading
        //Check if string is empty or not to handle lines with no characters
        if (!str.empty() && (str.at(0) == '$')) {
            break;
        }

        //Process the newly entered line and count characters in it
        StringProcess::countWordLengths(str, wordLengths, maxLength);
    }

    cout << "Word length" << "\t\t" << "Occurences" << endl << endl;
    for (int i = 1; i <= maxLength; ++i) {
        cout << i << "\t\t:\t" << wordLengths[i] << endl;

    }

    //Free the memory allocated to the array
    delete [] wordLengths;

    return 0;
}