//
// Created by devansh on 23/11/18.
//

#include <iostream>
#include <string>

using namespace std;

class Member {

    int id;

public:

    Member(int id, bool throwException = false) {
        this->id = id;

        cout << "Member object " << id << " constructed\n";

        if (throwException) {
            throw id;
        }
    }

    ~Member() {
        cout << "Member object " << id << " destructed\n";
    }
};