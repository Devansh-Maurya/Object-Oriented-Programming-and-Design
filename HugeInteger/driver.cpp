#include <iostream>
#include <cstring>
#include <cstdio>

#include "HugeInteger.cpp"

using namespace std;

int main() {

    char num1[41];
    char num2[41];

    cout << "Enter first number" << endl;
    scanf("%s", num1);

    cout << "Enter second number" << endl;
    scanf(" %s", num2);

    HugeInteger hugeInteger1(num1), hugeInteger3(num2), hugeInteger2(num2);

    cout << "First number: ";
    hugeInteger1.output();

    cout << "\nSecond number: ";
    hugeInteger2.output();

    //Addition
    cout << "\n" << hugeInteger1.toString() << " + " << hugeInteger2.toString() + " = ";
    cout << hugeInteger1.add(hugeInteger2).toString();

    //Subtraction
    cout << "\n" << hugeInteger1.toString() << " - " << hugeInteger2.toString() + " = ";
    hugeInteger1.subtract(hugeInteger2).toString();


    if (hugeInteger1.isGreaterThan(hugeInteger2))
        cout << hugeInteger1.toString() << " is greater than " << hugeInteger2.toString();
    else
        cout << hugeInteger1.toString() << " is not greater than " << hugeInteger2.toString();

    if (hugeInteger1.isLessThan(hugeInteger2))
        cout << hugeInteger1.toString() << " is less than " << hugeInteger2.toString();
    else
        cout << hugeInteger1.toString() << " is not less than " << hugeInteger2.toString();

    if (hugeInteger1.isEqualTo(hugeInteger2))
        cout << hugeInteger1.toString() << " is equal to " << hugeInteger2.toString();
    else
        cout << hugeInteger1.toString() << " is not equal to " << hugeInteger2.toString();

    if (hugeInteger1.isNotEqualTo(hugeInteger2))
        cout << hugeInteger1.toString() << " is not equal to " << hugeInteger2.toString();
    else
        cout << hugeInteger1.toString() << " is equal to " << hugeInteger2.toString();

    if (hugeInteger1.isGreaterThanOrEqualTo(hugeInteger2))
        cout << hugeInteger1.toString() << " is greater than or equal to " << hugeInteger2.toString();
    else
        cout << hugeInteger1.toString() << " is not greater than or equal to " << hugeInteger2.toString();

    if (hugeInteger1.isLessThanOrEqualTo(hugeInteger2))
        cout << hugeInteger1.toString() << " is less than or equal to " << hugeInteger2.toString();
    else
        cout << hugeInteger1.toString() << " is not less than or equal to " << hugeInteger2.toString();

    return 0;
}