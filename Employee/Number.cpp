//
// Created by user on 11/6/18.
//
#include <iostream>

using namespace std;

class Number {

    unsigned long long mobile;
    int areaCode;
    int landline;

public:

    unsigned long long getMobileNumber() const {
        return mobile;
    }

    void setMobile(unsigned long long mobile) {
        if (mobile > 0)
            Number::mobile = mobile;
    }

    int getAreaCode() const {
        if (areaCode > 0)
            return areaCode;
    }

    void setAreaCode(int areaCode) {
        this->areaCode = areaCode;
    }

    int getLandline() const {
        return landline;
    }

    void setLandline(int landline) {
        if (landline > 0)
            Number::landline = landline;
    }

    void printLandlineNum() {
        cout << areaCode << "-" << landline;
    }

    friend istream& operator>>(istream& in, Number& num);
    friend ostream& operator<<(ostream& out, const Number& num);
};

istream& operator>>(istream& in, Number& num) {
    cout << "\nEnter mobile number: ";
    cin >> num.mobile;

    cout << "Enter landline number: ";
    int ac, ll;
    cin >> ac >> ll;
    num.setAreaCode(ac);
    num.setLandline(ll);

    return in;
}

ostream& operator<<(ostream& out, const Number& num) {
    out << "\nMobile number: " << num.mobile;
    out << "\nLandline number: " << num.areaCode << "-" << num.landline;

    return out;
}
