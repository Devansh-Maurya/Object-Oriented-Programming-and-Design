#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

//
// Created by devansh on 10/10/18.
//

class HugeInteger {

    const static int MAX_LENGTH = 40;
    const static int MAX_9_DIGIT_VALUE = 999999999;
    const static int BORROW_FACTOR = 1000000000;

    unsigned int _0To9;
    unsigned int _10To18;
    unsigned int _19To27;
    unsigned int _28To36;
    unsigned int _37To40;

    bool negative = false;

    void appendZerosToString(string &str, int length) {

        char *strToAppend = new char[length];

        for (int i = 0; i < length; ++i) {
            strToAppend[i] = '0';
        }


        str = strToAppend + str;
    }

    bool hasLessMagnitude(HugeInteger hugeInteger) {
        bool result = false;

        if (_37To40 < hugeInteger._37To40)
            result =  true;
        else
            if (_28To36 < hugeInteger._28To36)
                result =  true;
            else
                if (_19To27 < hugeInteger._19To27)
                    result =  true;
                else
                    if (_10To18 < hugeInteger._10To18)
                        result =  true;
                    else
                        if (_0To9 < hugeInteger._0To9)
                            result =  true;

        return result;
    }

public:

    HugeInteger() {
        _0To9 = _10To18 = _19To27 = _28To36 = _37To40 = 0;
    }

    HugeInteger(string numString) {
        input(numString);
    }

    //Copy constructor
    HugeInteger(const HugeInteger &oldNum) {
        negative = oldNum.negative;
        
        _0To9 = oldNum._0To9;
        _10To18 = oldNum._10To18;
        _19To27 = oldNum._19To27;
        _28To36 = oldNum._28To36;
        _37To40 = oldNum._37To40;
    }


    void input(string numString) {

        //stringLen specifies the last position up to which we need to go
        int stringLen = numString.length();

        if(numString[0] == '-') {
            negative = true;
            //Excluding the minus sign
            numString = numString.substr(1, stringLen);
        } else
            numString = numString.substr(0, stringLen);

        //MAX_LENGTH-stringLen specifies the number of zeroes to append
        appendZerosToString(numString, MAX_LENGTH - stringLen);

        _0To9 = stoi(numString.substr(37, 4));
        _10To18 = stoi(numString.substr(28, 9));
        _19To27 = stoi(numString.substr(19, 9));
        _28To36 = stoi(numString.substr(10, 9));
        _37To40 = stoi(numString.substr(1, 9));
    }


    void output() {
        string str = toString();
        cout << str;
    }

    //Getting a string representation of the number so that it can be used with cout
    string toString() {

        string out;

        if (negative) {
            out += '-';
        }

        if (_37To40 == 0) {
            if (_28To36 == 0) {
                if (_19To27 == 0) {
                    if (_10To18 == 0) {
                        out += to_string(_0To9);
                    } else
                        out +=  to_string(_10To18) + to_string(_0To9);
                } else
                    out +=  to_string(_19To27) + to_string(_10To18) + to_string(_0To9);
            } else
                out += to_string(_28To36) + to_string(_19To27) + to_string(_10To18) + to_string(_0To9);
        } else
             out += to_string(_37To40) + to_string(_28To36) + to_string(_19To27) + to_string(_10To18) + to_string(_0To9);

        return out;
    }



    HugeInteger add(HugeInteger &hugeInteger) {

        HugeInteger newHugeInteger;

        int carry = 0;

        //If anyone of the numbers is negative, subtract the two numbers
        if (isNegative() ^ hugeInteger.isNegative())
            return subtract(hugeInteger);

        if (isGreaterThan(hugeInteger))
            newHugeInteger.negative = negative;
        else
            newHugeInteger.negative = hugeInteger.negative;

        unsigned int _0To9Sum = _0To9 + hugeInteger._0To9;
        newHugeInteger._0To9 = _0To9Sum;
        if (_0To9Sum > MAX_9_DIGIT_VALUE)
            carry = 1;

        unsigned int _10To18Sum = _10To18 + hugeInteger._10To18 + carry;
        newHugeInteger._10To18 = _10To18Sum;
        carry = 0;
        if (_10To18Sum > MAX_9_DIGIT_VALUE)
            carry = 1;

        unsigned int _19To27Sum = _19To27 + hugeInteger._19To27 + carry;
        carry = 0;
        newHugeInteger._19To27 = _19To27Sum;
        if (_19To27Sum > MAX_9_DIGIT_VALUE)
            carry = 1;

        unsigned int _28To36Sum = _28To36 + hugeInteger._28To36 + carry;
        carry = 0;
        newHugeInteger._28To36 = _28To36Sum;
        if (_28To36Sum > MAX_9_DIGIT_VALUE)
            carry = 1;

        unsigned int _37To40Sum = _37To40 + hugeInteger._37To40 + carry;
        newHugeInteger._37To40 = _37To40Sum;

        return newHugeInteger;
    }


    HugeInteger subtract(HugeInteger hugeInteger) {

        HugeInteger newHugeInteger, thisNum = *this, temp;

        //If second number had opposite sign as that of first, after applying minus,
        //its sign will become the same as first, so both numbers will be added up

        //Here we are checking if both numbers have same sign or not, after applying minus
        //to second number
        if (!(isNegative() ^ !hugeInteger.negative)) {
            hugeInteger.negative = !hugeInteger.negative;
            return add(hugeInteger);
        }

        bool firstNumHasLessMag = hasLessMagnitude(hugeInteger);

        //Always subtract bigger number from smaller number
        if (firstNumHasLessMag) {
            //First number is lesser than second number, so sign of the result will be
            //opposite of the sign of the first number, as both numbers are of distinct sign
            temp = thisNum;
            thisNum = hugeInteger;
            hugeInteger = temp;
        }

        if (hugeInteger._0To9 > thisNum._0To9) {
            thisNum._10To18--;
            thisNum._0To9 += BORROW_FACTOR;
        }
        
        unsigned int _0To9Diff = thisNum._0To9 - hugeInteger._0To9;
        newHugeInteger._0To9 = _0To9Diff;

        if (hugeInteger._10To18 > thisNum._10To18) {
            thisNum._19To27--;
            thisNum._10To18 += BORROW_FACTOR;
        }
        unsigned int _10To18Diff = thisNum._10To18 - hugeInteger._10To18;
        newHugeInteger._10To18 = _10To18Diff;

        if (hugeInteger._19To27 > thisNum._19To27) {
            thisNum._28To36--;
            thisNum._19To27 += BORROW_FACTOR;
        }
        unsigned int _19To27Diff = thisNum._19To27 - hugeInteger._19To27;
        newHugeInteger._19To27 = _19To27Diff;

        if (hugeInteger._28To36 > thisNum._28To36) {
            thisNum._37To40--;
            thisNum._28To36 += BORROW_FACTOR;
        }
        unsigned int _28To36Diff = thisNum._28To36 - hugeInteger._28To36;
        newHugeInteger._28To36 = _28To36Diff;

        unsigned int _37To40Diff = thisNum._37To40 - hugeInteger._37To40;
        newHugeInteger._37To40 = _37To40Diff;

        //Result will get the flipped sign of second number
        if (firstNumHasLessMag)
            newHugeInteger.negative = !hugeInteger.negative;
        else
            newHugeInteger.negative = negative;

        return newHugeInteger;
    }

    bool isGreaterThan(HugeInteger &hugeInteger) {

        bool result = false;

        //If signs of both the numbers are different, and if first number is negative,
        //its lesser, else its greater

        if (isNegative() ^ hugeInteger.isNegative())
            return !isNegative();

        if (_37To40 > hugeInteger._37To40)
            result =  true;
        else
            if (_28To36 > hugeInteger._28To36)
                result =  true;
            else
                if (_19To27 > hugeInteger._19To27)
                    result =  true;
                else
                    if (_10To18 > hugeInteger._10To18)
                        result =  true;
                    else
                        if (_0To9 > hugeInteger._0To9)
                            result =  true;

        return (isNegative() & hugeInteger.isNegative()) == !result;

    }

    bool isEqualTo(HugeInteger &hugeInteger) {

        if (isNegative() ^ hugeInteger.isNegative())
            return false;

        return (_37To40 = hugeInteger._37To40)
               && (_28To36 = hugeInteger._28To36)
               && (_19To27 = hugeInteger._19To27)
               && (_10To18 = hugeInteger._10To18)
               && (_0To9 = hugeInteger._0To9);
    }

    //Parameter is a reference to prevent copying every time
    bool isLessThan(HugeInteger hugeInteger) {
        return !(isGreaterThan(hugeInteger) || isEqualTo(hugeInteger));
    }


    bool isNotEqualTo(HugeInteger &hugeInteger) {
        return !isEqualTo(hugeInteger);
    }


    bool isGreaterThanOrEqualTo(HugeInteger &hugeInteger) {
        return (isGreaterThan(hugeInteger) | isEqualTo(hugeInteger));
    }


    bool isLessThanOrEqualTo(HugeInteger &hugeInteger) {
        return (isLessThan(hugeInteger) | isEqualTo(hugeInteger));
    }

    bool isNegative() {
        return negative;
    }

    //Overloading not operator, because its being used in the subtract(HugeInteger) function
    HugeInteger operator! () {
        HugeInteger newInt;
        newInt.negative = !negative;
        return newInt;
    }
};
