//
// Created by devansh on 23/11/18.
//
#include <iostream>

using namespace std;

class ThrowAny {

public:

    static void showExceptionTypes() {
        cout << "1: int\n" << "2: float\n" << "3: char\n" << "4: const char*\n\n";
    }

    static void throwException(int type) {

        switch (type) {
            case 1:
                cout << "Throwing int exception\n";
                throw 4;
            case 2:
                cout << "Throwing float exception\n";
                throw 4.4;
            case 3:
                cout << "Throwing char exception\n";
                throw '4';
            case 4:
                cout << "Throwing const char* exception\n";
                throw "4";
        }
    }
};