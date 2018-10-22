#include <iostream>
#include <string>
#include "StringProcess.cpp"

using namespace std;

#define TOTAL_CHAR 26

int main() {

    string str;
    //It will keep the number of occurences of each character
    int characters[TOTAL_CHAR] = {0};

    cout << "Enter your text (Enter '$' on a new line to stop):" << endl;

    while (true) {
        //Take a new line as input
        getline(cin, str);

        //While entered string is not equal to '$', keep on reading
        //Check if string is empty or not to handle lines with no characters
        if ( !str.empty() && (str.at(0) == '$')) {
            break;
        }

        //Process the newly entered line and count characters in it
        StringProcess::countChar(str, characters);
    }

    cout << "Character count:" << endl << endl;
    for (int i = 0; i < TOTAL_CHAR; ++i) {
        if (characters[i]) {
            char ch = i + 97;
            cout << ch << "\t:\t" << characters[i] << endl;
        }
    }

    return 0;
}