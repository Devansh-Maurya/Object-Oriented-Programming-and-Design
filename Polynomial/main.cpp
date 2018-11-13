#include <iostream>
#include "Polynomial.cpp"

using namespace std;

#define MAX 100

int main() {

    int degree;
    int *poly;

    cout << "For polynomial 1: \n\n";
    cout << "Enter the degree: ";
    cin >> degree;

    poly = new int[degree];

    cout << "Enter the coefficients one by one\n";
    for (int i = 0; i < degree; ++i) {

        cout << "Coefficient " << i <<": ";
        cin >> poly[i];

    }

    Polynomial polynomial1(poly, degree);

    cout << "\nFor polynomial 2: \n\n";
    cout << "Enter the degree: ";
    cin >> degree;

    poly = new int[degree];

    cout << "Enter the coefficients one by one\n";
    for (int i = 0; i < degree; ++i) {

        cout << "Coefficient " << i <<": ";
        cin >> poly[i];

    }

    Polynomial polynomial2(poly, degree);

    cout << "\nPolynomial 1: ";
    polynomial1.print();

    cout << "\n\nPolynomial 2: ";
    polynomial2.print();

    cout <<"\n\nSum: ";
    (polynomial1 + polynomial2).print();

    cout <<"\n\nDifference: ";
    (polynomial1 - polynomial2).print();

    cout <<"\n\nProduct: ";
    (polynomial1 * polynomial2).print();

    cout << "\n\nAssignment of polynomial 2 to 1: ";
    polynomial1 = polynomial2;
    polynomial1.print();

    return 0;
}