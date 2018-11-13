//
// Created by user on 11/13/18.
//

#include "TwoDimentionalShape.cpp"
#include <cmath>

class Circle : public TwoDimentionalShape{

    double r;

public:

    Circle(double r) : r(r) {}

    double getArea() override {
        cout << "Calculating area of circle: ";
        return M_PI*r*r;
    }
};


class Square : public TwoDimentionalShape {

    double side;

public:

    Square(double side) : side(side) {}

    double getArea() override {
        cout << "Calculating area of square: ";
        return side*side;
    }
};


class Triangle : public TwoDimentionalShape {

    double base, height;

public:

    Triangle(double base, double height) : base(base), height(height) {}

    double getArea() override {
        cout << "Calculating area of triangle: ";
        return (base*height)/2;
    }
};