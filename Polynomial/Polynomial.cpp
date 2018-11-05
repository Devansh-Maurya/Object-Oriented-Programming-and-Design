//
// Created by devansh on 5/11/18.
//

#include <iostream>

using namespace std;

#define MAX 100

class Polynomial {

    int poly[MAX];
    int degree;

    //Initialize the full array to zero
    void initializeToZero() {
        for (int &i : poly) {
            i = 0;
        }
    }

public:

    Polynomial(const int *poly, int n) {
        degree = n;
        initializeToZero();

        //Initialize the polynomial array
        for(int i = 0; i < degree; i++)
            this->poly[i] = poly[i];
    }

    //Copy constructor
    Polynomial(const Polynomial& polynomial) {
        degree = polynomial.degree;
        initializeToZero();

        for (int i = 0; i < degree; ++i) {
            poly[i] = polynomial.poly[i];
        }
    }

    Polynomial operator+(const Polynomial& polynomial) {
        int newP[MAX];
        //Select the maximum degree as the degree of the resulting polynomial
        int max = degree > polynomial.degree ? degree : polynomial.degree;

        for (int i = 0; i < max; ++i) {
            newP[i] = poly[i] + polynomial.poly[i];
        }

        return Polynomial(newP, max);
    }

    Polynomial operator-(const Polynomial& polynomial) {
        int newP[MAX];
        int max = degree > polynomial.degree ? degree : polynomial.degree;

        for (int i = 0; i < max; ++i) {
            newP[i] = poly[i] - polynomial.poly[i];
        }

        return Polynomial(newP, max);
    }

    Polynomial operator*(const Polynomial& polynomial) {
        int newP[MAX];
        int max = degree > polynomial.degree ? degree : polynomial.degree;
        int maxDegree = 2*max-2;
        int c = 0;

        for (int j = 0; j <= maxDegree; ++j) {
            c = 0;
            for (int k = 0; k <= j; ++k) {
                c += poly[k]*polynomial.poly[j-k];
            }
            newP[j] = c;
        }

        return Polynomial(newP, maxDegree);
    }

    Polynomial operator+=(const Polynomial& polynomial) {
        *this = *this + polynomial;
        return *this;
    }

    Polynomial operator-=(const Polynomial& polynomial) {
        *this = *this - polynomial;
        return *this;
    }

    Polynomial operator*=(const Polynomial& polynomial) {
        *this = *this * polynomial;
        return *this;
    }

    //Returns a polynomial to facilitate chaining of = operations
    Polynomial operator=(const Polynomial& polynomial) {
        degree = polynomial.degree;
        initializeToZero();

        for (int i = 0; i < degree; ++i) {
            poly[i] = polynomial.poly[i];
        }

        return *this;
    }

    void print() {
        for (int i = 0; i < degree; ++i) {

            cout << poly[i] << "x^" << i;
            if (i < degree && poly[i+1] > 0)
                cout << " + ";
            else if (i < degree && poly[i+1] == 0)
                i++;

            if (i == degree-1)
                cout << "\b\b";
        }
    }
};